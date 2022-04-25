vector<int> ans;
int iterator;
PeekingIterator(const vector<int> &nums) : Iterator(nums){
    ans = nums;
    iterator = 0;
}

int peek(){
    return ans[iterator];
}

int next(){
    return ans[iterator++];
}

bool hasNext() const{
    return iterator < ans.size();
}