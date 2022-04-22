int sum(int a, int b){
    int carry = 0, ans = 0;
    for(int i = 0; i <= 31; i++){
        int x = ((a & (1 << i)) ? 1 : 0);
        int y = ((b & (1 << i)) ? 1 : 0);
        int add = x + y + carry;
        if(add % 2){
            ans |= (1 << i);
        }
        carry = (add >= 2 ? 1 : 0);
    }
    return ans;
}