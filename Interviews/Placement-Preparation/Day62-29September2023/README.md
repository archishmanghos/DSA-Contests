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