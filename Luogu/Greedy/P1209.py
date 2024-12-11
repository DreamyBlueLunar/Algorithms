# P1209.py

arr = []
in_str = list(input().split(' '))
for str in in_str:
    if ('' != str):
        arr.append(int(str))
n = arr[0]
m = arr[1]

arr = []
for i in range(m):
    milk = []
    in_str = list(input().split(' '))
    for str in in_str:
        if ('' != str):
            milk.append(int(str))
    arr.append(milk)

arr.sort(key=lambda x: x[0], reverse=False)

sum = 0
for i in range(m):
    if (n <= 0):
        break
    if (n - arr[i][1] >= 0):
        sum += arr[i][0] * arr[i][1]
    else:
        sum += arr[i][0] * n
    n -= arr[i][1]

print(sum)