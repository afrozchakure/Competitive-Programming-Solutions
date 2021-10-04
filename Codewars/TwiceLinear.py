def dbl_linear(n) : 
    list = [1] 
    x = 0
    y = 0
    
    while(len(list)<=n) : 
        a = 2*list[x] + 1 
        b = 3*list[y] + 1 
        
        if a>b : 
            list.append(b)
            y+= 1 
        elif a<b : 
            list.append(a)
            x += 1 
        else : 
            list.append(a)
            x += 1 
            y += 1
            
    return list[n]