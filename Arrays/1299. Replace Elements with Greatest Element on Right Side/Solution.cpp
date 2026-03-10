class Solution {
public:
    int minFlips(string s) {
        int count=0;
        int count2=0;
        string j=s;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                s[i+1]=s[i+1]^1;
                count++;
            }
        }
        reverse(j.begin(),j.end());
        for(int i=0;i<s.size()-1;i++){
            if(j[i]==j[i+1]){
                j[i+1]=j[i+1]^1;
                count2++;
            }
        }
        return min(count,count2);
    }
};
