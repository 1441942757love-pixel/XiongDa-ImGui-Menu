#ifndef CLASS_H
#define CLASS_H

using namespace std;

bool alike(const string& Gname, const string& ClassName) {
return (Gname.find(ClassName)!= string::npos);
}
//---------------------------------------------------



string 金插(const string& n) {
if (n.find("perPeopleSkill") != string::npos)
return "金插";
return "";
}


string 信号枪_(const string& n) {
if (n.find("BP_Pistol_Flaregun_Wrapper_C") != string::npos || n.find("Flare") != string::npos)
return "信号枪";
return "";
}

inline const char* GetItems(int Id) {
switch (Id) {
//子弹

case 303001:
return "5.56子弹";
break;
case 3030011:
return "5.56子弹 锈蚀";
break;
case 3030012:
return "5.56子弹 普通";
break;
case 3030013:
return "5.56子弹 抛光";
break;
case 3030014:
return "5.56子弹 高爆";
break;
case 3030015:
return "5.56子弹 燃烧";
break;
case 3030016:
return "5.56子弹 毒性";
break;

case 301002:
return "5.7毫米";
break;
case 3010021:
return "5.7毫米 锈蚀";
break;
case 3010022:
return "5.7毫米 普通";
break;
case 3010023:
return "5.7毫米 抛光";
break;
case 3010024:
return "5.7毫米 高爆";
break;
case 3010025:
return "5.7毫米 燃烧";
break;
case 3010026:
return "5.7毫米 毒性";
break;

case 306001:
return "马格南";
break;
case 3060011:
return "马格南 锈蚀";
break;
case 3060012:
return "马格南 普通";
break;
case 3060013:
return "马格南 抛光";
break;
case 3060014:
return "马格南 高爆";
break;
case 3060015:
return "马格南 燃烧";
break;
case 3060016:
return "马格南 毒性";
break;

case 306002:
return "50口径";
break;
case 3060021:
return "50口径 锈蚀";
break;
case 3060022:
return "50口径 普通";
break;
case 3060023:
return "50口径 抛光";
break;
case 3060024:
return "50口径 高爆";
break;
case 3060025:
return "50口径 燃烧";
break;
case 3060026:
return "50口径 毒性";
break;

case 302001:  
return "7.62子弹";
break;
case 3020011:  
return "7.62子弹 锈蚀";
break;
case 3020012:  
return "7.62子弹 普通";
break;
case 3020013:  
return "7.62子弹 抛光";
break;
case 3020014:  
return "7.62子弹 高爆";
break;
case 3020015:  
return "7.62子弹 燃烧";
break;
case 3020016:  
return "7.62子弹 毒性";
break;

case 304001:
return "12口径";
break;
case 3040011:
return "12口径 锈蚀";
break;
case 3040012:
return "12口径 普通";
break;
case 3040013:
return "12口径 抛光";
break;
case 3040014:
return "12口径 高爆";
break;
case 3040015:
return "12口径 燃烧";
break;
case 3040016:
return "12口径 毒性";
break;


case 301001:
return "9毫米";
break;
case 3010011:
return "9毫米 锈蚀";
break;
case 3010012:
return "9毫米 普通";
break;
case 3010013:
return "9毫米 抛光";
break;
case 3010014:
return "9毫米 高爆";
break;
case 3010015:
return "9毫米 燃烧";
break;
case 3010016:
return "9毫米 毒性";
break;


case 305001:
return "45口径";
break;
case 3050011:
return "45口径 锈蚀";
break;
case 3050012:
return "45口径 普通";
break;
case 3050013:
return "45口径 抛光";
break;
case 3050014:
return "45口径 高爆";
break;
case 3050015:
return "45口径 燃烧";
break;
case 3050016:
return "45口径 毒性";
break;


//枪械
case 101004:
return "M416";
break;
case 1010041:
return "M416 破损";
break;
case 1010042:
return "M416 修复";
break;
case 1010043:
return "M416 完好";
break;
case 1010044:
return "M416 改进";
break;
case 1010045:
return "M416 精致";
break;
case 1010046:
return "M416 独眼";
break;
case 1010047:
return "M416 钢铁";
break;


case 101002:
return "M16A4";
break;
case 1010021:
return "M16A4 破损";
break;
case 1010022:
return "M16A4 修复";
break;
case 1010023:
return "M16A4 完好";
break;
case 1010024:
return "M16A4 改进";
break;
case 1010025:
return "M16A4 精致";
break;
case 1010026:
return "M16A4 独眼";
break;
case 1010027:
return "M16A4 钢铁";
break;


case 101005:
return "Groza";
break;
case 1010051:
return "Groza破损";
break;
case 1010052:
return "Groza修复";
break;
case 1010053:
return "Groza完好";
break;
case 1010054:
return "Groza改进";
break;
case 1010055:
return "Groza精致";
break;
case 1010056:
return "Groza独眼蛇";
break;
case 1010057:
return "Groza钢铁阵线";
break;


case 101009:
return "MK47(榴弹枪)";
break;
case 1010091:
return "MK47(榴弹枪) 破损";
break;
case 1010092:
return "MK47(榴弹枪) 修复";
break;
case 1010093:
return "MK47(榴弹枪) 完好";
break;
case 1010094:
return "MK47(榴弹枪) 改进";
break;
case 1010095:
return "MK47(榴弹枪) 精致";
break;
case 1010096:
return "MK47(榴弹枪) 独眼";
break;
case 1010097:
return "MK47(榴弹枪) 钢铁";
break;


case 102002:
return "UMP45";
break;
case 1020021:
return "UMP45 破损";
break;
case 1020022:
return "UMP45 修复";
break;
case 1020023:
return "UMP45 完好";
break;
case 1020024:
return "UMP45 改进";
break;
case 1020025:
return "UMP45 精致";
break;
case 1020026:
return "UMP45 独眼";
break;
case 1020027:
return "UMP45 钢铁";
break;



case 101007:
return "QBZ步枪";
break;
case 1010071:
return "QBZ步枪 破损";
break;
case 1010072:
return "QBZ步枪 修复";
break;
case 1010073:
return "QBZ步枪 完好";
break;
case 1010074:
return "QBZ步枪 改进";
break;
case 1010075:
return "QBZ步枪 精致";
break;
case 1010076:
return "QBZ步枪 独眼";
break;
case 1010077:
return "QBZ步枪 钢铁";
break;



case 102005:
return "野牛冲锋枪";
break;
case 1020051:
return "野牛冲锋枪 破损";
break;
case 1020052:
return "野牛冲锋枪 修复";
break;
case 1020053:
return "野牛冲锋枪 完好";
break;
case 1020054:
return "野牛冲锋枪 改进";
break;
case 1020055:
return "野牛冲锋枪 精致";
break;
case 1020056:
return "野牛冲锋枪 独眼";
break;
case 1020057:
return "野牛冲锋枪 钢铁";
break;

case 102001:
return "UZI";
break;
case 1020011:
return "UZI 破损";
break;
case 1020012:
return "UZI 修复";
break;
case 1020013:
return "UZI 完好";
break;
case 1020014:
return "UZI 改进";
break;
case 1020015:
return "UZI 精致";
break;
case 1020016:
return "UZI 独眼";
break;
case 1020017:
return "UZI 钢铁";
break;

case 103001:
return "98K";
break;
case 1030011:
return "98K 破损";
break;
case 1030012:
return "98K 修复";
break;
case 1030013:
return "98K 完好";
break;
case 1030014:
return "98K 改进";
break;
case 1030015:
return "98K 精致";
break;
case 1030016:
return "98K 独眼";
break;
case 1030017:
return "98K 钢铁";
break;

case 103002:
return "M24";
break;
case 1030021:
return "M24 破损";
break;
case 1030022:
return "M24 修复";
break;
case 1030023:
return "M24 完好";
break;
case 1030024:
return "M24 改进";
break;
case 1030025:
return "M24 精致";
break;
case 1030026:
return "M24 独眼";
break;
case 1030027:
return "M24 钢铁";
break;

case 103007:
case 1030071:  
return "M14(妹控)";
break;
case 1030072:  
return "M14(妹控) 修复";
break;
case 1030073:  
return "M14(妹控) 完好";
break;
case 1030074:  
return "M14(妹控) 改进";
break;
case 1030075:  
return "M14(妹控) 精致";
break;
case 1030076:  
return "M14(妹控) 独眼";
break;
case 1030077: 
return "M14(妹控) 钢铁";
break;






case 1004002:
return "S686";
break;
case 10040021:
return "S686 破损";
break;
case 10040022:
return "S686 修复";
break;
case 10040023:
return "S686 完好";
break;
case 10040024:
return "S686 改进";
break;
case 10040025:
return "S686 精致";
break;
case 10040026:
return "S686 独眼";
break;
case 10040027:
return "S686 钢铁";
break;


case 103100:
return "MK12狙击步枪";
break;
case 1031001:
return "MK12狙击步枪 破损";
break;
case 1031002:
return "MK12狙击步枪 修复";
break;
case 1031003:
return "MK12狙击步枪 完好";
break;
case 1031004:
return "MK12狙击步枪 改进";
break;
case 1031005:
return "MK12狙击步枪 精致";
break;
case 1031006:
return "MK12狙击步枪 独眼";
break;
case 1031007:
return "MK12狙击步枪 钢铁";
break;

case 102007:
return "MP5K";
break;
case 1020071:
return "MP5K 破损";
break;
case 1020072:
return "MP5K 修复";
break;
case 1020073:
return "MP5K 完好";
break;
case 1020074:
return "MP5K 改进";
break;
case 1020075:
return "MP5K 精致";
break;
case 1020076:
return "MP5K 独眼";
break;
case 1020077:
return "MP5K 钢铁";
break;


case 104003:
return "S12K";
break;
case 1040031:
return "S12K 破损";
break;
case 1040032:
return "S12K 修复";
break;
case 1040033:
return "S12K 完好";
break;
case 1040034:
return "S12K 改进";
break;
case 1040035:
return "S12K 精致";
break;
case 1040036:
return "S12K 独眼";
break;
case 1040037:
return "S12K 钢铁";
break;


case 101006:
return "AUG";
break;
case 1010061:
return "AUG 破损";
break;
case 1010062:
return "AUG 修复";
break;
case 1010063:
return "AUG 完好";
break;
case 1010064:
return "AUG 改进";
break;
case 1010065:
return "AUG 精致";
break;
case 1010066:
return "AUG 独眼";
break;
case 1010067:
return "AUG 钢铁";
break;

case 104102:
return "NS2000";
break;
case 1041021:
return "NS2000 破损";
break;
case 1041022:
return "NS2000 修复";
break;
case 1041023:
return "NS2000 完好";
break;
case 1041024:
return "NS2000 改进";
break;
case 1041025:
return "NS2000 精致";
break;
case 1041026:
return "NS2000 独眼";
break;
case 1041027:
return "NS2000 钢铁";
break;



case 101003:
return "SCAR_L";
break;
case 1010031:
return "SCAR_L 破损";
break;
case 1010032:
return "SCAR_L 修复";
break;
case 1010033:
return "SCAR_L 完好";
break;
case 1010034:
return "SCAR_L 改进";
break;
case 1010035:
return "SCAR_L 精致";
break;
case 1010036:
return "SCAR_L 独眼";
break;
case 1010037:
return "SCAR_L 钢铁";
break;

case 101008:
return "M762";
break;
case 1010081:
return "M762 破损";
break;
case 1010082:
return "M762 修复";
break;
case 1010083:
return "M762 完好";
break;
case 1010084:
return "M762 改进";
break;
case 1010085:
return "M762 精致";
break;
case 1010086:
return "M762 独眼";
break;
case 1010087:
return "M762 钢铁";
break;


case 101001:
return "AKM";
break;
case 1010011:
return "AKM 破损";
break;
case 1010012:
return "AKM 修复";
break;
case 1010013:
return "AKM 完好";
break;
case 1010014:
return "AKM 改进";
break;
case 1010015:
return "AKM 精致";
break;
case 1010016:
return "AKM 独眼";
break;
case 1010017:
return "AKM 钢铁";
break;

case 104002:
return "S1897";
break;
case 1040021:
return "S1897 破损";
break;
case 1040022:
return "S1897 修复";
break;
case 1040023:
return "S1897 完好";
break;
case 1040024:
return "S1897 改进";
break;
case 1040025:
return "S1897 精致";
break;
case 1040026:
return "S1897 独眼";
break;
case 1040027:
return "S1897 钢铁";
break;

case 104004:
return "DBS";
break;
case 1040041:
return "DBS 破损";
break;
case 1040042:
return "DBS 修复";
break;
case 1040043:
return "DBS 完好";
break;
case 1040044:
return "DBS 改进";
break;
case 1040045:
return "DBS 精致";
break;
case 1040046:
return "DBS 独眼";
break;
case 1040047:
return "DBS 钢铁";
break;


case 102003:
return "维克托冲锋枪";
break;
case 1020031:
return "维克托冲锋枪 破损";
break;
case 1020032:
return "维克托冲锋枪 修复";
break;
case 1020033:
return "维克托冲锋枪 完好";
break;
case 1020034:
return "维克托冲锋枪 改进";
break;
case 1020035:
return "维克托冲锋枪 精致";
break;
case 1020036:
return "维克托冲锋枪 独眼";
break;
case 1020037:
return "维克托冲锋枪 钢铁";
break;

case 102004:
return "汤姆逊冲锋枪";
break;
case 1020041:
return "汤姆逊冲锋枪 破损";
break;
case 1020042:
return "汤姆逊冲锋枪 修复";
break;
case 1020043:
return "汤姆逊冲锋枪 完好";
break;
case 1020044:
return "汤姆逊冲锋枪 改进";
break;
case 1020045:
return "汤姆逊冲锋枪 精致";
break;
case 1020046:
return "汤姆逊冲锋枪 独眼";
break;
case 1020047:
return "汤姆逊冲锋枪 钢铁";
break;


case 101102:
return "ACE步枪";
break;
case 1011021:
return "ACE步枪 破损";
break;
case 1011022:
return "ACE步枪 修复";
break;
case 1011023:
return "ACE步枪 完好";
break;
case 1011024:
return "ACE步枪 改进";
break;
case 1011025:
return "ACE步枪 精致";
break;
case 1011026:
return "ACE步枪 独眼";
break;
case 1011027:
return "ACE步枪 钢铁";
break;

case 105001:
return "M249";
break;
case 1050011:
return "M249 破损";
break;
case 1050012:
return "M249 修复";
break;
case 1050013:
return "M249 完好";
break;
case 1050014:
return "M249 改进";
break;
case 1050015:
return "M249 精致";
break;
case 1050016:
return "M249 独眼";
break;
case 1050017:
return "M249 钢铁";
break;


case 101100:
return "FAMAS(步枪)";
break;
case 1011001:
return "FAMAS(步枪) 破损";
break;
case 1011002:
return "FAMAS(步枪) 修复";
break;
case 1011003:
return "FAMAS(步枪) 完好";
break;
case 1011004:
return "FAMAS(步枪) 改进";
break;
case 1011005:
return "FAMAS(步枪) 精致";
break;
case 1011006:
return "FAMAS(步枪) 独眼";
break;
case 1011007:
return "FAMAS(步枪) 钢铁";
break;

case 101010:
return "G36C";
break;
case 1010101:
return "G36C破损";
break;
case 1010102:
return "G36C修复";
break;
case 1010103:
return "G36C完好";
break;
case 1010104:
return "G36C改进";
break;
case 1010105:
return "G36C精致";
break;
case 1010106:
return "G36C独眼蛇";
break;
case 1010107:
return "G36C钢铁阵线";
break;

case 101011:
return "AC-VAL";
break;

case 101012:
return "蜜獾突击步枪";
break;
case 1010121:
return "蜜獾突击步枪破损";
break;
case 1010122:
return "蜜獾突击步枪修复";
break;
case 1010123:
return "蜜獾突击步枪完好";
break;
case 1010124:
return "蜜獾突击步枪改进";
break;
case 1010125:
return "蜜獾突击步枪精致";
break;
case 1010126:
return "蜜獾突击步枪独眼蛇";
break;
case 1010127:
return "蜜獾突击步枪钢铁阵线";
break;

case 105010:
return "MG3";
break;
case 1050101:
return "MG3 破损";
break;
case 1050102:
return "MG3 修复";
break;
case 1050103:
return "MG3 完好";
break;
case 1050104:
return "MG3 改进";
break;
case 1050105:
return "MG3 精致";
break;
case 1050106:
return "MG3 独眼";
break;
case 1050107:
return "MG3 钢铁";
break;

case 103005:
return "VSS狙击枪";
break;
case 1030051:
return "VSS狙击枪 破损";
break;
case 1030052:
return "VSS狙击枪 修复";
break;
case 1030053:
return "VSS狙击枪 完好";
break;
case 1030054:
return "VSS狙击枪 改进";
break;
case 1030055:
return "VSS狙击枪 精致";
break;
case 1030056:
return "VSS狙击枪 独眼";
break;
case 1030057:
return "VSS狙击枪 钢铁";
break;


case 103009:
return "SLR狙击枪";
break;
case 1030091:
return "SLR狙击枪 破损";
break;
case 1030092:
return "SLR狙击枪 修复";
break;
case 1030093:
return "SLR狙击枪 完好";
break;
case 1030094:
return "SLR狙击枪 改进";
break;
case 1030095:
return "SLR狙击枪 精致";
break;
case 1030096:
return "SLR狙击枪 独眼";
break;
case 1030097:
return "SLR狙击枪 钢铁";
break;


case 103003:
return "AWM狙击枪";
break;
case 1030031:
return "AWM狙击枪 破损";
break;
case 1030032:
return "AWM狙击枪 修复";
break;
case 1030033:
return "AWM狙击枪 完好";
break;
case 1030034:
return "AWM狙击枪 改进";
break;
case 1030035:
return "AWM狙击枪 精致";
break;
case 1030036:
return "AWM狙击枪 独眼";
break;
case 1030037:
return "AWM狙击枪 钢铁";
break;


case 103004:
return "SKS狙击枪";
break;
case 1030041:
return "SKS狙击枪 破损";
break;
case 1030042:
return "SKS狙击枪 修复";
break;
case 1030043:
return "SKS狙击枪 完好";
break;
case 1030044:
return "SKS狙击枪 改进";
break;
case 1030045:
return "SKS狙击枪 精致";
break;
case 1030046:
return "SKS狙击枪 独眼";
break;
case 1030047:
return "SKS狙击枪 钢铁";
break;

//手枪
case 106010:
return "沙漠之鹰(手枪)";
break;
case 1060101:
return "沙漠之鹰(手枪) 破损";
break;
case 1060102:
return "沙漠之鹰(手枪) 修复";
break;
case 1060103:
return "沙漠之鹰(手枪) 完好";
break;
case 1060104:
return "沙漠之鹰(手枪) 改进";
break;
case 1060105:
return "沙漠之鹰(手枪) 精致";
break;
case 1060106:
return "沙漠之鹰(手枪) 独眼";
break;
case 1060107:
return "沙漠之鹰(手枪) 钢铁";
break;


case 106002:
return "P1911";
break;
case 1060021:
return "P1911 破损";
break;
case 1060022:
return "P1911 修复";
break;
case 1060023:
return "P1911 完好";
break;
case 1060024:
return "P1911 改进";
break;
case 1060025:
return "P1911 精致";
break;
case 1060026:
return "P1911 独眼";
break;
case 1060027:
return "P1911 钢铁";
break;


case 106001:
return "P92手枪";
break;
case 1060011:
return "P92手枪 破损";
break;
case 1060012:
return "P92手枪 修复";
break;
case 1060013:
return "P92手枪 完好";
break;
case 1060014:
return "P92手枪 改进";
break;
case 1060015:
return "P92手枪 精致";
break;
case 1060016:
return "P92手枪 独眼";
break;
case 1060017:
return "P92手枪 钢铁";
break;


case 106004:
return "P18C(手枪)";
break;
case 1060041:
return "P18C(手枪) 破损";
break;
case 1060042:
return "P18C(手枪) 修复";
break;
case 1060043:
return "P18C(手枪) 完好";
break;
case 1060044:
return "P18C(手枪) 改进";
break;
case 1060045:
return "P18C(手枪) 精致";
break;
case 1060046:
return "P18C(手枪) 独眼";
break;
case 1060047:
return "P18C(手枪) 钢铁";
break;


case 106006:
return "短管霰弹枪";
break;
case 1060061:
return "短管霰弹枪 破损";
break;
case 1060062:
return "短管霰弹枪 修复";
break;
case 1060063:
return "短管霰弹枪 完好";
break;
case 1060064:
return "短管霰弹枪 改进";
break;
case 1060065:
return "短管霰弹枪 精致";
break;
case 1060066:
return "短管霰弹枪 独眼";
break;
case 1060067:
return "短管霰弹枪 钢铁";
break;

case 106008:
return "蝎式手枪";
break;
case 1060081:
return "蝎式手枪 破损";
break;
case 1060082:
return "蝎式手枪 修复";
break;
case 1060083:
return "蝎式手枪 完好";
break;
case 1060084:
return "蝎式手枪 改进";
break;
case 1060085:
return "蝎式手枪 精致";
break;
case 1060086:
return "蝎式手枪 独眼";
break;
case 1060087:
return "蝎式手枪 钢铁";
break;


case 106011:
return "双枪(手枪)";
break;
case 1060111:
return "双枪(手枪) 破损";
break;
case 1060112:
return "双枪(手枪) 修复";
break;
case 1060113:
return "双枪(手枪) 完好";
break;
case 1060114:
return "双枪(手枪) 改进";
break;
case 1060115:
return "双枪(手枪) 精致";
break;
case 1060116:
return "双枪(手枪) 独眼";
break;
case 1060117:
return "双枪(手枪) 钢铁";
break;

//护甲
case 501106:  
return "六级包";
break;
case 501105:  
return "五级包";
break;
case 501104:  
return "四级包";
break;
case 501103:
case 501003:  
return "三级包";
break;
case 501102:  
case 501002:
return "二级包";
break;
case 501101:
case 501001:
return "一级包";
break;

case 503112:
return "六级甲 钢铁";
break;
case 503109:
return "六级甲 独眼";
break;
case 503106:
return "六级甲";
break;

case 503111:
return "五级甲 钢铁";
break;
case 503108:
return "五级甲 独眼";
break;
case 503105:
return "五级甲";
break;

case 503110:
return "四级甲 钢铁";
break;
case 503107:
return "四级甲 独眼";
break;
case 503104:
return "四级甲";
break;

case 503103:
case 503003:
return "三级甲";
break;
case 503102:
case 503002:
return "二级甲";
break;
case 503101:
case 503001:
return "一级甲";
break;

case 502112:
return "六级头 钢铁";
break;
case 502109:
return "六级头 独眼";
break;
case 502106:
return "六级头";
break;

case 502111:
return "五级头 钢铁";
break;
case 502108:
return "五级头 独眼";
break;
case 502105:
return "五级头";
break;

case 502110:
return "四级头 钢铁";
break;
case 502107:
return "四级头 独眼";
break;
case 502104:
return "四级头";
break;

case 502103:
//case 1031003:
return "三级头";
break;

case 502102:
//case 1031002:
return "二级头";
break;

case 502101:
//case 1031001:
return "一级头";
break;


//配件
case 205002:  
return "步枪枪托";
break;
case 204004:  
return "冲锋枪扩容弹夹";
break;
//倍镜
case 203015:  
return "6倍镜";
break;
//药品
case 601001:
return "能量饮料";
break;
case 601002:
return "肾上腺素";
break;
case 601003:
return "止痛药";
break;
case 601004:
return "绷带";
break;
case 601005:
return "急救包";
break;
case 601006:
return "全能医疗箱";
break;
case 601007:
return "抗干扰药";//应该是抗辐射药
break;
//投掷物
case 602001:
return "震爆弹";
break;
case 602002:
return "烟雾弹";
break;
case 602003:
return "燃烧瓶";
break;
case 602004:
return "破片手榴弹";
break;
//近战武器
case 1080041:
return "平底锅";
break;
case 1080051:
return "军用匕首";
break;
case 1080011:
return "大砍刀";
break;
//其他
case 3001028:
return "现金袋";
break;
case 3001068:
return "鼓鼓的现金袋";
break;
case 3001030:
return "科技部件";
break;
case 3001035:
return "蓝图";
break;
case 3001085:
return "军用电池";
break;
case 2040083:
return "狙击枪快速弹夹(完好)";
break;
case 3001098:
return "过期的奖券";
break;
case 3001067:
return "金砖";
break;
case 307099:
return "榴弹";
break;
case 203001:
return "红点";
break;
case 203002:
return "全息瞄准镜";
break;
case 1060071:
return "撤离信号枪";
break;
case 3001042:
return "红卡";
break;
case 3001045:
return "黑卡";
break;
case 3001049:
return "净水器";
break;
case 3001086:
return "军用电路板";
break;
case 3001055:
return "CPU处理器";
break;
case 20900451:
return "精致尼龙绑带 破损";
break;
case 20900452:
return "精致尼龙绑带 修复";
break;
case 20900453:
return "精致尼龙绑带 完好";
break;
case 20900454:
return "精致尼龙绑带 精致";
break;
case 3001032:
return "狗牌";
break;
case 3001053:
return "平板电脑";
break;
case 3001038:
return "探测器";
break;
case 3001033:
return "信号发生器";
break;
case 3001054:
return "一根金条";
break;
case 204006:
return "冲锋枪(手枪)快速扩容";
break;
case 2040061:
return "冲锋枪(手枪)快速扩容 破损";
break;
case 2040062:
return "冲锋枪(手枪)快速扩容 修复";
break;
case 2040063:
return "冲锋枪(手枪)快速扩容 完好";
break;
case 2040064:
return "冲锋枪(手枪)快速扩容 精致";
break;




default:
return "未收录";
break;
}
}

