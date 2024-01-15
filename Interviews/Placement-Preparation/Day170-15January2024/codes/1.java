import java.util.*;

public class LC2225 {
    static class MutableInt {
        private int val = 0;
        void increment() { ++val; }
        int get() { return val; }
    }

    public List<List<Integer>> findWinners(int[][] matches) {
        Map<Integer, MutableInt> mp = new HashMap<>();
        for (int[] match : matches) {
            if (mp.get(match[0]) == null) mp.put(match[0], new MutableInt());
            if (mp.get(match[1]) == null) mp.put(match[1], new MutableInt());
            mp.get(match[1]).increment();
        }

        List<List<Integer>> answer = new ArrayList<>();
        answer.add(new ArrayList<>());
        answer.add(new ArrayList<>());
        for (int key : mp.keySet()) {
            if (mp.get(key).get() == 0) answer.get(0).add(key);
            if (mp.get(key).get() == 1) answer.get(1).add(key);
        }

        answer.get(0).sort(Comparator.comparingInt(a -> a));
        answer.get(1).sort(Comparator.comparingInt(a -> a));

        return answer;
    }
}