int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        vector<int> makeShiftColumn(R);
    int ans = 0, maxNegative = -INT_MAX;
    
    for(int i = 0; i < C; i++){
        makeShiftColumn.assign(R, 0);
        
        for(int j = i; j < C; j++){
            int sumTillNow = 0;

            for(int k = 0; k < R; k++){
                makeShiftColumn[k] += M[k][j];
                maxNegative = max(maxNegative, M[k][j]);
                sumTillNow += makeShiftColumn[k];
                ans = max(ans, sumTillNow);
                sumTillNow = max((int)0, sumTillNow);
            }
        }
    }
    
    return (maxNegative < 0 ? maxNegative : ans);
}