import java.util.ArrayList;
import java.util.List;

public class LC118 {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> answer = new ArrayList<>(numRows);
        for (int i = 0; i < numRows; i++) {
            answer.add(new ArrayList<>(i + 1));
            for (int j = 0; j < i + 1; j++) {
                if (i - 1 >= 0 && j - 1 >= 0 && j < i)
                    answer.get(i).add(answer.get(i - 1).get(j - 1) + answer.get(i - 1).get(j));
                else answer.get(i).add(1);
            }
        }

        return answer;
    }
}