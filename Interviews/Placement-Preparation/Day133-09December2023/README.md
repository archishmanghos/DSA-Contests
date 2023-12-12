<h2>94. Binary Tree Inorder Traversal</h2>

[Link to Problem](https://leetcode.com/problems/binary-tree-inorder-traversal)

<details><summary>Code</summary>

```java
import java.util.ArrayList;
import java.util.List;

public class LC94 {
    public static class TreeNode {
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

    private void inorder(TreeNode root, List<Integer> answer) {
        if (root == null) return;

        inorder(root.left, answer);
        answer.add(root.val);
        inorder(root.right, answer);
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> answer = new ArrayList<>();
        inorder(root, answer);
        return answer;
    }
}
```

</details>