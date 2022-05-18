#include <bits/stdc++.h>

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
    public:
    Trie(){
        root = new Node();
    }
    public:
    void insert(int x){
        Node *node = root;
        for(int i = 31; i >= 0; i--){
            int bit = (x >> i) & 1;
            if(!node->containsKey(bit)){
                node->createKey(bit, new Node());
            }
            node = node->getKey(bit);
        }
    }
    public:
    int getMaximum(int x){
        Node *node = root;
        int ans = 0;
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

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    sort(arr.begin(), arr.end());
    vector<pair<int, pair<int, int>>> offlineQueries;
    int q = queries.size();
    for(int i = 0; i < q; i++){
        queries[i].push_back(i);
    }
    sort(queries.begin(), queries.end(), [](vector<int> &a, vector<int> &b){
      return a[1] < b[1];
    });
    int i = 0, n = arr.size();
    vector<int> ans(q);
    Trie trie;
    
    for(int j = 0; j < q; j++){
        int ai = queries[j][1];
        int xi = queries[j][0];
        int qInd = queries[j][2];
        while(i < n and arr[i] <= ai){
            trie.insert(arr[i]);
            i += 1;
        }
        if(i == 0){
            ans[qInd] = -1;
        }else{
            ans[qInd] = trie.getMaximum(xi);
        }
    }
    
    return ans;
}