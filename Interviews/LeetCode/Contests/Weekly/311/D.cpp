struct Node {
    int count = 0;
    Node* links[26];

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void createKey(char ch, Node* newNode) {
        links[ch - 'a'] = newNode;
    }

    Node* getKey(char ch) {
        return links[ch - 'a'];
    }

    void countInc() {
        count += 1;
    }
};

class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }

    void constructPrefix(string s) {
        Node* dummy = root;
        for (int i = 0; i < s.size(); i++) {
            if (!dummy->containsKey(s[i])) {
                dummy->createKey(s[i], new Node());
            }
            dummy = dummy->getKey(s[i]);
            dummy->countInc();
        }
    }

    int getCount(string s) {
        Node* dummy = root;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (!dummy->containsKey(s[i])) {
                return ans;
            }
            dummy = dummy->getKey(s[i]);
            ans += dummy->count;
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie obj;
        int n = words.size();
        for (string s : words) {
            obj.constructPrefix(s);
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = obj.getCount(words[i]);
        }

        return ans;
    }
};