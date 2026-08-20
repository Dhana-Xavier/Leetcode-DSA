class Solution {
    public int longestConsecutive(int[] arr) {
        int n= arr.length;
        if(n==0){
            return 0;
        }
        HashSet<Integer> st=new HashSet<>();
        for(int i=0;i<n;i++){
            st.add(arr[i]);
        }
        int mxln=-1;
        for(int i=0;i<n;i++){
           int len=1;
           if(!st.contains(arr[i]-1)){
            int x=arr[i];
            while(st.contains(x+1)){
                len++;
                x++;
            }
           }
           if(len>mxln){
            mxln=len;
           }
        }
        
        return mxln;

    }
}