class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<double, vector<double>, greater<double>> min_heap;
        
        for(int i=0; i<speed.size(); i++)
        {
            min_heap.push(ceil((double)dist[i] / speed[i]));
        }
        
        int current_time = 0;
        int ans = 0;
        for(int i=0; i<speed.size(); i++)
        {
            if(current_time < min_heap.top())
            {
                min_heap.pop();
                ans++;
            }
            else
            {
                return ans;
            }
            current_time++;
        }
        return ans;
        
    }
};

// Time Complexity - O(NlogN)
// Space Complexity - O(N), we're using a min_heap
