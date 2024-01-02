import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LC2610 {
    static class MutableInt {
        int v = 1;

        void increment() { ++v; }

        void decrement() { --v; }

        int get() { return v; }
    }

    public List<List<Integer>> findMatrix(int[] nums) {
        Map<Integer, MutableInt> mp = new HashMap<>();
        for (int i : nums) {
            if (mp.get(i) == null) mp.put(i, new MutableInt());
            else mp.get(i).increment();
        }

        List<List<Integer>> answer = new ArrayList<>();
        boolean flag;
        int idx = 0;
        do {
            flag = false;
            for (int key : mp.keySet()) {
                if (mp.get(key).get() > 0) {
                    flag = true;
                    if (answer.size() == idx) answer.add(new ArrayList<>());
                    answer.get(idx).add(key);
                    mp.get(key).decrement();
                }
            }
            ++idx;
        } while (flag);

        return answer;
    }
}