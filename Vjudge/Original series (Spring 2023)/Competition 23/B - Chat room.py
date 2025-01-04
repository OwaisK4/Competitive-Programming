#!/usr/bin/python
import re

s = input()
reg = re.compile(r"(h)+.*(e)+.*(l)+.*(l)+.*(o)+")
mo = reg.search(s)
if mo == None:
    print("NO")
else:
    print("YES")
