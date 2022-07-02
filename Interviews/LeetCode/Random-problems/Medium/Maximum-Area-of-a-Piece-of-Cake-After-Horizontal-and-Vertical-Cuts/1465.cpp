int getMaxLength(int totalLength, vector<int> lengthArray){
    sort(lengthArray.begin(), lengthArray.end());
    int maxLength = max(lengthArray[0], totalLength - lengthArray.back());
    for(int i = 1; i < lengthArray.size(); i++){
        maxLength = max(maxLength, lengthArray[i] - lengthArray[i - 1]);
    }

    return maxLength;
}

int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    int maxLength = getMaxLength(w, verticalCuts);
    int maxBreadth = getMaxLength(h, horizontalCuts);

    return (maxLength * 1LL * maxBreadth) % int(1e9 + 7);
}