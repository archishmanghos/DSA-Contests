int *greaterElement(int arr[], int n){
    vector<int> v;
    for(int i = 0; i < n; i++){
        v.push_back(arr[i]);
    }
    
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        int index = upper_bound(v.begin(), v.end(), arr[i]) - v.begin();
        if(index < n){
            arr[i] = v[index];
        }else{
            arr[i] = -10000000;
        }
    }
    return arr;
}