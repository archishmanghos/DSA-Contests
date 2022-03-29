vector<int> Smallestonleft(int arr[], int n)
{
    set<int> s;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(s.size() and *s.begin() < arr[i]){
            auto it = s.lower_bound(arr[i]);
            it--;
            ans.push_back(*it);
        }else{
            ans.push_back(-1);
        }
        s.insert(arr[i]);
    }
    
    return ans;
}