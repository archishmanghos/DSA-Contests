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

<h2>2933. High-Access Employees</h2>

[Link to Problem](https://leetcode.com/problems/high-access-employees)

<details><summary>Code</summary>

```java
import java.util.*;
import java.util.function.Function;

public class LC2933 {
    public List<String> findHighAccessEmployees(List<List<String>> access_times) {
        Map<String, List<Integer>> mp = new HashMap<>();
        Function<String, Integer> getTime = (String t) -> Integer.parseInt(t.substring(0, 2)) * 60 + Integer.parseInt(t.substring(2));

        for (var x : access_times) {
            String emp = x.get(0);
            int time = getTime.apply(x.get(1));
            mp.putIfAbsent(emp, new ArrayList<>());
            mp.get(emp).add(time);
        }

        List<String> answer = new ArrayList<>();
        for (String key : mp.keySet()) {
            Collections.sort(mp.get(key));
            if (mp.get(key).size() >= 3) {
                for (int i = 0; i + 2 < mp.get(key).size(); i++) {
                    if (mp.get(key).get(i + 2) - mp.get(key).get(i) < 60) {
                        answer.add(key);
                        break;
                    }
                }
            }
        }

        return answer;
    }
}
```

</details>