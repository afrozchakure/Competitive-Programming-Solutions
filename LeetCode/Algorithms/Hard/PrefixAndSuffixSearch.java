// Doesn't work
class WordFilter {
    Trie prefix = null; 
    Trie suffix = null; 
    public WordFilter(String[] words) {
        prefix = new Trie(); 
        suffix = new Trie(); 

        for(int i=0; i < words.length; i++) {
            prefix.insert(words[i], i); 
            suffix.insert(new StringBuilder(words[i]).reverse().toString(), i);             
        }
    }
    
    public int f(String prefix, String suffix) {
        List<Integer> pList = prefix.startsWith(prefix); 
        List<Integer> sList = suffix.startsWith(new StringBuilder(suffix).reverse().toString());

        int i = pList.size() - 1, j = sList.size() -1; 
        while(i >= 0 && j >= 0) {
            // Since the List uses an Integer and not int method you'll need to use 
            // equals method and not == 
            if(Object.equals(pList.get(i), sList.get(j))) return pList.get(i); 
            else if(pList.get(i) > sList.get(j)) i--; 
            else j--; 
        }
        return -1; 
    }
}

class Trie {
    public Trie[] t; 
    List<Integer> index; 

    Trie() {
        t = new Trie[26]; 
        index = new ArrayList<>(); 
    }

    // insert 
    public void insert(String word, int i) {
        Trie root = this; 
        for(char c: word.toCharArray()) {
            if(root.t[c-'a'] == null) {
                root.t[c-'a'] = new Trie(); 
            }
            root = root.t[c - 'a']; 
            root.index.add(i); 
        }
    }

    // startsWith
    public List<Integer> startsWith(String word) {
        Trie root = this; 
        for(char c: word.toCharArray()) {
            if(root.t[c - 'a'] == null) {
                return new ArrayList<>(); 
            }
            root = root.t[c - 'a']; 
        }
        return root.index; 
    }
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */