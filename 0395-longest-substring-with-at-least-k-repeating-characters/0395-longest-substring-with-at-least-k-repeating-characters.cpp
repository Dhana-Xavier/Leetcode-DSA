class Solution {
public:
    int longestSubstring(string s, int k) {
        int n= s.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
             freq[s[j]-'a']++;
             bool ok=true;
             for(int l=0;l<26;l++){
                if(freq[l]>0 && freq[l]<k){
                    ok=false;
                    break;
                }
             }
             if(ok){
                maxi=max(maxi,j-i+1);
             }
            }
        }
        return maxi;
    }
};