<h2>300. Longest Increasing Subsequence</h2>

[Link to Problem](https://leetcode.com/problems/longest-increasing-subsequence)

<details><summary>Code</summary>

```java
import java.util.ArrayList;
import java.util.List;

public class LC300 {
    public int lengthOfLIS(int[] nums) {
        List<Integer> li = new ArrayList<>();
        int answer = 0;

        for (int i : nums) {
            if (li.isEmpty() || i > li.get(li.size() - 1)) {
                li.add(i);
                answer = answer + 1;
            } else {
                int lo = 0, hi = li.size() - 1, idx = -1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (li.get(mid) >= i) {
                        idx = mid;
                        hi = mid - 1;
                    } else {
                        lo = mid + 1;
                    }
                }
                li.set(idx, i);
            }
        }

        return answer;
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