bunches = []

input_str = input()
n, t = map(int, input_str.split(" "))

for i in range(n):
    input_str = input()
    m, v = map(float, input_str.split(" "))
    bunches.append([m, v, v / m])

bunches.sort(key = lambda x: x[2], reverse = True)

sum = 0.0
for bunch in bunches:
    if (t <= 0):
        break
    weight = bunch[0] if t - bunch[0] >= 0 else t
    sum += weight * bunch[2]
    t -= bunch[0]

print(f"{sum:.2f}")