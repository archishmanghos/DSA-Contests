int uniquePaths(int m, int n){
    if(n > m) swap(n, m);
    double ans = 1;
    for(int i = 1; i <= m - 1; i++) ans = ans * (i + n - 1) / i;
    return (int)ans;
}