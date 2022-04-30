int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls){
    unordered_map<int, set<int>> rowW, columnW, rowG, columnG;
    
    for(auto i : walls){
        int r = i[0], c = i[1];
        rowW[r].insert(c);
        columnW[c].insert(r);
    }
    
    for(auto i : guards){
        int r = i[0], c = i[1];
        rowG[r].insert(c);
        columnG[c].insert(r);
    }
    
    int ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(rowG[i].find(j) != rowG[i].end() and columnG[j].find(i) != columnG[i].end()){
                continue;
            }
            if(rowW[i].find(j) != rowW[i].end() and columnW[j].find(i) != columnW[i].end()){
                continue;
            }
            
            int closestGuardToLeft = -1, closestGuardToRight = -1, closestGuardToUp = -1, closestGuardToDown = -1;
            if(n > 1){
                if(rowG[i].size()){
                    if(*rowG[i].begin() < j){
                        if(*rowG[i].rbegin() < j){
                            closestGuardToLeft = *rowG[i].rbegin();
                        }else{
                            auto it = rowG[i].lower_bound(j);
                            it--;
                            closestGuardToLeft = *it;
                        }
                    }
                    if(*rowG[i].rbegin() > j){
                        if(*rowG[i].begin() > j){
                            closestGuardToRight = *rowG[i].begin();
                        }else{
                            auto it = rowG[i].lower_bound(j);
                            closestGuardToRight = *it;
                        }
                    }
                }
            }
            
            if(m > 1){
                if(columnG[j].size() > 0){
                    if(*columnG[j].begin() < i){
                        if(*columnG[j].rbegin() < i){
                            closestGuardToUp = *columnG[j].rbegin();
                        }else{
                            auto it = columnG[j].lower_bound(i);
                            it--;
                            closestGuardToUp = *it;
                        }
                    }
                    if(*columnG[j].rbegin() > i){
                        if(*columnG[j].begin() > i){
                            closestGuardToDown = *columnG[j].begin();
                        }else{
                            auto it = columnG[j].lower_bound(i);
                            closestGuardToDown = *it;
                        }
                    }
                }
            }
            
            int closestWallToLeft = -1, closestWallToRight = n, closestWallToUp = -1, closestWallToDown = m;
            if(n > 1){
                if(rowW[i].size()){
                    if(*rowW[i].begin() < j){
                        if(*rowW[i].rbegin() < j){
                            closestWallToLeft = *rowW[i].rbegin();
                        }else{
                            auto it = rowW[i].lower_bound(j);
                            it--;
                            closestWallToLeft = *it;
                        }
                    }
                    if(*rowW[i].rbegin() > j){
                        if(*rowW[i].begin() > j){
                            closestWallToRight = *rowW[i].begin();
                        }else{
                            auto it = rowW[i].lower_bound(j);
                            closestWallToRight = *it;
                        }
                    }
                }
            }
            
            if(m > 1){
                if(columnW[j].size() > 0){
                    if(*columnW[j].begin() < i){
                        if(*columnW[j].rbegin() < i){
                            closestWallToUp = *columnW[j].rbegin();
                        }else{
                            auto it = columnW[j].lower_bound(i);
                            it--;
                            closestWallToUp = *it;
                        }
                    }
                    if(*columnW[j].rbegin() > i){
                        if(*columnW[j].begin() > i){
                            closestWallToDown = *columnW[j].begin();
                        }else{
                            auto it = columnW[j].lower_bound(i);
                            closestWallToDown = *it;
                        }
                    }
                }
            }
            
            bool okCell = true;
            if(closestGuardToLeft != -1 and closestGuardToLeft > closestWallToLeft){
                okCell = false;
            }
            if(closestGuardToRight != -1 and closestGuardToRight < closestWallToRight){
                okCell = false;
            }
            if(closestGuardToUp != -1 and closestGuardToUp > closestWallToUp){
                okCell = false;
            }
            if(closestGuardToDown != -1 and closestGuardToDown < closestWallToDown){
                okCell = false;
            }
            
            ans += okCell == true;
            
        }
    }
    
    return ans;
}