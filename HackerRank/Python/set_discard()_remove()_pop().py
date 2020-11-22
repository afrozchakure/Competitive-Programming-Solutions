def pop_fun(sets):
    sets.pop()
def discard_fun(sets, num):
    sets.discard(num)
def remove_fun(sets, num):
    sets.remove(num)
if __name__ == '__main__':
    n = int(input())
    s = set(map(int, input().split()))
    N = int(input()) # no. of commands
    for i in range(N):
        cmd_list = list(input().split())
        if cmd_list[0] == 'pop':
            pop_fun(s)    
        elif cmd_list[0] == 'discard':
            discard_fun(s, int(cmd_list[1]))
        elif cmd_list[0] == 'remove':
            remove_fun(s, int(cmd_list[1]))
    sum = 0
    for i in s:
        sum = sum + i
    print(sum, end = '')

# Input

# 9
# 1 2 3 4 5 6 7 8 9
# 10
# pop
# remove 9
# discard 9
# discard 8
# remove 7
# pop 
# discard 6
# remove 5
# pop 
# discard 5

# Output:

# 4