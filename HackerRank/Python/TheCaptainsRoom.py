
if __name__ == '__main__':
    K = int(input())
    list_elements = list(map(int, input().split()))
    set_elements = set(list_elements)
    captains_roomno = (((sum(set_elements)* K - sum(list_elements))// (K - 1)))
    print(captains_roomno, end = '')

# Input 
# 5
# 1 2 3 6 5 4 4 2 5 3 6 1 6 5 3 2 4 1 2 5 1 4 3 6 8 4 3 1 5 6 2 

# Ouput (find the unique element from it)
# 8