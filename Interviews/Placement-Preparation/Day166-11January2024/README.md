<h2>1026. Maximum Difference Between Node and Ancestor</h2>

[Link to Problem](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor)

<details><summary>Code</summary>

```java
public class LC1026 {
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

    private int maxDiff(TreeNode root, int maxVal, int minVal) {
        if (root == null) return 0;

        int nMaxVal = Math.max(maxVal, root.val);
        int nMinVal = Math.min(minVal, root.val);

        int left = maxDiff(root.left, nMaxVal, nMinVal);
        int right = maxDiff(root.right, nMaxVal, nMinVal);
        int current = maxVal == Integer.MIN_VALUE ? maxVal : Math.max(Math.abs(root.val - maxVal), Math.abs(root.val - minVal));

        return Math.max(current, Math.max(left, right));
    }

    public int maxAncestorDiff(TreeNode root) {
        return maxDiff(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
}
```

</details>

<br>
<br>