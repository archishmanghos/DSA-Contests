bool checkBipartite(int node, int parent, vector<int> &colour, vector<vector<int>> &graph){
    if(colour[node] != -1){
        return colour[node] == (1 - colour[parent]);
    }
    
    colour[node] = (parent == -1 ? 0 : 1 - colour[parent]);
    for(int child : graph[node]){
        if(!checkBipartite(child, node, colour, graph)){
            return false;
        }
    }
    
    return true;
}
bool isBipartite(vector<vector<int>> &graph){
    int n = graph.size();
    bool ans = true;
    vector<int> colour(n, -1);
    for(int i = 0; i < n; i++){
        if(colour[i] == -1){
            ans &= checkBipartite(i, -1, colour, graph);
        }
    }
    
    return ans;
}