int addDigits(int num) {
    while (num > 9) {
        int newNum = 0;
        while (num > 0) {
            newNum += num % 10;
            num /= 10;
        }
        num = newNum;
    }
    return num;
}