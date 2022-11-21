class Solution{
	public:
	void helper (int n, vector<int> curSet, vector<vector<int>> &ans) {
	    if (n == 0) {
	        ans.push_back(curSet);
	        return;
	    }
    
        int last = (curSet.size() == 0 ? n : min(n, curSet.back()));
	    for (int i = last; i >= 1; i--) {
	        curSet.push_back(i);
	        helper (n - i, curSet, ans);
	        curSet.pop_back();
	    }
	}
    vector<vector<int>> UniquePartitions(int n) {
        vector<vector<int>> ans;
        helper (n, {}, ans);
        return ans;
    }
};