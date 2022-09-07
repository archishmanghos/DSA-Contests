int isStackPermutation(int N, vector<int> &A, vector<int> &B) {
    int j = 0;
    stack<int> s;
    for (int i = 0; i < N; i++) {
        s.push(A[i]);
        while (!s.empty() and s.top() == B[j]) {
            s.pop();
            j++;
        }
    }

    return s.empty();
}