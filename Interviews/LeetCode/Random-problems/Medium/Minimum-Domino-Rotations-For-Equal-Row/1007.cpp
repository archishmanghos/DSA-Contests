int minDominoRotations(vector<int> &tops, vector<int> &bottoms){
    int n = tops.size();
    vector<int> cntA(7, 0), cntB(7, 0), sameAB(7, 0);
    for(int i = 0; i < n; i++){
        cntA[tops[i]] += 1;
        cntB[bottoms[i]] += 1;
        if(tops[i] == bottoms[i]){
            sameAB[tops[i]] += 1;
        }
    }
    
    for(int i = 1; i <= 6; i++){
        if(cntA[i] + cntB[i] - sameAB[i] == n){
            return min(cntA[i], cntB[i]) - sameAB[i];
        }
    }
    
    return -1;
}