n_strs = input().split(' ')
n = int(n_strs[0])

in_nums = []
in_nums_strs = input().split(' ')
for str in in_nums_strs:
    if ('' != str):
        in_nums.append(int(str))

in_nums.sort()

stones = []
for i in range(n):
    stones.append(in_nums[n - 1 - i])
    stones.append(in_nums[i])

sum = stones[0] * stones[0]
for i in range(1, n):
    sum += (stones[i] - stones[i - 1]) * (stones[i] - stones[i - 1])

print(sum)