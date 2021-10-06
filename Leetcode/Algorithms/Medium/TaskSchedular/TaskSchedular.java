import java.util.Arrays;

public class TaskSchedular {
    public int leastInterval(char[] tasks, int n) {
        int[] char_map = new int[26];
        for (char c : tasks) {
            char_map[c - 'A']++;
        }
        Arrays.sort(char_map);

        int partCount = char_map[25] - 1;
        int idle_slots = partCount * n;
        for (int i = 24; i >= 0; i--) {
            idle_slots -= Math.min(char_map[i], partCount);
        }
        return idle_slots > 0 ? idle_slots + tasks.length : tasks.length;
    }
}
