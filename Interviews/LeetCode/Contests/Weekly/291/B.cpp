int minimumCardPickup(vector<int>& cards) {
    vector<int> index(int(1e6 + 2), -1);
    int minDist = int(1e7);
    for(int i = 0; i < cards.size(); i++){
        if(index[cards[i]] != -1) minDist = min(minDist, i - index[cards[i]] + 1);
        index[cards[i]] = i;
    }
    return (minDist == int(1e7) ? -1 : minDist);
}