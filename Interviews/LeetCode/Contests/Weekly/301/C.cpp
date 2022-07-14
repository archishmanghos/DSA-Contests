bool canChange(string start, string target) {
    int l = 0, r = 0, n = start.size();
    for(char c : start) l += c == 'L', r += c == 'R';
    for(char c : target) l -= c == 'L', r -= c == 'R';
    if(l != 0 or r != 0) return false;
    
    set<int> lIndices, rIndices;
    for(int i = 0; i < n; i++){
        if(target[i] == 'L') lIndices.insert(i);
        if(start[i] == 'R') rIndices.insert(i);
        if(start[i] == 'L'){
            if(lIndices.size() == 0) return false;
            int toMove = *lIndices.begin();
            int lastR = (rIndices.size() > 0 ? *rIndices.rbegin() : -1);
            if(lastR >= toMove) return false;
            lIndices.erase(toMove);
        }
    }
    
    lIndices.clear(), rIndices.clear();
    for(int i = n - 1; i >= 0; i--){
        if(target[i] == 'L') lIndices.insert(i);
        if(target[i] == 'R') rIndices.insert(i);
        if(start[i] == 'R'){
            if(rIndices.size() == 0) return false;
            int toMove = *rIndices.rbegin();
            int lastL = (lIndices.size() > 0 ? *lIndices.begin() : n + 1);
            if(lastL <= toMove) return false;
            rIndices.erase(toMove);
        }
    }
    
    return true;
}