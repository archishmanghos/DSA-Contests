int numRescueBoats(vector<int> &people, int limit){
    sort(people.begin(), people.end());
    int i = 0, j = people.size() - 1, ans = 0;
    
    while(i <= j){
        ans += 1;
        if(people[i] + people[j] <= limit){
            i += 1;
        }
        j -= 1;
    }
    
    return ans;
}