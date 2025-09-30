public class LongestPallindromicSubstring {

    public String longestPalindrome(String s) {
        if (s == null || s.length() < 1) return "";
        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); i++) {
            int len1 = expandFromMiddle(s, i, i); // racecar
            int len2 = expandFromMiddle(s, i, i + 1); // abba
            int len = Math.max(len1, len2);
            if (len > end - start) {
                start = i - ((len - 1) / 2);
                end = i + (len / 2);
            }
        }
        return s.substring(start, end + 1);
    }

    // racecar
    // 0123456
    // i = 3
    // len1 = 7
    // start = 3 - (7-1/2) = 0
    // end = 3 + 7/2 = 3 + 3 = 6

    public int expandFromMiddle(String s, int left, int right) {
        if (s == null || left > right)
            return 0;

        while (left >= 0 && right < s.length() &&
                s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return right - left - 1; // -1 for that extra right++ increment in while loop
    }
}

