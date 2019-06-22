#!/usr/bin/python3

import pymysql

db=pymysql.connect("localhost","root","","TESTDB")

cursor=db.cursor()#使用cursor（）获取操作游标

sql="SELECT * FROM EMPLOYEE \
WHERE INCOME > %s"%(1000)#sql查询语句

try:
    cursor.execute(sql)#执行SQL语句
    results=cursor.fetchall()
    for row in results:
        fname=row[0]
        lname=row[1]
        age=row[2]
        sex=row[3]
        income=row[4]
        print("fname=%s,lname=%s,age=%s,income=%s"%(fname,lname,age,sex,income))
except:
    print("Error:unable to fetch data")

db.close()#关闭数据库连接

