public class IsSubsequence {
    public boolean isSubsequence(String s, String t) {
        if (s.isEmpty())
            return true;
        if (t.isEmpty())
            return false;
        int i = 0; // s pointer
        int j = 0;  // t pointer
        while (i != s.length() && j != t.length()) {
            if (s.charAt(i) == t.charAt(j)) {
                i++;
            }
            j++;
        }
        if (i == s.length())
            return true;
        return false;
    }

    public boolean isSubsequence_II(String s, String t) {
        if (s.length() == 0)
            return true;
        int i = 0, j = 0;
        while (j < t.length()) {
            char a = s.charAt(i);
            char b = t.charAt(j);

            if (a == b) {
                i++;

                if (i == s.length()) {
                    return true;
                }
            }
            j++;
        }
        return false;
    }
}

