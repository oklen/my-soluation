#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t;scanf("%d",&t);
    int ccnt = 1;
    while (t--) {
        string a,b;cin>>a;cin>>b;int w0 = 0,w1=0,cnt = 0,add0 = 0;
        for(int i = 0;i<a.size();++i){
            if(a[i]=='?'){++cnt;if(b[i]=='1')++add0;}
            else if(a[i]==b[i])continue;
            else if(a[i]=='0')++w0;
            else ++w1;
        }
        if(add0<w1-w0) cnt=-1;
        else{
            if(w0>=w1)cnt+=w0;
            else cnt+=w1;
        }
        printf("Case %d: %d\n",ccnt++,cnt);
    }
    return 0;
}
