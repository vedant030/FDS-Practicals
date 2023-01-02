b=[]
n=int(input("Enter the number of elements you want to store & sort"))
def insert():
    for i in range(n):    
        num=int(input("Enter the element no"))
        b.append(num)
        

def shell():
    gap=int(len(b)//2)     # always take len cause we need int values not decimal 
    while gap>0:
        for i in range(gap,len(b)):
            anchor=b[i]                 # we made first one as anchor element 
            j=i
            while j>=gap and b[j-gap]<anchor:    #comapared gap element with the with achor and gap on both side so we use it 
                b[j]=b[j-gap]                         # swao that elements in the gap 
                j-=gap                      #reduce j element cause gap is on both the sides 
            b[j]=anchor                     # change the anchor elements 
        gap=gap//2         

def display():
    for i in range (5):
        print(b[i])            

insert()
shell()
display()