inline char *文本手持(int Id) {
switch (Id) {
case 101001:
return "AKM";
break;
case 1010011:
return "AKM破损";
break;
case 1010012:
return "AKM修复";
break;
case 1010013:
return "AKM完好";
break;
case 1010014:
return "AKM改进";
break;
case 1010015:
return "AKM精致";
break;
case 1010016:
return "AKM独眼蛇";
break;
case 1010017:
return "AKM钢铁阵线";
break;

case 101002:
return "M16A4";
break;
case 1010021:
return "M16A4破损";
break;
case 1010022:
return "M16A4修复";
break;
case 1010023:
return "M16A4完好";
break;
case 1010024:
return "M16A4改进";
break;
case 1010025:
return "M16A4精致";
break;

case 101003:
return "SCAR-L";
break;
case 1010031:
return "SCAR-L破损";
break;
case 1010032:
return "SCAR-L修复";
break;
case 1010033:
return "SCAR-L完好";
break;
case 1010034:
return "SCAR-L改进";
break;
case 1010035:
return "SCAR-L精致";
break;
case 1010036:
return "SCAR-L独眼蛇";
break;
case 1010037:
return "SCAR-L钢铁阵线";
break;

case 101004:
return "M416";
break;
case 1010041:
return "M416破损";
break;
case 1010042:
return "M416修复";
break;
case 1010043:
return "M416完好";
break;
case 1010044:
return "M416改进";
break;
case 1010045:
return "M416精致";
break;
case 1010046:
return "M416独眼蛇";
break;
case 1010047:
return "M416钢铁阵线";
break;

case 101005:
return "Groza";
break;
case 1010051:
return "Groza破损";
break;
case 1010052:
return "Groza修复";
break;
case 1010053:
return "Groza完好";
break;
case 1010054:
return "Groza改进";
break;
case 1010055:
return "Groza精致";
break;
case 1010056:
return "Groza独眼蛇";
break;
case 1010057:
return "Groza钢铁阵线";
break;

case 101006:
return "AUG";
break;
case 1010061:
return "AUG破损";
break;
case 1010062:
return "AUG修复";
break;
case 1010063:
return "AUG完好";
break;
case 1010064:
return "AUG改进";
break;
case 1010065:
return "AUG精致";
break;
case 1010066:
return "AUG独眼蛇";
break;
case 1010067:
return "AUG钢铁阵线";
break;

case 101007:
return "QBZ";
break;
case 1010071:
return "QBZ破损";
break;
case 1010072:
return "QBZ修复";
break;
case 1010073:
return "QBZ完好";
break;
case 1010074:
return "QBZ改进";
break;
case 1010075:
return "QBZ精致";
break;
case 1010076:
return "QBZ独眼蛇";
break;
case 1010077:
return "QBZ钢铁阵线";
break;

case 101008:
return "M762";
break;
case 1010081:
return "M762破损";
break;
case 1010082:
return "M762修复";
break;
case 1010083:
return "M762完好";
break;
case 1010084:
return "M762改进";
break;
case 1010085:
return "M762精致";
break;
case 1010086:
return "M762独眼蛇";
break;
case 1010087:
return "M762钢铁阵线";
break;

case 101102:
return "ACE32";
break;
case 1011021:
return "ACE32破损";
break;
case 1011022:
return "ACE32修复";
break;
case 1011023:
return "ACE32完好";
break;
case 1011024:
return "ACE32改进";
break;
case 1011025:
return "ACE32精致";
break;
case 1011026:
return "ACE32独眼蛇";
break;
case 1011027:
return "ACE32钢铁阵线";
break;

case 101009:
return "Mk47";
break;
case 1010091:
return "Mk47破损";
break;
case 1010092:
return "Mk47修复";
break;
case 1010093:
return "Mk47完好";
break;
case 1010094:
return "Mk47改进";
break;
case 1010095:
return "Mk47精致";
break;

case 101010:
return "G36C";
break;
case 1010101:
return "G36C破损";
break;
case 1010102:
return "G36C修复";
break;
case 1010103:
return "G36C完好";
break;
case 1010104:
return "G36C改进";
break;
case 1010105:
return "G36C精致";
break;
case 1010106:
return "G36C独眼蛇";
break;
case 1010107:
return "G36C钢铁阵线";
break;

case 101011:
return "AC-VAL";
break;

case 101012:
return "蜜獾突击步枪";
break;
case 1010121:
return "蜜獾突击步枪破损";
break;
case 1010122:
return "蜜獾突击步枪修复";
break;
case 1010123:
return "蜜獾突击步枪完好";
break;
case 1010124:
return "蜜獾突击步枪改进";
break;
case 1010125:
return "蜜獾突击步枪精致";
break;
case 1010126:
return "蜜獾突击步枪独眼蛇";
break;
case 1010127:
return "蜜獾突击步枪钢铁阵线";
break;

case 102001:
return "UZI";
break;
case 1020011:
return "UZI破损";
break;
case 1020012:
return "UZI修复";
break;
case 1020013:
return "UZI完好";
break;
case 1020014:
return "UZI改进";
break;
case 1020015:
return "UZI精致";
break;

case 102002:
return "UMP-45";
break;
case 1020021:
return "UMP-45破损";
break;
case 1020022:
return "UMP-45修复";
break;
case 1020023:
return "UMP-45完好";
break;
case 1020024:
return "UMP-45改进";
break;
case 1020025:
return "UMP-45精致";
break;

case 102003:
return "Vector";
break;
case 1020031:
return "Vector破损";
break;
case 1020032:
return "Vector修复";
break;
case 1020033:
return "Vector完好";
break;
case 1020034:
return "Vector改进";
break;
case 1020035:
return "Vector精致";
break;
case 1020036:
return "Vector独眼蛇";
break;
case 1020037:
return "Vector钢铁阵线";
break;

case 102004:
return "汤姆逊";
break;
case 1020041:
return "汤姆逊破损";
break;
case 1020042:
return "汤姆逊修复";
break;
case 1020043:
return "汤姆逊完好";
break;
case 1020044:
return "汤姆逊改进";
break;
case 1020045:
return "汤姆逊精致";
break;

case 102005:
return "野牛";
break;
case 1020051:
return "野牛破损";
break;
case 1020052:
return "野牛修复";
break;
case 1020053:
return "野牛完好";
break;
case 1020054:
return "野牛改进";
break;
case 1020055:
return "野牛精致";
break;

case 102006:
return "MP5K";
break;
case 1020061:
return "MP5K破损";
break;
case 1020062:
return "MP5K修复";
break;
case 1020063:
return "MP5K完好";
break;
case 1020064:
return "MP5K改进";
break;
case 1020065:
return "MP5K精致";
break;
case 1020066:
return "MP5K独眼蛇";
break;
case 1020067:
return "MP5K钢铁阵线";
break;

case 102007:
return "P90";
break;
case 1020071:
return "P90破损";
break;
case 1020072:
return "P90修复";
break;
case 1020073:
return "P90完好";
break;
case 1020074:
return "P90改进";
break;
case 1020075:
return "P90精致";
break;

case 103001:
return "Kar98K";
break;
case 1030011:
return "Kar98K破损";
break;
case 1030012:
return "Kar98K修复";
break;
case 1030013:
return "Kar98K完好";
break;
case 1030014:
return "Kar98K改进";
break;
case 1030015:
return "Kar98K精致";
break;

case 103002:
return "M24";
break;
case 1030021:
return "M24破损";
break;
case 1030022:
return "M24修复";
break;
case 1030023:
return "M24完好";
break;
case 1030024:
return "M24改进";
break;
case 1030025:
return "M24精致";
break;
case 1030026:
return "M24独眼蛇";
break;
case 1030027:
return "M24钢铁阵线";
break;

case 103003:
return "AWM";
break;
case 1030031:
return "AWM破损";
break;
case 1030032:
return "AWM修复";
break;
case 1030033:
return "AWM完好";
break;
case 1030034:
return "AWM改进";
break;
case 1030035:
return "AWM精致";
break;
case 1030036:
return "AWM独眼蛇";
break;
case 1030037:
return "AWM钢铁阵线";
break;

case 103004:
return "SKS";
break;
case 1030041:
return "SKS破损";
break;
case 1030042:
return "SKS修复";
break;
case 1030043:
return "SKS完好";
break;
case 1030044:
return "SKS改进";
break;
case 1030045:
return "SKS精致";
break;
case 1030046:
return "SKS独眼蛇";
break;
case 1030047:
return "SKS钢铁阵线";
break;

case 103005:
return "VSS";
break;
case 1030051:
return "VSS破损";
break;
case 1030052:
return "VSS修复";
break;
case 1030053:
return "VSS完好";
break;
case 1030054:
return "VSS改进";
break;
case 1030055:
return "VSS精致";
break;

case 103006:
return "Mini14";
break;
case 1030061:
return "Mini14破损";
break;
case 1030062:
return "Mini14修复";
break;
case 1030063:
return "Mini14完好";
break;
case 1030064:
return "Mini14改进";
break;
case 1030065:
return "Mini14精致";
break;

case 103007:
return "MK14";
break;
case 1030071:
return "MK14破损";
break;
case 1030072:
return "MK14修复";
break;
case 1030073:
return "MK14完好";
break;
case 1030074:
return "MK14改进";
break;
case 1030075:
return "MK14精致";
break;
case 1030076:
return "MK14独眼蛇";
break;
case 1030077:
return "MK14钢铁阵线";
break;

case 103008:
return "Win94";
break;
case 1030081:
return "Win94破损";
break;
case 1030082:
return "Win94修复";
break;
case 1030083:
return "Win94完好";
break;
case 1030084:
return "Win94改进";
break;
case 1030085:
return "Win94精致";
break;

case 103009:
return "SLR";
break;
case 1030091:
return "SLR破损";
break;
case 1030092:
return "SLR修复";
break;
case 1030093:
return "SLR完好";
break;
case 1030094:
return "SLR改进";
break;
case 1030095:
return "SLR精致";
break;
case 1030096:
return "SLR独眼蛇";
break;
case 1030097:
return "SLR钢铁阵线";
break;

case 103010:
return "QBU";
break;
case 1030101:
return "QBU破损";
break;
case 1030102:
return "QBU修复";
break;
case 1030103:
return "QBU完好";
break;
case 1030104:
return "QBU改进";
break;
case 1030105:
return "QBU精致";
break;

case 103100:
return "MK12";
break;
case 1031001:
return "MK12破损";
break;
case 1031002:
return "MK12修复";
break;
case 1031003:
return "MK12完好";
break;
case 1031004:
return "MK12改进";
break;
case 1031005:
return "MK12精致";
break;
case 1031006:
return "MK12独眼蛇";
break;
case 1031007:
return "MK12钢铁阵线";
break;

case 104001:
return "S686";
break;
case 1040011:
return "S686破损";
break;
case 1040012:
return "S686修复";
break;
case 1040013:
return "S686完好";
break;
case 1040014:
return "S686改进";
break;
case 1040015:
return "S686精致";
break;

case 104002:
return "S1897";
break;
case 1040021:
return "S1897破损";
break;
case 1040022:
return "S1897修复";
break;
case 1040023:
return "S1897完好";
break;
case 1040024:
return "S1897改进";
break;
case 1040025:
return "S1897精致";
break;

case 104003:
return "S12K";
break;
case 1040031:
return "S12K破损";
break;
case 1040032:
return "S12K修复";
break;
case 1040033:
return "S12K完好";
break;
case 1040034:
return "S12K改进";
break;
case 1040035:
return "S12K精致";
break;

case 104004:
return "DBS";
break;
case 1040041:
return "DBS破损";
break;
case 1040042:
return "DBS修复";
break;
case 1040043:
return "DBS完好";
break;
case 1040044:
return "DBS改进";
break;
case 1040045:
return "DBS精致";
break;

case 104101:
return "M1014";
break;

case 105001:
return "M249";
break;
case 1050011:
return "M249破损";
break;
case 1050012:
return "M249修复";
break;
case 1050013:
return "M249完好";
break;
case 1050014:
return "M249改进";
break;
case 1050015:
return "M249精致";
break;
case 1050016:
return "M249独眼蛇";
break;
case 1050017:
return "M249钢铁阵线";
break;

case 105002:
return "DP-28";
break;
case 1050021:
return "DP-28破损";
break;
case 1050022:
return "DP-28修复";
break;
case 1050023:
return "DP-28完好";
break;
case 1050024:
return "DP-28改进";
break;
case 1050025:
return "DP-28精致";
break;

case 106001:
return "P92";
break;
case 1060011:
return "P92破损";
break;
case 1060012:
return "P92修复";
break;
case 1060013:
return "P92完好";
break;
case 1060014:
return "P92改进";
break;
case 1060015:
return "P92精致";
break;

case 106002:
return "P1911";
break;
case 1060021:
return "P1911破损";
break;
case 1060022:
return "P1911修复";
break;
case 1060023:
return "P1911完好";
break;
case 1060024:
return "P1911改进";
break;
case 1060025:
return "P1911精致";
break;

case 106003:
return "R1895";
break;
case 1060031:
return "R1895破损";
break;
case 1060032:
return "R1895修复";
break;
case 1060033:
return "R1895完好";
break;
case 1060034:
return "R1895改进";
break;
case 1060035:
return "R1895精致";
break;

case 106004:
return "P18C";
break;
case 1060041:
return "P18C破损";
break;
case 1060042:
return "P18C修复";
break;
case 1060043:
return "P18C完好";
break;
case 1060044:
return "P18C改进";
break;
case 1060045:
return "P18C精致";
break;

case 106005:
return "R45";
break;
case 1060051:
return "R45破损";
break;
case 1060052:
return "R45修复";
break;
case 1060053:
return "R45完好";
break;
case 1060054:
return "R45改进";
break;
case 1060055:
return "R45精致";
break;

case 106006:
return "Sawed-off";
break;
case 1060061:
return "Sawed-off破损";
break;
case 1060062:
return "Sawed-off修复";
break;
case 1060063:
return "Sawed-off完好";
break;
case 1060064:
return "Sawed-off改进";
break;
case 1060065:
return "Sawed-off精致";
break;

case 106007:
return "蝎式手枪";
break;
case 1060071:
return "蝎式手枪破损";
break;
case 1060072:
return "蝎式手枪修复";
break;
case 1060073:
return "蝎式手枪完好";
break;
case 1060074:
return "蝎式手枪改进";
break;
case 1060075:
return "蝎式手枪精致";
break;

case 106008:
return "沙漠之鹰";
break;
case 1060081:
return "沙漠之鹰破损";
break;
case 1060082:
return "沙漠之鹰修复";
break;
case 1060083:
return "沙漠之鹰完好";
break;
case 1060084:
return "沙漠之鹰改进";
break;
case 1060085:
return "沙漠之鹰精致";
break;

case 107001:
return "十字弩";
break;
case 1070011:
return "十字弩破损";
break;
case 1070012:
return "十字弩修复";
break;
case 1070013:
return "十字弩完好";
break;
case 1070014:
return "十字弩改进";
break;
case 1070015:
return "十字弩精致";
break;

case 103011:
return "莫甘娜辛";
break;
case 103012:
return "AMR";
break;
case 103013:
return "M417";
break;
case 103014:
return "MK20-H";
break;

case 104100:
return "SPAS-12";
break;

case 105010:
return "MG3";
break;
case 1050101:
return "MG3破损";
break;
case 1050102:
return "MG3修复";
break;
case 1050103:
return "MG3完好";
break;
case 1050104:
return "MG3改进";
break;
case 1050105:
return "MG3精致";
break;

case 106010:
return "沙漠之鹰";
break;

case 107006:
return "RPG";
break;

case 0:
return "拳头";
break;

case 108001:
return "砍刀";
break;

case 108002:
return "撬棍";
break;

case 108003:
return "镰刀";
break;

case 108004:
return "平底锅";
break;

case 602005:
return "苹果";
break;
case 602001:
return "震撼弹";
break;
case 602002:
return "烟雾弹";
break;
case 602003:
return "燃烧瓶";
break;
case 602004:
return "手榴弹";
break;
default:
return "未收录";
break;
}
}


