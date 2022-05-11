string largestNumber(int n, int sum){
    string ans = "";
    while(n--){
        int canAdd = min(9, sum);
        ans += (canAdd + '0');
        sum -= canAdd;
    }
    
    return (sum ? "-1" : ans);
}