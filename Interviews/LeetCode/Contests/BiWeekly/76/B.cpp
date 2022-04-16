long long waysToBuyPensPencils(int total, int cost1, int cost2){
    long long ans = 0;
    for(int i = 0; i <= (total / cost1); i++){
        long long rem = total - i * cost1;
        ans += (rem / cost2) + 1;
    }
    return ans;
}