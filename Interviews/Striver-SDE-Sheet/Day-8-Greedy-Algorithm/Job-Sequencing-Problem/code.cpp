vector<int> JobScheduling(Job arr[], int n){
    sort(arr, arr + n, [](Job &a, Job &b){
        return a.profit > b.profit;
    });
    
    vector<int> deadlineTimes(105, -1);
    int ans = 0, curDeadline = 0, jobsDone = 0;
    for(int i = 0; i < n; i++){
        int curDeadline = arr[i].dead;
        while(curDeadline > 0 and deadlineTimes[curDeadline] != -1) curDeadline -= 1;
        if(curDeadline > 0) deadlineTimes[curDeadline] = arr[i].id, ans += arr[i].profit, jobsDone += 1;
    }
    
    return {jobsDone, ans};
} 