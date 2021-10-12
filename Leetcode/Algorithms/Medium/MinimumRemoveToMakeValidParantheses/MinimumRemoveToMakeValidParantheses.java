public class MinimumRemoveToMakeValidParantheses {
    public String minRemoveToMakeValid(String s) {
        StringBuilder sb = new StringBuilder();
        int open = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                open++;
            } else if (c == ')') {
                if (open == 0)
                    continue; // continue of seen an close without open before
                open--;
            }
            sb.append(c);
        }
        //backwards loop, we want to remove extra open  bracket
        StringBuilder res = new StringBuilder();
        for (int i = sb.length() - 1; i >= 0; i--) {
            if (sb.charAt(i) == '(' && open-- > 0)
                continue;
            res.append(sb.charAt(i));
        }
        return res.reverse().toString();
    }
}

