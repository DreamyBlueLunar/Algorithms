in_str = input()
k = int(input())

n = []
for i in range(len(in_str)):
    if (in_str[i] >= '0' and in_str[i] <= '9'):
        n.append(int(in_str[i]))

while k:
    i = 0
    while i + 1 < len(n) and n[i] <= n[i + 1]:
        i += 1
    n.pop(i)
    k -= 1

while n[0] == 0 and len(n) > 1:
    n.pop(0)

for num in n:
    print(num, end='')
print()