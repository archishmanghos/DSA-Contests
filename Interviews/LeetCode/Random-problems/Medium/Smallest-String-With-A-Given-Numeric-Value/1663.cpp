string getSmallestString(int n, int k){
    string ans = string(n, 'a');
    k -= n;
    while(k > 0){
        int toReplace = min(25, k);
        ans[--n] = (toReplace + 'a');
        k -= toReplace;
    }
    
    return ans;
}