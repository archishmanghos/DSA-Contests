import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class LC403 {
    Map<Integer, Integer> mp;

    public int dp(int idx, int firstJump, int lastJump, int[] stones, int[][][] cache) {
        if (idx == stones.length - 1) return 1;
        if (cache[idx][firstJump][lastJump] != -1) return cache[idx][firstJump][lastJump];

        int answer = 0;
        if (firstJump == 0) {
            int newStone = stones[idx] + 1;
            if (newStone >= 0 && newStone <= stones[stones.length - 1] && newStone != stones[idx] && mp.get(newStone) != null)
                answer |= dp(mp.get(newStone), 1, 1, stones, cache);
        } else {
            for (int i = -1; i <= 1; i++) {
                int newStone = stones[idx] + lastJump + i;
                if (newStone >= 0 && newStone <= stones[stones.length - 1] && newStone != stones[idx] && mp.get(newStone) != null)
                    answer |= dp(mp.get(newStone), 1, lastJump + i, stones, cache);
            }
        }

        return cache[idx][firstJump][lastJump] = answer;
    }

    public boolean canCross(int[] stones) {
        mp = new HashMap<>();
        for (int i = 0; i < stones.length; i++) mp.put(stones[i], i);
        int[][][] cache = new int[stones.length][2][2 * stones.length];
        for (int[][] a : cache) {
            for (int[] b : a) {
                Arrays.fill(b, -1);
            }
        }
        int answer = dp(0, 0, 1, stones, cache);
        return answer == 1;
    }
}
