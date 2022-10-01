class Solution {
public:
    struct Engineer {
        public:
        int speed; 
        int efficiency; 

        Engineer(int speed, int efficiency) {
            this->speed = speed; 
            this->efficiency = efficiency; 
        }
    }; 

    static bool compareEngineers(Engineer e1, Engineer e2) {
        if(e1.efficiency == e2.efficiency) {
            return e1.speed < e2.speed; 
        }
        return e1.efficiency > e2.efficiency;
    }

    struct CompareHeight {
        bool operator() (Engineer const& p1, Engineer const& p2) {
            if(p1.speed == p2.speed) {
                return p1.efficiency < p2.efficiency;
            }
            return p1.speed < p2.speed; 
        }
    };
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<Engineer> engineers; 

        for(int i=0; i<n; i++) {
            engineers.push_back(Engineer(speed[i], efficiency[i])); 
        }

        // now sort the engineers list by their efficiency descending 
        sort(engineers.begin(), engineers.end(), compareEngineers); 

        // will keep the slowest members at the top, fastest ones stay in the team longest 
        priority_queue<Engineer, vector<Engineer>, CompareHeight> currentTeam;

        long teamSpeed = 0; 
        long maxPerformance = 0; 

        for(Engineer newHire: engineers) {
            if(currentTeam.size() == k) {
                // we must evict the slwoest engineer from out current team 
                Engineer slowGuy = currentTeam.top(); 
                currentTeam.pop(); 
                // now we must remove the slow guys speed from our total speed 
                teamSpeed -= slowGuy.speed; 
            }

            // hire the new guy to the team 
            currentTeam.push(newHire); 

            // so pickup the new engineers speed and add it to the current teams speed 
            teamSpeed += newHire.speed; 

            // Minimum would be new hire effici (don't need to worry about getting minimum efficiency)
            long performanceWithNewGuy = teamSpeed * (long) newHire.efficiency; 
            maxPerformance = max(maxPerformance, performanceWithNewGuy); 
            cout<<maxPerformance<<endl;
        }

        return (int) (maxPerformance % 1000000007);


    }
};
//  k 
// speed 
// efficiency 

// k different engineers out of n to form team of maximum performance 

// performance = sum(speeds * minimum effciency(team)); 

// return maximum performance of the team 

// Performance of a team = (S1 + s2 + s3 + ... + sk) * MIN(E1, E2, E2, ... Ek)

// Select K Most experienced ones first Sort based on Efficiency 
// Priority Queue<Engineer> with comparator based on speed. 
// Lowest will be pulled out first

// Time complexity - O(NlogN) 
// Space Complexity - O(N), N is the number of engineers in the input array 