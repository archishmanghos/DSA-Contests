<h2>2385. Amount of Time for Binary Tree to Be Infected</h2>

[Link to Problem](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected)

<details><summary>Code</summary>

```java
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;

public class LC2385 {
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() { }

        TreeNode(int val) { this.val = val; }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    Map<TreeNode, TreeNode> par = new HashMap<>();
    TreeNode node;

    private void traverse(TreeNode root, TreeNode parent, int start) {
        if (root == null) return;
        par.put(root, parent);
        if (root.val == start) node = root;
        traverse(root.left, root, start);
        traverse(root.right, root, start);
    }

    public int amountOfTime(TreeNode root, int start) {
        traverse(root, null, start);
        Deque<TreeNode> dq = new ArrayDeque<>();
        dq.offerLast(node);
        Map<Integer, Boolean> mp = new HashMap<>();

        int answer = -1;
        while (!dq.isEmpty()) {
            int sz = dq.size();
            boolean add = false;
            for (int i = 1; i <= sz; i++) {
                TreeNode curNode = dq.pollFirst();
                assert curNode != null;
                if (mp.get(curNode.val) != null) continue;
                mp.put(curNode.val, true);
                if (par.get(curNode) != null) dq.offerLast(par.get(curNode));
                if (curNode.left != null) dq.offerLast(curNode.left);
                if (curNode.right != null) dq.offerLast(curNode.right);
                add = (par.get(curNode) != null) || (curNode.left != null) || (curNode.right != null);
            }
            if (add) ++answer;
            else return Math.max(0, answer);
        }

        return 0;
    }
}
```

</details>

<br>
<br>