std::string tou(int 头) {
std::string StateName = "未知";
if (头 == 0) {
 StateName = ""; 
}
if (头 == 502001||头 == 502004||头 == 502101) {
 StateName = "头[一]"; 
}
if (头 == 502002||头 == 502005||头 == 502102) {
 StateName = "头[二]"; 
}
if (头 == 502003||头 == 502006||头 == 502103) {
 StateName = "头[三]"; 
}
if (头 == 502104) {
 StateName = "头[四]"; 
}
if (头 == 502107) {
 StateName = "头[四·独眼]"; 
}
if (头 == 502110) {
 StateName = "头[四·钢铁]"; 
}
if (头 == 502105) {
 StateName = "头[五]"; 
}
if (头 == 502108) {
 StateName = "头[五·独眼]"; 
}
if (头 == 502111) {
 StateName = "头[五·钢铁]"; 
}
if (头 == 502106) {
 StateName = "头[六]"; 
}
if (头 == 502109) {
 StateName = "头[六·独眼]"; 
}
if (头 == 502112) {
 StateName = "头[六·钢铁]"; 
}
return StateName;
}

std::string jia(int 甲) {
std::string StateName = "未知";
if (甲 == 0) {
 StateName = ""; 
}
if (甲 == 503001||甲 == 503004||甲 == 503101) {
 StateName = "甲[一]"; 
}
if (甲 == 503002||甲 == 503005||甲 == 503102) {
 StateName = "甲[二]"; 
}
if (甲 == 503003||甲 == 503006||甲 == 503103) {
 StateName = "甲[三]"; 
}
if (甲== 503104) {
 StateName = "甲[四]"; 
}
if (甲 == 503107) {
 StateName = "甲[四·独眼]"; 
}
if (甲 == 503110) {
 StateName = "甲[四·钢铁]"; 
}
if (甲== 503105) {
 StateName = "甲[五]"; 
}
if (甲 == 503108) {
 StateName = "甲[五·独眼]"; 
}
if (甲 == 503111) {
 StateName = "甲[五·钢铁]"; 
}
if (甲== 503106) {
 StateName = "甲[六]"; 
}
if (甲 == 503109) {
 StateName = "甲[六·独眼]"; 
}
if (甲 == 503112) {
 StateName = "甲[六·钢铁]"; 
}
return StateName;
}

