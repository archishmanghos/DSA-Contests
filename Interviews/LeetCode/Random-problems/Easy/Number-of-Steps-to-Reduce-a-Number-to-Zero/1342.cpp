int numberOfSteps(int num) {
    if(num == 0) return 0;
    int ans = 1;
    while(num > 1){
        if(num & 1) ans += 2;
        else ans += 1;
        num >>= 1;
    }
    
    return ans;
}