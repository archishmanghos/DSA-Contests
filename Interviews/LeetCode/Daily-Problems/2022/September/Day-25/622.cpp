class MyCircularQueue {
private:
    struct Node {
        int data;
        Node *left, *right;
        Node(int val) {
            data = val;
            left = right = NULL;
        }
    };
    int n;
    Node *head, *tail, *end;
public:
    MyCircularQueue(int k) {
        head = new Node(-1);
        Node* tempNode = head;
        tail = head;
        end = head;
        for (int i = 1; i < k; i++) {
            Node* temp = new Node(-1);
            tempNode->right = temp;
            end = temp;
            temp->left = tempNode;
            tempNode = tempNode->right;
        }
    }

    bool enQueue(int value) {
        if (tail->data != -1) return false;
        tail->data = value;
        if (tail->right) {
            tail = tail->right;
        }
        return true;
    }

    bool deQueue() {
        if (head->data == -1) return false;
        Node* temp = new Node(-1);
        end->right = temp;
        temp->left = end;
        end = end->right;
        head = head->right;
        head->left = NULL;
        if (tail->data != -1) {
            tail = tail->right;
        }
        return true;
    }

    int Front() {
        return head->data;
    }

    int Rear() {
        return tail->data == -1 ? head->data == -1 ? -1 : tail->left->data : tail->data;
    }

    bool isEmpty() {
        return head->data == -1;
    }

    bool isFull() {
        return end->data != -1;
    }
};
