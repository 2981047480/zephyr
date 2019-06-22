#!usr/bin/python3

import pymysql

db=pymysql.connect("localhost","root","","TESTDB")

cursor=db.cursor()#使用cursor操作游标

sql="""INSERT INTO EMPLOYEE(FIRST_NAME,
LAST_NAME,AGE,SEX,INCOME)
VALUES ('Mac', 'Mohan', '20', 'M', 2000)"""#sql插入语句

try:
    cursor.execute(sql)#执行SQL语句
    db.commit()#提交到数据库执行
except:#发生错误
    db.rollback()#使游标回滚

db.close()#关闭数据库连接

#游标操作：db.scroll(数字,模式（‘relative’或‘absolute’）)relative是相对，absolute是绝对（从头数几位）
#fetchone（）匹配游标所在位的下一位
#fetmany（数字）匹配接下来n个
