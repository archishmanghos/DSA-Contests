### Please try to solve the problems first before seeing the solution. This repository contains clean codes. Enjoy!

<details><summary>Arrays & Hashing</summary>

<p><a href="#1.1">1. Contains Duplicate</a></p>
<p><a href="#1.2">2. Valid Anagram</a></p>
<p><a href="#1.3">3. Two Sum</a></p>
<p><a href="#1.4">4. Group Anagrams</a></p>
<p><a href="#1.5">5. Top K Frequent Elements</a></p>
<p><a href="#1.6">6. Product of Array Except Self</a></p>
<p><a href="#1.7">7. Valid Sudoku</a></p>
<p><a href="#1.8">8. Encode and Decode Strings</a></p>
<p><a href="#1.9">9. Longest Consecutive Sequence</a></p>

</details>

<h5 id="#1.1">1. Contains Duplicate</h5>

[Link to Problem](https://leetcode.com/problems/contains-duplicate)

<details><summary>Codes</summary>

```java
import java.util.HashMap;
import java.util.Map;

public class LC217 {
    public boolean containsDuplicate(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i : nums) {
            if (mp.get(i) != null) return true;
            mp.put(i, 1);
        }

        return false;
    }
}
```

</details>

<br>
<br>

<h5 id="#1.2">2. Valid Anagram</h5>

[Link to Problem](https://leetcode.com/problems/valid-anagram)

<details><summary>Codes</summary>

```java
public class LC242 {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        int[] count = new int[26];
        for (int i = 0; i < s.length(); i++) {
            count[(int) s.charAt(i) - 97]++;
            count[(int) t.charAt(i) - 97]--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }

        return true;
    }
}
```

</details>

<br>
<br>

<h5 id="#1.3">3. Two Sum</h5>

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

<br>
<br>

<h5 id="1.4">4. Group Anagrams</h5>

[Link to Problem](https://leetcode.com/problems/group-anagrams)

<details><summary>Solution</summary>

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

<h5 id="1.5">5. Top K Frequent Elements</h5>

[Link to Problem](https://leetcode.com/problems/top-k-frequent-elements/)

<details><summary>Solution</summary>

```java
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LC347 {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        int max_count = 0;
        for (int i : nums) {
            mp.merge(i, 1, Integer::sum);
            max_count = Math.max(mp.get(i), max_count);
        }

        List<List<Integer>> bucket = new ArrayList<>(max_count + 1);
        for (int i = 0; i <= max_count; i++) bucket.add(new ArrayList<>());
        for (int i : mp.keySet()) bucket.get(mp.get(i)).add(i);

        int[] answer = new int[k];
        for (int i = max_count, j = 0; i >= 1 && j < k; i--) {
            if (bucket.get(i).size() > 0) {
                for (int ii : bucket.get(i)) answer[j++] = ii;
            }
        }

        return answer;
    }
}
```

</details>

<br>
<br>

<h5 id="1.6">6. Product of Array Except Self</h5>

[Link to Problem](https://leetcode.com/problems/product-of-array-except-self/)

<details><summary>Solution</summary>

```java
public class LC238 {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] answer = new int[n];
        int current_product = 1;

        for (int i = 0; i < n; i++) {
            answer[i] = current_product;
            current_product *= nums[i];
        }

        current_product = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= current_product;
            current_product *= nums[i];
        }

        return answer;
    }
}
```

</details>

<br>
<br>

<h5 id="1.7">7. Valid Sudoku</h5>

[Link to Problem](https://leetcode.com/problems/valid-sudoku/)

<details><summary>Solution</summary>

```java
public class LC36 {
    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < 9; i++) {
            boolean[] row = new boolean[10];
            boolean[] column = new boolean[10];
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && row[((int) board[i][j] - 48)]) return false;
                if (board[j][i] != '.' && column[((int) board[j][i] - 48)]) return false;
                if (board[i][j] != '.') row[((int) board[i][j] - 48)] = true;
                if (board[j][i] != '.') column[((int) board[j][i] - 48)] = true;
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                boolean[] check = new boolean[10];
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        if (board[k][l] == '.') continue;
                        if (check[((int) board[k][l] - 48)]) return false;
                        check[((int) board[k][l] - 48)] = true;
                    }
                }
            }
        }

        return true;
    }
}
```

</details>

<br>
<br>

<h5 id="1.8">8. Encode and Decode Strings</h5>

[Link to Problem](https://leetcode.com/problems/encode-and-decode-strings/)

<details><summary>Solution</summary>

```java
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LC271 {
    public static String encode(List<String> strs) {
        StringBuilder encoded_string = new StringBuilder();
        for (String s : strs) {
            for (int i = 0; i < s.length(); i++) {
                int ch = s.charAt(i);
                encoded_string.append(ch);
                encoded_string.append('-');
            }
            encoded_string.append("-");
        }

        return encoded_string.toString();
    }

    public static List<String> decode(String str) {
        StringBuilder s = new StringBuilder();
        StringBuilder now = new StringBuilder();
        List<String> answer = new ArrayList<>();
        for (int i = 0; i < str.length() - 1; ) {
            now.setLength(0);
            do {
                now.append(str.charAt(i));
                i++;
            } while (str.charAt(i) != '-');

            char ch = (char) Integer.parseInt(now.toString());
            s.append(ch);

            if (str.substring(i, i + 2).compareTo("--") == 0) {
                answer.add(s.toString());
                s.setLength(0);
                i += 2;
            } else i++;
        }

        return answer;
    }
}
```

</details>

<br>
<br>

<h5 id="1.9">9. Longest Consecutive Sequence</h5>

[Link to Problem](https://leetcode.com/problems/longest-consecutive-sequence/)

<details><summary>Solution</summary>

```java
import java.util.HashMap;
import java.util.Map;

public class LC128 {
    public int longestConsecutive(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int num : nums) mp.put(num, 1);
        int answer = 0;
        for (int num : nums) {
            if (mp.get(num) == 1 && mp.get(num + 1) == null) {
                int k = num;
                while (mp.get(k) != null && mp.get(k) != 0) k--;
                answer = Math.max(answer, num - k);
            }
        }

        return answer;
    }
}
```

</details>

<br>
<br>
