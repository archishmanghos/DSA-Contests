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

<br>
<br>

<h2>2343. Query Kth Smallest Trimmed Number</h2>

[Link to Problem](https://leetcode.com/problems/query-kth-smallest-trimmed-number)

<details><summary>Code</summary>

```java
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class LC2343 {
    static class pair {
        private final String f;
        private final int s;

        pair(String f, int s) {
            this.f = f;
            this.s = s;
        }

        public int getS() {
            return s;
        }
    }

    public int[] smallestTrimmedNumbers(String[] nums, int[][] queries) {
        int n = nums.length, n1 = nums[0].length(), ql = queries.length;
        int[] answer = new int[ql];
        for (int q = 0; q < ql; q++) {
            int k = queries[q][0], trim = queries[q][1];
            String[] a = new String[n];
            for (int i = 0; i < n; i++) {
                a[i] = nums[i].substring(n1 - trim);
            }
            List<pair> li = new ArrayList<>(n);
            for (int i = 0; i < n; i++) li.add(new pair(a[i], i));
            System.out.println();
            li.sort(Comparator.comparing(o -> o.f));
            answer[q] = li.get(k - 1).getS();
        }

        return answer;
    }
}
```

</details>

<br>
<br>

<h2>216. Combination Sum III</h2>

[Link to Problem](https://leetcode.com/problems/combination-sum-iii)

<details><summary>Code</summary>

```java
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
```

</details>

<br>
<br>

<h2>519. Random Flip Matrix</h2>

[Link to Problem](https://leetcode.com/problems/random-flip-matrix)

<details><summary>Code</summary>

```java
public class LC519 {
    int start, n, m;
    public LC519(int m, int n) {
        start = 0;
        this.n = m;
        this.m = n;
    }

    public int[] flip() {
        int[] ans = {start / m, start % m};
        start = (start + 1) % (n * m);
        return ans;
    }

    public void reset() {
    }
}
```

</details>

<br>
<br>

<h2>17. Letter Combinations of a Phone Number</h2>

[Link to Problem](https://leetcode.com/problems/letter-combinations-of-a-phone-number)

<details><summary>Code</summary>

```java
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class LC17 {
    List<List<Character>> mp = new ArrayList<>();
    List<String> answer = new ArrayList<>();
    private void fnction(int idx, String digit, List<Character> li) {
        if (idx == digit.length()) {
            String s = li.stream().map(Object::toString).collect(Collectors.joining(""));
            if (!s.isEmpty()) answer.add(s);
            return;
        }

        for (var c : mp.get(((int)digit.charAt(idx)) - 50)) {
            li.add(c);
            fnction(idx + 1, digit, li);
            li.remove(li.size() - 1);
        }
    }
    public List<String> letterCombinations(String digits) {
        mp.add(new ArrayList<>(List.of('a', 'b', 'c')));
        mp.add(new ArrayList<>(List.of('d', 'e', 'f')));
        mp.add(new ArrayList<>(List.of('g', 'h', 'i')));
        mp.add(new ArrayList<>(List.of('j', 'k', 'l')));
        mp.add(new ArrayList<>(List.of('m', 'n', 'o')));
        mp.add(new ArrayList<>(List.of('p', 'q', 'r', 's')));
        mp.add(new ArrayList<>(List.of('t', 'u', 'v')));
        mp.add(new ArrayList<>(List.of('w', 'x', 'y', 'z')));

        fnction(0, digits, new ArrayList<>());
        return answer;
    }
}
```

</details>

<br>
<br>