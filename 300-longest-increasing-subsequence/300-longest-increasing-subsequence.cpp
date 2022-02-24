class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        vector<int>  dp(nums.size()+1,1);
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};