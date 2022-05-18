struct Node{
    Node *links[26];
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    void createKey(char ch, Node *node){
        links[ch - 'a'] = node;
    }
    Node *getReferenceTrie(char ch){
        return links[ch - 'a'];
    }
};

int countDistinctSubstrings(string &s)
{
    int ans = 0, n = s.size();
    Node *root = new Node();
    for(int i = 0; i < n; i++){
        Node *node = root;
        for(int j = i; j < s.size(); j++){
            if(!node->containsKey(s[j])){
                ans += 1;
                node->createKey(s[j], new Node());
            }
            node = node->getReferenceTrie(s[j]);
        }
    }
    return ans + 1;
}