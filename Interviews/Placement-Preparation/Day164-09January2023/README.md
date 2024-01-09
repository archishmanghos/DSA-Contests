<h2>872. Leaf-Similar Trees</h2>

[Link to Problem](https://leetcode.com/problems/leaf-similar-trees)

<details><summary>Code</summary>

```java
import java.util.ArrayList;
import java.util.List;

public class LC872 {
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

    List<Integer> leafVal = new ArrayList<>();
    int idx = 0;

    private boolean checkSymmetry(TreeNode root, boolean check) {
        if (root.left == null && root.right == null) {
            if (check) {
                if (idx == leafVal.size() || leafVal.get(idx) != root.val) return false;
                ++idx;
                return true;
            }
            leafVal.add(root.val);
            return true;
        }

        if (root.left != null && !checkSymmetry(root.left, check)) return false;
        return root.right == null || checkSymmetry(root.right, check);
    }

    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        checkSymmetry(root1, false);
        return checkSymmetry(root2, true) && idx == leafVal.size();
    }
}
```

</details>

<br>
<br>