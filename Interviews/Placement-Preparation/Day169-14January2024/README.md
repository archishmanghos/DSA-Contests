<h2>1657. Determine if Two Strings Are Close</h2>

[Link to Problem](https://leetcode.com/problems/determine-if-two-strings-are-close)

<details><summary>Code</summary>

```java
public class LC1657 {
    public boolean closeStrings(String word1, String word2) {
        if (word1.length() != word2.length()) return false;
        int[] freq1 = new int[30];
        int[] freq2 = new int[30];

        for (int i = 0; i < word1.length(); i++) {
            freq1[(int) word1.charAt(i) - 97]++;
            freq2[(int) word2.charAt(i) - 97]++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq1[i] == freq2[i]) continue;
            if (freq1[i] == 0 || freq2[i] == 0) return false;
            boolean ok = false;
            for (int j = i + 1; j < 26; j++) {
                if (freq1[i] == freq2[j]) {
                    ok = true;
                    int temp = freq2[i];
                    freq2[i] = freq2[j];
                    freq2[j] = temp;
                    break;
                }
            }

            if (!ok) return false;
        }

        return true;
    }
}
```

</details>

<br>
<br>