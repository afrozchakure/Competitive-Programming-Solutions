def gap(g, m, n):
    start = 0
    end = 0
    for i in range(m,n+1):
      if is_prime(i):
        print (i)
        if start == 0:
          start = i
        elif end == 0:
          end = i
        else:
          start = end
          end = i
      if end - start == g:
        return [start, end]
    return None

def is_prime(n):
  if n <= 0 or n == 1:
    return False
  i = 2
  while (i <= n ** 0.5 ):
    if n % i == 0:
      return False
    i += 1
  return True
