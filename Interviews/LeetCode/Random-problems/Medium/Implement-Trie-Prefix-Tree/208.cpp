struct Node{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    void createKey(char ch){
        links[ch - 'a'] = new Node();
    }
    Node *getReferenceTrie(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
};
private:Node *root;
public:
Trie(){
    root = new Node();
}

void insert(string word){
    Node *dummy = root;
    for(int i = 0; i < word.size(); i++){
        if(!dummy->containsKey(word[i])){
            dummy->createKey(word[i]);
        }
        dummy = dummy->getReferenceTrie(word[i]);
    }
    dummy->setEnd();
}

bool search(string word){
    Node *dummy = root;
    for(int i = 0; i < word.size(); i++){
        if(!dummy->containsKey(word[i])){
            return false;
        }
        dummy = dummy->getReferenceTrie(word[i]);
    }
    return dummy->flag;
}

bool startsWith(string prefix){
    Node *dummy = root;
    for(int i = 0; i < prefix.size(); i++){
        if(!dummy->containsKey(prefix[i])){
            return false;
        }
        dummy = dummy->getReferenceTrie(prefix[i]);
    }
    return true;
}