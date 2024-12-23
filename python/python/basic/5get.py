dist={'a':'A','b':'B','c':'C','d':'D','e':'E','f':'F','g':'G','h':'H'}

print(dist)

print("\ndist.get('a','not existing')\n")
print(dist.get('a','not existing'))
print("\ndist.get('z','not existing')\n")
print(dist.get('z','not existing'))

print("\n------------dist.setdefault('a','Z')-----------\n")
print(dist.setdefault('a','Z'))
print('\n')
print(dist)
print("\n---------------dist.setdefault('a','Z')----------\n")
print(dist.setdefault('z','Z'))
print('\n')
print(dist)
