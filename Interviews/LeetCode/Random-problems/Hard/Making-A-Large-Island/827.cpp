bool checkValid(int indexX, int indexY, int &n){
    return (indexX >= 0 and indexX<n and indexY >= 0 and indexY < n);
}
void findIsland(int indexX, int indexY, int &colour, int &area, int &n, vector<vector<bool>> &visited, vector<vector<int>> &grid){
    if(!checkValid(indexX, indexY, n)){
        return;
    }
    if(grid[indexX][indexY] == 0 or visited[indexX][indexY]){
        return;
    }
    area += 1;
    grid[indexX][indexY] = colour;
    visited[indexX][indexY] = true;
    
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    for(int i = 0; i < 4; i++){
        findIsland(indexX + dx[i], indexY + dy[i], colour, area, n, visited, grid);
    }
}
int largestIsland(vector<vector<int>> &grid){
    int ans = 0, n = grid.size(), colour = 0;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<int> areaColour;
    areaColour.push_back(-1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j] and grid[i][j] == 1){
                int area = 0;
                colour += 1;
                findIsland(i, j, colour, area, n, visited, grid);
                areaColour.push_back(area);
                ans = max(ans, area);
            }
        }
    }
    
    if(ans == n *n){
        return ans;
    }
    
    int finalAns = ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 0){
                int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, areaCanBeAdded = 1;
                set<int> coloursArea;
                
                for(int k = 0; k < 4; k++){
                    int cellX = i + dx[k], cellY = j + dy[k];
                    if(!checkValid(cellX, cellY, n)){
                        continue;
                    }
                    if(grid[cellX][cellY] != 0){
                        coloursArea.insert(grid[cellX][cellY]);
                    }
                }
                
                for(int i : coloursArea){
                    areaCanBeAdded += areaColour[i];
                }
                
                finalAns = max(finalAns, areaCanBeAdded);
            }
        }
    }
    
    return finalAns;
}