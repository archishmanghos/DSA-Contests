int swapBitGame(long long N) {
    int setBits = 0;
    for (int i = 0; i <= 45; i++) {
        if ((N >> i) & 1) {
            setBits += 1;
        }
    }

    return (setBits & 1 ? 1 : 2);
}