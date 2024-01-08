<h2>938. Range Sum of BST</h2>

[Link to Problem](https://leetcode.com/problems/range-sum-of-bst)

<details><summary>Code</summary>

```java
public class LC938 {
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

    public int rangeSumBST(TreeNode root, int low, int high) {
        if (root == null) return 0;
        if (root.val < low) return rangeSumBST(root.right, low, high);
        if (root.val > high) return rangeSumBST(root.left, low, high);
        return rangeSumBST(root.right, low, high) + rangeSumBST(root.left, low, high) + root.val;
    }
}
```

</details>

<br>
<br>