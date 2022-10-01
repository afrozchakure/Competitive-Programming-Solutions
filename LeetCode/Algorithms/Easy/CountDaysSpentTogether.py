class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        alice_arrive_month = int(arriveAlice[0:2])
        alice_arrive_day = int(arriveAlice[3:])
        bob_arrive_month = int(arriveBob[0:2] )
        bob_arrive_day = int(arriveBob[3:] )
        
        alice_leave_month = int(leaveAlice[0:2] )
        # print(alice_leave_day)
        alice_leave_day = int(leaveAlice[3:])
        bob_leave_month = int(leaveBob[0:2] )
        bob_leave_day = int(leaveBob[3:] )
        count = 0
        
        b = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        if(arriveAlice == arriveBob and leaveBob == leaveAlice): 
            # print("Equal")
            if(alice_arrive_month == bob_leave_month): 
                # print("Equal1")
                return alice_leave_day - alice_arrive_day + 1
            else: 
                # print("equal2")
                count += b[alice_arrive_month - 1] - alice_arrive_day + 1
                for i in range(alice_arrive_month + 1, alice_leave_month): 
                    count += b[i-1]
                count += alice_leave_day
                return count
            
        
        # if(bob_arrive_month > alice_arrive_month) 
        
        
        if((arriveAlice < arriveBob and leaveAlice < arriveBob) or (arriveBob < arriveAlice and leaveBob < arriveAlice)): 
            # print("1")
            return 0 
        
        
        # when either arrive between arrival and stop
        if(arriveBob > arriveAlice and leaveBob < leaveAlice): 
            # print("2")
            if(bob_leave_month == bob_arrive_month): 
                return bob_leave_day - bob_arrive_day + 1
            else:
                # print("3")
                count += b[bob_arrive_month-1] - bob_arrive_day + 1
                for i in range(bob_arrive_month + 1, bob_leave_month):
                    count += (b[i -1]) 
                count += bob_leave_day 
                return count
        elif(arriveAlice > arriveBob and leaveAlice < leaveBob): 
            # print("4")
            if(alice_leave_month == alice_arrive_month): 
                # print("5")
                # print("leave day: "  + str(alice_leave_day))
                return alice_leave_day - alice_arrive_day + 1
            else:
                # print("6")
                count += (b[alice_arrive_month -1] - alice_arrive_day)  + 1
                for i in range(alice_arrive_month + 1, alice_leave_month):
                    count += (b[i -1]) 
                count += alice_leave_day
                return count
            
        # tested 
        # arriveAlice = "08-15", leaveAlice = "08-18", 
        # arriveBob = "08-16", leaveBob = "08-19"
        if(arriveBob < leaveAlice and leaveAlice < leaveBob): 
            # print("7")
            if(bob_arrive_month == alice_leave_month): 
                print("8")
                return alice_leave_day - bob_arrive_day + 1
            else: 
                # print("9")
                count += b[bob_arrive_month-1] - bob_arrive_day + 1
                for i in range(bob_arrive_month + 1, alice_leave_month): 
                    count += (b[i -1]) 
                count += alice_leave_day
                return count 
        
# "08-06" --> 
# "12-08"  
# "02-04"
# "09-01" --> 
        if(arriveAlice < leaveBob and leaveBob < leaveAlice): 
            # print("10")
            if(alice_arrive_month == bob_leave_month): 
                # print("11")
                return bob_leave_day - alice_arrive_day + 1
            else: 
                # print("12")
                count += b[alice_arrive_month-1] - alice_arrive_day + 1
                for i in range(alice_arrive_month + 1, bob_leave_month): 
                    count += (b[i -1]) 
                count += bob_leave_day
                return count 
        
                
        
            
        
        
"01-01"
"12-31"
"01-01"
"12-31"
                
        
            
        