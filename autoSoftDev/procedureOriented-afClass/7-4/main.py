week = input().split(" ")
new = []
number1 = int(input())
number2 = int(input())
for i in range(len(week)):
    if '-' in week[i]:
        for j in range(int((week[i].split('-'))[0]),int((week[i].split('-'))[1])+1):
            new.append(j)
    else:
        new.append(int(week[i]))

if number1 not in new or number2 in new:
    print("not available") 

else:
    new.remove(number1)
    new.append(number2)
    new.sort()
    flag = 0
    for i in range(len(new)):
        if i<len(new)-1:
            if new[i]+1 == new[i+1]:
                if flag == 0:
                    print(new[i],end="-")
                flag = 1
            else:
                print(new[i],end=" ")
                flag = 0
        else:
            print(new[i])