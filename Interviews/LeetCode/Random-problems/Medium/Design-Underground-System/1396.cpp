map<pair<string, string>, int> cntEncounters, timeTaken;
map<int, pair<string, int>> people;
UndergroundSystem(){
    cntEncounters.clear();
    timeTaken.clear();
}

void checkIn(int id, string stationName, int t){
    people[id] = {stationName, t};
}

void checkOut(int id, string stationName, int t){
    string checkInStation = people[id].first;
    int checkInTime = people[id].second;
    people.erase(id);
    timeTaken[ {checkInStation, stationName}] += t - checkInTime;
    cntEncounters[ {checkInStation, stationName}] += 1;
}

double getAverageTime(string startStation, string endStation){
    int totalTime = timeTaken[ {startStation, endStation}];
    int encounters = cntEncounters[ {startStation, endStation}];
    double ans = (double)totalTime / encounters;
    return ans;
}