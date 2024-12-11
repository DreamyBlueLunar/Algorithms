w = 0
in_str = list(input().split(" "))
for str in in_str:
    if ('' != str):
        w = int(str)

n = 0
in_str = list(input().split(" "))
for str in in_str:
    if ('' != str):
        n = int(str)

souvenirs = []
for i in range(n):
    in_str = list(input().split(" "))
    for str in in_str:
        if ('' != str):
            souvenirs.append(int(str))

souvenirs.sort(reverse=False)

i = 0
j = n - 1
groups = 0
while i < j:
    if souvenirs[i] + souvenirs[j] <= w:
        groups += 1
        i += 1
        j -= 1
    else:
        j -= 1
       
print(n - groups)