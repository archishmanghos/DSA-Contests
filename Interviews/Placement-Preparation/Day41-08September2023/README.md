<h2>118. Pascal's Triangle</h2>

[Link to Problem](https://leetcode.com/problems/pascals-triangle)

<details><summary>Codes</summary>

```java
import java.util.ArrayList;
import java.util.List;

public class LC118 {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> answer = new ArrayList<>(numRows);
        for (int i = 0; i < numRows; i++) {
            answer.add(new ArrayList<>(i + 1));
            for (int j = 0; j < i + 1; j++) {
                if (i - 1 >= 0 && j - 1 >= 0 && j < i)
                    answer.get(i).add(answer.get(i - 1).get(j - 1) + answer.get(i - 1).get(j));
                else answer.get(i).add(1);
            }
        }

        return answer;
    }
}
```

</details>

<br>
<br>

<h2>11. Container With Most Water</h2>

[Link to Problem](https://leetcode.com/problems/container-with-most-water)

<details><summary>Codes</summary>

```java
public class LC11 {
    public int maxArea(int[] height) {
        int i = 0, j = height.length - 1, answer = 0;
        while (i < j) {
            answer = Math.max(answer, Math.min(height[i], height[j]) * (j - i));
            if (height[i] <= height[j]) i++;
            else j--;
        }

        return answer;
    }
}
```

</details>
