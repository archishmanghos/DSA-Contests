class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if(password.size() < 8) return false;
        bool upperCase = false, lowerCase = false, digit = false, spCh = false;
        string special = "!@#$%^&*()-+";
        for(char c : password){
            upperCase |= (c >= 'A' and c <= 'Z');
            lowerCase |= (c >= 'a' and c <= 'z');
            digit |= (c >= '0' and c <= '9');
            size_t found = special.find(c);
            spCh |= (found != string::npos);
        }

        if(!upperCase or !lowerCase or !digit or !spCh) return false;
        for(int i = 1; i < password.size(); i++){
            if(password[i] == password[i - 1]) return false;
        }

        return true;
    }
};