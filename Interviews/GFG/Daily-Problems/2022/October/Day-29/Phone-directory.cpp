struct Node {
    Node* links[26];
    bool end = false;
    vector <int> indices;

    bool containsKey (char ch) {
        return links[ch - 'a'] != NULL;
    }

    void createKey (char ch, Node* root) {
        links[ch - 'a'] = root;
    }

    Node* getReferenceTrie (char ch) {
        return links[ch - 'a'];
    }

    void pushIndex (int index) {
        indices.push_back(index);
    }

    void setEnd () {
        end = true;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie () {
        root = new Node();
    }

    void createTrie (string s, int idx) {
        Node* dummy = root;
        for (char c : s) {
            if (!dummy->containsKey(c)) {
                dummy->createKey(c, new Node());
            }
            dummy = dummy->getReferenceTrie(c);
        }

        if (!dummy->end) {
            dummy = root;
            for (char c : s) {
                dummy = dummy->getReferenceTrie(c);
                dummy->pushIndex(idx);
            }
        }
        dummy->setEnd();
    }

    vector<string> getStrings (string s, string *v) {
        Node* dummy = root;
        for (char c : s) {
            if (!dummy->containsKey(c)) {
                return {"0"};
            }
            dummy = dummy->getReferenceTrie(c);
        }

        vector<string> ans;
        for (int i : dummy->indices) {
            ans.push_back(v[i]);
        }

        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        sort(contact, contact + n);
        Trie obj;
        for (int i = 0; i < n; i++) {
            obj.createTrie(contact[i], i);
        }

        vector<vector<string>> ans(s.size());
        string pref = "";
        for (int i = 0; i < s.size(); i++) {
            pref += s[i];
            ans[i] = obj.getStrings(pref, contact);
        }

        return ans;
    }
};