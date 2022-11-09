class StockSpanner {
   public:
    vector<vector<int>> st;
    StockSpanner() {
        st.clear();
    }

    int next(int price) {
        int crushed = 0;
        while (st.size() > 0 and st.back()[0] <= price) {
            crushed += 1 + st.back()[1];
            st.pop_back();
        }

        st.push_back({price, crushed});
        return 1 + crushed;
    }
};