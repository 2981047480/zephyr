#/usr/bin/env python3
import sys
from datetime import date
from xlrd import open_workbook,xldate_as_tuple#这个用来把时间存入元组
from xlwt import Workbook
input_file=sys.argv[1]
output_file=sys.argv[2]
output_workbook=Workbook()
output_worksheet=output_workbook.add_sheet('jan_2013_output')
with open_workbook(input_file) as workbook:
    worksheet=workbook.sheet_by_name('january_2013')
    for row_index in range(worksheet.nrows):
        row_list_output=[]
        for col_index in range(worksheet.ncols):
            if worksheet.cell_type(row_index,col_index)==3:#数字3代表这一行是日期
                date_cell=xldate_as_tuple(worksheet.cell_value(row_index,col_index),workbook.datemode)#cell_value函数用来引用单元格中的值，也可以用cell().value函数，会被转换成元组中的一个代表日期的浮点数
                date_cell=date(*date_cell[0:3]).strftime('%m/%d/%Y')#把date格式转换为一个具有特定格式的字符串
                row_list_output.append(date_cell)#使用追加函数将date_cell中的值追加给输出列表row_list_output
                output_worksheet.write(row_index,col_index,non_date_cell)
            else:
                non_date_cell=worksheet.cell_value(row_index,col_index)
                row_list_output.append(non_date_cell)
                output_worksheet.write(row_index,col_index,non_date_cell)
output_workbook.save(output_file)