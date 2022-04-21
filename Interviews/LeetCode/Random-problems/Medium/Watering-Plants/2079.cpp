int wateringPlants(vector<int> &plants, int capacity){
    int ans = 0, curCapacity = capacity;
    for(int i = 0; i < plants.size(); i++){
        if(plants[i] <= curCapacity){
            ans += 1;
            curCapacity -= plants[i];
        }else{
            ans += 2 * i + 1;
            curCapacity = capacity - plants[i];
        }
    }
    return ans;
}