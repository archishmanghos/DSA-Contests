int isSTString(string s) {
    for(char c : s){
        if(c != 'S' and c != 't') return 0;
    }

    return 1;
}
