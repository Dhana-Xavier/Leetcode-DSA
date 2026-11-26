class Solution {
public:
    bool canAliceWin(int n) {
        bool flag1=true;
        bool flag2=false;
        bool ans=false;
        int var=10;
        while(n>1){
           if(flag1){
            n-=var;
            var--;
            if(n>=0){
                ans=true;
            }
            flag1=!flag1;
            
           }
           else{
            n-=var;
            var--;
            if(n>=0){
                ans=false;;
            }
            flag1=!flag1;
            
           }
        }
        return ans;

    }
};