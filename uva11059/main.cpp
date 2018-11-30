#include <iostream>
#include <cmath>
using namespace std;
int gc;
int main()
{
    long long a,b,wmax;int n,c;
    while(~scanf("%d",&n))
    {
        wmax = 0;
        bool beginrecord = false;b = 0;
        //scanf("%lld",&a);
        a = 1;
        for(int i = 0;i<n;i++)
        {
            scanf("%d",&c);
            while(c==0&&(i+1)<n)
            {
                scanf("%d",&c); a= 1;b=0;beginrecord = false;
                ++i;
            }
            a*=c;
            if(beginrecord)
                b*=c;
            if(wmax<max(a,b))
              wmax = max(a,b);
            if(c<0&&!beginrecord)
            {beginrecord = true;b=1;}
        }
        cout << "Case #"<<++gc << ":" << " The maximum product is "
             << wmax <<'.'<< endl <<endl;
    }
    return 0;
}
