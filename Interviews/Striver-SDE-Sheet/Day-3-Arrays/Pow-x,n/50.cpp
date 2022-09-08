double myPow(double x, int n){
    double ans = 1.0;
    long long n1 = abs(n);
    
    while(n1 > 0){
        if(n1 % 2 == 0) x *= x, n1 >>= 1;
        else ans *= x, n1 -= 1;
    }
    
    ans = (n < 0 ? (double)1 / ans : ans);
    return ans;
}