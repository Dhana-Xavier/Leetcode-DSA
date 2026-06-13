class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n=words.size();
        string ans="";
        for(int i=0;i<n;i++){
            string str=words[i];
            int sum=0;
            for(int j=0;j<str.size();j++){
              int idx=str[j]-'a';
              sum+=weights[idx];
            }
            sum%=26;
            char ch='z'-sum;
            ans+=ch;
        }
        return ans;
    }
};