#!/usr/bin/env python3
n = int(input())
count_a = 0
sum_a = 0
for i in range(n):
    x = list(map(int, input().split()))
    sum_a = sum(x)
    if(sum_a == 2 or sum_a == 3):
        count_a += 1
print(count_a)
    