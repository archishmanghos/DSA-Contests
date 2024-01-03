import java.util.ArrayList;
import java.util.List;

public class LC216 {
    List<List<Integer>> answer = new ArrayList<>();

    private void fnction(int num, int sumRemaining, int k, List<Integer> l) {
        if (sumRemaining == 0) {
            if (k == 0) answer.add(new ArrayList<>(l));
            return;
        }
        if (k == 0 || num > 9) return;

        if (num <= sumRemaining) {
            l.add(num);
            fnction(num + 1, sumRemaining - num, k - 1, l);
            l.remove(l.size() - 1);
        }
        fnction(num + 1, sumRemaining, k, l);
    }

    public List<List<Integer>> combinationSum3(int k, int n) {
        List<Integer> l = new ArrayList<>();
        fnction(1, n, k, l);
        return answer;
    }
}