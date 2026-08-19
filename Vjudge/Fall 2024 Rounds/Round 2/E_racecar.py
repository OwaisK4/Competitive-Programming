import sys

n = int(input())
S = ["" for i in range(n)]
for i in range(n):
    S[i] = input()

# print(S)

for i in range(0, n-1):
    for j in range(0, n):
        if (i == j):
            continue
        p = S[i] + S[j]
        if p == p[::-1]:
            print("Yes")
            sys.exit(0)
print("No")