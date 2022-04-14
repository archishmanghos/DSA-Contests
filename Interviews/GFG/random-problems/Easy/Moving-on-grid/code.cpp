string movOnGrid(int r, int c){
    return (((r - 1) % 7) != ((c - 1) % 4) ? "JON" : "ARYA");
}