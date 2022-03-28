struct Node{
    Node *links[26];
    int endsWith = 0, countPrefix = 0;
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    void createKey(char ch, Node *node){
        links[ch - 'a'] = node;
    }
    Node *getReferenceTrie(char ch){
        return links[ch - 'a'];
    }
    void changeCountEnd(int n){
        endsWith += n;
    }
    void changeCountPrefix(int n){
        countPrefix += n;
    }
};
class Trie{
    private:Node *root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node *node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->createKey(word[i], new Node());
            }
            node = node->getReferenceTrie(word[i]);
            node->changeCountPrefix(1);
        }
        node->changeCountEnd(1);
    }

    int countWordsEqualTo(string &word){
        Node *node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->getReferenceTrie(word[i]);
        }
        return node->endsWith;
    }

    int countWordsStartingWith(string &word){
        Node *node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->getReferenceTrie(word[i]);
        }
        return node->countPrefix;
    }

    void erase(string &word){
        Node *node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                return;
            }
            node = node->getReferenceTrie(word[i]);
            node->changeCountPrefix(-1);
        }
        node->changeCountEnd(-1);
    }
};
