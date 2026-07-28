class Solution {
public:
    string smallestPalindrome(string s) {
        string ans="";
        string rev="";
        string odd="";
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto i:mp){
            
                for(int j=0;j<i.second/2;j++){
                    ans+=i.first;
                    rev+=i.first;
                }           
                 if(i.second%2==1)
                 odd+=i.first;
            
                       
        }

        
        ans+=odd;
        reverse(rev.begin(),rev.end());
        ans+=rev;
    
        return ans;
    }
};