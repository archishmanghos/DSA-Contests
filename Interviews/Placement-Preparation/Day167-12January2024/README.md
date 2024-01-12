<h2>1704. Determine if String Halves Are Alike</h2>

[Link to Problem](https://leetcode.com/problems/determine-if-string-halves-are-alike)

<details><summary>Code</summary>

```java
import java.util.function.Function;

public class LC1704 {
    public boolean halvesAreAlike(String s) {
        Function<Character, Integer> isVowel = (Character c) -> (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') ? 1 : 0;

        int i = 0, j = s.length() - 1, netChange = 0;
        while (i < j) {
            netChange += isVowel.apply(s.charAt(i));
            netChange -= isVowel.apply(s.charAt(j));
            i++;
            j--;
        }

        return netChange == 0;
    }
}
```

</details>

<br>
<br>