int minimumRounds(vector<int> &tasks){
    sort(tasks.begin(), tasks.end());
    int cnt = 1, ans = 0;
    for(int i = 1; i < tasks.size(); i++){
        if(tasks[i] == tasks[i - 1]){
            cnt += 1;
        }else{
            if(cnt == 1){
                return -1;
            }
            ans += (cnt + 2) / 3;
            cnt = 1;
        }
    }
    
    if(cnt == 1){
        return -1;
    }
    ans += (cnt + 2) / 3;
    return ans;
}