std::string bao(int 包) {
std::string StateName = "未知";
if (包 == 0) {
 StateName = ""; 
}
if (包 == 501001||包 == 501004||包 == 501101) {
 StateName = "包[一]"; 
}
if (包 == 501002||包 == 501005||包 == 501102) {
 StateName = "包[二]"; 
}
if (包 == 501003||包 == 501006||包 == 501103) {
 StateName = "包[三]"; 
}
if (包 == 501104||包 == 501107||包 == 501110) {
 StateName = "包[四]"; 
}
if (包 == 501105||包 == 501108||包 == 501111) {
 StateName = "包[五]"; 
}
if (包 == 501106||包 == 501109||包 == 501112) {
 StateName = "包[六]"; 
}
return StateName;
}



string 盒子空投(const string& n) {
if (alike(n, "CharacterDeadInventoryBox_C"))
return "敌人盒子";
if (alike(n, "_TrainingBoxListWrapper_C"))
return "盒子";
if (alike(n, "PickUpListWrapperActor"))
return "盒子";
if (alike(n, "Chara cterDeadInventoryBox_C"))
return "敌人盒子";
if (alike(n, "_AirDropPlane_C") || alike(n, "_AirDropPlane_SuperPeople_C"))
return "空投飞机";
if (alike(n, "_AirDropBox_C") || alike(n, "_AirDropBox_SuperPeople_C"))
return "空投盒子";
return "";
}

string 载具(const string& n) {
if (alike(n, "_Mountainbike_Training_C"))
return "自行车";
if (alike(n, "licedTrain_C"))
return "磁吸小火车";
if (alike(n, "VH_BRDM_C"))
return "装甲车";
if (alike(n, "VH_Scooter_C"))
return "小电驴";
if (alike(n, "VH_Motorcycle"))
return "摩托车";
if (alike(n, "VH_MotorcycleCart"))
return "摩托手推车";
if (alike(n, "VH_Snowmobile_C"))
return "雪地车";
if (alike(n, "VH_Tuk"))
return "三轮老爷车";
if (alike(n, "VH_Horse_1_C"))
return "马";
if (alike(n, "LadaNiva_01_C"))
return "旅行车";
if (alike(n, "VH_4SportCar_C"))
return "四人跑车";
if (alike(n, "VH_DesertCar_C"))
return "拉力车";
if (alike(n, "Buggy"))
return "蹦蹦";
if (alike(n, "Dacia"))
return "小轿车";
if (alike(n, "UAZ"))
return "吉普车";
if (alike(n, "PickUp_07_C"))
return "大皮卡车";
if (alike(n, "Rony"))
return "小皮卡车";
if (alike(n, "Mirado"))
return "四轮敞篷车";
if (alike(n, "MiniBus"))
return "大巴车";
if (alike(n, "PG117"))
return "4 人快艇";
if (alike(n, "AquaRail"))
return "摩托艇";
if (alike(n, "Snowbike"))
return "雪地摩托车";
if (alike(n, "CoupeRB"))
return "双人跑车";
if (alike(n, "Motorglider"))
return "滑翔机";
if (alike(n, "Monster"))
return "电车";
if (alike(n, "UTV"))
return "越野车";
if (alike(n, "Bigfoot"))
return "大脚车";
if (alike(n, "VH_ATV"))
return "越野车";
if (alike(n, "AIVH_Leopard_1A3_C"))
return "低级坦克 BOSS";
if (alike(n, "ClassicStore"))
return "高级坦克 BOSS";
if (alike(n, "TrackVehicle_BP_C"))
return "地铁矿车";
if (alike(n, "AIVH_Weapon_Turret_C"))
return "地铁坦克";
return "";
}



string 姥爷物资(const string& n) {
if (alike(n, "FileBag_Lua_Lv1_C"))
return "手提包 V1";
if (alike(n, "FileBag_Lua_Lv2_C"))
return "手提包 V2";
if (alike(n, "FileBag_Lua_Lv3_C"))
return "手提包 V3";
if (alike(n, "FileBag_Lua_Lv4_C"))
return "手提包 V4";
if (alike(n, "FileBag_Lua_Lv5_C"))
return "手提包 V5";
if (alike(n, "EggBox_Lua_Lv1_C"))
return "隐匿点";
return "";
}

string 信函箱(const string& n) {
if (alike(n, "BP_DC_HighLevel_TE_FileBox_Lua_Lv1_C"))
return "1级信函箱";
if (alike(n, "BP_DC_HighLevel_TE_FileBox_Lua_Lv2_C"))
return "2级信函箱";
if (alike(n, "BP_DC_HighLevel_TE_FileBox_Lua_Lv3_C"))
return "3级信函箱";
if (alike(n, "BP_DC_HighLevel_TE_FileBox_Lua_Lv4_C"))
return "4级信函箱";
if (alike(n, "BP_DC_HighLevel_TE_FileBox_Lua_Lv5_C"))
return "5级信函箱";
return "";
}




string 宝箱(const string& n) {
if (alike(n, "Escape_SupplyBax_Lv1_C") || alike(n, "EscapeBoxHight_SupplyBox_Lv1_C"))
return "1 级宝箱";
if (alike(n, "Escape_SupplyBax_Lv2_C") || alike(n, "EscapeBoxHight_SupplyBox_Lv2_C"))
return "2 级宝箱";
if (alike(n, "Escape_SupplyBax_Lv3_C") || alike(n, "EscapeBoxHight_SupplyBox_Lv3_C"))
return "3 级宝箱";
if (alike(n, "Escape_SupplyBax_Lv4_C") || alike(n, "EscapeBoxHight_SupplyBox_Lv4_C"))
return "4 级宝箱";
if (alike(n, "Escape_SupplyBax_Lv5_C") || alike(n, "EscapeBoxHight_SupplyBox_Lv5_C"))
return "5 级宝箱";
return "";
}


string 物资箱(const string& n) {
if (alike(n, "ClassicStore"))
return "黑店";
if (alike(n, "BP_DC_HighLevel_TE_FileBox_Lua_Lv1_C"))
return "1 级物资箱";
if (alike(n, "BP_DC_HighLevel_TE_FileBox_Lua_Lv2_C"))
return "2 级物资箱";
if (alike(n, "BP_DC_HighLevel_TE_ItemBox_Lua_Lv3_C"))
return "3 级物资箱";
if (alike(n, "BP_DC_HighLevel_TE_ItemBox_Lua_Lv4_C"))
return "4 级物资箱";
if (alike(n, "BP_DC_HighLevel_TE_ItemBox_Lua_Lv5_C"))
return "5 级物资箱";
if (alike(n, "BP_DC_HighLevel_TE_ItemBox_Lua_Lv6_C"))
return "6 级物资箱";
return "";
}


