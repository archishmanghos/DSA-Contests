int minimumNumbers(int num, int k) {
    if(num == 0) return 0;
    if(num < k) return -1;
    int digit = num % 10;
    if(k == 0) return (digit == 0 ? 1 : -1);
    if(k == 1) return (digit > 0 ? digit : 10);
    if(k == 2) return (digit % 2 ? -1 : digit == 0 ? 5 : digit / k);
    if(k == 3) {
        int multiple[10] = {10, 7, 4, 1, 8, 5, 2, 9, 6, 3};
        return (multiple[digit] * k <= num ? multiple[digit] : -1);
    }
    if(k == 4){
        int multiple[10] = {5, -1, 3, -1, 1, -1, 4, -1, 2, -1};
        return (multiple[digit] * k <= num ? multiple[digit] : -1);
    }
    if(k == 5){
        int multiple[10] = {2, -1, -1, -1, -1, 1, -1, -1, -1, -1};
        return (multiple[digit] * k <= num ? multiple[digit] : -1);
    }
    if(k == 6) {
        int multiple[10] = {5, -1, 2, -1, 4, -1, 1, -1, 3, -1};
        return (multiple[digit] * k <= num ? multiple[digit] : -1);
    }
    if(k == 7) {
        int multiple[10] = {10, 3, 6, 9, 2, 5, 8, 1, 4, 7};
        return (multiple[digit] * k <= num ? multiple[digit] : -1);
    }
    if(k == 8){
        int multiple[10] = {5, -1, 4, -1, 3, -1, 2, -1, 1, -1};
        return (multiple[digit] * k <= num ? multiple[digit] : -1);
    }
    if((10 - digit)*k <= num) return 10 - digit;
    return -1;
}