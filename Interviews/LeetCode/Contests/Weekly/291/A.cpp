string removeDigit(string number, char digit) {
    string maxNumber = "0";
    for(int i = 0; i < number.size(); i++){
        if(number[i] == digit){
            string newNumber = number.substr(0, i) + number.substr(i + 1);
            maxNumber = max(maxNumber, newNumber);
        }
    }

    return maxNumber;
}