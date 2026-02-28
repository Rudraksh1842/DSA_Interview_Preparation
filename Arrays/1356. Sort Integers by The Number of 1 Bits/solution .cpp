class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>v;
        vector<int>res;
        for(int num:arr){
            v.push_back({__builtin_popcount(num),num});
        }
        sort(v.begin(),v.end());
        for(auto &p:v){
            res.push_back(p.second);
        }
        return res;
    }
};
