vector<int> subsetSums(vector<int> arr, int N){
    vector<int> ans;
    for(int i = 0; i < (1 << N); i++){
        int curSum = 0;
        for(int j = 0; j < N; j++){
            if(i & (1 << j)) curSum += arr[j];
        }
        ans.push_back(curSum);
    }
    
    return ans;
}

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