string 武器箱(const string& n) {
if (alike(n, "_DC_HighLevel_TE_WeaponBox_Lua_Lv1_C") || alike(n, "_DC_HighLevel_TE_WeaponBox_Lua_Lv1_C"))
return "1 级武器箱";
if (alike(n, "_DC_HighLevel_TE_WeaponBox_Lua_Lv2_C") || alike(n, "_DC_HighLevel_TE_WeaponBox_Lua_Lv2_C"))
return "2 级武器箱";
if (alike(n, "_DC_HighLevel_TE_WeaponBox_Lua_Lv3_C") || alike(n, "_DC_HighLevel_TE_WeaponBox_Lua_Lv3_C"))
return "3 级武器箱";
if (alike(n, "_DC_HighLevel_TE_WeaponBox_Lua_Lv4_C") || alike(n, "_DC_HighLevel_TE_WeaponBox_Lua_Lv4_C"))
return "4 级武器箱";
if (alike(n, "_DC_HighLevel_TE_WeaponBox_Lua_Lv5_C") || alike(n, "_DC_HighLevel_TE_WeaponBox_Lua_Lv5_C"))
return "5 级武器箱";
return "";
}


string 药品箱(const string& n) {
if (alike(n, "EscapeBox_Medical_Lv1_C") || alike(n, "EscapeBoxHight_Medical_Lv1_C"))
return "1 级药品箱";
if (alike(n, "EscapeBox_Medical_Lv2_C") || alike(n, "EscapeBoxHight_Medical_Lv2_C"))
return "2 级药品箱";
if (alike(n, "EscapeBox_Medical_Lv3_C") || alike(n, "EscapeBoxHight_Medical_Lv3_C"))
return "3 级药品箱";
return "";
}


string 药品(const string& n) {
if (alike(n, "ink_Pickup_C"))
return "饮料";
if (alike(n, "rstaid_Pickup_C"))
return "医药包";
if (alike(n, "lls_Pickup_C"))
return "止痛药";
if (alike(n, "rstAidbox_Pickup_C"))
return "医药箱";
if (alike(n, "_revivalAED_Pickup_C"))
return "自救器";
if (alike(n, "jection_Pickup_C"))
return "肾上腺素";
return "";
}


string 手枪(const string& n) {
if (alike(n, "P92"))
return "P92";
if (alike(n, "Vz61"))
return "Vz61";
if (alike(n, "R45"))
return "R45";
if (alike(n, "P1911"))
return "P1911";
if (alike(n, "P18C"))
return "P18C";
if (alike(n, "BP_Pistol_DesertEagle_Wrapper_C"))
return "沙漠之鹰";
return "";
}


string 步枪(const string& n) {
if (alike(n, "Rifle_AKM_Wrapper_C"))
return "AKM";
if (alike(n, "Rifle_M416_Wrapper_C"))
return "M416";
if (alike(n, "Rifle_M16A4_Wrapper_C"))
return "M16A4";
if (alike(n, "Rifle_SCAR_Wrapper_C"))
return "SCAR";
if (alike(n, "Rifle_QBZ_Wrapper_C"))
return "QBZ";
return "";
}


string 霰弹枪(const string& n) {
if (alike(n, "ShotGun_S12K_Wrapper_C"))
return "S12K";
if (alike(n, "ShotGun_DP12_Wrapper_C"))
return "DBS散弹枪";
if (alike(n, "ShotGun_S686_Wrapper_C"))
return "S686";
if (alike(n, "ShotGun_S1897_Wrapper_C"))
return "S1897";
if (alike(n, "ShotGun_SPAS-12_Wrapper_C"))
return "SPAS_12";
return "";
}


string 冲锋枪(const string& n) {
if (alike(n, "MachineGun_UMP9_Wrapper_C"))
return "UMP-45";
if (alike(n, "MachineGun_TommyGun_Wrapper_C"))
return "汤姆逊冲锋枪";
if (alike(n, "MachineGun_PP19_Wrapper_C"))
return "野牛";
if (alike(n, "MachineGun_Uzi_Wrapper_C"))
return "Uzi";
return "";
}


string 狙击枪(const string& n) {
if (alike(n, "Sniper_Kar98k_Wrapper_C"))
return "Kar98k";
if (alike(n, "Sniper_Win94_Wrapper_C"))
return "WIN94";
if (alike(n, "Sniper_Mini14_Wrapper_C"))
return "Mini14";
if (alike(n, "Sniper_SKS_Wrapper_C"))
return "SKS";
if (alike(n, "Sniper_M24_Wrapper_C"))
return "M24";
if (alike(n, "WEP_Mk14_Pickup_C"))
return "MK14";
return "";
}


string 瞄准镜(const string& n) {
if (alike(n, "MZJ_HD_Pickup_C"))
return "红点";
if (alike(n, "MZJ_QX_Pickup_C"))
return "全息瞄准镜";
if (alike(n, "MZJ_SideRMR_Pickup_C"))
return "侧面瞄准镜";
if (alike(n, "MZJ_2X_Pickup_C"))
return "2倍镜";
if (alike(n, "MZJ_3X_Pickup_C"))
return "3倍镜";
if (alike(n, "MZJ_4X_Pickup_C"))
return "4倍镜";
if (alike(n, "MZJ_6X_Pickup_C"))
return "6倍镜";
if (alike(n, "MZJ_8X_Pickup_C"))
return "8倍镜";
return "";
}


string 弹夹(const string& n) {
if (alike(n, "DJ_Large_EQ_Pickup_C"))
return "步枪快扩";
if (alike(n, "DJ_Large_E_Pickup_C"))
return "步枪扩容";
if (alike(n, "DJ_Sniper_EQ_Pickup_C"))
return "狙击枪快扩";
if (alike(n, "DJ_Sniper_E_Pickup_C"))
return "狙击枪扩容";
if (alike(n, "DJ_Mid_E_Pickup_C"))
return "冲锋枪扩容";
if (alike(n, "DJ_Mid_EQ_Pickup_C"))
return "冲锋枪快扩";
if (alike(n, "ZDD_Sniper_Pickup_C"))
return "子弹袋";
if (alike(n, "DJ_DrumMag_Pickup_C"))
return "小型弹鼓";
if (alike(n, "ZDD_Crossbow_Q_Pickup_C"))
return "箭袋";
if (alike(n, "DJ_ShotGun_Pickup_C"))
return "散弹枪快速填装器";
if (alike(n, "DJ_Mid_Q_Pickup_C"))
return "手枪快速扩容";
return "";
}


string 枪口(const string& n) {
if (alike(n, "QK_Large_Suppressor_Pickup_C"))
return "步枪消音器";
if (alike(n, "QK_Sniper_Suppressor_Pickup_C"))
return "狙击枪消音器";
if (alike(n, "QT_Sniper_Pickup_C"))
return "托腮板";
if (alike(n, "QK_Large_Compensator_Pickup_C"))
return "步枪补偿器";
if (alike(n, "QK_Sniper_Compensator_Pickup_C"))
return "狙击枪补偿器";
if (alike(n, "QK_Large_FlashHider_Pickup_C"))
return "步枪消焰器";
if (alike(n, "WB_Vertical_Pickup_C"))
return "垂直握把";
if (alike(n, "QK_Choke_Pickup_C"))
return "收束器";
if (alike(n, "WB_Lasersight_Pickup_C"))
return "激光瞄准器";
return "";
}


string 子弹(const string& n) {
 if (alike(n, "Ammo_556mm_Pickup_C"))
return "5.56子弹";
if (alike(n, "Ammo_762mm_Pickup_C"))
return "7.62子弹";
if (alike(n, "Ammo_45AC_Pickup_C"))
return ".45口径子弹";
if (alike(n, "Ammo_9mm_Pickup_C"))
return "9毫米子弹";
if (alike(n, "Ammo_12Guage_Pickup_C"))
return "12口径子弹";
if (alike(n, "Ammo_300Magnum_Pickup_C"))
return "马格南";
return "";
}


string 狗子(const string& n) {
if (alike(n, "Watcher_C") || alike(n, "Watcher_Child_C") || alike(n, "HungerH_C") || alike(n, "HungerB_C") || alike(n, "VenomVariant_C") || alike(n, "BurningVariant_C") || alike(n, "Library_C") || alike(n, "AIMob_PatrolDog_C"))
return "狗子";
return "";
}




char *dzdz(int dzid) {
switch (dzid) {

//站立一系列
case 8:
 return"立正";
break;
case 521:
 return"开镜";
break;
case 648:
 return"开火";
break;
case 649:
 return"开火";
break;
case 1032:
 return"探头";
break;
case 1033:
 return"探头";
break;
case 136:
 return"开火";
break;
case 137:
case 139:
 return"开火";
break;
case 1160:
 return"探头";
break;
case 1161:
 return"探头";
break;
case 1544:
 return"开镜";
break;
case 1545:
 return"开镜";
break;
case 1672:
 return"开火";
break;
case 1673:
 return"开火";
break;
case 8200:
 return"挥拳";
break;
case 8201:
case 8203:
 return"挥拳";
break;
case 267:
 return"换弹";
break;
case 17417:
 return"投掷";
break;
//蹲下一系列
case 16:
 return"蹲下";
break;
case 17:
case 147:
 return"开火";
break;
case 656:
 return"开火";
break;
case 657:
 return"开火";
break;
case 1040:
 return"探头";
break;
case 1041:
 return"探头";
break;
case 528:
 return"开镜";
break;
case 529:
 return"开镜";
break;
case 1168:
 return"开火";
break;
case 1169:
 return"开火";
break;
case 1552:
 return"开镜";
break;
case 1553:
 return"开镜";
break;
case 1680:
 return"开火";
break;
case 1681:
 return"开火";
break;
case 8209:
 return"挥拳";
break;
case 275:
 return"换弹";
break;
case 2064:
 return"换枪";
break;
case 16401:
 return"投掷";
break;
case 17425:
 return"投掷";
break;
case 65553:
 return"打药";
break;
//趴下一系列
case 32:
 return"趴下";
break;
case 33:
case 34:
case 35:
 return"趴下";
break;
case 544:
 return"开镜";
break;
case 545:
 return"开镜";
break;
case 672:
 return"开火";
break;
case 289:
case 291:
 return"换弹";
break;
case 16417:
 return"投掷";
break;
//跳跃一系列
case 72:
 return"跳跃";
break;
case 73:
case 75:
 return"跳跃";
break;
case 8264:
 return"跳拳";
break;
case 8265:
case 8267:
 return"跳拳";
break;
case 203:
 return"开火";
break;
case 331:
 return"换弹";
break;
//车一系列
case 524296:
 return"开车";
break;
case 1048584:
 return"没动";
break;
case 3145736:
 return"探头";
break;
case 3145864:
 return"开火";
break;
case 3146248:
 return"开镜";
break;
case 3146376:
 return"开火";
break;
case 3145992:
 return"换弹";
break;
case 3162120:
 return"投掷";
break;
//游泳
case 4194307:
case 4194305:
 return"游泳";
break;
//倒地

//其它一系列
case 16777226:
 return"攀爬";
break;
case 10:
 return"跑跳";
break;
case 8202:
 return"跳拳";
break;
case 268435464:
 return"跳舞";
break;
case 1073741832:
 return"立正";
break;


case 329:
case 328:
case 288:
case 272:
case 273:
case 264:
case 265:
return "换弹";
break;

case 9:
return "行走";
break;

case 11:
return "跑路";
break;

case 16777224:
return "翻墙";
break;


case 16392:
case 17416:
case 16400:
case 17424:
case 16416:
case 16456:
case 16393:
case 16457:
return "投掷";
break;


case 520:
return "开镜";
break;

case 65545:
return "打药";
break;

case 200:
case 201:
return "跳枪";
break;

case 144:
case 145:
return "蹲着";
break;

case 160:
return "趴下";
break;

case 8208:
return "蹲拳";
break;

case 8211:
return "蹲跑";
break;

case 19:
return "蹲跑";
break;

case 131072:
case 524303:
case 524304:
case 524289:
return "倒地";
break;

case 2056:
case 2057:
case 2059:
case 2065:
case 2067:
case 2081:
case 2080:
case 2083:
case 2121:
case 2120:
case 2123:
return "切枪";
break;

case 4194304:
return "游泳";
break;

case 65544:
case 65552:

case 65568:
return "打药";
break;


default:
return "未知";
break;
}
return nullptr;
} 




