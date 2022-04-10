void segregateElements(int arr[], int n){
    vector<int> a;
    for(int i = 0; i < n; i++){
        a.push_back(arr[i]);
    }
    
    for(int i = 0; i < n; i++){
        if(a[i] < 0){
            a.push_back(a[i]);
        }
    }
    
    int j = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i]<0 and i >= n){
            arr[j++] = a[i];
        }else if(a[i] >= 0){
            arr[j++] = a[i];
        }
    }
}