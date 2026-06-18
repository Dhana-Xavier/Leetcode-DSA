class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        map<char,int>mp;

        int l=0,r=0,maxLen=0,maxFreq=0;
        while(r<n){
            mp[s[r]]++;
            maxFreq=max(maxFreq,mp[s[r]]);
            
            while((r-l+1)-maxFreq >k){
             mp[s[l]]--;
             l++;
            }
            if((r-l+1)-maxFreq <= k){
                maxLen=max(maxLen,(r-l+1));
            }
            r++;
        }
        return maxLen;
    }
};