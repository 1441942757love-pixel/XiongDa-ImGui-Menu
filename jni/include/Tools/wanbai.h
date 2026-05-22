#include <iostream>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <sys/socket.h>
#include <linux/netlink.h>
#include <sys/stat.h>

#define MAX_PAYLOAD 1048
// dit驱动对接例子，稍微对使用wanbai.h的源码优化了一下，把函数名改成和对接qx的一样，wanbai.h源码直接替换就可以对接上dit3.3和ditpor3.3了
// dit作者频道: @bbtsyyds  改名仔白云: @whitecloud6

//dit 3.3
struct Memory_uct{
	int read_write;//读或者写
	int pid;
	uintptr_t addr;
	void *buffer;
	size_t size;
};

//dit pro 3.3
struct Ditpro_uct{
	int read_write;//读或者写
	int pid;
	uintptr_t addr;
	void *buffer;
	size_t size;
	int wendi;//这个是判断只进行属于我们的操作,616
};


class drivers {
	private:
	bool ditbool;
	int sock_fd;
	struct sockaddr_nl dest_addr;
	struct nlmsghdr *nlh;
	struct iovec iov;
	struct msghdr msg;
	pid_t pid;
	int fd;
	
	typedef struct _COPY_MEMORY {
		pid_t pid;
		uintptr_t addr;
		void* buffer;
		size_t size;
	} COPY_MEMORY;
	
	
    bool File_authority(mode_t mode){
        if(mode & S_IRUSR && mode & S_IWUSR && mode & S_IRGRP && mode & S_IWGRP && mode & S_IROTH && mode & S_IWOTH)
            return true;
        return false;
    }
  	
  	
    char *proc_Sch() {
        struct dirent *ent;
        DIR *dir = opendir("/proc");
        char *device_path = NULL;

        if (dir == NULL) {
            printf("Could not open /proc directory");
            return NULL;
        }

        while ((ent = readdir(dir)) != NULL) {
        	if(!atoi(ent->d_name)){
        		char str[32] = "";
        		sprintf(str,"/proc/%s",ent->d_name);
        		struct stat sb;
        		if(stat(str, &sb) == 0){       		    
        		    if(this->File_authority(sb.st_mode)){
                    char *procpath = (char *)malloc(32);
                    sprintf(procpath,"/proc/%s",ent->d_name);
                    closedir(dir);
                    return procpath;
        		    }
        		}
        	}
        }
        closedir(dir);
        return NULL;
    }
    
    char *dev_Sch(){
        const char *dev_path = "/dev";
		DIR *dir = opendir(dev_path);
		if (dir == NULL){
			printf("无法打开/dev目录\n");
			return NULL;
		}

		struct dirent *entry;
		char file_path[256];
		while ((entry = readdir(dir)) != NULL) {

			if (strstr(entry->d_name,"std") != NULL || strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0 || strstr(entry->d_name, "gpiochip") != NULL) {
				continue;
			}
			
			if(strchr(entry->d_name, '_') != NULL && strchr(entry->d_name, '-') != NULL && strchr(entry->d_name, ':') != NULL) {
			    continue;
			}
			
			sprintf(file_path, "%s/%s", dev_path, entry->d_name);
			
			struct stat file_info;
			if (stat(file_path, &file_info) < 0)
				continue;
				
			if((localtime(&file_info.st_ctime)->tm_year + 1900) <= 1980)
		    	continue;
			
            if(strlen(entry->d_name) > 7 || strlen(entry->d_name) < 5)
                continue;
            
            if(file_info.st_gid != 0 || file_info.st_uid != 0)
                continue;

			if (S_ISCHR(file_info.st_mode) || S_ISBLK(file_info.st_mode)){					
				if(file_info.st_gid == 0 && file_info.st_uid == 0){
				    printf("%s\n",file_path);
				    char *devpath = (char *)malloc(32);
                    strcpy(devpath,file_path);
				    closedir(dir);
				    return devpath;
				}
			}
				
			
		}
	    closedir(dir);
	    return NULL;
    }
  	
    char* proc_hide_Sch()
	{
    	const char* command = "dir=$(ls -l /proc/*/exe 2>/dev/null | grep -E '/data/[^/]* \\(deleted\\)' | sed 's/ /\\n/g' | grep '/proc' | sed 's/\\/[^/]*$//g');if [[ \"$dir\" ]]; then sbwj=$(head -n 1 \"$dir/comm\");open_file=\"\";for file in \"$dir\"/fd/*; do link=$(readlink \"$file\");if [[ \"$link\" == \"/dev/$sbwj (deleted)\" ]]; then open_file=\"$file\";break;fi;done;if [[ -n \"$open_file\" ]]; then nhjd=$(echo \"$open_file\");sbid=$(ls -L -l \"$nhjd\" | sed 's/\\([^,]*\\).*/\\1/' | sed 's/.*root //');echo \"/dev/$sbwj\";rm -rf \"/dev/$sbwj\";mknod \"/dev/$sbwj\" c \"$sbid\" 0;fi;fi;";
    	FILE* file = popen(command, "r");
    	if (file == NULL) {
        	return NULL;
    	}
    	static char result[512];
    	if (fgets(result, sizeof(result), file) == NULL) {
			return NULL;
		}
    	pclose(file);
        result[strlen(result)-1] = '\0';
		return result;
    }
    
