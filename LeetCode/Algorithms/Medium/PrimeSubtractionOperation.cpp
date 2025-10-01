class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        
        int prev = 0; 

        // O(n * m * sqrt(m))
        for(auto &n : nums) {
            int upper_bound = n - prev; // non-inclusive [2, n)
            int largest_p = 0;

            for(int i=upper_bound-1; i>=2; i--) {
                if(is_prime(i)) {
                    largest_p = i; 
                    break;
                }
            }

            if((n - largest_p) <= prev) {
                return false; 
            }

            prev = n - largest_p;

        }
    }

    bool isPrime(int n) {
        for(int i=2; i<pow(n, 0.5) + 1; i++) {
            if(n % i == 0) {
                return false; 
            }
        }
        return true; 
    }
};

// Time Complexity - O(N * M * sqrt(M))
// Space Complexity - O(N)

// 1. nums[i-1] < nums[i] - p < nums[i + 1]
// 2. If nums[i] - p < nums[i - 1]
//    should we backtrack?
// 3. Greedy: make each num as small as possible 
//    from the get go