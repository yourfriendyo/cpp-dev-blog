a = 1
print(f"a = {f'{a} + a'}")

b = 'hello'
print(b)

c = True
print(c)

a = input('请输入一个整数->')
print(f"您输入的数字是 {a}")

b = input('请输入一个整数->')
print(f"您输入的数字是 {b}")

print(type(a))
print(type(b))

a = int(a)
b = int(b)

print(a + b)

a = str(a)
b = str(b)

print(a + b)

a = input('请输入第一个数字')
b = input('请输入第二个数字')
c = input('请输入第三个数字')
d = input('请输入第四个数字')

a = float(a)
b = float(b)
c = float(c)
d = float(d)

avg = (a + b + c + d) / 4
print(f"平均值是 {avg}")
