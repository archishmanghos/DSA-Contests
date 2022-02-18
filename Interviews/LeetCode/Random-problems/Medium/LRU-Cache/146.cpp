struct Node {
    int key, value;
    Node *pre, *next;

    Node(int x, int y) {
        key = x, value = y;
        pre = next = NULL;
    }
};

int cacheCapacity;
unordered_map<int, Node *> cache;
Node *head = new Node(0, 0);
Node *tail = new Node(0, 0);

void addNewNode(Node *newNode) {
    Node *tempNode = head->next;
    newNode->next = tempNode;
    newNode->pre = head;
    tempNode->pre = newNode;
    head->next = newNode;
}

void deleteLRUNode(Node *givenNode) {
    Node *leftNode = givenNode->pre;
    Node *rightNode = givenNode->next;
    leftNode->next = rightNode;
    rightNode->pre = leftNode;
}

LRUCache(int capacity) {
    cacheCapacity = capacity;
    head->next = tail;
    tail->pre = head;
}

int get(int key) {
    if (cache.find(key) != cache.end()) {
        int value = cache[key]->value;
        deleteLRUNode(cache[key]);
        cache.erase(key);
        Node *newNode = new Node(key, value);
        addNewNode(newNode);
        cache[key] = newNode;
        return cache[key]->value;
    } else {
        return -1;
    }
}

void put(int key, int value) {
    if (cache.find(key) == cache.end()) {
        if (cache.size() < cacheCapacity) {
            Node *newNode = new Node(key, value);
            addNewNode(newNode);
            cache[key] = newNode;
        } else {
            cache.erase(tail->pre->key);
            deleteLRUNode(tail->pre);
            Node *newNode = new Node(key, value);
            addNewNode(newNode);
            cache[key] = newNode;
        }
    } else {
        deleteLRUNode(cache[key]);
        cache.erase(key);
        Node *newNode = new Node(key, value);
        addNewNode(newNode);
        cache[key] = newNode;
    }
}