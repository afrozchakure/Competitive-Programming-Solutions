import java.util.Arrays;
import java.util.List;

public class PascalTriangleII {
    public List<Integer> getRow(int rowIndex) {
        Integer[] result = new Integer[rowIndex + 1];
        Arrays.fill(result, 0);
        result[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                result[j] = result[j] + result[j - 1];
            }
        }
        return Arrays.asList(result);
    }
}
/*Complexity : 
 * TC: o(k*k) where k is rowIndex
 * SC: o(k) where k is rowIndex
 * */
