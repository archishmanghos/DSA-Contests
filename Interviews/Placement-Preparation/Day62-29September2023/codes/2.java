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