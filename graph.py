import re
import matplotlib.pyplot as plt
string="""count is 65 and time taken is 22.529354
count is 129 and time taken is 22.689116
count is 257 and time taken is 22.007377
count is 513 and time taken is 22.055860
count is 1025 and time taken is 21.606012
count is 2049 and time taken is 9.500944
count is 4097 and time taken is 9.234010
count is 8193 and time taken is 9.293282
count is 16385 and time taken is 9.191563
count is 32769 and time taken is 9.196437
count is 65537 and time taken is 9.192405
count is 131073 and time taken is 9.165999
count is 262145 and time taken is 9.597990
count is 524289 and time taken is 10.830024
count is 1048577 and time taken is 10.546016
count is 17 and time taken is 9.672882
count is 33 and time taken is 10.894848
count is 65 and time taken is 10.032000
count is 129 and time taken is 9.675612
count is 257 and time taken is 9.284661
count is 513 and time taken is 9.239082
count is 1025 and time taken is 17.454214
count is 2049 and time taken is 16.522901
count is 4097 and time taken is 17.524526
count is 8193 and time taken is 17.742441
count is 16385 and time taken is 17.728709
count is 32769 and time taken is 20.034577
count is 65537 and time taken is 24.393452
count is 131073 and time taken is 21.570473
count is 262145 and time taken is 20.513071
count is 5 and time taken is 10.121600
count is 9 and time taken is 10.199111
count is 17 and time taken is 10.810000
count is 33 and time taken is 10.010455
count is 65 and time taken is 9.369400
count is 129 and time taken is 9.095884
count is 257 and time taken is 13.723786
count is 513 and time taken is 13.844632
count is 1025 and time taken is 20.798699
count is 2049 and time taken is 26.831098
count is 4097 and time taken is 26.341415
count is 8193 and time taken is 35.607567
count is 16385 and time taken is 81.590158
count is 32769 and time taken is 86.960173
count is 65537 and time taken is 97.232401
count is 2 and time taken is 10.796000
count is 3 and time taken is 10.266667
count is 5 and time taken is 10.110400
count is 9 and time taken is 10.132444
count is 17 and time taken is 10.675118
count is 33 and time taken is 10.801909
count is 65 and time taken is 16.131646
count is 129 and time taken is 20.787039
count is 257 and time taken is 20.814739
count is 513 and time taken is 44.051538
count is 1025 and time taken is 40.446067
count is 2049 and time taken is 58.864899
count is 4097 and time taken is 94.670217
count is 8193 and time taken is 112.547216
count is 16385 and time taken is 124.678113
count is 1 and time taken is 11.092000
count is 1 and time taken is 10.888000
count is 2 and time taken is 10.710000
count is 3 and time taken is 10.282667
count is 5 and time taken is 10.143200
count is 9 and time taken is 8.988667
count is 17 and time taken is 18.014118
count is 33 and time taken is 17.292697
count is 65 and time taken is 26.960446
count is 129 and time taken is 43.400767
count is 257 and time taken is 43.547409
count is 513 and time taken is 63.757982
count is 1025 and time taken is 132.469103
count is 2049 and time taken is 195.863624
count is 4097 and time taken is 213.468625"""

list1=[]
for element in string.split("\n"):
    list1.append(re.findall("\d+\.\d+", element))

stride1=[]
for element in list1[:15]:
    stride1.append(float(element[0])/1.75   )

stride2=[]
for element in list1[15:30]:
    stride2.append(float(element[0])/1.75)

stride3=[]
for element in list1[30:45]:
    stride3.append(float(element[0])/1.75)

stride4=[]
for element in list1[45:60]:
    stride4.append(float(element[0])/1.75)

stride5=[]
for element in list1[60:75]:
    stride5.append(float(element[0])/1.75)

plt.plot(stride1,label="2*4")
plt.plot(stride2,label="8*4")
plt.plot(stride3,label="32*4")
plt.plot(stride4,label="128*4")
plt.plot(stride5,label="512*4")
plt.legend()
plt.show()



