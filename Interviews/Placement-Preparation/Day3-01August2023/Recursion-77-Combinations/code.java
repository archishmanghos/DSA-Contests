import java.util.ArrayList;
import java.util.List;

public class LC77 {
    private List<List<Integer>> answer = new ArrayList<>();
    private void f(int i, int k, int n, List<Integer> cur) {
        if (k == 0) {
            answer.add(new ArrayList<>(cur));
            return;
        }
        if (i == n + 1) return;

        if (n - i + 1 > k) f (i + 1, k, n, cur);
        cur.add(i);
        f (i + 1, k - 1, n, cur);
        cur.remove(cur.size() - 1);
    }
    public List<List<Integer>> combine(int n, int k) {
        f (1, k, n, new ArrayList<>());
        return answer;
    }
}
