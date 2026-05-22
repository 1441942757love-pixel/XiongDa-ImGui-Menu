#include <iostream>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//二次改进升级作者: 白云 @whitecloud6 食用方法自行参考qq收藏

#define MAX_LENGTH 1024

// 用于从源字符串中提取子字符串
char *getSubstring(const char *const src, const char *const startTag, const char *const endTag) {
const char *start = strstr(src, startTag);
if (start == nullptr) {
return nullptr;
}
start += strlen(startTag);

const char *end = strstr(start, endTag);
if (end == nullptr) {
return nullptr;
}

size_t length = end - start;
if (length == 0) {
return nullptr;
}

char *result = (char *)malloc(sizeof(char) * (length + 1));
if (result == nullptr) {
return nullptr;
}
strncpy(result, start, length);
result[length] = '\0';

return result;
}


// 获取云端链接
char *获取云端链接() {
char url[128];
sprintf(url, "curl -s %s", "https://sharechain.qq.com/23a839e6a5dd5354a57d315e6672c2f8");
FILE *fp = popen(url, "r");
if (fp == nullptr) {
return nullptr;
}
char buf[MAX_LENGTH];
while (fgets(buf, MAX_LENGTH, fp) != nullptr) {
char *链接文本 = strstr(buf, "[链接]");
if (链接文本 != nullptr) {
pclose(fp);
return getSubstring(链接文本, "[链接]", "[链接]");
}
}

pclose(fp);
return nullptr;
}

// 获取云端版本号
int 获取云端版本号() {
char url[128];
sprintf(url, "curl -s %s", "https://sharechain.qq.com/23a839e6a5dd5354a57d315e6672c2f8");
FILE *fp = popen(url, "r");
if (fp == nullptr) {
return 0; // or any suitable default value
}
char buf[MAX_LENGTH];
while (fgets(buf, MAX_LENGTH, fp) != nullptr) {
char *version = strstr(buf, "[版本号]");
if (version != nullptr) {
pclose(fp);
version = getSubstring(version, "[版本号]", "[版本号]");
int convertedVersion = atoi(version);
free(version);
return convertedVersion;
}
}

pclose(fp);
return 0; // or any suitable default value
}

// 获取云端公告
char *获取云端公告() {
char url[128];
sprintf(url, "curl -s %s", "https://sharechain.qq.com/23a839e6a5dd5354a57d315e6672c2f8");
FILE *fp = popen(url, "r");
if (fp == nullptr) {
return nullptr;
}
char buf[MAX_LENGTH];
while (fgets(buf, MAX_LENGTH, fp) != nullptr) {
char *公告文本 = strstr(buf, "[公告]");
if (公告文本 != nullptr) {
pclose(fp);
return getSubstring(公告文本, "[公告]", "[公告]");
}
}

pclose(fp);
return nullptr;
}

// 获取云端文件名
char *获取云端文件名() {
char url[128];
sprintf(url, "curl -s %s", "https://sharechain.qq.com/23a839e6a5dd5354a57d315e6672c2f8");
FILE *fp = popen(url, "r");
if (fp == nullptr) {
return nullptr;
}
char buf[MAX_LENGTH];
while (fgets(buf, MAX_LENGTH, fp) != nullptr) {
char *文件名 = strstr(buf, "[文件名]");
if (文件名 != nullptr) {
pclose(fp);
return getSubstring(文件名, "[文件名]", "[文件名]");
}
}

pclose(fp);
return nullptr;
}


char *测试1() {
char url[128];
sprintf(url, "curl -s https://sharechain.qq.com/eaa9e0235be943ce3303925cfd6525d6");

FILE *fp = popen(url, "r");
if (fp == nullptr) {
return nullptr;
}

// 分配足够大的缓冲区来存储整个网页内容
char *buffer = (char *)malloc(MAX_LENGTH);
if (buffer == nullptr) {
pclose(fp);
return nullptr;
}
buffer[0] = '\0'; // 初始化缓冲区

char tempBuffer[MAX_LENGTH];
while (fgets(tempBuffer, MAX_LENGTH, fp) != nullptr) {
// 将读取的内容追加到缓冲区
strcat(buffer, tempBuffer);
}

pclose(fp);
return buffer; // 返回整个网页内容
}

