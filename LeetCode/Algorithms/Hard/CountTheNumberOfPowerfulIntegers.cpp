class Solution {
    public:
        vector<int> powerfulIntegers(int x, int y, int bound) {

        }
};


/*

16 digit 

10^15 >> 10^8 

pow(10^15, 0.5) == logN ~ 10^8

Observations 

1. Start < Finish,  example: s = 1500, finish = 1234 

s may not be < finish 

Start can be either <= or > 's' 

2. s[i] <= limit 

But this is not necessarily true for start & finish 

example start = 142 
finish = 24638
limit = 4 
s = 214 

3. max no <= 16 digits 
finish is max No 
finish <= 10^15 

Idea

start = 15 
finish = 2134 
limit = 7 
s = 10 

Goal: find all nos from start to finish with 's' as suffix 
ex: 110, 210, 2110, 410, etc 

{count start -> finish} = count (1 -> finish) - count (1 -> start) 
= x - y 

count(15, 2134) = count(1, 2134) - count(1, 14)  = 18 - 1 
 = 17 

Boundary Cases: 

If start < s
then count(start, finish) = count(1, finish) 

example start = 8, s = "10" 

If finish < s then total count = 0 always 

Generating numbers: Digit-wise 



*/