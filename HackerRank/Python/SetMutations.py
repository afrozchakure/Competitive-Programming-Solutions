# .update() or |=

# Update the set by adding elements from an iterable/another set.
# >>> H = set("Hacker")
# >>> R = set("Rank")
# >>> H.update(R)
# >>> print H
# set(['a', 'c', 'e', 'H', 'k', 'n', 'r', 'R'])

# .intersection_update() or &=

# Update the set by keeping only the elements found in it and an iterable/another set.
# >>> H = set("Hacker")
# >>> R = set("Rank")
# >>> H.intersection_update(R)
# >>> print H
# set(['a', 'k'])

# .difference_update() or -=

# Update the set by removing elements found in an iterable/another set.
# >>> H = set("Hacker")
# >>> R = set("Rank")
# >>> H.difference_update(R)
# >>> print H
# set(['c', 'e', 'H', 'r']

# .symmetric_difference_update() or ^=

# Update the set by only keeping the elements found in either set, but not in both.
# >>> H = set("Hacker")
# >>> R = set("Rank")
# >>> H.symmetric_difference_update(R)
# >>> print H
# set(['c', 'e', 'H', 'n', 'r', 'R']

if __name__ == '__main__':

    A = int(input())
    A_element = set(map(int, input().split()))
    N = int(input())

    for x in range(N):
        operation_length = list(input().split())
        N_element = set(map(int, input().split()))
        if operation_length[0] == 'intersection_update':
            A_element.intersection_update(N_element)
        elif operation_length[0] == 'update':
            A_element.update(N_element)
        elif operation_length[0] == 'symmetric_difference_update':
            A_element.symmetric_difference_update(N_element)
        elif operation_length[0] == 'difference_update':
            A_element.difference_update(N_element)
    sum_A = 0 
    for x in A_element:
        sum_A += x
    print(sum_A)
    
# N performs some operations on set A
    