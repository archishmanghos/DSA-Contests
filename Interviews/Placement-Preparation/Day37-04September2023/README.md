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
