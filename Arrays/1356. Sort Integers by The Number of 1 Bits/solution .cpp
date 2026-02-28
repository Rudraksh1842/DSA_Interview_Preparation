class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
      unordered_map<int,int>m;
      vector<int>res;
      for(int i:arr){
        m[i]=__builtin_popcount(i);
      }
      int min=INT_MAX;
      int max=INT_MIN;
      for(auto i:m){
         if(i.second<min){
            min=i.second;
         }
         if(i.second>max){
            max=i.second;
         }
      }
     
      for(auto i:m){
        for(int j=min;j<=max;j++){
            if(i.second==j){
                res.push_back(i.first);
            }
        }
      }
      return res;
    }
};
