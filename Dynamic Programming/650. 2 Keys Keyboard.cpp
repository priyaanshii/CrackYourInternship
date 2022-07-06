class Solution {
public:
    int minSteps(int n) {
            if(n==1) return 0;
        return solve(1,1,n);
    }
    int solve(int i,int copied_item,int n)
    {
            if(i==n)
                    return 1;
            if(i>n)
                    return 10001;
            int copy_paste = 2 + solve(i*2,i,n);
            int paste = 1 + solve(i+copied_item,copied_item,n);
            
            
            return min(copy_paste,paste);
    }
};
