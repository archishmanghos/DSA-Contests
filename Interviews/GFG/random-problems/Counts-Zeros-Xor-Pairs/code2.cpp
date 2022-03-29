long long int calculate(int a[], int n)
{
    long long ans = 0;
    int cnt = 1;
    sort(a, a + n);
    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1]){
            cnt += 1;
        }else{
            ans += cnt * (cnt - 1) / 2;
            cnt = 1;
        }
    }
    ans += cnt * (cnt - 1) / 2;
    
    return ans;
}