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