class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> store = new HashMap<>(); 

        for(String path: paths) {
            String[] arr = path.split(" "); 
            String directory = arr[0]; 

            for(int i=1; i<arr.length; i++) {
                // fileName(content)
                String fileName = arr[i].substring(0, arr[i].indexOf("(")); 
                String content = arr[i].substring(arr[i].indexOf("(") + 1, arr[i].length() - 1); 
                List<String> filepaths = store.getOrDefault(content, new ArrayList<>()); 
                filepaths.add(directory + "/" + fileName); 
                store.put(content, filepaths); 
            }
        }       

        store.entrySet().removeIf(entry -> entry.getValue().size() < 2); 

        return new ArrayList<>(store.values()); 
    }
}
// Time Complexity - O(N * L), where N is the number of path and L is the average length we need to iterate
// Space Complexity 