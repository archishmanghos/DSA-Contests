int countLatticePoints(vector<vector<int>> &circles){
    int n = circles.size();
    set<pair<int, int>> points;
    for(int i = 0; i < n; i++){
        int centreX = circles[i][0], centreY = circles[i][1], radius = circles[i][2];
        int startX = circles[i][0] - radius, startY = circles[i][1] - radius, endX = circles[i][0] + radius, endY = circles[i][1] + radius;
        for(int i = startX; i <= endX; i++){
            for(int j = startY; j <= endY; j++){
                int distSq = (abs(centreX - i) * abs(centreX - i)) + (abs(centreY - j) * abs(centreY - j));
                if(distSq <= (radius *radius)){
                    points.insert({i, j});
                }
            }
        }
    }
    
    return (int)points.size();
}