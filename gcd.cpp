class Solution {
public:
    long long gcd(long long a,long long b)
    {
        if(a==0)
        {
            return b;
        }
        if(b==0)
        {
            return a;
        }
        while(a!=b)
        {
            if(a>b)
            {
                a-=b;
            }
            else
            {
                b-=a;
            }
        }
        return b;
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long a=0,b=0,c=0,low=1,high=1e10,mid=0;
        long long lcm=(long(divisor1)*long(divisor2))/gcd(long(divisor1),long(divisor2));
        while(low<=high)
        {
            mid=low+(high-low)/2;
            a=mid - mid/divisor1;
            b=mid - mid/divisor2;
            c=mid - mid/divisor1 - mid/divisor2 + mid/lcm;
            if(a>=uniqueCnt1 && b>=uniqueCnt2 && a+b-c>=uniqueCnt1 + uniqueCnt2)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return (int)low;
    }
};