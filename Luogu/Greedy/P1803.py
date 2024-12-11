import sys
input = sys.stdin.readline
print = sys.stdout.write

n = int(input())

contests = []

for i in range(n):
    begin, end = map(int, input().split(" "))
    contests.append([begin, end])

contests.sort(key=lambda x: x[1], reverse=False)

i = 0
cnt = 1
for j in range(n):
    if (contests[j][0] >= contests[i][1]):
        cnt += 1
        i = j

print(str(cnt))