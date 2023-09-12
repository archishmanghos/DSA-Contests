<h2>1647. Minimum Deletions to Make Character Frequencies Unique</h2>

[Link to Problem](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique)

<details><summary>Codes</summary>

```java
import java.util.NavigableSet;
import java.util.TreeSet;

public class LC1647 {
    public int minDeletions(String s) {
        NavigableSet<Integer> st = new TreeSet<>();
        int[] count = new int[26];
        int maxx = 0;
        for (int i = 0; i < s.length(); i++) {
            int ch = (int) s.charAt(i) - 97;
            count[ch]++;
            maxx = Math.max(maxx, count[ch]);
        }

        for (int i = 1; i <= maxx; i++) st.add(i);

        int answer = 0;
        for (int i = 0; i < 26; i++) {
            if (st.contains(count[i])) {
                st.remove(count[i]);
            } else {
                Integer getLower = st.lower(count[i]);
                if (getLower == null) answer += count[i];
                else {
                    answer += count[i] - getLower;
                    st.remove(getLower);
                }
            }
        }

        return answer;
    }
}
```

</details>
