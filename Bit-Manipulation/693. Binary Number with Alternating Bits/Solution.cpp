class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int>res;
        while(n>0){
            int a=n%2;
            n=n/2;
            res.insert(res.begin(),a);
        }
        for(int i=0;i<res.size()-1;i++){
           if(res[i+1]==res[i]){
            return false;
           }
        }
        return true;
    }
};
