s = ""
while True:
    s = input()
    if s == "ENDOFINPUT":
        break
    s = input()
    _ = input()
    # print(s)
    e = ""
    for i in s:
        if ord(i) < ord("A") or ord(i) > ord("Z"):
            e += i
            continue
        x = ord(i)
        x -= ord("A")
        x -= 5
        x = (x + 26) % 26
        e += chr(x + ord("A"))
    print(e)
