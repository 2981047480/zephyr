# coding=utf-8

import re
import time
local_time = time.asctime(time.localtime(time.time()))
with open("房源信息.txt", "r",encoding='utf-8') as f1:
    with open("data_clear.txt", "w", encoding='utf-8') as f2:
        f2.write("房源编号 城市 区 方位 房屋名 大小 租赁方式 朝向 月租 计费方式 几室 几厅 几卫 入住 租期 看房 所在楼层 总楼高 电梯 车位 用水 用电 燃气 供暖"+" "+str(local_time)+"\n")
        data = f1.read()
        list1 = data.split('\n')
        #print(len(list1))
        for i in range(len(list1)):
            list2 = list1[i].split(" ")
            #print(len(list2))
            for j in range(len(list2)):
                if list2[j] == "" or j==7:
                    pass
                else:
                    f2.write(list2[j]+" ")
            f2.write('\n')
with open("data_clear.txt", "r",encoding='utf-8') as f:
    with open("data_real.txt", "w",encoding='utf-8') as ff:
        data = f.read()
        list1 = data.split("\n")
        print(len(list1))
        for i in range(len(list1)):
            list2 = list1[i].split(" ")
            if(i>=1 and i<2949):
                str0 = re.findall(".*(.租).*", list2[6])
                if list2[7] == "复式" or list2[7] == "跃层":
                    list2[7] = list2[8]
                    list2[8] = list2[9]
                    list2[9] = "NULL"
            if len(list2) == 23:
                str1 = re.findall("(.*?元/月)\((.*?)\)", list2[8])
                if str1:
                    list2[8] = str1[0][0]
                    list2.insert(9, str1[0][1])
                else:
                    list2.insert(9, "NULL")
            if len(list2) == 24:
                str2 = re.findall(".*\((.*?)\)", list2[9])
                if str2:
                    list2[9] = str2[0]
            if(i>=1 and i<2949):
                if list2[16]:
                    str3 = re.findall("(.*?)/(.*)", list2[16])
                    list2[16] = str3[0][0]+" "+str3[0][1]
            for j in range(len(list2)-2):
                if list2[j] == "":
                    pass
                elif i>=1 and j==6:
                    ff.write(str0[0] + " ")
                else:
                    ff.write(list2[j] + " ")
            ff.write("\n")
with open("data_real.txt", "r",encoding='utf-8') as f:
    data = f.read()
    list1 = data.split("\n")
    print(len(list1))
    for i in range(len(list1)):
        list2 = list1[i].split(" ")
        print(len(list2))