//获取名人名言
typedef struct {
char *quote;
char *from;
} OneSay;

OneSay 获取名人名言() {
char url[128];
sprintf(url, "curl -s https://v1.hitokoto.cn/?c=d&min_length=1&max_length=200&encode=text");

FILE *fp = popen(url, "r");
if (fp == nullptr) {
return (OneSay){nullptr, nullptr};
}

char *buffer = (char *)malloc(MAX_LENGTH);
if (buffer == nullptr) {
pclose(fp);
return (OneSay){nullptr, nullptr};
}
buffer[0] = '\0';

char tempBuffer[MAX_LENGTH];
while (fgets(tempBuffer, MAX_LENGTH, fp) != nullptr) {
strcat(buffer, tempBuffer);
}

pclose(fp);

// 提取名人名言内容
char *quoteStart = strstr(buffer, "\"hitokoto\":\"");
if (quoteStart == nullptr) {
free(buffer);
return (OneSay){nullptr, nullptr};
}
quoteStart += strlen("\"hitokoto\":\"");
char *quoteEnd = strstr(quoteStart, "\",\"type\":\"d\"");
if (quoteEnd == nullptr) {
free(buffer);
return (OneSay){nullptr, nullptr};
}
size_t quoteLength = quoteEnd - quoteStart;
char *quote = (char *)malloc(quoteLength + 1);
if (quote == nullptr) {
free(buffer);
return (OneSay){nullptr, nullptr};
}
strncpy(quote, quoteStart, quoteLength);
quote[quoteLength] = '\0';

// 提取出处
char *fromStart = strstr(buffer, "\"from\":\"");
if (fromStart == nullptr) {
free(buffer);
free(quote);
return (OneSay){nullptr, nullptr};
}
fromStart += strlen("\"from\":\"");
char *fromEnd = strstr(fromStart, "\",\"from_who\"");
if (fromEnd == nullptr) {
free(buffer);
free(quote);
return (OneSay){nullptr, nullptr};
}
size_t fromLength = fromEnd - fromStart;
char *from = (char *)malloc(fromLength + 1);
if (from == nullptr) {
free(buffer);
free(quote);
return (OneSay){nullptr, nullptr};
}
strncpy(from, fromStart, fromLength);
from[fromLength] = '\0';

free(buffer); // 释放原始缓冲区
return (OneSay){quote, from}; // 返回提取的名言和出处
}


// 云更新
void 云更新() {
printf("\033[0;1m");//白色
printf("\n正在验证版本是否为最新版...\n\n");
int 当前版本 = 1; // 为了演示目的，这里将当前版本设为2
int 云端版本 = 获取云端版本号();
char *更新公告 = 获取云端公告();
char *下载链接 = 获取云端链接();
char 版本号[10]; 
char 更新文件名[50]; 
sprintf(版本号, "%d", 云端版本 / 1, (云端版本 % 1) / 1, 云端版本 % 1);
strcat(更新文件名, 版本号);


if (云端版本 <= 当前版本) {
printf("\033[32;1m");//绿色
printf("当前食用版本: %d 可放心食用\n\n", 当前版本 / 1, (当前版本 % 1) / 1, 当前版本 % 1);
printf("云端版本: %s\n\n", 更新文件名);
printf("\033[0;1m");//白色
printf("公告:%s\n", 更新公告);
} else {
printf("\033[31;1m");//红色
printf("！！！当前食用版本: %d 过低\n\n", 当前版本 / 100, (当前版本 % 100) / 10, 当前版本 % 10);
printf("\033[0;1m");//白色
printf("具体更新内容请前往TG查看对应版本的更新公告\n\n");

char cmd[MAX_LENGTH];
int ret = system(cmd);
if (ret == 0) {
printf("\033[32;1m");//绿色
exit(0);
} else {
printf("\033[31;1m");//红色
printf("！！更新失败 请手动更新");
exit(0);
}
free(下载链接);
free(更新公告);
exit(0);
}
}