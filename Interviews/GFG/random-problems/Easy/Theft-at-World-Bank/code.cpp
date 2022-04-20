bool checkPerfectSquare(long long x){
    return ((long long)sqrt(x) * (long long)sqrt(x) == x);
}

long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
    vector<pair<long double, long long>> v;
    for(int i = 0; i < N; i++){
        v.push_back({(long double)p[i] / w[i], w[i]});
    }
    
    sort(v.begin(), v.end(), [](pair<long double, long long> &a, pair<long double, long long> &b){
        return a.first > b.first;
    });
    
    long double ans = 0.0;
    for(auto i : v){
        if(C and !checkPerfectSquare(i.second)){
            long long canCut = min(i.second, C);
            ans += i.first * canCut;
            C -= canCut;
        }
    }
    
    return ans;
}