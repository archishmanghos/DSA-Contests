<h2>392. Is Subsequence</h2>

[Link to Problem](https://leetcode.com/problems/is-subsequence)

<details><summary>Codes</summary>

```java
public class LC392 {
    public boolean isSubsequence(String s, String t) {
        int i = 0;
        for (int j = 0; j < t.length() && i < s.length(); j++) {
            if (s.charAt(i) == t.charAt(j)) i++;
        }

        return i == s.length();
    }
}
```

</details>