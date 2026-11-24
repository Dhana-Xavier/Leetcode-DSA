class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            long long  prod=nums[i];
            long long  Lcm=nums[i];
            long long  Gcd=nums[i];
            for(int j=i+1;j<n;j++){
                prod=prod*nums[j];
                Lcm=lcm(Lcm,nums[j]);
                Gcd=gcd(Gcd,nums[j]);

                if(prod>(Lcm * Gcd)){
                    break;
                }
                if(prod==(Lcm * Gcd)){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};