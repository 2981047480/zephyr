bibtex = """@ARTICLE{Cesar2013,
  author = {Jean César},
  title = {An amazing title},
  year = {2013},
  volume = {12},
  pages = {12--23},
  journal = {Nice Journal},
  abstract = {This is an abstract. This line should be long enough to test
     multilines...},
  comments = {A comment},
  keywords = {keyword1, keyword2}
}
"""

with open('C:\\Users\\dell\\Desktop\\bibtex.bib', 'w') as bibfile:#这句代码的作用是用bibfile作为指针打开文件
    bibfile.write(bibtex)
#上面为第一段代码，作用是打开并写入文件
import bibtexparser#调用库

with open('C:\\Users\\dell\\Desktop\\bibtex.bib') as bibtex_file:
    bib_database = bibtexparser.load(bibtex_file)

#print(bib_database)#尝试不带.entries,打印出疑似地址的东西
print(bib_database.entries)#打印bib_database.entries中的字符，不过打印出来的内容顺序和原来文件中的顺序相反
#print(bib_database.comments)#打印评论的内容
#同理，也可以打印除comments外的preambles，strings，格式与上面类似
#上面为第二段代码，作用是读取文件并显示


import bibtexparser

with open('C:\\Users\\dell\\Desktop\\bibtex.bib') as bibtex_file:
    bibtex_str = bibtex_file.read()

bib_database = bibtexparser.loads(bibtex_str)

print(bibtex_str)#这么打印出来和原文档一致
#print(bibtex_str.entries)这么写报错显示没有entires。entries：条目。

