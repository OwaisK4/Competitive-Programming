t = int(input())

for _ in range(t):
    hc, dc = map(int, input().split())
    hm, dm = map(int, input().split())
    k, w, a = map(int, input().split())

    valid = False
    for i in range(k + 1):
        upgraded_hc = hc + (i * a)
        upgraded_dc = dc + ((k - i) * w)
        if (upgraded_hc + dm - 1) // dm >= (hm + upgraded_dc - 1) // upgraded_dc:
            valid = True
            break
    if valid:
        print("YES")
    else:
        print("NO")
