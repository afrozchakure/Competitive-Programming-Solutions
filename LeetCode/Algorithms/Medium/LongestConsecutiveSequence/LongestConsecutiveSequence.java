import java.util.HashSet;
import java.util.Set;

public class LongestConsecutiveSequence {
    public int longestConsecutive(int[] nums) {
        Set<Integer> num_set = new HashSet<Integer>();
        for (int num : nums) {
            num_set.add(num);
        }
        int max_seq_length = 0;

        for (int num : num_set) {
            if (!num_set.contains(num - 1)) { 
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.contains(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                max_seq_length = Math.max(max_seq_length, currentStreak);
            }
        }

        return max_seq_length;
    }
}

