#define pii pair<int, int> 
class Solution {
    public:
        struct myComp {
            bool operator() (pair<int, int> &a, pair<int, int> &b) {
                if(a.first == b.first) {
                    return a.second < b.second; 
                }
                return a.first > b.first; 
            }
        };
        
        vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
            sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
                return a[0] < b[0]; 
            }); 

            vector<int> sorted_query = queries; 
            sort(sorted_query.begin(), sorted_query.end()); 

            // priority_queue<int, vector<int>, greater<int>> pq; 
            priority_queue<pii, vector<pii>, myComp> pq; 

            int i = 0; 
            unordered_map<int, int> m; 
            for(auto &q: sorted_query) {
                // adding all the intervals 
                while(i < intervals.size() && intervals[i][0] <= q) {
                    auto &temp = intervals[i]; 
                    int l = temp[0]; 
                    int r = temp[1]; 
                    pq.push({(r - l + 1), r});
                    i++; 
                }
                
                // removing invalid intervals from 
                // priority queue
                while(!pq.empty() && pq.top().second < q) {
                    pq.pop(); 
                }

                if(!pq.empty()) {
                    m[q] = pq.top().first; 
                } else {
                    m[q] = -1; 
                }
            }

            vector<int> result; 
            for(auto &q: queries) {
                result.push_back(m[q]); 
            }
            return result; 
        }
};

// Time Complexity - O(nlogn + qlogq), 
// q is length of queries 
// n is the lenght of intervals