string LCP(string ar[], int n){
    sort(ar, ar + n);
    string ans = "";
    for(int i = 0; i < ar[0].size(); i++){
        if(ar[0][i] == ar[n - 1][i]){
            ans += ar[0][i];
        }else{
            break;
        }
    }
    
    return (ans.size() ? ans : "-1");
}