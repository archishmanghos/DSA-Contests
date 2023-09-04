<h2>141. Linked List Cycle</h2>

[Link to Problem](https://leetcode.com/problems/linked-list-cycle)

<details><summary>Codes</summary>

```java
public class LC141 {
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
            next = null;
        }
    }

    public boolean hasCycle(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) return true;
        }

        return false;
    }
}
```

</details>

<br>
<br>

<h2>242. Valid Anagram</h2>

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

<h2>217. Contains Duplicate</h2>

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
