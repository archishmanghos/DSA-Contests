void subsetSum(int index,int curSum,int &N,vector<int> &ans,vector<int> &arr){
    if(index == N){
        ans.push_back(curSum);
        return;
    }
    
    subsetSum(index + 1, curSum + arr[index], N, ans, arr);
    subsetSum(index + 1, curSum, N, ans, arr);
}
vector<int> subsetSums(vector<int> arr, int N){
    vector<int> ans;
    subsetSum(0, 0, N, ans, arr);
    return ans;
}