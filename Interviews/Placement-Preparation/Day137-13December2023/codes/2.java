import java.util.ArrayList;
import java.util.List;

public class LC1582 {
    public int numSpecial(int[][] mat) {
        List<Integer> rows = new ArrayList<>();
        List<Integer> cols = new ArrayList<>();

        for (int i = 0; i < mat.length; i++) {
            int one = 0;
            for (int j = 0; j < mat[0].length; j++) {
                if (mat[i][j] == 1) one++;
            }

            if (one == 1) rows.add(i);
        }

        for (int i = 0; i < mat[0].length; i++) {
            int one = 0;
            for (int[] ints : mat) {
                if (ints[i] == 1) one++;
            }

            if (one == 1) cols.add(i);
        }

        int answer = 0;
        for (int i : rows) {
            for (int j : cols) {
                if (mat[i][j] == 1) answer++;
            }
        }

        return answer;
    }
}
