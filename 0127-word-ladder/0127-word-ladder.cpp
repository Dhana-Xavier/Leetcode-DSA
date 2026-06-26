class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& words) {
        
        queue<pair<string,int>>q;
        unordered_set<string>st(words.begin(),words.end());

        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string wrd=it.first;
            int level=it.second;
            if(wrd==endWord){
                return level;
            }

            for(int i=0;i<wrd.size();i++){
                char ori=wrd[i];
                for(char ch='a';ch<='z';ch++){
                   wrd[i]=ch;
                   if(st.count(wrd)){
                    st.erase(wrd);
                    q.push({wrd,level+1});
                   } 
              }
              wrd[i]=ori;
            }
        }
        return 0;
    }
};