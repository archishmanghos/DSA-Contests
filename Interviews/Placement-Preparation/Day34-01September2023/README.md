<h2>338. Counting Bits</h2>

[Link to Problem](https://leetcode.com/problems/counting-bits/)

<details><summary>Codes</summary>

```java
public class LC338 {
    public int[] countBits(int n) {
        int[] answer = new int[n + 1];
        int one_bits = 0;
        answer[0] = 0;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                one_bits = 1;
            } else {
                int k = i - 1;
                if (k % 2 == 0) one_bits++;
                else {
                    int deduct = 0;
                    while (k % 2 != 0) {
                        deduct++;
                        k >>= 1;
                    }

                    one_bits -= (deduct - 1);
                }
            }

            answer[i] = one_bits;
        }

        return answer;
    }
}
```

</details>

<br>
<br>

<h2>1326. Minimum Number of Taps to Open to Water a Garden</h2>

[Link to Problem](https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden)

<details><summary>Codes</summary>

```java
import java.util.*;

public class LC1326 {
    static class Pair implements Comparable<Pair> {
        private final int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair o) {
            return this.first - o.first;
        }
    }

    private int dp(int idx, List<Pair> range, int n, int[] cache) {
        if (range.get(idx).second == n) return 1;
        if (cache[idx] != -1) return cache[idx];

        int answer = (int) 1e9;
        for (int i = idx + 1; i < range.size(); i++) {
            if (range.get(idx).second < range.get(i).first) break;
            answer = Math.min(answer, dp(i, range, n, cache) + 1);
        }

        return cache[idx] = answer;
    }

    public int minTaps(int n, int[] ranges) {
        List<Pair> range = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            int left_range = Math.max(0, i - ranges[i]);
            int right_range = Math.min(n, i + ranges[i]);
            range.add(new Pair(left_range, right_range));
        }
        Collections.sort(range);

        int[] cache = new int[n + 1];
        Arrays.fill(cache, -1);
        int answer = (int) 1e9;
        for (int i = 0; i < range.size(); i++) {
            if (range.get(i).first == 0) {
                Arrays.fill(cache, -1);
                answer = Math.min(answer, dp(i, range, n, cache));
            }
        }

        return (answer == (int) 1e9 ? -1 : answer);
    }
}
```

</details>

<br>
<br>

<h2>49. Group Anagrams</h2>

[Link to Problem](https://leetcode.com/problems/group-anagrams)

<details><summary>Codes</summary>

```java
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LC49 {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, Integer> index = new HashMap<>();
        List<List<String>> answer = new ArrayList<>();

        for (String s : strs) {
            int[] count = new int[26];
            for (int i = 0; i < s.length(); i++) {
                int ch = (int)s.charAt(i) - 97;
                count[ch]++;
            }
            StringBuilder str = new StringBuilder();
            for (int i = 0; i < 26; i++) {
                if (count[i] > 0) {
                    char ch = (char)(i + 97);
                    str.append(String.valueOf(ch).repeat(count[i]));
                }
            }

            String str_clone = str.toString();
            if (index.get(str_clone) == null) {
                answer.add(new ArrayList<>());
                index.put(str_clone, answer.size() - 1);
            }

            answer.get(index.get(str_clone)).add(s);
        }

        return answer;
    }
}
```

</details>

<br>
<br>

<h2>1. Two Sum</h2>

[Link to Problem](https://leetcode.com/problems/two-sum)

<details><summary>Codes</summary>

```java
import java.util.HashMap;
import java.util.Map;

public class LC1 {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> index = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (index.get(target - nums[i]) != null) return new int[] {index.get(target - nums[i]), i};
            index.put(nums[i], i);
        }

        return new int[] { -1};
    }
}
```

</details>
