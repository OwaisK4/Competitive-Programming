def solve():
    n: int
    n = int(input())
    s: str
    s = input()

    sz = len(s)
    f = False

    if s == "the":
        f = True
    else:
        # for (int i = 0; i < sz; i++) {
        for i in range(0, sz):
            if i + 4 < sz and " the " in s:
                f = True
            # if (i == 0 && i + 3 < sz && s.substr(i, 4) == "the ") {
            if i == 0 and i + 3 < sz and s.startswith("the"):
                f = True
            # if (i + n == sz - 1 && s.substr(i, 4) == " the") {
            if i + n == sz - 1 and s.endswith("the"):
                f = True

    # for (int i = 0; i < sz; i++) {
    for i in range(0, sz):
        if s[i] == " ":
            continue

        if f:
            if s[i] - chr(n) >= "a":
                s[i] -= n
            else:
                x = n - (s[i] - "a")
                s[i] = "z"
                x -= 1
                s[i] -= x
        else:
            if s[i] + n <= "z":
                s[i] += n
            else:
                x = n
                x = n - ("z" - s[i])
                s[i] = "a"
                x -= 1
                s[i] += x

    print(s)
    # cout << s << endl;


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        solve()
