set<int> ans;
SmallestInfiniteSet() {
    ans.clear();
    for(int i = 1; i <= 1000; i++) ans.insert(i);
}

int popSmallest() {
    int small = *ans.begin();
    ans.erase(small);
    return small;
}

void addBack(int num) {
    ans.insert(num);
}