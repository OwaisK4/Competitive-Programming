names = ["Danil", "Olya", "Slava", "Ann", "Nikita"]

s = input()
count : int = 0

for i in names:
    a = s.count(i)
    count += a

# print(count)
if count == 1:
    print("YES")
else:
    print("NO")