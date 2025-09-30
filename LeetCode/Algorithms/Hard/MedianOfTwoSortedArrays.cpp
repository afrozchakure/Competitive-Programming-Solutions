class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            vector<int> A = nums1, B = nums2; 

            int total = nums1.size() + nums2.size(); 
            int half = total / 2; 

            if(B.size() < A.size()) {
                swap(A, B); 
            }

            // log(min(n, m))
            int l = 0, r = A.size() - 1; 
            while(true) {
                int i = (l + r) / 2;  // for A 
                int j = half - i - 2; // B 

                // A -> Aright 
                // B -> Bleft 

                // A -> Aleft 
                // B -> Bright 
                int Aleft = (i >= 0) ? A[i] : INT_MIN;
                int Aright = (i + 1) < A.size() ? A[i + 1] : INT_MAX; 
                int Bleft = (j >= 0) ? B[j] : INT_MIN; 
                int Bright = (j + 1) < B.size() ? B[j + 1] : INT_MAX; 

                // parition is correct 
                if(Aleft <= Bright && Bleft <= Aright) {
                    // if odd 
                    if(total % 2) {
                        return min(Aright, Bright); 
                    }
                    // even 
                    return (max(Aleft, Bleft) + min(Bright, Aright)) / 2; 
                } else if(Aleft > Bright)
                    r = i - 1; 
                } else if(Bleft > Bright) {
                    l = i + 1; 
                }
            }
        }
};