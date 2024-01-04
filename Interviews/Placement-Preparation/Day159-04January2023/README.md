<h2>2870. Minimum Number of Operations to Make Array Empty</h2>

[Link to Problem](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty)

<details><summary>Code</summary>

```java
import java.util.HashMap;
import java.util.Map;

public class LC2870 {
    static class MutableInt {
        int value = 1;
        void increment() { ++value; }
        int get() { return value; }
    }
    public int minOperations(int[] nums) {
        Map<Integer, MutableInt> mp = new HashMap<>();
        for (int i : nums) {
            if (mp.get(i) == null) mp.put(i, new MutableInt());
            else mp.get(i).increment();
        }

        int answer = 0;
        for (int key : mp.keySet()) {
            int value = mp.get(key).get();
            if (value == 1) return -1;
            if (value % 3 == 1) answer += (value - 4) / 3 + 2;
            else if (value % 3 == 2) answer += (value - 2) / 3 + 1;
            else answer += value / 3;
        }

        return answer;
    }
}
```

</details>