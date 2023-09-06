class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

public class LC725 {
    private int getSize(ListNode head) {
        ListNode temp = head;
        int sz = 0;
        while (temp != null) {
            sz++;
            temp = temp.next;
        }

        return sz;
    }

    public ListNode[] splitListToParts(ListNode head, int k) {
        int sz = getSize(head);
        int parts = sz / k, rem = sz % k;
        ListNode[] answer = new ListNode[k];
        ListNode temp = head, prevTemp = head;
        for (int i = 0; i < k; i++) {
            for (int j = 1; j <= parts; j++) {
                prevTemp = head;
                head = head.next;
            }
            if (rem > 0) {
                prevTemp = head;
                head = head.next;
                rem--;
            }
            if (prevTemp != null) prevTemp.next = null;
            answer[i] = temp;
            temp = head;
        }

        return answer;
    }
}