class Solution {
   public:
    vector<int> minPartition(int N) {
        vector<int> notes = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        vector<int> ans;

        int i = 0;
        while (N > 0) {
            for (int j = 1; j <= (N / notes[i]); j++) {
                ans.push_back(notes[i]);
            }
            N %= notes[i++];
        }

        return ans;
    }
};