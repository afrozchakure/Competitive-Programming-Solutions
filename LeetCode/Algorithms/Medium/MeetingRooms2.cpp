/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

 class Solution {
    public:
        int minMeetingRooms(vector<Interval>& intervals) {
            vector<int> start, end; 
            for(int i=0; i<intervals.size(); i++) {
                start.push_back(intervals[i].start); 
                end.push_back(intervals[i].end); 
            }

            sort(start.begin(), start.end()); 
            sort(end.begin(), end.end());  
            
            int start_index = 0, end_index = 0; 
            int count = 0; 
            int result = 0; 
            while(start_index < intervals.size()) {
                if(start[start_index] < end[end_index]) {
                    start_index++; 
                    count++; 
                } else {
                    end_index++; 
                    count--; 
                }

                result = max(result, count); 
            }

            return result; 
        }
    };
    