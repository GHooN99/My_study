import numpy as np
import csv

x_data=[]
y_data=[]

f=open("price_data.csv")

data=csv.reader(f)
next(data)
for i in data:
    s=[]
    for j in range(3):
        s.append(float(i[j]))
    x_data.append(s)
    y_data.append(float(i[4]))

np.array(x_data)

    

