class Solution {
public:
    int kthFactor(int n, int k) {
        int i;
        for(i=1;i*i<=n;i++)
            if(n%i==0 and --k==0)
                return i;    
            
        i--;
        for(;i>0;i--){
            if(i*i==n)
                continue;
            if(n%i==0 and --k==0)
                return n/i;
        }
        
        return -1;
    }
};