    void netlink_dit(){
    	memset(&dest_addr, 0, sizeof(dest_addr));
    	dest_addr.nl_family = AF_NETLINK;
    	dest_addr.nl_pid = 0;  // 内核
    	dest_addr.nl_groups = 0;

    	nlh = (struct nlmsghdr *)malloc(NLMSG_SPACE(MAX_PAYLOAD));
    	if (!nlh) {
            perror("malloc");
            exit(1);
    	}
    	memset(nlh, 0, NLMSG_SPACE(MAX_PAYLOAD));
    	nlh->nlmsg_len = NLMSG_SPACE(MAX_PAYLOAD);
    	nlh->nlmsg_flags = 0;

    	iov.iov_base = (void *)nlh;
    	iov.iov_len = nlh->nlmsg_len;

    	msg.msg_name = (void *)&dest_addr;
    	msg.msg_namelen = sizeof(dest_addr);
    	msg.msg_iov = &iov;
    	msg.msg_iovlen = 1;
    }
    
    int ioctl_str(const char *path){
        int bsf = open(path,O_RDWR);
        if(bsf == -1){
        	return -1;
        }
        return bsf;
    }
    
    public:
    int drivers_byte;
  	
    drivers() {
        fd = -1;
    	drivers_byte = -1;
    	sock_fd = -1;
        nlh = NULL;
        printf("\033[0;1m");//白色
        sock_fd = socket(PF_NETLINK, SOCK_RAW, 17);
        if(sock_fd < 0){
        	printf("未找到dit驱动\n");
            char *Procstr = this->proc_Sch();
            if(Procstr == NULL){
            	printf("未寻找到GT驱动\n");
                char *Devstr = this->dev_Sch();
                if(Devstr == NULL){
                	printf("未寻找到QX方案1\n");
                    char *Proc_H = this->proc_hide_Sch();
                    if(Proc_H == NULL){
                    	printf("未寻找到QX方案2\n");
                    }else{
                        fd = this->ioctl_str(Proc_H);
                        if(fd > 0){
                        	printf("载入QX方案2 %s\n",Proc_H);
                        	unlink(Proc_H);
                        	this->drivers_byte = 3;
                        }	
                    }
                }else{
                	fd = this->ioctl_str(Devstr);
                	if(fd > 0){
                        printf("载入QX方案1 %s\n",Devstr);
                        free(Devstr);
                        this->drivers_byte = 2;
                    }
                }
            }else{
                fd = this->ioctl_str(Procstr);
                if(fd > 0){
                     printf("载入GT驱动 %s\n",Procstr);
                     free(Procstr);
                     this->drivers_byte = 1;
                }		
            }
        }else{
        	this->netlink_dit();
        	printf("载入dit驱动\n");
        	this->drivers_byte = 0;
        }
        if(this->drivers_byte == -1){
        	printf("载入ditpro驱动\n(如果你不是ditpro 那就说明驱动对接失败 建议重启手机尝试输入别的驱动)\n");
        }
    }
    
      
	bool read(uintptr_t addr, void *buffer, size_t size) {
		if(this->drivers_byte == 0){
    		struct Memory_uct ptr;
			void *uctaddr = &ptr;
    		ptr.addr=addr;
			ptr.buffer=buffer;
			ptr.pid=this->pid;
			ptr.read_write=0x400;
			ptr.size=size;
			int bytelen = 8;
			char *source = (char *)&uctaddr;
			char *target = (char *)NLMSG_DATA(nlh);
			if(source == NULL || target == NULL)
				return false;
    		while (bytelen--) {
        		*target++ = *source++;
    		}
    		if (sendmsg(sock_fd, &msg, 0) < 0) {
    			return false;
    		}
		}else if(this->drivers_byte == -1){
			struct Ditpro_uct ptr;
    		ptr.read_write = 0x400;
    		ptr.addr = addr;
    		ptr.buffer = buffer;
    		ptr.wendi = 616;
    		ptr.pid = this->pid;
    		ptr.size = size;		
			if(syscall(SYS_lookup_dcookie,&ptr)){
				return true;
			}
		}else{
		    COPY_MEMORY cm;
		    cm.pid = this->pid;
		    cm.addr = addr;
		    cm.buffer = buffer;
		    cm.size = size;
		    if (ioctl(fd, 0x801, &cm) != 0) {
			    return false;
		    }
		}
    	return true;
	}
  
	template <typename T>
	T read(uintptr_t addr) {
		T res;
		if (this->read(addr, &res, sizeof(T)))
			return res;
		return {};
	}
	
	int init_pid(pid_t pid) {
        this->pid = pid;
        return pid;
    }
   
	~drivers() {
    	if (sock_fd != -1 && (int)this->drivers_byte == 1)
      		close(sock_fd);
    	if (nlh != NULL && (int)this->drivers_byte == 1)
    		free(nlh);
    	if(this->drivers_byte != 0){
    		close(fd);	
    	}
	}
	
pid_t GetPid(char* name) {
FILE* fp;
pid_t pid;
char cmd[0x100] = "pidof ";
strcat(cmd, name);
fp = popen(cmd,"r");
fscanf(fp,"%d", &pid);
pclose(fp);
return pid;
}

		uintptr_t getModuleBase(const char *module_name) {
		FILE *fp; 
		long addr = 0; 
		char *pch; 
		char filename[64]; 
		char line[1024]; 
		snprintf(filename, sizeof(filename), "/proc/%d/maps", this->pid); 
		fp = fopen(filename, "r"); 
		if (fp != NULL) { 
			while (fgets(line, sizeof(line), fp)) { 
				if (strstr(line, module_name)) { 
					pch = strtok(line, "-"); 
					addr = strtoul(pch, NULL, 16); 
					if (addr == 0x8000) addr = 0; 
						break; 
				} 
			} 
			fclose(fp); 
		} 
		return addr; 
	}
	
	
};

drivers* White = new drivers();

