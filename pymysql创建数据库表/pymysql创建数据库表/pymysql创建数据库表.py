#!usr/bin/python3

import pymysql

db=pymysql.connect("localhost","root","","TESTDB")#打开数据库连接

cursor=db.cursor()#创建一个游标对象

cursor.execute("DROP TABLE IF EXISTS EMPLOYEE")#存在表则删除

sql="""CREATE TABLE EMPLOYEE (
FIRST_NAME CHAR(20) NOT NULL,
LAST_NAME CHAR(20),
AGE INT,
SEX CHAR(1),
INCOME FLOAT )"""#SQL语句创建表

cursor.execute(sql)#执行SQL语句

#print(cursor.execute("DESC EMPLOYEE"))

db.close()#关闭数据库连接
