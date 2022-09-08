int majorityElement(vector<int> &nums){
    int count = 0, majorityElement = 0;
    for(int i : nums){
        if(count == 0) majorityElement = i;
        if(i == majorityElement) count += 1;
        else count -= 1;
    }
    
    return majorityElement;
}