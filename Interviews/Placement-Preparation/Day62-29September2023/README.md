<h2>GFG: Left View of Binary Tree</h2>

[Link to Problem](https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1)

<details><summary>Codes</summary>

```java
package GFG;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;

public class BT_Left_View {
    static class Node {
        int data;
        Node left, right;

        Node(int item) {
            data = item;
            left = right = null;
        }
    }

    ArrayList<Integer> leftView(Node root) {
        Deque<Node> q = new ArrayDeque<>();
        ArrayList<Integer> answer = new ArrayList<>();
        if (root != null) q.offerLast(root);

        while (!q.isEmpty()) {
            int sz = q.size();
            for (int i = 1; i <= sz; i++) {
                Node node = q.pollFirst();
                assert node != null;
                if (i == 1) answer.add(node.data);

                if (node.left != null) q.offerLast(node.left);
                if (node.right != null) q.offerLast(node.right);
            }
        }

        return answer;
    }
}
```

</details>

<br>
<br>

<h2>199. Binary Tree Right Side View</h2>

[Link to Problem](https://leetcode.com/problems/binary-tree-right-side-view/description/)

<details><summary>Codes</summary>

```java
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class LC199 {
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public List<Integer> rightSideView(TreeNode root) {
        Deque<TreeNode> q = new ArrayDeque<>();
        List<Integer> answer = new ArrayList<>();
        if (root != null) q.offerLast(root);

        while (!q.isEmpty()) {
            int sz = q.size();
            for (int i = 1; i <= sz; i++) {
                TreeNode node = q.pollFirst();
                assert node != null;
                if (i == sz) answer.add(node.val);

                if (node.left != null) q.offerLast(node.left);
                if (node.right != null) q.offerLast(node.right);
            }
        }

        return answer;
    }
}
```

</details>

<br>
<br>

<h2>GFG: Bottom View of Binary Tree</h2>

[Link to Problem](https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1)

<details><summary>Codes</summary>

```java
package GFG;

import java.util.*;

public class BT_bottom_view {
    static class Node {
        int data;
        Node left, right;

        Node(int item) {
            data = item;
            left = right = null;
        }
    }

    record Nodemod(Node node, int level) {
    }

    public ArrayList<Integer> bottomView(Node root) {
        Map<Integer, Integer> mp = new HashMap<>();
        Deque<Nodemod> q = new ArrayDeque<>();
        q.offerLast(new Nodemod(root, 0));
        int minLevel = 0, maxLevel = 0;

        while (!q.isEmpty()) {
            Nodemod n = q.pollFirst();
            mp.put(n.level(), n.node().data);
            minLevel = Math.min(minLevel, n.level());
            maxLevel = Math.max(maxLevel, n.level());

            if (n.node().left != null) q.offerLast(new Nodemod(n.node().left, n.level() - 1));
            if (n.node().right != null) q.offerLast(new Nodemod(n.node().right, n.level() + 1));
        }

        ArrayList<Integer> answer = new ArrayList<>();
        for (int i = minLevel; i <= maxLevel; i++) answer.add(mp.get(i));

        return answer;
    }
}
```

</details>

<br>
<br>

<h2>896. Monotonic Array</h2>

[Link to Problem](https://leetcode.com/problems/monotonic-array)

<details><summary>Codes</summary>

```java
public class LC896 {
    public boolean isMonotonic(int[] nums) {
        boolean incr = true, decr = true;
        for (int i = 1; i < nums.length; i++) {
            incr &= nums[i] >= nums[i - 1];
            decr &= nums[i] <= nums[i - 1];
        }

        return incr || decr;
    }
}
```

</details>