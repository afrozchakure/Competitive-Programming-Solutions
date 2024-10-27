public class ParsingABooleanExpression {

    public boolean parseBoolExpr(String expression) {
        Stack<Character> st = new Stack<>();

        for (char currChar : expression.toCharArray()) {
            if (currChar == ',' || currChar == '(') continue; 
            if (
                currChar == 't' ||
                currChar == 'f' ||
                currChar == '!' ||
                currChar == '&' ||
                currChar == '|'
            ) {
                st.push(currChar);
            }
            else if (currChar == ')') {
                boolean hasTrue = false, hasFalse = false;

                while (
                    st.peek() != '!' && st.peek() != '&' && st.peek() != '|'
                ) {
                    char topValue = st.pop();
                    if (topValue == 't') hasTrue = true;
                    if (topValue == 'f') hasFalse = true;
                }

                char op = st.pop();
                if (op == '!') {
                    st.push(hasTrue ? 'f' : 't');
                } else if (op == '&') {
                    st.push(hasFalse ? 'f' : 't');
                } else {
                    st.push(hasTrue ? 't' : 'f');
                }
            }
        }
        return st.peek() == 't';
    }
}
