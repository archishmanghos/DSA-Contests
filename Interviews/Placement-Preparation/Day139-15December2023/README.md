<h2>287. Find the Duplicate Number</h2>

[Link to Problem](https://leetcode.com/problems/find-the-duplicate-number)

<details><summary>Code</summary>

```java
package striver_sde_sheet.array2;

public class LC287 {
    public int findDuplicate(int[] nums) {
        int slow = nums[0], fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
}
```

</details>

<br>
<br>

<h2>1436. Destination City</h2>

[Link to Problem](https://leetcode.com/problems/destination-city)

<details><summary>Code</summary>

```java
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LC1436 {
    static class MutableInt {
        int value = 0;
        public void increment() { ++value; }
        public void decrement() { --value; }
        public int get() { return value; }
    }

    public String destCity(List<List<String>> paths) {
        Map<String, MutableInt> mp = new HashMap<>();
        for (var path : paths) {
            String u = path.get(0), v = path.get(1);

            if (mp.get(u) == null) mp.put(u, new MutableInt());
            mp.get(u).increment();

            if (mp.get(v) == null) mp.put(v, new MutableInt());
            mp.get(v).decrement();
        }

        for (String key : mp.keySet()) { if (mp.get(key).get() == -1) return key; }

        return "-1";
    }
}
```

</details>