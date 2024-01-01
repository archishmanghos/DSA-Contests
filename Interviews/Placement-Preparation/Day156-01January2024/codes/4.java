package GFG;

import java.util.HashMap;
import java.util.Map;

public class Array_Pair_Sum_Divisibility_Problem {
    static class MutableInt {
        int value = 1;
        public void increment() { ++value; }
        public void decrement() { --value; }
        public int get() { return value; }
    }
    public boolean canPair(int[] nums, int k) {
        if (nums.length % 2 == 1) return false;

        Map<Integer, MutableInt> mp = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            nums[i] %= k;
            if (mp.get(nums[i]) == null) mp.put(nums[i], new MutableInt());
            else mp.get(nums[i]).increment();
        }

        for (int num : nums) {
            if (mp.get(num).get() == 0) continue;
            mp.get(num).decrement();
            if (mp.get((k - num) % k) != null && mp.get((k - num) % k).get() > 0) mp.get((k - num) % k).decrement();
            else return false;
        }

        return true;
    }
}