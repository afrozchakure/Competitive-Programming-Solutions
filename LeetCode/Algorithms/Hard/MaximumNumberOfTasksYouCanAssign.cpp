class Solution {
    public:
        bool canAssign(int mid, vector<int> &workers, vector<int> &tasks, int pills, int strength) {
            // it means that if mid = 2, we'll be taking the last two values in workers and putting them in multiset 
            multiset<int> usable_workers(workers.end() - mid, workers.end()); 

            // iterating from right to left 
            for(int i=mid-1; i>=0; i--) {
                auto curr_workers = --usable_workers.end(); 

                if(*curr_workers < tasks[i]) {
                    if(pills <= 0) return false; 
                    
                    // Optimal Strategy: Assign weakest worker to get the current task done 
                    auto weakest_worker = usable_workers.lower_bound(tasks[i] - strength); 

                    if(weakest_worker == usable_workers.end()) {
                        return false;  // no one can be assigned the current job (even using pill) 
                    }

                    pills--; 
                    usable_workers.erase(weakest_worker); 
                } else {
                    usable_workers.erase(curr_workers); 
                }
            }
            return true; 
        }

        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            sort(workers.begin(), workers.end()); 
            sort(tasks.begin(), tasks.end()); 

            int low = 0; 
            int high = min(tasks.size(), workers.size()); 
            int mid; 

            int assigned = 0; 
            while(low <= high) {
                mid = low + (high - low) / 2; 

                if(canAssign(mid, workers, tasks, pills, strength)) {
                    assigned = mid; 
                    low = mid + 1; 
                } else {
                    high = mid - 1; 
                }
            }
            
            return assigned;
        }
};

/*
Optimal Matchup Strategy 

Strategy - 1: Strong fights the weak 

Strategy - 2: Strong fights strong. (fair)  -- choose this one 

Ques: What if you have G > R or G < R 

Note: Sort to search optimal matchups faster 

Goal: Get more wins for green 

Note: 
Fights are only 1:1 
A person can only fight once 

1 7 6 
2 6 5 

Sorting: 

1. Remove the person who is the strongest in the opposite team


I.     
II.    2, (4, 5, 6) -> (N - M) workers ignore 

Sorted Asc: Strongest worker gets hardest job 
      0  1  2 
T[]: [6, 7, 7]   ,   Pill = 1,   Strength = 3 
W[]: [2, 5, 6]

Lower bound binary search: 
 
 0  1  2  3  4  5  6  7 
[1, 2, 2, 4, 4, 5, 7, 7]

lb(2) = 1 
lb(6) = 6 

// set shoudl not be used because the order is not unique 

multiset works well in this scenario since it preserves order
or
ordered_map

Max tasks to be done <= Max workers 

       0  1  2  3  4 
T[] : [7, 6, 8, 7, 9]    =>  T[]:  [6, 7, 7, 8, 9]
                                    <----    | ignore
       0  1  2                      0  1  2 
W[] : [6, 2, 5]          =>  W[]:  [2, 5, 6]

Strategy: Choose weakest M tasks 

If N < M then only N workers 

      0  1  
T[]: [6, 7] --> N
      
      0  1  2 
W[]: [2, 5, 6] --> M
ignore| 

M > N 

Note: R->L is imp to match strongest W[i] with toughest task 

Max No of Tasks: Similar to Leetcode's First Bad version probelm 

Goal: Find max tasks which can be done 
-> find the first bad version 

low = 0
high = min(N, M)
mid = low + (high - low) / 2 

if(canAssign(mid)) {
    assigned = mid; 
    love = mid + 1; 
} else {
    love = mid - 1; 
}

pick strongest worker and weakest task, so that we have change of completing the task 

Time Complexity -

W = min(N, M)

logW * W * logW 
= W(logW)**2 

Binary Search ---> Loop ---> lower bound on multiset


Total time Complexity - W(logW)^2 + NlogN + MlogM, tasks and workers array will also be sorted 
Space Complexity - O(W), due to multiset / map being used

W = min(N, M)
*/