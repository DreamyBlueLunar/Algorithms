nums = []
candies = []
in_str = list(input().split(" "))
sum = 0
for str in in_str:
    if ('' != str):
        nums.append(int(str))
n = nums[0]
x = nums[1]

in_str = list(input().split(" "))
for str in in_str:
    if ('' != str):
        candies.append(int(str))

if (candies[0] > x):
    sum += candies[0] - x
    candies[0] = x

for i in range(1, n):
    if (candies[i - 1] + candies[i] > x):
        sum += (candies[i - 1] + candies[i] - x)
        candies[i] = (x - candies[i - 1])

print(sum)