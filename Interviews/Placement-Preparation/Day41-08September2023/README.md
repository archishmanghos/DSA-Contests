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

<br>
<br>

<h2>15. 3Sum</h2>

[Link to Problem](https://leetcode.com/problems/3sum)

<details><summary>Codes</summary>

```java
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LC15 {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> answer = new ArrayList<>();

        for (int i = 0; i + 2 < nums.length; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int j = i + 1, k = nums.length - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    answer.add(new ArrayList<>());
                    answer.get(answer.size() - 1).add(nums[i]);
                    answer.get(answer.size() - 1).add(nums[j]);
                    answer.get(answer.size() - 1).add(nums[k]);
                    j++;
                    while (j < k && nums[j - 1] == nums[j]) j++;
                    k--;
                    while (j < k && nums[k + 1] == nums[k]) k--;
                } else if (sum < 0) {
                    j++;
                    while (j < k && nums[j - 1] == nums[j]) j++;
                } else {
                    k--;
                    while (j < k && nums[k + 1] == nums[k]) k--;
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

<h2>167. Two Sum II - Input Array Is Sorted</h2>

[Link to Problem](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted)

<details><summary>Codes</summary>

```java
public class LC167 {
    public int[] twoSum(int[] numbers, int target) {
        int i = 0, j = numbers.length - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) return new int[] {i + 1, j + 1};
            if (sum < target) i++;
            else j--;
        }

        return new int[] { -1};
    }
}
```

</details>

<br>
<br>

<h2>125. Valid Palindrome</h2>

[Link to Problem](https://leetcode.com/problems/valid-palindrome)

<details><summary>Codes</summary>

```java
public class LC125 {
    public boolean isPalindrome(String s) {
        StringBuilder str = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char ch = Character.toLowerCase(s.charAt(i));
            if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) str.append(ch);
        }

        int i = 0, j = str.length() - 1;
        while (i < j) {
            if (str.charAt(i++) != str.charAt(j--)) return false;
        }

        return true;
    }
}
```

</details>
