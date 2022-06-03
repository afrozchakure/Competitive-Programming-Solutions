
class Solution {
    public String largestWordCount(String[] messages, String[] senders) {
        HashMap<String, Integer> map = new HashMap<String, Integer>(); 
        
        for(int i=0; i<messages.length; i++) {
            String[] part = messages[i].split(" "); 
            
            // check this line to merge changes faster in a map
            map.merge(senders[i], part.length, Integer::sum); 
        }
        
        int count = 0; 
        String answer = ""; 
        
        // Also breaking this into 2 loops is a better idea than iterating in a single loop
        for(int v: map.values()) {
            count = Math.max(count, v); 
        }
        
        for(String m: map.keySet()) {
            if(count == map.get(m)) {
                if(answer.compareTo(m) < 0) {
                    answer = m; 
                }
            }
        }
        return answer; 
    }
}

// Time Complexity - O(N)
// Space Complexity - O(N)

// My solution from competition, was close read the problem incorrectly 
class Solution {
    public String largestWordCount(String[] messages, String[] senders) {
        HashMap<String, ArrayList<String>> map = new HashMap<String, ArrayList<String>>(); 
        
        for(int i=0; i<messages.length; i++) {
            String[] part = messages[i].split(" "); 
            if(map.containsKey(senders[i])) {
                map.get(senders[i]).addAll(Arrays.asList(part));
            } else {
                map.put(senders[i], new ArrayList<>(Arrays.asList(part))); 
            }
        }
        
        int count = 0;
        String answer = "";
        for(Map.Entry<String, ArrayList<String>> m: map.entrySet()) {
            if(count < m.getValue().size()) {
                count = m.getValue().size();
                answer = new String(m.getKey());
            }
            if(count == m.getValue().size()) {
                if(m.getKey().compareTo(answer) > 0) {
                    answer = new String(m.getKey());
                }
            }
        }
        return answer;
    }
}

// Time Complexity - O(N)
// Space Complexitu - O(N)