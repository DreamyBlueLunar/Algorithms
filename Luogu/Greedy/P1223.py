que = []

n = int(input())

que_str = input()
input_nums = []
for num_str in que_str.split(" "):
    if (num_str == ''):
        break
    input_nums.append(int(num_str))

for i in range(n):
    que.append([input_nums[i], i + 1])

que.sort(key=lambda x: x[0], reverse=False)

sum = 0.0
for i in range(n):
    sum += (n - i - 1) * que[i][0]
sum /= n

for elm in que:
    print(elm[1], end=" ")
print()
print(f"{sum:.2f}")
