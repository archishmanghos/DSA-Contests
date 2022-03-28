struct Node{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    void createKey(char ch, Node *node){
        links[ch - 'a'] = node;
    }
    Node *getKey(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
};
class Trie{
    Node *root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node *node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->createKey(word[i], new Node());
            }
            node = node->getKey(word[i]);
        }
        node->setEnd();
    }
    bool ifComplete(string word){
        Node *node = root;
        for(int i = 0; i < word.size(); i++){
            if(node->containsKey(word[i]) and node->getKey(word[i])->flag){
                node = node->getKey(word[i]);
                continue;
            }
            return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    Trie obj;
    for(int i = 0; i < n; i++){
        obj.insert(a[i]);
    }
    string ans = "";
    for(int i = 0; i < n; i++){
        if(obj.ifComplete(a[i]) and a[i].size() >= ans.size()){
            if(a[i].size() > ans.size()){
                ans = a[i];
            }else{
                if(a[i] < ans){
                    ans = a[i];
                }
            }
        }
    }
    return (ans == "" ? "None" : ans);
}