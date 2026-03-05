class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i:nums){
            m[i]++;
        }
        for(auto i:m){
            if(i.second>1){
                return i.first;
            }
        }
        return 0;
    }
};
