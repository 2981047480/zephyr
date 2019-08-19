# coding=gbk

import re

set_fangyuan = set()
set_qu = set()
set_fangwei = set()
set_fangwuming = set()
set_zulinfangshi = set()
set_chaoxiang = set()
set_jifeifangshi = set()
set_ruzhu = set()
set_zuqi = set()
set_kanfang = set()
set_dianti = set()
set_chewei = set()
set_yongshui = set()
set_yongdian = set()
set_ranqi = set()
set_gongnuan = set()
with open("b.txt", "r")as f:
    data = f.read()
    list1 = data.split("\n")
    print(len(list1))
    for i in range(1, 3001):
        list2 = list1[i].split(" ")
        set_fangyuan.add(list2[0])
        set_qu.add(list2[2])
        set_fangwei.add(list2[3])
        set_fangwuming.add(list2[4])
        set_zulinfangshi.add(list2[6])
        chaoxiang = re.findall("(.*?)/", list2[7])
        if chaoxiang :
            set_chaoxiang.add(chaoxiang[0])
        else:
            set_chaoxiang.add(list2[7])
        #set_chaoxiang.add(list2[7])
        set_jifeifangshi.add(list2[9])
        set_ruzhu.add(list2[13])
        set_zuqi.add(list2[14])#???????
        set_kanfang.add(list2[15])
        set_dianti.add(list2[18])
        set_chewei.add(list2[19])
        set_yongshui.add(list2[20])
        set_yongdian.add(list2[21])
        set_ranqi.add(list2[22])
        set_gongnuan.add(list2[23])


dict_high = {}
dict_high["低楼层"] = 1
dict_high["中楼层"] = 2
dict_high["高楼层"] = 3
dict_high["地下室"] = -1
dict_high["未知"] = -2

print(len(set_fangyuan))
dict_qu = {}
for i in range(len(set_qu)):
    dict_qu[list(set_qu)[i]] = i+1
print(dict_qu)
print("\n")

dict_fangwei = {}
for i in range(len(set_fangwei)):
    dict_fangwei[list(set_fangwei)[i]] = i+1
print(dict_fangwei)
print("\n")

dict_fangwuming = {}
for i in range(len(set_fangwuming)):
    dict_fangwuming[list(set_fangwuming)[i]] = i+1
print(dict_fangwuming)
print("\n")

dict_zulinfangshi = {}
for i in range(len(set_zulinfangshi)):
    dict_zulinfangshi[list(set_zulinfangshi)[i]] = i+1
dict_zulinfangshi["合租"] = 2
print(dict_zulinfangshi)
print("\n")

dict_chaoxiang = {}
dict_chaoxiang["朝向暂无"] = 0
dict_chaoxiang["东"] = 1
dict_chaoxiang["南"] = 2
dict_chaoxiang["西"] = 3
dict_chaoxiang["北"] = 4
dict_chaoxiang["东北"] = 5
dict_chaoxiang["东南"] = 6
dict_chaoxiang["西北"] = 7
dict_chaoxiang["西南"] = 8
print(dict_chaoxiang)
print("\n")

dict_jifeifangshi = {}
dict_jifeifangshi["NULL"] = 0
dict_jifeifangshi["季付价"] = 1
dict_jifeifangshi["年付价"] = 2
dict_jifeifangshi["月付价"] = 3
dict_jifeifangshi["半年付价"] = 4
dict_jifeifangshi["双月付价"] = 5
print(dict_jifeifangshi)
print("\n")

dict_ruzhu = {}
dict_ruzhu["NULL"] = 0
for i in range(len(set_ruzhu)):
    if list(set_ruzhu)[i] == "随时入住":
        dict_ruzhu[list(set_ruzhu)[i]] = 2
    else:
        dict_ruzhu["具体入住"] = 1
print(dict_ruzhu)
print("\n")

dict_kanfang = {}
dict_kanfang["NULL"] = 0
for i in range(len(set_kanfang)):
    dict_kanfang[list(set_kanfang)[i]] = i+1
print(dict_kanfang)
print("\n")

dict_dianti = {}
dict_dianti["NULL"] = 0
dict_dianti["无"] = 1
dict_dianti["有"] = 2
dict_dianti["暂无数据"] = 3
print(dict_dianti)
print("\n")

dict_yongshui = {}
dict_yongshui["NULL"] = 0
dict_yongshui["民水"] = 1
dict_yongshui["商水"] = 2
dict_yongshui["暂无数据"] = 3
print(dict_yongshui)
print("\n")

dict_chewei = {}
dict_chewei["NULL"] = 0
dict_chewei["免费使用"] = 1
dict_chewei["租用车位"] = 2
dict_chewei["暂无数据"] = 3
print(dict_chewei)
print("\n")

dict_yongdian = {}
dict_yongdian["NULL"] = 0
dict_yongdian["民电"] = 1
dict_yongdian["商电"] = 2
dict_yongdian["暂无数据"] = 3
print(dict_yongdian)
print("\n")

dict_ranqi = {}
#for i in range(len(set_ranqi)):
#    dict_ranqi[list(set_ranqi)[i]] = i+1
dict_ranqi["NULL"] = 0
dict_ranqi["无"] = 1
dict_ranqi["有"] = 2
dict_ranqi["暂无数据"] = 3
print(dict_ranqi)
print("\n")

dict_gongnuan = {}
dict_gongnuan["NULL"] = 0
dict_gongnuan["集中供暖"] = 1
dict_gongnuan["自采暖"] = 2
dict_gongnuan["暂无数据"] = 3
print(dict_gongnuan)
print("\n")

