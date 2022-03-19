bool divideArray(vector<int> &nums){
    vector<int> count(505, 0);
    for(int i : nums){
        count[i] += 1;
    }
    
    bool even = true;
    for(int i = 1; i <= 500; i++){
        even &= (count[i] % 2 == 0);
    }
    
    return even;
}