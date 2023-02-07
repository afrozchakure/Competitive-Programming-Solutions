class MedianFinder {
public:
    priority_queue<int> maxHeap; 
    priority_queue<int, vector<int>, greater<int>> minHeap; 
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxHeap.size() == 0 || maxHeap.top() >= num) {
            maxHeap.push(num); 
        } else {
            minHeap.push(num); 
        }
        balance(); 
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()) {  
            return maxHeap.top(); 
        } else if(maxHeap.size() < minHeap.size()) {
            return minHeap.top(); 
        } else {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
    }

    void balance() {
        if(minHeap.size() - maxHeap.size() > 1) {
            maxHeap.push(minHeap.top()); 
            minHeap.pop(); 
        } else if(maxHeap.size() - minHeap.size() > 1) {
            minHeap.push(maxHeap.top()); 
            maxHeap.pop(); 
        }
    }
};

// Time Complexity - O(klogN) 
// Space Complexity - O(k); // If you are adding k data streams 

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// Median formula 

// length is odd 
// 1   2   3   4  5  ====> median = 3 
    //     _ 

// 1   2   3   4  5  6  =====> (3 + 4) / 2 
//         _   _ 


// Approach -> The largest element in the Max Heap will be lower than minimum 
// element of Min heap

// Max Heap < Min Heap 

// 1. If no element in maxHeap (check size first), add element to maxHeap 
// 2. If element in maxHeap 
        // 2.1. Check if maxElement in MaxHeap < newElement, add in minHeap 
        // 2.2 Else Add in maxHeap 

// For median, take out top elements from minHeap and maxHeap and
// devide by 2 and return the answer 

// 3. Check (size of maxHeap + size of minHeap)
//     3.1. (size of maxHeap + size of minHeap) % 2 == 0 (even) take average 
//     3.2. (size of maxHeap + size of minHeap) % 2 == 1 (odd) return topmost element of minHeap 

// For Rebalancing (3 - 1 > 1) ... abs(minHeap_Size - MaxHeap_Size) > 1 
// Do it at difference of sizes of Heaps > 1
// Here remove the element from the one where there are more elements 
// and add it to other 

// if size of MinHeap == size of MaxHeap, then return the result



