#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
long sum,w1,v1,w2,v2;

int main()
{
    unsigned int n;scanf("%d\n",&n);unsigned int casecnt = 0;
    while(n--)
    {
        scanf("%ld%ld%ld%ld%ld",&sum,&w1,&v1,&w2,&v2);
        if(1.0*v1/w1 < 1.0*v2/w2)
        {
            long c;c = v1;v1=v2;v2=c;
            c=w1;w1=w2;w2=c;
        }
        cout << "Case #" << ++casecnt << ": ";
            if(w1==w2)
             cout <<  sum/w1*1LL*v1 <<endl;
            else
            {
                unsigned long cnt1 = sum/w1,cnt2= (sum%w1)/w2;
                double left = (sum%w1)%w2;
////                cout << "max value:" <<  <<endl;;
                    unsigned long  mostusedSpace =  ceil(left*(1.0*v2/w2)/(1.0*v1/w1-1.0*v2/w2));
                    unsigned long  mostswitchcnt =  mostusedSpace/w1+1;
                    long long maxvalue = 1LL*cnt1*v1+1LL*cnt2*v2;
                    for(unsigned i = 0; i <= (mostswitchcnt*2) && i <= cnt1;++i)
                    {
                        if(1LL*(sum-w1*(cnt1-i))/w2*v2+1LL*v1*(cnt1-i)>maxvalue)
                        {
                            maxvalue = 1LL*(sum-w1*(cnt1-i))/w2*v2+1LL*v1*(cnt1-i);
                        }
                    }
                    cout << maxvalue <<endl;
            }
    }
    return 0;
}
