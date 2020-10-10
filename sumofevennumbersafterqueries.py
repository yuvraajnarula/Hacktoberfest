a= [1,2,3,4]
q=[[1,0],[-3,1],[-4,0],[2,3]]
b=[]
combine = []

for i in q:
    f,g=i
    a[g]=a[g]+f
    
    num=[]
    for i in a:
        num.append(i)
    
    combine.append(num)

for i in combine:
    s=0
    for j in i:
        if(j%2==0):
            s=s+j
    b.append(s)
print(b)
        



    
