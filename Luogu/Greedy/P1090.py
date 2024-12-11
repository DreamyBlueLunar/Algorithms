from queue import PriorityQueue

n = int(input())
in_str = input()
sum = 0
pq = PriorityQueue()
bunches_str = list(in_str.split(" "))
bunches = []

for i in range(n):
    if ('\0' == bunches_str[i]): break
    bunches.append(int(bunches_str[i]))

for bunch in bunches:
    pq.put(bunch)

while (pq.qsize() > 1):
    bunch_1 = pq.get()
    bunch_2 = pq.get()
    sum += (bunch_1 + bunch_2)
    pq.put(bunch_1 + bunch_2)

print(sum)
