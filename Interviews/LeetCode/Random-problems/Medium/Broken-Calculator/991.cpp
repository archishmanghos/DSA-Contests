int brokenCalc(int startValue, int target){
    int ans = 0;
    while(target != startValue){
        if(target > startValue){
            if(target & 1){
                target += 1;
                ans += 1;
            }
            target >>= 1;
            ans += 1;
        }else{
            ans += startValue - target;
            break;
        }
    }
    return ans;
}