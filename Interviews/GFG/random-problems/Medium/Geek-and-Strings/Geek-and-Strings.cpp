struct Node {
    int count = 0;
    Node *links[26];
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    Node *getReferenceKey(char ch) {
        return links[ch - 'a'];
    }
    void createKey(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    void increaseCount() {
        count += 1;
    }
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }

    void makeTrie(string s) {
        Node *dummy = root;
        for (char ch : s) {
            if (!dummy->containsKey(ch)) {
                dummy->createKey(ch, new Node());
            }
            dummy = dummy->getReferenceKey(ch);
            dummy->increaseCount();
        }
    }

    int countPrefix(string s) {
        Node *dummy = root;
        int ans = 0;
        for (char ch : s) {
            if (!dummy->containsKey(ch)) {
                ans = 0;
                break;
            }
            dummy = dummy->getReferenceKey(ch);
            ans = dummy->count;
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[]) {
        Trie obj;
        for (int i = 0; i < N; i++) {
            obj.makeTrie(li[i]);
        }
        vector<int> ans(Q);
        for (int i = 0; i < Q; i++) {
            ans[i] = obj.countPrefix(query[i]);
        }

        return ans;
    }
};