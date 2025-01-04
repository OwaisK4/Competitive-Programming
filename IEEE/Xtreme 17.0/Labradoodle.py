n, m = [int(i) for i in input().split()]

dictionary = []
for i in range(n):
    word = input()
    dictionary.append(word)

blended = []
for i in range(m):
    word = input()
    blended.append(word)

answers = []

for word in blended:
    if len(word) < 5:
        print("none")
        continue
    prefix = word[:3]
    suffix = word[len(word) - 3 :]

    prefix_possible = []
    suffix_possible = []
    for possible in dictionary:
        if possible.startswith(prefix):
            prefix_possible.append(possible)
    for possible in dictionary:
        if possible.endswith(suffix):
            suffix_possible.append(possible)

    total = []
    for prefix in prefix_possible:
        for suffix in suffix_possible:
            cnt = 0
            if len(total) > 1:
                break

            answers = [-1 for i in range(len(word))]
            i = 0
            j = 0
            while i < len(word) and j < len(prefix):
                if answers[i] == 1:
                    break
                elif word[i] == prefix[j]:
                    answers[i] = 1
                    i += 1
                    j += 1
                    cnt += 1
                else:
                    break
            i = len(word) - 1
            j = len(suffix) - 1

            while i >= 0 and j >= 0:
                if answers[i] == 1:
                    break
                elif word[i] == suffix[j]:
                    answers[i] = 1
                    i -= 1
                    j -= 1
                    cnt += 1
                else:
                    break

            # if answers.count(-1) == 0:
            if cnt == len(word):
                # print("Count = ", cnt)
                total.append((prefix, suffix))
            else:
                continue
        if len(total) > 1:
            break

    if len(total) > 1:
        print("ambiguous")
    elif len(total) == 0:
        print("none")
    else:
        print(" ".join(*total))
