public class BestTimeToBuyAndSellStockIII {
    //    o(n) O(n)
    int maxProfit(int[] prices) {
        int maxProfit = 0;
        int n = prices.length;
        int[] leftMaxProfit = new int[n];
        int[] rightMaxProfit = new int[n];

        int minPrice = prices[0];
        for(int i = 1; i < n; i++){
            minPrice = Math.min(minPrice, prices[i]);
            leftMaxProfit[i] = Math.max(leftMaxProfit[i - 1], prices[i] - minPrice);
        }

        int maxPrice = prices[n - 1];
        for(int i = n - 2; i >= 0 ; i--){
            maxPrice = Math.max(maxPrice, prices[i]);
            rightMaxProfit[i] = Math.max(rightMaxProfit[i + 1], maxPrice - prices[i]);
        }

        for(int i = 0; i < n ; i++){
            maxProfit = Math.max(maxProfit, rightMaxProfit[i] + leftMaxProfit[i]);
        }

        return maxProfit;
    }


    //O(n^2) O(1)
    int maxProfit_II(int[] prices) {
        int profit = 0;
        for (int i = 0; i < prices.length; i++) {
            profit = Math.max(profit, getMaxProfit(prices, 0, i) + getMaxProfit(prices, i + 1, prices.length - 1));
        }
        return profit;
    }
    int getMaxProfit(int[] prices, int start, int end) {
        int profit = 0, minPrice = Integer.MAX_VALUE;
        for(int i = start; i <= end; i++) {
            minPrice = Math.min(minPrice, prices[i]);
            profit = Math.max(profit, prices[i] - minPrice);
        }
        return profit;
    }
}

