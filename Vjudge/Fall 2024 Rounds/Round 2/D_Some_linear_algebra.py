import sys

def solve():
    N = int(input())
    S = [[(i*N) + j for j in range(N)] for i in range(N)]
    # print(S)
    for i in range(N):
        l = list(map(int, input().split()))
        for j in range(N):
            S[i][j] = l[j]
    answer = 0
    for k in range(N):
        i = N - k - 1
        j = 0
        current = 0
        while i < N and j < N:
            current += S[i][j]
            i, j = i + 1, j + 1
        answer = max(answer, current)
    for k in range(N):
        i = 0
        j = k
        current = 0
        while i < N and j < N:
            current += S[i][j]
            i, j = i + 1, j + 1
        answer = max(answer, current)

    print(answer)
        
        
if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        solve()