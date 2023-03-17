#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *links[26];
    bool eow = false;
    bool containsKey(char c) {
        return links[c - 'a'] != NULL;
    }
    void createKey(char c, Node *link) {
        links[c - 'a'] = link;
    }
    Node *getReferenceTrie(char c) {
        return links[c - 'a'];
    }
    void setEnd() {
        eow = true;
    }
    bool getEnd() {
        return eow;
    }
};
class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *dummy = root;
        for (char c : word) {
            if (!dummy->containsKey(c)) {
                dummy->createKey(c, new Node());
            }
            dummy = dummy->getReferenceTrie(c);
        }
        dummy->setEnd();
    }

    bool search(string word) {
        Node *dummy = root;
        for (char c : word) {
            if (!dummy->containsKey(c)) return false;
            dummy = dummy->getReferenceTrie(c);
        }

        return dummy->getEnd();
    }

    bool startsWith(string prefix) {
        Node *dummy = root;
        for (char c : prefix) {
            if (!dummy->containsKey(c)) return false;
            dummy = dummy->getReferenceTrie(c);
        }

        return true;
    }
};