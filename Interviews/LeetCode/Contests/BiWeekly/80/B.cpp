class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        for(int i = 0; i < spells.size(); i++){
            int reqdMin = (success + spells[i] - 1) / spells[i];
            int noSpells = lower_bound(potions.begin(), potions.end(), reqdMin) - potions.begin();
            ans.push_back((int)potions.size() - noSpells);
        }

        return ans;
    }
};