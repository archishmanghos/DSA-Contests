int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
    sort(buses.begin(), buses.end());
    sort(passengers.begin(), passengers.end());
    
    set<int> passengerTimes;
    for(int i : passengers) passengerTimes.insert(i);
    
    int ans = 0, i = 0, j = 0;
    while(i < buses.size()){
        int maxCan = capacity;
        while(j < passengers.size() and passengers[j] <= buses[i] and maxCan){
            if(passengerTimes.find(passengers[j] - 1) == passengerTimes.end()) ans = passengers[j] - 1;
            j += 1;
            maxCan -= 1;
        }
        if(maxCan and passengerTimes.find(buses[i]) == passengerTimes.end()) ans = buses[i];
        i += 1;
    }
    
    return ans;
}