int findLength(vector<int>& A, vector<int>& B) {
    int out = 0;
    for (int i = 0; i < A.size() + B.size() - 1; i++)
    {
        int sA = std::max(0, (int)A.size() - 1 - i);
        int sB = std::max(0, i - (int)A.size() + 1);
        int cnt = 0;
        //slding window with increasing overlapping between A and B
        for (; sA < A.size() && sB < B.size(); sA++, sB++)
        {
            if (A[sA] == B[sB])
            {
                cnt++;
                out = max(cnt, out);
            }
            else
                cnt = 0;
        }
    }
    return out;
}