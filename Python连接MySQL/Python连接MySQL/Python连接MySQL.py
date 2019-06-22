#!/usr/bin/python3

import pymysql

db=pymysql.connect("localhost","root","","TESTDB")#打开数据库连接

cursor=db.cursor()#创建一个游标对象cursor

cursor.execute("SELECT VERSION()")#使用execute（）进行SQL查询,执行结果是MySQL的版本号

data=cursor.fetchone()#获取单条数据

print("Database version : %s " %data)