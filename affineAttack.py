def weigh(s):
    w = 0
    n = len(s)
    for i in range(n):
        if(s[i]=='Y'):
            w+=1
        if(s[i]=='Z' or s[i]=='V'):
            w+=2
        if(i<n-1 and s[i+1]!=' ' and s[i]=='Q' and s[i+1]!='U'):
            w=1000
        elif(i<n-1 and s[i+1]!=' ' and s[i]=='Q' and s[i+1]=='U'):
            w=-100
        
        if(i<n-1 and s[i+1]!=' ' and s[i]=='X' and check(s[i+1])==0 ):
            w=1000
        
        if(i<n-1 and (s[i]=='O' and s[i+1] == 'O')):
            w-=5
        
        if(i<n-1 and (s[i]=='E' and s[i+1]=='E')):
            w-=5
        
        if(i<n-1 and (s[i]=='S' and s[i+1]=='H')):
            w-=5
        
        if(i<n-1 and (s[i]=='S' and s[i+1]=='C')):
            w-=10
        
        if(i<n-1 and (s[i]=='S' and s[i+1]=='S')):
            w-=10
        
        if(i<n-1 and (s[i]=='S' and s[i+1]=='T')):
            w-=5
        
        if(i<n-1 and (s[i]=='I' and s[i+1]=='E')):
            w-=5
        
        if(i<n-1 and (s[i]=='T' and s[i+1]=='H')):
            w-=5
        
        if(i<n-1 and (s[i]=='O' and s[i+1]=='U')):
            w-=5
        
        if(i<n-1 and (s[i]=='I' and s[i+1]=='S')):
            w-=50
        
        if(i<n-2 and (s[i]=='I' and s[i+1]=='O' and s[i+2]=='N')):
            w-=100
        
        if(i<n-2 and (s[i]=='I' and s[i+1]=='N' and s[i+2]=='G')):
            w-=100
        
        if(i<n-2 and (s[i]=='A' and s[i+1]=='N' and s[i+2]=='D')):
            w-=100
    
    return w

def check(a):
    if(a=='A' or a=='E' or a=='I' or a=='O' or a=='U' or a=='Y'):
        return 1
    else:
        return 0

def sencheck(s):
    maxdevoid=0 
    devoid=0
    ok=0
    n = len(s)
    for i in range(n):
        if(s[i] == ' '):
            if(ok==0):
                maxdevoid = 1000
                break
            else:
                if(devoid>maxdevoid):
                    maxdevoid = devoid
            ok = 0
            devoid = 0
            continue
        if(check(s[i])):
            if(devoid>maxdevoid):
                maxdevoid=devoid
            ok = 1
            devoid = 0
        else:
            devoid+=1
    
    if ok==0:
        maxdevoid = 1000
    if devoid>=maxdevoid:
        maxdevoid = devoid
    return maxdevoid

def decrypt(s, ainv, b):
    n = len(s)
    msg = ''
    for i in range(n):
        if(s[i]==' '):
            msg+=' '
        else:
            msg+=chr((ainv * (ord(s[i])-ord('A') - b+26) % 26) + ord('A'))

    return sencheck(msg), weigh(msg)

def printmsg(s, ainv, b):
    n = len(s)
    msg = ['a']*n
    for i in range(n):
        if(s[i]==' '):
            msg[i] = ' '
        else:
            msg[i] = chr((ainv * (ord(s[i])-ord('A') - b+26) % 26) + ord('A'))
    print(''.join(msg))

def printmsgi(s, i):
    ainv = Ainv[i//26 + (i%26>0)-1]
    b = (i%26)
    printmsg(s, ainv, b)

Ainv = [1, 8, 21, 15, 3, 19, 7, 23, 11, 5, 17, 25]

ciphertxt = str(input())
Devoid = [0]*312
Weights = [0]*312
n = len(ciphertxt)

k=0
for i in range(12):
    for j in range(1,27):
        Devoid[k], Weights[k] = decrypt(ciphertxt, Ainv[i], j)
        k+=1

mini = 99999
for i in range(312):
    if Devoid[i]<mini:
        mini = Devoid[i]
        index = i
    if Devoid[i]<=mini+1:
        if Weights[i]<Weights[index]:
            index = i

print("A few possible decryptions are:")
print()

for i in range(312):
    if Devoid[i]<=mini+1 and Weights[i]<n*5:
        printmsgi(ciphertxt, i+1)

print()
print("A possible decryption is:")
print()
printmsgi(ciphertxt, index+1)
