class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMin=nums[0];
        int currMax=nums[0];
       int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int temp=currMax;
            currMax=max({nums[i],currMax*nums[i],currMin*nums[i]});
            currMin=min({nums[i],nums[i]*temp,currMin*nums[i]});
            ans=max(currMax,ans);
        }
        
        return ans;
    }
};
