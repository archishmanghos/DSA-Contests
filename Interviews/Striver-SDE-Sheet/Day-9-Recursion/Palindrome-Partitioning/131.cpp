class PartitionRecursion{
private:
    string S;
    int N;
public:
    PartitionRecursion(string S1){
        S = S1;
        N = S1.size();
    }

    bool isPalindrome(string s, int i, int j){
        while(i < j){
            if(s[i++] != s[j--]) return false;
        }

        return true;
    }

    void partition(int index, vector<string> partitionDetails, vector<vector<string>> &ans){
        if(index == N){
            ans.push_back(partitionDetails);
            return;
        }
        for(int i = index; i < N; i++){
            if(isPalindrome(S, index, i)){
                partitionDetails.push_back(S.substr(index, i - index + 1));
                partition(i + 1, partitionDetails, ans);
                partitionDetails.pop_back();
            }
        }
    }

    vector<vector<string>> findAnswer(){
        vector<vector<string>> ans;
        partition(0, {}, ans);
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> partition(string s){
        PartitionRecursion obj(s);
        return obj.findAnswer();
    }
};