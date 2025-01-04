def binpow(x : int, n : int) -> int:
    if (n == 0):
        return 1
    elif (n == 1):
        return x
    u = binpow(x, n // 2)
    u *= u
    if n % 2:
        u *= x
    return u

if __name__ == "__main__":
    n = int(input())
    if (n == 0):
        print(1)
    elif ((n - 1) % 4 == 0):
        print(8)
    elif ((n - 2) % 4 == 0):
        print(4)
    elif ((n - 3) % 4 == 0):
        print(2)
    else:
        print(6)
    # answer = binpow(1378, n) % 10
    # print(answer)