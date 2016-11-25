class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0 || prices.size() <= 1) {
            return 0;
        }
        k=min(k,prices.size()/2);
        int* buy = new int[k];
        int* sell = new int[k];
        for(int i=0;i<k;i++){buy[i]=-2000000000;sell[i]=0;}
        for (int i = 0; i < prices.size(); ++ i) {
            buy[0] = max(buy[0], -prices[i]);
            sell[0] = max(sell[0], buy[0] + prices[i]);
            for (int j = 1; j < k; ++ j) {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        int ret = sell[k-1];
        delete[] buy;
        delete[] sell;
        return ret;
    }
    int min(int a,int b){
        return a<b?a:b;
    }
};