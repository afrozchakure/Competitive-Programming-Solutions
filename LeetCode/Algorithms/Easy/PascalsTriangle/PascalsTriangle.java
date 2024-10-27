import java.util.ArrayList;
import java.util.List;

public class PascalTriangle {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList();
        if(numRows == 0)
            return result;

        List<Integer> first_row = new ArrayList<>();
        first_row.add(1);
        result.add(first_row);

        for(int i = 1; i < numRows; i++){
            List<Integer> prev_row = result.get(i - 1);
            List<Integer> row = new ArrayList<>();
            row.add(1);
            for(int j = 1; j < i; j++){
                row.add(prev_row.get(j - 1) + prev_row.get(j));
            }
            row.add(1);
            result.add(row);
        }
        return result;
    }
}
