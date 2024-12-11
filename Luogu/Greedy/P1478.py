nums = []
in_str = list(input().split(" "))
for str in in_str:
    if ('' != str):
        nums.append(int(str))
n = nums[0]
s = nums[1]

nums.clear()
in_str.clear()
in_str = list(input().split(" "))
for str in in_str:
    if ('' != str):
        nums.append(int(str))
height = nums[0] + nums[1]

apples = []
for i in range(n):
    apple = []
    print(apple)
    in_str = list(input().split(" "))
    for str in in_str:
        if ('' != str):
            apple.append(int(str))
    apples.append(apple)

    if (apple[0] <= height):
        apples.append(apple)

apples.sort(key=lambda x: x[1], reverse=False)

cnt = 0
for i in range(len(apples)):
    if (s - apples[i][1] >= 0):
        cnt += 1
        s -= apples[i][1]
    else:
        break

print(cnt)