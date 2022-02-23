Node *dfs(Node *node, map<Node *, Node *> &ifCopied) {
    Node *newCopy = new Node(node->val);
    ifCopied[node] = newCopy;

    for (Node *neighbor: node->neighbors) {
        if (ifCopied.find(neighbor) == ifCopied.end()) {
            ifCopied[neighbor] = dfs(neighbor, ifCopied);
        }
        newCopy->neighbors.push_back(ifCopied[neighbor]);
    }

    return newCopy;
}

Node *cloneGraph(Node *node) {
    if (!node) {
        return NULL;
    }

    map < Node * , Node * > ifCopied;
    Node *ans = dfs(node, ifCopied);
    return ans;
}