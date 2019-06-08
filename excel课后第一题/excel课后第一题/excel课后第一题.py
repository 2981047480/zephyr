#!/usr/bin/env python3
import pandas as pd
import sys
input_file=sys.argv[1]
output_file=sys.argv[2]
data_frame=pd.read_excel(input_file,'january_2013',index_col=None)
important_dates=['1/1/2013','1/6/2013']
data_frame_value_in_set=data_frame[data_frame['Purchase Date'].isin(important_dates)]#isin接受一个列表，可以判断元素是否在里面
writer=pd.ExcelWriter(output_file)
print(data_frame_value_in_set)
data_frame_value_in_set.to_excel(writer,sheet_name='jan_13_output',index=False)
writer.save()