package striver_sde_sheet.array1;

public class P6SBS {
    public int maxProfit(int[] prices) {
        int minStockPrice = prices[0], profit = 0;
        for (int i = 1; i < prices.length; i++) {
            profit = Math.max(profit, prices[i] - minStockPrice);
            minStockPrice = Math.min(minStockPrice, prices[i]);
        }

        return profit;
    }
}