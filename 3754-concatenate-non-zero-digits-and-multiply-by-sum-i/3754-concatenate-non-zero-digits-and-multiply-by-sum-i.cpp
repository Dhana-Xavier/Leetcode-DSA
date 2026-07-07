class Solution {
public:
    long long sumAndMultiply(int n) {
        string str=to_string(n);
        string ans="";
        long long sum=0;
        for(int i=0;i<str.size();i++){
          if(str[i]=='0'){
            continue;
          }
          else{
            ans+=str[i];
            sum+=str[i]-'0';
          }
        }
        if(ans==""){
            return 0;
        }
        long long res=stoll(ans);
        return res*sum;

    }
};