with open("number_rule.txt", "w")as f:
    f.write("编码规则为\n")
    f.write(str(dict_qu)+"\n"+str(dict_fangwei)+"\n"+str(dict_fangwuming)+"\n"+str(dict_zulinfangshi)+"\n")
    f.write(str(dict_chaoxiang)+"\n"+str(dict_jifeifangshi)+"\n"+str(dict_ruzhu)+"\n"+str(dict_kanfang)+"\n")
    f.write(str(dict_dianti)+"\n"+str(dict_chewei)+"\n")
    f.write(str(dict_yongshui)+"\n"+str(dict_yongdian)+"\n"+str(dict_ranqi)+"\n"+str(dict_gongnuan)+"\n")
    f.write(str(dict_high)+"\n")
with open("数字.txt", "w")as f:
    f.write("城市 区 方位 房屋名 大小 租赁方式 朝向 月租 计费方式 几室 几厅 几卫 入住 租期 看房 所在楼层 总楼高 电梯 车位 用水 用电 燃气 供暖 \n")
    for i in range(1, 3001):
        list2 = list1[i].split(" ")
        #print(list2)
        f.write("3 "+str(dict_qu[list2[2]])+" "+str(dict_fangwei[list2[3]]) + " "+str(dict_fangwuming[list2[4]]) + " ")
        #f.write(str(list2[5])+" 1 ")
        list2[6]=list2[6].replace('合租','2')
        list2[6] = list2[6].replace('整租', '1')
        f.write(str(list2[5]) + ' ' +str(list2[6])+' ')
        chaoxiang = re.findall("(.*?)/", list2[7])
        if chaoxiang:
            f.write(str(dict_chaoxiang[chaoxiang[0]])+" ")
        else:
            f.write(str(dict_chaoxiang[list2[7]])+" ")
        money = re.findall("(.*?)元/月", list2[8])
        if list2[9] == "NULL":
            f.write(money[0]+" 0 ")
        else:
            f.write(money[0]+" "+str(dict_jifeifangshi[list2[9]])+" ")
        size0 = re.findall("(.*)室", list2[10])
        size1 = re.findall("(.*)厅", list2[11])
        size2 = re.findall("(.*)卫", list2[12])
        if size0:
            f.write(size0[0]+" "+size1[0]+" "+size2[0]+" ")
        else :
            f.write("0 0 0 ")
        if list2[13]=="随时入住" or list2[13] == "NULL":
            ruzhu = list2[13]
        else:
            ruzhu = "具体入住"
        f.write(str(dict_ruzhu[ruzhu])+" ")
        #print(list2[14])
        tenancy_time = re.findall("(.)年", list2[14])
        if tenancy_time:
            t_time = int(tenancy_time[0])*12
            f.write(str(t_time)+" ")  # 租期编号
        else:
            tenancy_time = re.findall("~(.*)个月", list2[14])
            if tenancy_time:
                f.write(str(tenancy_time[0])+" ")
            else:
                f.write("0 ")
        if list2[15]=="NULL":
            f.write("0 ")
        else:
            f.write(str(dict_kanfang[list2[15]])+" ")
#################
        high0 = re.findall("([0-9]*)", list2[16])
        #print(high0[0])
        high1 = re.findall("(.*)层", list2[17])
        high_class = float(high1[0])/3
        if high0[0]:
            if float(high0[0]) < high_class:
                f.write(str(dict_high["低楼层"])+" ")
                #print(str(dict_high["低楼层"]))
            elif float(high0[0]) < high_class*2:
                f.write(str(dict_high["中楼层"])+" ")
                #print(str(dict_high["中楼层"]))
            else:
                f.write(str(dict_high["高楼层"])+" ")
                #print(str(dict_high["高楼层"]))
        else:
            f.write(str(dict_high[list2[16]])+" ")
            #print(str(dict_high[list2[16]]))
        f.write(high1[0]+" ")
###############
        if list2[18] == "NULL":
            f.write("0 ")
        else:
            f.write(str(dict_dianti[list2[18]])+" ")  # 电梯
        if list2[19] == "NULL":
            f.write("0 ")
        else:
            f.write(str(dict_chewei[list2[19]])+" ")  # 车位
        if list2[20] == "NULL":
            f.write("0 ")
        else:
            f.write(str(dict_yongshui[list2[20]])+" ")  # 用水
        if list2[21] == "NULL":
            f.write("0 ")
        else:
            f.write(str(dict_yongdian[list2[21]])+" ")  # 用电
        if list2[22] == "NULL":
            f.write("0 ")
        else:
            f.write(str(dict_ranqi[list2[22]])+" ")  # 燃气
        if list2[23]=="NULL":
            f.write("0\n")
        else:
            f.write(str(dict_gongnuan[list2[23]])+"\n")  # 供暖

with open("data_number.txt", "r")as f:
    data = f.read()
    list1 = data.split("\n")
    with open("training_set.txt", "w")as f1:
        with open("validation_set.txt", "w")as f2:
            for i in range(1, len(list1)):
                if i < 1201:
                    f1.write(str(list1[i])+"\n")
                else:
                    f2.write(str(list1[i])+"\n")
'''
with open("validation_set.txt", "r")as f:
    data = f.read()
    list1 = data.split("\n")
    for i in range(1, len(list1)):
        list2 = list1[i].split(" ")
        list3 = list1[i-1].split(" ")
        if len(list2) != len(list3):
            print("*********")
        else:
            print("111")'''
