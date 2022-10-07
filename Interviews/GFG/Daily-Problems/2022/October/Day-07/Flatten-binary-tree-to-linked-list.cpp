class Solution {
public:
    void flatten(Node *root) {
        vector<Node*> st;
        st.push_back(root);

        while (st.size()) {
            Node* curNode = st.back();
            st.pop_back();

            if (curNode->right) {
                st.push_back(curNode->right);
            }
            if (curNode->left) {
                st.push_back(curNode->left);
            }

            if (st.size()) {
                curNode->right = st.back();
            }
            curNode->left = NULL;
        }
    }
};