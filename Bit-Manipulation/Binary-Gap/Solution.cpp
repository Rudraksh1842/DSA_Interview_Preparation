class Solution {
public:
    int binaryGap(int n) {
        vector<int>m;
       while(n>0){
          int a=n%2;
          n=n/2;
          m.insert(m.begin(),a);
       } 
       
       int left=0;
       int maxC=0;
       int count=0;
       for(int right=0;right<m.size();right++){
         if(m[left]==1 && m[right]==1){
           count=right-left;
           maxC=max(maxC,count);
           left=right;
         }
       }
     return maxC;
    }
};
