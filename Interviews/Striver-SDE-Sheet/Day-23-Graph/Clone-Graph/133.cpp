Node* cloned(Node* node, map<Node*, Node*> &clone) {
    Node* root = new Node(node->val);
    clone[node] = root;
    for (Node* child : node->neighbors) {
        if (clone.find(child) != clone.end()) {
            root->neighbors.push_back(clone[child]);
        } else {
            root->neighbors.push_back(cloned(child, clone));
        }
    }

    return root;
}
Node* cloneGraph(Node* node) {
    if (!node) return NULL;
    map<Node*, Node*> clone;
    return cloned(node, clone);
}