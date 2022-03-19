unordered_map<int, vector<int>> mp;
unordered_map<int, int> count;
int maxCount;
FreqStack(){
    mp.clear();
    count.clear();
    maxCount = 0;
}

void push(int val){
    count[val] += 1;
    if(count[val] > maxCount){
        maxCount = count[val];
    }
    mp[count[val]].push_back(val);
}

int pop() {
    int ans = mp[maxCount].back();
    mp[maxCount].pop_back();
    count[ans] -= 1;
    if(mp[maxCount].size() == 0){
        maxCount -= 1;
    }
    return ans;
}