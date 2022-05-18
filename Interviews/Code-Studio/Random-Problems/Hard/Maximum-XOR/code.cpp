struct Node{
    Node *links[2];
    bool containsKey(int bit){
        return links[bit] != NULL;
    }
    void createKey(int bit, Node *node){
        links[bit] = node;
    }
    Node *getKey(int bit){
        return links[bit];
    }
};

class Trie{
    private:Node *root;
    public:Trie(){
                 root = new Node();
             }
    public:void insert(int number){
            Node *node = root;
            for(int i = 31; i >= 0; i--){
                int bit = (number >> i) & 1;
                if(!node->containsKey(bit)){
                    node->createKey(bit, new Node());
                }
                node = node->getKey(bit);
            }
        }
    public:int maximiseXor(int x){
            int ans = 0;
            Node *node = root;
            for(int i = 31; i >= 0; i--){
                int bit = (x >> i) & 1;
                if(node->containsKey(1 - bit)){
                    ans |= (1 << i);
                    node = node->getKey(1 - bit);
                }else{
                    node = node->getKey(bit);
                }
            }
            return ans;
        }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    Trie trie;
    for(int i: arr1){
        trie.insert(i);
    }
    int ans=0;
    for(int i: arr2){
        ans=max(ans,trie.maximiseXor(i));
    }
    
    return ans;
}