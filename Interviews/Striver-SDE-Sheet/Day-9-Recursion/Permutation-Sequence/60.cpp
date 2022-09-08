class Solution {
public:
    void factorialValue(int n, vector<int> &factValue){
        int prod = 1;
        for(int i = 1; i < n; i++) prod *= i, factValue.push_back(prod);
    }

    void findKthPermutation(int index, vector<int> &integers, vector<int> &factValue, int &k, string &s){
        if(integers.size() == 1){
            s.push_back(integers[0] + '0');
            return;
        }
        int blockNo = k / factValue[index];
        k %= factValue[index];
        s.push_back(integers[blockNo] + '0');
        integers.erase(integers.begin() + blockNo);
        findKthPermutation(index - 1, integers, factValue, k, s);
    }
    
    string getPermutation(int n, int k){
        string ans = "";
        k -= 1;
        vector<int> integers, factValue;
        for(int i = 1; i <= n; i++) integers.push_back(i);
        factorialValue(n, factValue);
        findKthPermutation(n - 2, integers, factValue, k, ans);
        return ans;
    }
};