class Solution {
public:
    double calculateTax(vector<vector<int>> &brackets, int income){
        double tax = 0.0;
        int prev = 0;
        for(int i = 0; i < brackets.size(); i++){
            int taxableIncome = min(brackets[i][0] - prev, income);
            double taxNow = ((double)brackets[i][1] / 100.0) * taxableIncome;
            tax += taxNow;
            income -= taxableIncome;
            prev = brackets[i][0];
        }

        return tax;
    }
};