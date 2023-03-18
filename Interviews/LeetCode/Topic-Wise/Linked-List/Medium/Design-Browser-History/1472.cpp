#include <bits/stdc++.h>
using namespace std;

struct Page {
    string val;
    Page *pre, *next;
public:
    Page (string val, Page *prepoint, Page *nextpoint) {
        this->val = val;
        pre = prepoint;
        next = nextpoint;
    }
};
class BrowserHistory {
    Page *root;
public:
    BrowserHistory(string homepage) {
        root = new Page(homepage, NULL, NULL);
    }

    void visit(string url) {
        root->next = NULL;
        Page *temp = new Page(url, root, NULL);
        root->next = temp;
        root = root->next;
    }

    string back(int steps) {
        while (steps and root->pre) {
            root = root->pre;
            steps--;
        }

        return root->val;
    }

    string forward(int steps) {
        while (steps and root->next) {
            root = root->next;
            steps--;
        }

        return root->val;
    }
};