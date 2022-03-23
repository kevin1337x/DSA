class Solution {
public:
    int recur(vector<int>& prices,vector<vector<int>> &dp,int idx,bool buy){
        if(idx>=prices.size())
            return 0;
        if(dp[idx][buy]!=-1)
            return dp[idx][buy];
        
        if(buy){
            return dp[idx][buy] = max(recur(prices,dp,idx+1,!buy)-prices[idx],recur(prices,dp,idx+1,buy));
        }
        return dp[idx][buy] = max(recur(prices,dp,idx+1,buy),recur(prices,dp,idx+1,!buy)+prices[idx]);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        
        int sell=INT_MIN,buy=0;
        for(auto p:prices){
            int prev=buy;
            sell = max(sell,prev-p);
            buy = max(buy,sell+p);
        }
        return buy;
        //return recur(prices,dp,0,1);
    }
};