int GetWeapon(int Wuqi) {
switch (Wuqi) {
//突击步枪
case 101008:
return 30; //M762
break;
case 1010081:
return 31; //M762破损
break;
case 1010082:
return 32; //M762修复
break;
case 1010083:
return 33; //M762完好
break;
case 1010084:
return 34; //M762改进
break;
case 1010085:
return 35; //M762精制
break;
case 1010086:
return 37; //M762独眼
break;
case 1010087:
return 38; //M762钢铁
break;

case 101001:
return 50; //AKM
break;
case 1010011:
return 51; //AKM破损
break;
case 1010012:
return 52; //AKM修复
break;
case 1010013:
return 53; //AKM完好
break;
case 1010014:
return 54; //AKM改进
break;
case 1010015:
return 55; //AKM精制
break;
case 1010016:
return 57; //AKM独眼
break;
case 1010017:
return 58; //AKM钢铁
break;

case 101004:
return 20; //M416
break;
case 1010041:
return 21; //M416破损
break;
case 1010042:
return 22; //M416修复
break;
case 1010043:
return 23; //M416完好
break;
case 1010044:
return 24; //M416改进
break;
case 1010045:
return 25; //M416精制
break;
case 1010046:
return 27; //M416独眼
break;
case 1010047:
return 28; //M416钢铁
break;

case 101003:
return 40; //SCAR_L
break;
case 1010031:
return 41; //SCAR_L破损
break;
case 1010032:
return 42; //SCAR_L修复
break;
case 1010033:
return 43; //SCAR_L完好
break;
case 1010034:
return 44; //SCAR_L改进
break;
case 1010035:
return 45; //SCAR_L精制
break;
case 1010036:
return 47; //SCAR_L独眼
break;
case 1010037:
return 48; //SCAR_L钢铁
break;

case 101002:
return 90; //M16A4
break;
case 1010021:
return 91; //M16A4破损
break;
case 1010022:
return 92; //M16A4修复
break;
case 1010023:
return 93; //M16A4完好
break;
case 1010024:
return 94; //M16A4改进
break;
case 1010025:
return 95; //M16A4精制
break;
case 1010026:
return 97; //M16A4独眼
break;
case 1010027:
return 98; //M16A4钢铁
break;

case 101009:
return 100; //MK47
break;
case 1010091:
return 101; //MK47破损
break;
case 1010092:
return 102; //MK47修复
break;
case 1010093:
return 103; //MK47完好
break;
case 1010094:
return 104; //MK47改进
break;
case 1010095:
return 105; //MK47精制
break;
case 1010096:
return 107; //MK47独眼
break;
case 1010097:
return 108; //MK47钢铁
break;

case 101006:
return 70; //AUG
break;
case 1010061:
return 71; //AUG破损
break;
case 1010062:
return 72; //AUG修复
break;
case 1010063:
return 73; //AUG完好
break;
case 1010064:
return 74; //AUG改进
break;
case 1010065:
return 75; //AUG精制
break;
case 1010066:
return 77; //AUG独眼
break;
case 1010067:
return 78; //AUG钢铁
break;

case 101005:
return 120; //狗砸
break;
case 1010051:
return 121; //狗砸破损
break;
case 1010052:
return 122; //狗砸修复
break;
case 1010053:
return 123; //狗砸完好
break;
case 1010054:
return 124; //狗砸改进
break;
case 1010055:
return 125; //狗砸精制
break;
case 1010056:
return 127; //狗砸独眼
break;
case 1010057:
return 128; //狗砸钢铁
break;

case 101010:
return 80; //G36C
break;
case 1010101:
return 81; //G36C破损
break;
case 1010102:
return 82; //G36C修复
break;
case 1010103:
return 83; //G36C完好
break;
case 1010104:
return 84; //G36C改进
break;
case 1010105:
return 85; //G36C精制
break;
case 1010106:
return 87; //G36C独眼
break;
case 1010107:
return 88; //G36C钢铁
break;

case 101007:
return 60; //QBZ
break;
case 1010071:
return 61; //QBZ破损
break;
case 1010072:
return 62; //QBZ修复
break;
case 1010073:
return 63; //QBZ完好
break;
case 1010074:
return 64; //QBZ改进
break;
case 1010075:
return 65; //QBZ精制
break;
case 1010076:
return 67; //QBZ独眼
break;
case 1010077:
return 68; //QBZ钢铁
break;

case 101011:
return 310; //AC_VAL
break;
case 1010111:
return 311; //AC_VAL破损
break;
case 1010112:
return 312; //AC_VAL修复
break;
case 1010113:
return 313; //AC_VAL完好
break;
case 1010114:
return 314; //AC_VAL改进
break;
case 1010115:
return 315; //AC_VAL精制
break;
case 1010116:
return 317; //AC_VAL独眼
break;
case 1010117:
return 318; //AC_VAL钢铁
break;

case 101012:
return 110; //蜜獾突击步枪
break;
case 1010121:
return 111; //蜜獾突击步枪破损
break;
case 1010122:
return 112; //蜜獾突击步枪修复
break;
case 1010123:
return 113; //蜜獾突击步枪完好
break;
case 1010124:
return 114; //蜜獾突击步枪改进
break;
case 1010125:
return 115; //蜜獾突击步枪精制
break;
case 1010126:
return 117; //蜜獾突击步枪独眼
break;
case 1010127:
return 118; //蜜獾突击步枪钢铁
break;
//连狙
case 103009:
return 790; //SLR
break;
case 1030091:
return 791; //SLR破损
break;
case 1030092:
return 792; //SLR修复
break;
case 1030093:
return 793; //SLR完好
break;
case 1030094:
return 794; //SLR改进
break;
case 1030095:
return 795; //SLR精制
break;
case 1030096:
return 797; //SLR独眼
break;
case 1030097:
return 798; //SLR钢铁
break;

case 103005:
return 800; //VSS
break;
case 1030051:
return 801; //VSS破损
break;
case 1030052:
return 802; //VSS修复
break;
case 1030053:
return 803; //VSS完好
break;
case 1030054:
return 804; //VSS改进
break;
case 1030055:
return 805; //VSS精制
break;
case 1030056:
return 807; //VSS独眼
break;
case 1030057:
return 808; //VSS钢铁
break;

case 103006:
return 750; //Mini14
break;
case 1030061:
return 751; //Mini14破损
break;
case 1030062:
return 752; //Mini14修复
break;
case 1030063:
return 753; //Mini14完好
break;
case 1030064:
return 754; //Mini14改进
break;
case 1030065:
return 755; //Mini14精制
break;
case 1030066:
return 757; //Mini14独眼
break;
case 1030067:
return 758; //Mini14钢铁
break;

case 103010:
return 770; //QBU
break;
case 1030101:
return 771; //QBU破损
break;
case 1030102:
return 772; //QBU修复
break;
case 1030103:
return 773; //QBU完好
break;
case 1030104:
return 774; //QBU改进
break;
case 1030105:
return 775; //QBU精制
break;
case 1030106:
return 777; //QBU独眼
break;
case 1030107:
return 778; //QBU钢铁
break;

case 103004:
return 780; //SKS
break;
case 1030041:
return 781; //SKS破损
break;
case 1030042:
return 782; //SKS修复
break;
case 1030043:
return 783; //SKS完好
break;
case 1030044:
return 784; //SKS改进
break;
case 1030045:
return 785; //SKS精制
break;
case 1030046:
return 787; //SKS独眼
break;
case 1030047:
return 788; //SKS钢铁
break;

case 103007:
return 730; //MK14
break;
case 1030071:
return 731; //MK14破损
break;
case 1030072:
return 732; //MK14修复
break;
case 1030073:
return 733; //MK14完好
break;
case 1030074:
return 734; //MK14改进
break;
case 1030075:
return 735; //MK14精制
break;
case 1030076:
return 737; //MK14独眼
break;
case 1030077:
return 738; //MK14钢铁
break;

case 103014:
return 740; //MK20_H
break;
case 1030141:
return 741; //MK20_H破损
break;
case 1030142:
return 742; //MK20_H修复
break;
case 1030143:
return 743; //MK20_H完好
break;
case 1030144:
return 744; //MK20_H改进
break;
case 1030145:
return 745; //MK20_H精制
break;
case 1030146:
return 747; //MK20_H独眼
break;
case 1030147:
return 748; //MK20_H钢铁
break;

case 103013:
return 710; //M417
break;
case 1030131:
return 711; //M417破损
break;
case 1030132:
return 712; //M417修复
break;
case 1030133:
return 713; //M417完好
break;
case 1030134:
return 714; //M417改进
break;
case 1030135:
return 715; //M417精制
break;
case 1030136:
return 717; //M417独眼
break;
case 1030137:
return 718; //M417钢铁
break;
//连狙
case 103012:
return 520; //AMR
break;
case 1030121:
return 521; //AMR破损
break;
case 1030122:
return 522; //AMR修复
break;
case 1030123:
return 523; //AMR完好
break;
case 1030124:
return 524; //AMR改进
break;
case 1030125:
return 525; //AMR精制
break;
case 1030126:
return 527; //AMR独眼
break;
case 1030127:
return 528; //AMR钢铁
break;

case 103003:
return 510; //AWM
break;
case 1030031:
return 511; //AWM破损
break;
case 1030032:
return 512; //AWM修复
break;
case 1030033:
return 513; //AWM完好
break;
case 1030034:
return 514; //AWM改进
break;
case 1030035:
return 515; //AWM精制
break;
case 1030036:
return 517; //AWM独眼
break;
case 1030037:
return 518; //AWM钢铁
break;

case 103015:
return 546; //M200狙击枪
break;

case 103002:
return 550; //M24
break;
case 1030021:
return 551; //M24破损
break;
case 1030022:
return 552; //M24修复
break;
case 1030023:
return 553; //M24完好
break;
case 1030024:
return 554; //M24改进
break;
case 1030025:
return 555; //M24精制
break;
case 1030026:
return 557; //M24独眼
break;
case 1030027:
return 558; //M24钢铁
break;

case 103011:
return 570; //莫辛纳甘
break;
case 1030111:
return 571; //莫辛纳甘破损
break;
case 1030112:
return 572; //莫辛纳甘修复
break;
case 1030113:
return 573; //莫辛纳甘完好
break;
case 1030114:
return 574; //莫辛纳甘改进
break;
case 1030115:
return 575; //莫辛纳甘精制
break;
case 1030116:
return 577; //莫辛纳甘独眼
break;
case 1030117:
return 578; //莫辛纳甘钢铁
break;

case 103001:
return 530; //_98K
break;
case 1030011:
return 531; //_98K破损
break;
case 1030012:
return 532; //_98K修复
break;
case 1030013:
return 533; //_98K完好
break;
case 1030014:
return 534; //_98K改进
break;
case 1030015:
return 535; //_98K精制
break;
case 1030016:
return 537; //_98K独眼
break;
case 1030017:
return 538; //_98K钢铁
break;

case 103008:
return 560; //Win94
break;
case 1030081:
return 561; //Win94破损
break;
case 1030082:
return 562; //Win94修复
break;
case 1030083:
return 563; //Win94完好
break;
case 1030084:
return 564; //Win94改进
break;
case 1030085:
return 565; //Win94精制
break;
case 1030086:
return 567; //Win94独眼
break;
case 1030087:
return 568; //Win94钢铁
break;
//机关枪
case 105001:
return 550; //M249
break;
case 1050011:
return 551; //M249破损
break;
case 1050012:
return 552; //M249修复
break;
case 1050013:
return 553; //M249完好
break;
case 1050014:
return 554; //M249改进
break;
case 1050015:
return 555; //M249精制
break;
case 1050016:
return 557; //M249独眼
break;
case 1050017:
return 558; //M249钢铁
break;

case 105002:
return 1010; //DP_28
break;
case 1050021:
return 1011; //DP_28破损
break;
case 1050022:
return 1012; //DP_28修复
break;
case 1050023:
return 1013; //DP_28完好
break;
case 1050024:
return 1014; //DP_28改进
break;
case 1050025:
return 1015; //DP_28精制
break;
case 1050026:
return 1017; //DP_28独眼
break;
case 1050027:
return 1018; //DP_28钢铁
break;

case 105010:
return 1030; //MG3
break;
case 1050101:
return 1031; //MG3破损
break;
case 1050102:
return 1032; //MG3修复
break;
case 1050103:
return 1033; //MG3完好
break;
case 1050104:
return 1034; //MG3改进
break;
case 1050105:
return 1035; //MG3精制
break;
case 1050106:
return 1037; //MG3独眼
break;
case 1050107:
return 1038; //MG3钢铁
break;

case 107001:
return 1410; //十字弩
break;
case 1070011:
return 1411; //十字弩破损
break;
case 1070012:
return 1412; //十字弩修复
break;
case 1070013:
return 1413; //十字弩完好
break;
case 1070014:
return 1414; //十字弩改进
break;
case 1070015:
return 1415; //十字弩精制
break;
case 1070016:
return 1417; //十字弩独眼
break;
case 1070017:
return 1418; //十字弩钢铁
break;

case 107007:
return 1420; //爆炸猎弓
break;
case 1070071:
return 1421; //爆炸猎弓破损
break;
case 1070072:
return 1422; //爆炸猎弓修复
break;
case 1070073:
return 1423; //爆炸猎弓完好
break;
case 1070074:
return 1424; //爆炸猎弓改进
break;
case 1070075:
return 1425; //爆炸猎弓精制
break;
case 1070076:
return 1427; //爆炸猎弓独眼
break;
case 1070077:
return 1428; //爆炸猎弓钢铁
break;
//冲锋枪
case 102001:
return 350; //UZI
break;
case 1020011:
return 351; //UZI破损
break;
case 1020012:
return 352; //UZI修复
break;
case 1020013:
return 353; //UZI完好
break;
case 1020014:
return 354; //UZI改进
break;
case 1020015:
return 355; //UZI精制
break;
case 1020016:
return 357; //UZI独眼
break;
case 1020017:
return 358; //UZI钢铁
break;

case 102003:
return 380; //维克托
break;
case 1020031:
return 381; //维克托破损
break;
case 1020032:
return 382; //维克托修复
break;
case 1020033:
return 383; //维克托完好
break;
case 1020034:
return 384; //维克托改进
break;
case 1020035:
return 385; //维克托精制
break;
case 1020036:
return 387; //维克托独眼
break;
case 1020037:
return 388; //维克托钢铁
break;

case 100103:
return 360; //野牛 PP_19
break;
case 1001031:
return 361; //野牛 PP_19破损
break;
case 1001032:
return 362; //野牛 PP_19修复
break;
case 1001033:
return 363; //野牛 PP_19完好
break;
case 1001034:
return 364; //野牛 PP_19改进
break;
case 1001035:
return 365; //野牛 PP_19精制
break;
case 1001036:
return 367; //野牛 PP_19独眼
break;
case 1001037:
return 368; //野牛 PP_19钢铁
break;

case 102007:
return 320; //MP5K
break;
case 1020071:
return 321; //MP5K破损
break;
case 1020072:
return 322; //MP5K修复
break;
case 1020073:
return 323; //MP5K完好
break;
case 1020074:
return 324; //MP5K改进
break;
case 1020075:
return 325; //MP5K精制
break;
case 1020076:
return 327; //MP5K独眼
break;
case 1020077:
return 328; //MP5K钢铁
break;

case 102002:
return 340; //UMP45
break;
case 1020021:
return 341; //UMP45破损
break;
case 1020022:
return 342; //UMP45修复
break;
case 1020023:
return 343; //UMP45完好
break;
case 1020024:
return 344; //UMP45改进
break;
case 1020025:
return 345; //UMP45精制
break;
case 1020026:
return 347; //UMP45独眼
break;
case 1020027:
return 348; //UMP45钢铁
break;

case 102004:
return 370; //汤姆逊
break;
case 1020041:
return 371; //汤姆逊破损
break;
case 1020042:
return 372; //汤姆逊修复
break;
case 1020043:
return 373; //汤姆逊完好
break;
case 1020044:
return 374; //汤姆逊改进
break;
case 1020045:
return 375; //汤姆逊精制
break;
case 1020046:
return 377; //汤姆逊独眼
break;
case 1020047:
return 378; //汤姆逊钢铁
break;

case 102105:
return 330; //P90
break;
case 1021051:
return 331; //P90破损
break;
case 1021052:
return 332; //P90修复
break;
case 1021053:
return 333; //P90完好
break;
case 1021054:
return 334; //P90改进
break;
case 1021055:
return 335; //P90精制
break;
case 1021056:
return 337; //P90独眼
break;
case 1021057:
return 338; //P90钢铁
break;

case 102005:
return 360; //野牛
break;
case 1020051:
return 361; //野牛破损
break;
case 1020052:
return 362; //野牛修复
break;
case 1020053:
return 363; //野牛完好
break;
case 1020054:
return 364; //野牛改进
break;
case 1020055:
return 365; //野牛精制
break;
case 1020056:
return 367; //野牛独眼
break;
case 1020057:
return 368; //野牛钢铁
break;
//霰弹枪
case 104001:
return 930; //S686
break;
case 1040011:
return 931; //S686破损
break;
case 1040012:
return 932; //S686修复
break;
case 1040013:
return 933; //S686完好
break;
case 1040014:
return 934; //S686改进
break;
case 1040015:
return 935; //S686精制
break;
case 1040016:
return 937; //S686独眼
break;
case 1040017:
return 938; //S686钢铁
break;

case 104002:
return 920; //S1897
break;
case 1040021:
return 921; //S1897破损
break;
case 1040022:
return 922; //S1897修复
break;
case 1040023:
return 923; //S1897完好
break;
case 1040024:
return 924; //S1897改进
break;
case 1040025:
return 925; //S1897精制
break;
case 1040026:
return 927; //S1897独眼
break;
case 1040027:
return 928; //S1897钢铁
break;

case 104003:
return 910; //S12K
break;
case 1040031:
return 911; //S12K破损
break;
case 1040032:
return 912; //S12K修复
break;
case 1040033:
return 913; //S12K完好
break;
case 1040034:
return 914; //S12K改进
break;
case 1040035:
return 915; //S12K精制
break;
case 1040036:
return 917; //S12K独眼
break;
case 1040037:
return 918; //S12K钢铁
break;

case 104004:
return 900; //DBS
break;
case 1040041:
return 901; //DBS破损
break;
case 1040042:
return 902; //DBS修复
break;
case 1040043:
return 903; //DBS完好
break;
case 1040044:
return 904; //DBS改进
break;
case 1040045:
return 905; //DBS精制
break;
case 1040046:
return 907; //DBS独眼
break;
case 1040047:
return 908; //DBS钢铁
break;

case 104100:
return 0; //SPAS_12 没有
break;
case 1041001:
return 1; //SPAS_12破损
break;
case 1041002:
return 2; //SPAS_12修复
break;
case 1041003:
return 3; //SPAS_12完好
break;
case 1041004:
return 4; //SPAS_12改进
break;
case 1041005:
return 5; //SPAS_12精制
break;
case 1041006:
return 7; //SPAS_12独眼
break;
case 1041007:
return 8; //SPAS_12钢铁
break;
//投掷爆炸物
case 602001:
return 1510; //闪光弹
break;
case 602002:
return 1520; //烟雾弹
break;
case 602003:
return 1530; //燃烧瓶
break;
case 602004:
return 1540; //手榴弹
break;
//近战武器
case 108001:
return 1310; //砍刀
break;
case 108002:
return 1320; //撬棍
break;
case 108003:
return 1330; //镰刀
break;
case 108004:
return 1340; //平底锅
break;
case 0:
return 10; //拳头
break;
case 9808001:
return 1131; //P92手枪破损
break;
case 9808002:
return 1132; //P92手枪修复
break;
case 9808003:
return 1133; //P92手枪完好
break;
case 9808008:
return 1121; //P1911手枪破损
break;
case 9808009:
return 1122; //P1911手枪修复
break;
case 9808010:
return 1123; //P1911手枪完好
break;
case 9808015:
return 1161; //左轮手枪破损
break;
case 9808016:
return 1162; //左轮手枪修复
break;
case 9808017:
return 1163; //左轮手枪完好
break;
case 9808022:
return 1111; //P18C手枪破损
break;
case 9808023:
return 1112; //P18C手枪修复
break;
case 9808024:
return 1113; //P18C手枪完好
break;
case 9808029:
return 1141; //R45手枪破损
break;
case 9808030:
return 1142; //R45手枪修复
break;
case 9808031:
return 1143; //R45手枪完好
break;
case 9808036:
return 1181; //短管霰弹枪破损
break;
case 9808037:
return 1182; //短管霰弹枪修复
break;
case 9808038:
return 1183; //短管霰弹枪完好
break;
case 9808043:
return 1192; //蝎式手枪修复
break;
case 9808044:
return 1193; //蝎式手枪完好
break;
case 9808045:
return 1194; //蝎式手枪改进
break;
case 9808046:
return 1191; //蝎式手枪破损
break;
case 9808050:
return 1172; //沙漠之鹰手枪修复
break;
case 9808051:
return 1173; //沙漠之鹰手枪完好
break;
case 9808052:
return 1174; //沙漠之鹰手枪改进
break;
case 9808053:
return 1171; //沙漠之鹰手枪破损
break;
case 9808057:
return 2; //TMP_9手枪修复  没有
break;
case 9808058:
return 3; //TMP_9手枪完好
break;
case 9808059:
return 4; //TMP_9手枪改进
break;
case 9808060:
return 1150; //信号枪
break;
case 9808061:
return 1; //TMP_9手枪破损
break;
case 9809001:
return 1411; //十字弩破损
break;
case 9809002:
return 1412; //十字弩修复
break;
case 9809003:
return 1413; //十字弩完好
break;
case 9809009:
return 1429; //爆炸猎弓骑警
break;
case 9809010:
return 1429; //爆炸猎弓
break;
case 9810001:
return 931; //S686霰弹枪破损
break;
case 9810002:
return 932; //S686霰弹枪修复
break;
case 9810003:
return 933; //S686霰弹枪完好
break;
case 9810008:
return 921; //S1897霰弹枪破损
break;
case 9810009:
return 922; //S1897霰弹枪修复
break;
case 9810010:
return 923; //S1897霰弹枪完好
break;
case 9810015:
return 915; //S12K霰弹枪精制
break;
case 9810016:
return 912; //S12K霰弹枪修复
break;
case 9810017:
return 913; //S12K霰弹枪完好
break;
case 9810018:
return 914; //S12K霰弹枪改进
break;
case 9810022:
return 902; //DBS霰弹枪修复
break;
case 9810023:
return 903; //DBS霰弹枪完好
break;
case 9810024:
return 904; //DBS霰弹枪改进
break;
case 9810025:
return 905; //DBS霰弹枪精制
break;
case 9810029:
return 2; //SPAS_12霰弹枪修复  没有
break;
case 9810030:
return 3; //SPAS_12霰弹枪完好
break;
case 9810031:
return 4; //SPAS_12霰弹枪改进
break;
case 9810032:
return 5; //SPAS_12霰弹枪精制
break;
case 9810036:
return 2; //AA12_G霰弹枪修复  没有
break;
case 9810037:
return 3; //AA12_G霰弹枪完好
break;
case 9810038:
return 4; //AA12_G霰弹枪改进
break;
case 9810041:
return 5; //AA12_G霰弹枪精制
break;
case 9811001:
return 351; //UZI冲锋枪破损
break;
case 9811002:
return 352; //UZI冲锋枪修复
break;
case 9811003:
return 353; //UZI冲锋枪完好
break;
case 9811004:
return 354; //UZI冲锋枪改进
break;
case 9811008:
return 341; //UMP45冲锋枪破损
break;
case 9811009:
return 342; //UMP45冲锋枪修复
break;
case 9811010:
return 343; //UMP45冲锋枪完好
break;
case 9811011:
return 344; //UMP45冲锋枪改进
break;
case 9811015:
return 386; //维克托冲锋枪卓越
break;
case 9811016:
return 383; //维克托冲锋枪完好
break;
case 9811017:
return 384; //维克托冲锋枪改进
break;
case 9811018:
return 385; //维克托冲锋枪精制
break;
case 9811019:
return 386; //维克托冲锋枪卓越
break;
case 9811020:
return 388; //维克托冲锋枪黑鹰
break;
case 9811021:
return 387; //维克托冲锋枪铁爪
break;
case 9811022:
return 371; //汤姆逊冲锋枪破损
break;
case 9811023:
return 372; //汤姆逊冲锋枪修复
break;
case 9811024:
return 373; //汤姆逊冲锋枪完好
break;
case 9811025:
return 374; //汤姆逊冲锋枪改进
break;
case 9811029:
return 361; //野牛冲锋枪破损
break;
case 9811030:
return 362; //野牛冲锋枪修复
break;
case 9811031:
return 363; //野牛冲锋枪完好
break;
case 9811036:
return 326; //MP5K冲锋枪卓越
break;
case 9811037:
return 323; //MP5K冲锋枪完好
break;
case 9811038:
return 324; //MP5K冲锋枪改进
break;
case 9811039:
return 325; //MP5K冲锋枪精制
break;
case 9811040:
return 326; //MP5K冲锋枪卓越
break;
case 9811041:
return 328; //MP5K冲锋枪黑鹰
break;
case 9811042:
return 327; //MP5K冲锋枪铁爪
break;
case 9811043:
return 2; //AKS_74U冲锋枪修复   没有
break;
case 9811044:
return 3; //AKS_74U冲锋枪完好
break;
case 9811045:
return 4; //AKS_74U冲锋枪改进
break;
case 9811046:
return 5; //AKS_74U冲锋枪精制
break;
case 9811047:
return 6; //AKS_74U冲锋枪卓越
break;
case 9811048:
return 7; //AKS_74U冲锋枪铁爪
break;
case 9811049:
return 8; //AKS_74U冲锋枪黑鹰
break;
case 9811050:
return 336; //P90冲锋枪卓越
break;
case 9811051:
return 333; //P90冲锋枪完好
break;
case 9811052:
return 334; //P90冲锋枪改进
break;
case 9811053:
return 335; //P90冲锋枪精制
break;
case 9811054:
return 336; //P90冲锋枪卓越
break;
case 9811055:
return 338; //P90冲锋枪黑鹰
break;
case 9811056:
return 337; //P90冲锋枪铁爪
break;
case 9812002:
return 56; //AKM突击步枪卓越
break;
case 9812003:
return 53; //AKM突击步枪完好
break;
case 9812004:
return 54; //AKM突击步枪改进
break;
case 9812005:
return 55; //AKM突击步枪精制
break;
case 9812006:
return 56; //AKM突击步枪卓越
break;
case 9812007:
return 58; //AKM突击步枪黑鹰
break;
case 9812008:
return 57; //AKM突击步枪铁爪
break;
case 9812009:
return 91; //M16A4突击步枪破损
break;
case 9812010:
return 92; //M16A4突击步枪修复
break;
case 9812011:
return 93; //M16A4突击步枪完好
break;
case 9812012:
return 94; //M16A4突击步枪改进
break;
case 9812015:
return 46; //SCAR_L突击步枪卓越
break;
case 9812016:
return 43; //SCAR_L突击步枪完好
break;
case 9812017:
return 44; //SCAR_L突击步枪改进
break;
case 9812018:
return 45; //SCAR_L突击步枪精制
break;
case 9812019:
return 46; //SCAR_L突击步枪卓越
break;
case 9812020:
return 48; //SCAR_L突击步枪黑鹰
break;
case 9812021:
return 47; //SCAR_L突击步枪铁爪
break;
case 9812022:
return 27; //M416突击步枪铁爪
break;
case 9812023:
return 26; //M416突击步枪卓越
break;
case 9812024:
return 23; //M416突击步枪完好
break;
case 9812025:
return 24; //M416突击步枪改进
break;
case 9812026:
return 25; //M416突击步枪精制
break;
case 9812027:
return 26; //M416突击步枪卓越
break;
case 9812028:
return 28; //M416突击步枪黑鹰
break;
case 9812029:
return 126; //狗砸突击步枪卓越
break;
case 9812030:
return 124; //狗砸突击步枪改进
break;
case 9812031:
return 125; //狗砸突击步枪精制
break;
case 9812032:
return 126; //狗砸突击步枪卓越
break;
case 9812033:
return 128; //狗砸突击步枪黑鹰
break;
case 9812034:
return 127; //狗砸突击步枪铁爪
break;
case 9812036:
return 76; //AUG突击步枪卓越
break;
case 9812037:
return 74; //AUG突击步枪改进
break;
case 9812038:
return 75; //AUG突击步枪精制
break;
case 9812039:
return 76; //AUG突击步枪卓越
break;
case 9812040:
return 78; //AUG突击步枪黑鹰
break;
case 9812041:
return 77; //AUG突击步枪铁爪
break;
case 9812043:
return 66; //QBZ突击步枪卓越
break;
case 9812044:
return 63; //QBZ突击步枪完好
break;
case 9812045:
return 64; //QBZ突击步枪改进
break;
case 9812046:
return 65; //QBZ突击步枪精制
break;
case 9812047:
return 66; //QBZ突击步枪卓越
break;
case 9812048:
return 68; //QBZ突击步枪黑鹰
break;
case 9812049:
return 67; //QBZ突击步枪铁爪
break;
case 9812050:
return 36; //M762突击步枪卓越
break;
case 9812051:
return 33; //M762突击步枪完好
break;
case 9812052:
return 34; //M762突击步枪改进
break;
case 9812053:
return 35; //M762突击步枪精制
break;
case 9812054:
return 36; //M762突击步枪卓越
break;
case 9812055:
return 38; //M762突击步枪黑鹰
break;
case 9812056:
return 37; //M762突击步枪铁爪
break;
case 9812057:
return 101; //MK47突击步枪破损
break;
case 9812058:
return 102; //MK47突击步枪修复
break;
case 9812059:
return 103; //MK47突击步枪完好
break;
case 9812060:
return 104; //MK47突击步枪改进
break;
case 9812064:
return 86; //G36C突击步枪卓越
break;
case 9812065:
return 83; //G36C突击步枪完好
break;
case 9812066:
return 84; //G36C突击步枪改进
break;
case 9812067:
return 85; //G36C突击步枪精制
break;
case 9812068:
return 86; //G36C突击步枪卓越
break;
case 9812069:
return 88; //G36C突击步枪黑鹰
break;
case 9812070:
return 87; //G36C突击步枪铁爪
break;
case 9812071:
return 311; //AC_VAL突击步枪破损
break;
case 9812072:
return 312; //AC_VAL突击步枪修复
break;
case 9812073:
return 313; //AC_VAL突击步枪完好
break;
case 9812074:
return 314; //AC_VAL突击步枪改进
break;
case 9812078:
return 116; //蜜獾突击步枪卓越
break;
case 9812079:
return 113; //蜜獾突击步枪完好
break;
case 9812080:
return 114; //蜜獾突击步枪改进
break;
case 9812081:
return 115; //蜜獾突击步枪精制
break;
case 9812082:
return 116; //蜜獾突击步枪卓越
break;
case 9812083:
return 118; //蜜獾突击步枪黑鹰
break;
case 9812084:
return 117; //蜜獾突击步枪铁爪
break;
case 9812085:
return 6; //FAMAS突击步枪卓越  没有
break;
case 9812086:
return 3; //FAMAS突击步枪完好
break;
case 9812087:
return 4; //FAMAS突击步枪改进
break;
case 9812088:
return 5; //FAMAS突击步枪精制
break;
case 9812089:
return 6; //FAMAS突击步枪卓越
break;
case 9812090:
return 8; //FAMAS突击步枪黑鹰
break;
case 9812091:
return 7; //FAMAS突击步枪铁爪
break;
case 9812092:
return 29; //M416卡德
break;
case 9813001:
return 556; //M249轻机枪卓越
break;
case 9813002:
return 554; //M249轻机枪改进
break;
case 9813003:
return 555; //M249轻机枪精制
break;
case 9813004:
return 556; //M249轻机枪卓越
break;
case 9813005:
return 558; //M249轻机枪黑鹰
break;
case 9813006:
return 557; //M249轻机枪铁爪
break;
case 9813008:
return 1011; //DP_28轻机枪破损
break;
case 9813009:
return 1012; //DP_28轻机枪修复
break;
case 9813010:
return 1013; //DP_28轻机枪完好
break;
case 9813022:
return 1036; //MG3轻机枪卓越
break;
case 9813023:
return 1034; //MG3轻机枪改进
break;
case 9813024:
return 1035; //MG3轻机枪精制
break;
case 9813025:
return 1036; //MG3轻机枪卓越
break;
case 9813026:
return 1038; //MG3轻机枪黑鹰
break;
case 9813027:
return 1037; //MG3轻机枪铁爪
break;
case 9813029:
return 6; //PKM轻机枪卓越  没有
break;
case 9813030:
return 4; //PKM轻机枪改进
break;
case 9813031:
return 5; //PKM轻机枪精制
break;
case 9813032:
return 6; //PKM轻机枪卓越
break;
case 9813033:
return 8; //PKM轻机枪黑鹰
break;
case 9813034:
return 7; //PKM轻机枪铁爪
break;
case 9814001:
return 532; //_98K狙击枪修复
break;
case 9814002:
return 533; //_98K狙击枪完好
break;
case 9814003:
return 534; //_98K狙击枪改进
break;
case 9814008:
return 556; //M24狙击枪卓越
break;
case 9814009:
return 553; //M24狙击枪完好
break;
case 9814010:
return 554; //M24狙击枪改进
break;
case 9814011:
return 555; //M24狙击枪精制
break;
case 9814012:
return 556; //M24狙击枪卓越
break;
case 9814013:
return 558; //M24狙击枪黑鹰
break;
case 9814014:
return 557; //M24狙击枪铁爪
break;
case 9814015:
return 516; //AWM狙击枪卓越
break;
case 9814016:
return 514; //AWM狙击枪改进
break;
case 9814017:
return 515; //AWM狙击枪精制
break;
case 9814018:
return 516; //AWM狙击枪卓越
break;
case 9814019:
return 518; //AWM狙击枪黑鹰
break;
case 9814020:
return 517; //AWM狙击枪铁爪
break;
case 9814022:
return 571; //莫辛纳甘狙击枪破损
break;
case 9814023:
return 572; //莫辛纳甘狙击枪修复
break;
case 9814024:
return 573; //莫辛纳甘狙击枪完好
break;
case 9814029:
return 561; //Win94狙击枪破损
break;
case 9814030:
return 562; //Win94狙击枪修复
break;
case 9814031:
return 563; //Win94狙击枪完好
break;
case 9814036:
return 526; //AMR狙击枪卓越
break;
case 9814037:
return 524; //AMR狙击枪改进
break;
case 9814038:
return 525; //AMR狙击枪精制
break;
case 9814039:
return 526; //AMR狙击枪卓越
break;
case 9814040:
return 528; //AMR狙击枪黑鹰
break;
case 9814041:
return 527; //AMR狙击枪铁爪
break;
case 9814043:
return 546; //M200狙击枪卓越
break;
case 9814044:
return 543; //M200狙击枪完好
break;
case 9814045:
return 544; //M200狙击枪改进
break;
case 9814046:
return 545; //M200狙击枪精制
break;
case 9814047:
return 546; //M200狙击枪卓越
break;
case 9814048:
return 548; //M200狙击枪黑鹰
break;
case 9814049:
return 547; //M200狙击枪铁爪
break;
case 9814050:
return 4; //SVD狙击枪改进  没有
break;
case 9814051:
return 5; //SVD狙击枪精制
break;
case 9814052:
return 6; //SVD狙击枪卓越
break;
case 9814053:
return 6; //SVD狙击枪卓越
break;
case 9815001:
return 786; //SKS射手步枪卓越
break;
case 9815002:
return 783; //SKS射手步枪完好
break;
case 9815003:
return 784; //SKS射手步枪改进
break;
case 9815004:
return 785; //SKS射手步枪精制
break;
case 9815005:
return 786; //SKS射手步枪卓越
break;
case 9815006:
return 788; //SKS射手步枪黑鹰
break;
case 9815007:
return 787; //SKS射手步枪铁爪
break;
case 9815008:
return 801; //VSS射手步枪破损
break;
case 9815009:
return 802; //VSS射手步枪修复
break;
case 9815010:
return 803; //VSS射手步枪完好
break;
case 9815015:
return 751; //Mini14射手步枪破损
break;
case 9815016:
return 752; //Mini14射手步枪修复
break;
case 9815017:
return 753; //Mini14射手步枪完好
break;
case 9815018:
return 754; //Mini14射手步枪改进
break;
case 9815022:
return 736; //MK14射手步枪卓越
break;
case 9815023:
return 733; //MK14射手步枪完好
break;
case 9815024:
return 734; //MK14射手步枪改进
break;
case 9815025:
return 735; //MK14射手步枪精制
break;
case 9815026:
return 736; //MK14射手步枪卓越
break;
case 9815027:
return 738; //MK14射手步枪黑鹰
break;
case 9815028:
return 737; //MK14射手步枪铁爪
break;
case 9815029:
return 796; //SLR射手步枪卓越
break;
case 9815030:
return 793; //SLR射手步枪完好
break;
case 9815031:
return 794; //SLR射手步枪改进
break;
case 9815032:
return 795; //SLR射手步枪精制
break;
case 9815033:
return 796; //SLR射手步枪卓越
break;
case 9815034:
return 798; //SLR射手步枪黑鹰
break;
case 9815035:
return 797; //SLR射手步枪铁爪
break;
case 9815036:
return 771; //QBU射手步枪破损
break;
case 9815037:
return 772; //QBU射手步枪修复
break;
case 9815038:
return 773; //QBU射手步枪完好
break;
case 9815039:
return 774; //QBU射手步枪改进
break;
case 9815043:
return 716; //M417射手步枪卓越
break;
case 9815044:
return 713; //M417射手步枪完好
break;
case 9815045:
return 714; //M417射手步枪改进
break;
case 9815046:
return 715; //M417射手步枪精制
break;
case 9815047:
return 716; //M417射手步枪卓越
break;
case 9815048:
return 718; //M417射手步枪黑鹰
break;
case 9815049:
return 717; //M417射手步枪铁爪
break;
case 9815050:
return 746; //MK20_H射手步枪卓越
break;
case 9815051:
return 743; //MK20_H射手步枪完好
break;
case 9815052:
return 744; //MK20_H射手步枪改进
break;
case 9815053:
return 745; //MK20_H射手步枪精制
break;
case 9815054:
return 746; //MK20_H射手步枪卓越
break;
case 9815055:
return 748; //MK20_H射手步枪黑鹰
break;
case 9815056:
return 747; //MK20_H射手步枪铁爪
break;
case 9815064:
return 726; //MK12射手步枪卓越
break;
case 9815065:
return 723; //MK12射手步枪完好
break;
case 9815066:
return 724; //MK12射手步枪改进
break;
case 9815067:
return 725; //MK12射手步枪精制
break;
case 9815068:
return 726; //MK12射手步枪卓越
break;
case 9815069:
return 728; //MK12射手步枪黑鹰
break;
case 9815070:
return 727; //MK12射手步枪铁爪
break;
// case 9815071:
// return 9; //M134_装甲重机枪  没有
break;
default:
return 0;
break;}
return 0;
} 


#endif