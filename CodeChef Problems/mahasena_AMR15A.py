try:
    a = int(input())
    for i in range(a):
        weapon = list(map(int, input().split()))
        even_no = [i for i in weapon if i%2 == 0]
        odd_no = [j for j in weapon if j%2 == 1]
        
        if(len(even_no) <= len(odd_no)):
            print("NOT READY")
        else:
            print("READY FOR BATTLE")
except Exception:
    pass
