int halveArray(vector<int> &nums){
    priority_queue<double> pq;
    double sum = 0.0;
    for(int i : nums){
        pq.push((double)i);
        sum += (double)i;
    }
    
    double achieveSum = sum / 2.0;
    int ans = 0;
    while(!pq.empty()){
        double cur = pq.top();
        pq.pop();
        double newCur = cur / 2.0;
        sum -= newCur;
        ans += 1;
        if(sum <= achieveSum){
            return ans;
        }
        pq.push(newCur);
    }
    
    return ans;
}