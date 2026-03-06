class Solution {
public:
    bool checkOnesSegment(string s) {
      int flag=0;
      if(s[0]=='1'){
        flag=1;
      }
      for(int i=1;i<s.size();i++){
       
        if(s[i]=='1' && flag==1 && s[i-1]!='1'){
            return false;
        }
        if(s[i]=='1' && s[i-1]=='1'){
            flag=1;
        }

      }
        return flag;
    }
};
