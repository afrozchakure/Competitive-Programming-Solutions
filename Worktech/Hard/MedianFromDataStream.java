package Hard;

import java.util.*;
class MedianCalculator {
    /** initialize your data structure here. */
    PriorityQueue<Integer> minHeap = new PriorityQueue<>((a,b) -> a - b);
	PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a,b) -> b - a);
	boolean isEven = true; // for zero elements
	
	public MedianCalculator() {
		
		
    }
    
    public void addNum(int num) {
		if(isEven){
			maxHeap.offer(num);
			minHeap.offer(maxHeap.poll());
		}else{
			minHeap.offer(num);
			maxHeap.offer(minHeap.poll());
		}
		isEven = !isEven;
    }
    
    public float getMedian() {
    	if(isEven){
			return (minHeap.peek() + maxHeap.peek()) / 2f;
		}else{
			return minHeap.peek();
		}
	}
}

/**
 * Your MedianCalculator object will be instantiated and called as such:
 * MedianCalculator obj = new MedianCalculator();
 * obj.addNum(num);
 * float median = obj.getMedian();
 */

