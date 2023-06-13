class Solution {
public:
    int climbStairs(int n) {
        int a =0;
        int b = 1;
        int c=2;
        int d=-1;
        if(n==0)return a;
        else if(n==1) return b;
        else if(n==2)return c;
     for(int i = 3; i<=n;i++)
     {
        //  a[i]=a[i-1]+a[i-2];
         d=c+b;
         b=c;
         c=d;


     }
     return d;
    }
};