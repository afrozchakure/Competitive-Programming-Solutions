bool compare(vector<int> &a, vector<int> &b) {
    return a[0] < b[0]; 
}
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), compare); 

        // engaged meetings - {current_meeting_time, room}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> engaged; 

        // unused - {meetng_room}
        priority_queue<int, vector<int>, greater<int>> unused; 
        
        unordered_map<int, int> freq; 

        for(int i=0; i<n; i++) {
            unused.push(i); 
        }

        for(auto &x: meetings) {
            int start = x[0]; 
            int end = x[1]; 

            // remove the meetings that have already ended from engaged heap and add them in unused
            while(engaged.size() > 0 && engaged.top().first <= start) {
                int room = engaged.top().second; 

                engaged.pop(); 
                unused.push(room); 
            }

            // unused
            if(unused.size() > 0) {
                int room = unused.top(); 
                unused.pop(); 

                freq[room]++; 
                engaged.push({end, room});
            }
            // engaged 
            else {
                auto temp = engaged.top(); 
                engaged.pop(); 
                long long newEnd = temp.first; 
                int room = temp.second; 
                freq[room]++; 
                newEnd += end - start; 

                engaged.push({newEnd, room}); 
            }
        }

        int maxi = 0; 
        for(int i=1; i<n; i++) {
            if(freq[i] > freq[maxi]) {
                maxi = i; 
            }
        }
        return maxi; 

    }
};

// Time Complexity - MlogM + MlogN, where M is the number of meetings 
// N is the number of rooms 
// Space Complexity - O(n), since we using priority-queue

