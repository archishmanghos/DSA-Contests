<h2>2513. Minimize the Maximum of Two Arrays</h2>

[Link to Problem](https://leetcode.com/problems/minimize-the-maximum-of-two-arrays)

<details><summary>Code</summary>

```java
import java.util.function.Function;

public class LC2513 {
    public int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int g = divisor1;
        for (int x = divisor2; x > 0; ) {int tmp = g; g = x; x = tmp % x; }
        long low = 0, high = Integer.MAX_VALUE, answer = 0, lcmm = ((long)divisor1 * divisor2) / g;

        while (low <= high) {
            long mid = low + (high - low) / 2;
            long total = mid - (mid / lcmm);
            Function<Long, Boolean> f = (Long m) -> {
                if (m - m / divisor1 < uniqueCnt1) return false;
                if (m - m / divisor2 < uniqueCnt2) return false;
                return total >= uniqueCnt1 + uniqueCnt2;
            };

            if (f.apply(mid)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)answer;
    }
}
```

</details>

<br>
<br>

<h2>455. Assign Cookies</h2>

[Link to Problem](https://leetcode.com/problems/assign-cookies)

<details><summary>Code</summary>

```java
import java.util.ArrayList;
import java.util.Collections;

public class LC455 {
    static void sort(int[] a) {
        ArrayList<Integer> l = new ArrayList<>();
        for (int i : a)
            l.add(i);
        Collections.sort(l);
        for (int i = 0; i < a.length; i++)
            a[i] = l.get(i);
    }

    public int findContentChildren(int[] g, int[] s) {
        sort(g);
        sort(s);

        int j = 0;
        for (int i = 0; i < s.length && j < g.length; i++) {
            if (g[j] <= s[i]) j++;
        }

        return j;
    }
}
```

</details>