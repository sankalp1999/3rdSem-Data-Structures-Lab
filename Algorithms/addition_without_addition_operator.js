def add(a, b):
  while(b!=0):
    u = a^b
    v = a&b
    a = u
    b = v << 1
  
  return a
print(add(2,5))
