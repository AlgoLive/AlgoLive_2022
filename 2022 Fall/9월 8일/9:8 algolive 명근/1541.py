line = input()
a = line.split('-')
ans = 0
print(a)
c =[]
for i in a:
    b = i.split('+')
    c.append(sum([int(x) for x in b]))

ans = c[0]
print(c)
c = c[1:]
for x in c:
    ans = ans-x

print(ans)