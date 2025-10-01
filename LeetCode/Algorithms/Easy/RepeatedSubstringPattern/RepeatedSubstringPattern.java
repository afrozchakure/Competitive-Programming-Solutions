class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int len = s.length();
        
        for(int i = len/2; i >=1 ; i--){
            
            if(len % i == 0){ // if String can be divisible within half a length or 1
                
                int repeats = len/i;
                String subString = s.substring(0, i);
                
                StringBuilder sb = new StringBuilder();
                
                for(int j = 0; j < repeats ; j++){
                    sb.append(subString);
                }
                
                if(sb.toString().equals(s))
                    return true;
            }
        }
        return false;
    }
}
