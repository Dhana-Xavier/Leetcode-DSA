class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int l=0,r=0;
        vector<int>freq(26,0);
        vector<int>currFreq(26,0);
        vector<int>ans;
        
        if(p.size()> s.size()){
            return ans;
        }
        for(int i=0;i<p.size();i++){
            freq[p[i]-'a']++;
            currFreq[s[i]-'a']++;
            r++;
        }
        if(freq == currFreq){
            ans.push_back(0);
        }
        
        while(r<n){
         currFreq[s[r]-'a']++;
         
         currFreq[s[l]-'a']--;
         l++;
         if(freq == currFreq ){
            ans.push_back(l);
         }
         r++;
        }
        return ans;
    }

};