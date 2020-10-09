print("------------Implementing uniform probability distributon--------------")
try:
    ul = int(input("Enter the upper limit : "))
    ll = int(input("Enter the lower limit : "))
    from math import sqrt
    if(ul > ll):
    
        print("mean : ", ll+ul/2)
        print("variance : ",((ul-ll)**2)/12)
        print("standard deviation : ", (ul-ll)/2*sqrt(3))
    else:
        print("value of upper limit should be greater than lower limit")
except:
    print("enter valid input")
