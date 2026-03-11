class Solution {
public:
    int bitwiseComplement(int n) {
        vector<int>ans;
        if(n==0){
            return 1;
        }
        while(n>0){
            int rem=n%2;
            ans.insert(ans.begin(),rem);
            n=n/2;
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]==0){
                ans[i]=1;
            }
            else if(ans[i]==1){
                ans[i]=0;
            }
        }
        int res=0;
        for(int i:ans){
            res=res*2+i;
        }
        return res;
    }
};
