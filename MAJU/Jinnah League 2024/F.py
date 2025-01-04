import sys

# sys.stdin = open("paint.in", "r")
# sys.stdout = open("paint.out", "w")

n = 101
arr = [0 for i in range(n)]
a, b = list(map(int, input().split()))
c, d = list(map(int, input().split()))

for i in range(a, b):
    arr[i] = 1

for i in range(c, d):
    arr[i] = 1

answer = sum(arr)
print(answer)
