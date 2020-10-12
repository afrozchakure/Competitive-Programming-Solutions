class Solution {
    public int bitwiseComplement(int N) {
        if(N ==0)
            return 1;
        int ans = 0;
        int mul = 1;
        while(N > 0){
            int curBit = N & 1;
            N >>= 1;
            ans += mul * (1 - curBit); // flipping zero and 1
            mul *= 2;
        }
        // O(LOG2(N))
        return ans;
    }
}
