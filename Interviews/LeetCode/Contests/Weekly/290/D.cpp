vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons){
    unordered_map<int, int> mp;
    vector<int> preCalc, v;
    set<int> s;
    for(int i = 0; i < flowers.size(); i++){
        mp[flowers[i][0]] += 1;
        mp[flowers[i][1] + 1] -= 1;
        s.insert(flowers[i][0]);
        s.insert(flowers[i][1] + 1);
    }
    
    for(int i : s){
        v.push_back(i);
    }
    int total = 0;
    for(int i = 0; i < v.size(); i++){
        total += mp[v[i]];
        preCalc.push_back(total);
    }
    
    vector<int> ans;
    for(int i = 0; i < persons.size(); i++){
        if(persons[i] > v[v.size() - 1]){
            ans.push_back(0);
            continue;
        }
        auto lb = lower_bound(v.begin(), v.end(), persons[i]);
        int index = lb - v.begin();
        if(*lb == persons[i]){
            ans.push_back(preCalc[index]);
        }else{
            if(index == 0){
                ans.push_back(0);
            }else{
                ans.push_back(preCalc[index - 1]);
            }
        }
    }
    
    return ans;
}