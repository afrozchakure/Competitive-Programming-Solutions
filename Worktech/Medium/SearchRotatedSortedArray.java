class SearchRotatedSortedArray {
	int getElementIndex(int[] A, int target) {
		int low = 0, high = A.length - 1;
		while(low < high){
			int mid = low + (high - low ) / 2;
			if(A[mid] == target) return mid;
			
			// sorted 
			if(A[low] <= A[mid]){
				// sorted low, target, mid
				if(target >= A[low] && target < A[mid]){
					high = mid - 1;					
				}else{ // target is beyond mid
					low = mid + 1;
				}
			}else{
				if(target > A[mid] && target <= A[high]){
					low = mid + 1;
				}else{
					high = mid -1;
				}
			}
			
		}
		return A[low] == target ? low : -1;
	}
}
