MOD = 10**9 + 7


def binmult(a, b):
    if b == 0:
        return 0
    answer = binmult(a, b // 2) % MOD
    answer = (answer * 2) % MOD
    if b % 2 == 1:
        answer = (answer + a) % MOD
    return answer


def multiply(A, B, n):
    temp = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                A[i][k] %= MOD
                B[k][j] %= MOD
                value = binmult(A[i][k], B[k][j])
                temp[i][j] = (temp[i][j] + value) % MOD
    for i in range(n):
        for j in range(n):
            A[i][j] = temp[i][j] % MOD


def matrixExponentiation(T, initial, n):
    size = len(T)
    result = [[1 if i == j else 0 for j in range(size)] for i in range(size)]

    while n > 0:
        if n % 2 == 1:
            multiply(result, T, size)
        multiply(T, T, size)
        n //= 2

    multiply(result, initial, size)
    print(result[0][0])


def solve():
    n = int(input())
    if n < 2:
        print(n)
        return
    T = [[1, 1], [1, 0]]
    initial = [[1, 0], [0, 0]]
    matrixExponentiation(T, initial, n - 1)


if __name__ == "__main__":
    solve()
