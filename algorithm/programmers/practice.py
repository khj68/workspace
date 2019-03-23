from collections import Counter, defaultdict
a = Counter('blue')
b = Counter('yellow')

print(a)
print(b)
print((a+b).most_common(4))

my_dict = defaultdict(lambda : 'What the')
print(my_dict['a'])
print(my_dict['b'])

a, **b = [2, {'a':8}]
print(a)
print(b)