class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int count=0; int sum=0;
        m[0]=1;
        for(int n:nums){
          sum+=n;
          if(m.find(sum-k)!=m.end()){
            count+=m[sum-k];
          }
          m[sum]++;
        }
        return count;
    }
};
