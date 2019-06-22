import pymysql

db=pymysql.connect("localhost","root","","TESTDB")

cursor=db.cursor()

sql="UPDATE EMPLOYEE SET AGE = AGE + 1 WHERE SEX = '%c'"%('M')#SQL更新语句
try:
    cursor.execute(sql)#执行SQL语句
    db.commit()#提交到数据库
except:
    db.rollback()#发生错误时回滚

db.close()#关闭数据库连接