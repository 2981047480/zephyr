#!/usr/bin/env python3
import pandas as pd
import glob
import os
import sys
input_path=sys.argv[1]
output_file=sys.argv[2]
all_workbooks=glob.glob(os.path.join(input_path,"*.xls*"))#os.path.join的作用为拼接，把前面的路径和后面的拼接到一起
data_frames=[]
for workbook in all_workbooks:
    all_worksheets=pd.read_excel(workbook,sheetneme=None,index_col=None)#读其中的一个表格
    for worksheet_name,data in all_worksheets.items():
        data_frames.append(data)#向列表的后面添加值
all_data_concatenated=pd.concat(data_frames,axis=0,ignore_index=True)#concat用来合并链接，其中axis=1为列，=0为行，如果两个表的index都无用，那么可以无视它
writer=pd.ExcelWriter(output_file)
all_data_concatenated.to_excel(writer,sheet_name='all_data_all_workbooks',index=False)
writer.save()