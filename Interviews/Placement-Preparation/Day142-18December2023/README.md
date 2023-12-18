<h2>1913. Maximum Product Difference Between Two Pairs</h2>

[Link to Problem](https://leetcode.com/problems/maximum-product-difference-between-two-pairs)

<details><summary>Code</summary>

```java
import java.util.ArrayList;
import java.util.Collections;

public class LC1913 {
    static void sort(int[] a) {
        ArrayList<Integer> l = new ArrayList<>();
        for (int i : a)
            l.add(i);
        Collections.sort(l);
        for (int i = 0; i < a.length; i++)
            a[i] = l.get(i);
    }

    public int maxProductDifference(int[] nums) {
        sort(nums);
        return (nums[nums.length - 1] * nums[nums.length - 2]) - (nums[1] * nums[0]);
    }
}
```

</details>