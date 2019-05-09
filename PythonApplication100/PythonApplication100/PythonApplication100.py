import bibtexparser
from bibtexparser.bparser import BibTexParser

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

with open('bibtex.bib', 'w',encoding='UTF-8') as bibfile:
    bibfile.write(bibtex)

with open('bibtex.bib',encoding='UTF-8') as bibtex_file1:
    bib_database=bibtexparser.load(bibtex_file1)

print(bib_database.entries)
#这个打印的比较杂乱
print(bib_database.comments)
print(bib_database.preambles)
print(bib_database.strings)

with open('bibtex.bib',encoding='UTF-8') as bibtex_file2:
    bibtex_str=bibtex_file2.read()

bib_database=bibtexparser.loads(bibtex_str)
print(bibtex_str)
#这个很整齐（非常整齐那种）

parser=BibTexParser(common_strings=False)
parser.ignore_nonstandard_types=False
#parser.ignore_nonstandard_types=True
parser.homogenise_fields=False

bibdatabase=bibtexparser.loads(bibtex_str,parser)
print(bibdatabase)
#打印出来是一串不知道是什么的序列

bibtex_str=bibtexparser.dumps(bib_database)

print(bibtex_str)
#打印结果和上面比较整齐那个特别特别像
import bibtexparser

with open('bibtex.bib','w') as bibtex_file:
    bibtexparser.dump(bibtex_database,bibtex_file)