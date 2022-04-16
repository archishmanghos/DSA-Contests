vector<long> notes;
vector<int> valuation;
ATM(){
    notes.assign(5, 0);
    valuation.assign(5, 0);
    valuation[0] = 20, valuation[1] = 50, valuation[2] = 100, valuation[3] = 200, valuation[4] = 500;
}

void deposit(vector<int> banknotesCount){
    for(int i = 0; i < banknotesCount.size(); i++){
        notes[i] += banknotesCount[i];
    }
}

vector<int> withdraw(int amount){
    int i = 4;
    vector<int> ans(5, 0);
    while(amount > 0 and i >= 0){
        long maxNotes = amount / valuation[i];
        long minTake = min(notes[i], maxNotes);
        ans[i] = minTake;
        amount -= minTake * valuation[i];
        i -= 1;
    }
    
    if(amount == 0){
        for(int i = 0; i < 5; i++){
            notes[i] -= ans[i];
        }
        return ans;
    }else{
        return {-1};
    }
}