class NumberContainers {
private:
    map<int, int> indicesInUse;
    map<int, set<int>> lowestVal;
public:
    NumberContainers() {
        indicesInUse.clear(), lowestVal.clear();
    }

    void change(int index, int number) {
        if (indicesInUse.find(index) != indicesInUse.end()) {
            int numberAtPlace = indicesInUse[index];
            lowestVal[numberAtPlace].erase(index);
        }
        indicesInUse[index] = number;
        lowestVal[number].insert(index);
    }

    int find(int number) {
        return ((lowestVal.find(number) != lowestVal.end() and lowestVal[number].size() > 0) ? *lowestVal[number].begin() : -1);
    }
};