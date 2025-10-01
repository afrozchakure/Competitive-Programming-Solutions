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
    // struct myComp {
    //     bool operator() (Interval &a, Interval &b) {
    //         return a.start < b.start; 
    //     }
    // };

    static bool myComp(const Interval &a, const Interval &b) {
        return a.start < b.start; 
    }

    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.empty()) return true; 
        sort(intervals.begin(), intervals.end(), myComp); 
        
        // sort(intervals.begin(), intervals.end(), myComp()); 

        // sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
        //     return a.start < b.start; 
        // });

        int prevEnd = intervals[0].end; 

        for(int i=1; i<intervals.size(); i++) {
            if(prevEnd <= intervals[i].start) {
                prevEnd = intervals[i].end; 
                continue; 
            } else {
                return false; 
            }
        }
        return true; 
    }
};


// All the sorting method results and functions work