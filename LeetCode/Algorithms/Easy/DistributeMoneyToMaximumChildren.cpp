class Solution {
public:
    int distMoney(int money, int children) {
        money = money - children; 

        if(money < 0) {
            return -1; 
        }

        if(money / 7 == children && money % 7 == 0) {
            return children 
        } 

        if(money / 7 == children - 1 && money % 7 == 3) {
            return children - 2; 
        } 

        return min(children - 1, money / 7); 
    }
};

// money = 20, children = 3
// Output: 1

// money = 16, children = 2
// Output: 2

// 20 - 3 = 17
// 17 / 7 = 2... 
// 17 % 7 == 3 