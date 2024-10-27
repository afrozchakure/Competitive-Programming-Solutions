import java.util.Stack;

public class ScoreOfParanthesis {
    public int scoreOfParentheses(String s) {
        Stack<Integer> stack = new Stack<>();

        int score = 0;

        for (char c : s.toCharArray()) {
            if (c == '(') {
                stack.push(score);
                score = 0;
            } else {
                score = stack.pop() + Math.max(score * 2, 1);
            }
        }
        return score;
    }
/*
((()())) = 8

stack = 2 * (2 * (1 + 1))
*/
}

