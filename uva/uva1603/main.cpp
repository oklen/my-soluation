#include <iostream>
#include <cstring>
#include <unordered_set>
#include <cstdio>
#include <bitset>

using namespace std;
unsigned long bp,bbp;
char inc[61];int n,nsize,n21;
int maxd;
unsigned long ct[10];
unsigned cnts[5];
unsigned llmax;
struct Hash{
    size_t operator()(const long in)const
    {
        return in%10000071;
    }
};

unordered_set<long,Hash> sp;

void showbits(unsigned long in,int length,int nn)
{
    int cnt = 0;
    while(true&&cnt<length)
    {
        for(int i=0;i<nn&&cnt<length;++i,++cnt)
            if(in&(1LL<<cnt))cout<<" 0";else cout << " -";
        cout <<endl;
        for(int i =0;i<nn+1&&cnt<length;++i,++cnt)
            if(in&(1LL<<cnt))cout << "0 ";else cout << "| ";
        cout <<endl;
    }
}
int check(int dep)
{
    memset(cnts,0,sizeof(unsigned)*5);
  for(int i = 0;i<n;++i)
      for(int j = 0;j<n-i;++j)
          for(int k = 0;k<n-i;++k)
            if(!(bp&(ct[i]<<(k+j*(n21)))))
                ++cnts[i];
  unsigned mm = 0;
  for(int i = 0;i<n;++i)
      mm = max(mm,cnts[i]);
  if(mm==0)
  {
      return 1;
  }
  else if(mm>=2*(maxd-dep))
      return  -1;
  else
      return 0;
//    memset(cnts,0,sizeof(unsigned)*5);
//    unsigned mm = 0;
//  for(int i = 0;i<n;++i)
//      for(int j = 0;j<n-i;++j)
//          for(int k = 0;k<n-i;++k)
//            if(!(bp&(ct[i]<<(k+j*(n21)))))
//                ++mm;
//  if(mm==0)
//  {
//      return 1;
//  }
//  else if(llmax<mm)
//      return  -1;
//  else
//      llmax = mm;
//    return 0;
}

bool solve(int dep,int at)
{
    switch (check(dep)) {
    case 1:return true;
    case -1:return false;
    default:;
    }

    if(dep == maxd)
        return false;
    unsigned long ss = 1;
    for(int i = at;i<nsize;++i)
    {
        if(!(ss&bp)) bp|=ss;
        else {ss=1LL<<i;continue;}
        if(solve(dep+1,i))return true;
        bp&=~ss;
        ss=1LL<<i;
    }
    return false;
}


int main()
{
//    freopen("/media/root/Dstore/LENOVO/Qt_Project/build-uva1603-Desktop_Qt_5_11_1_GCC_64bit-Debug/input","r",stdin);
    int t,k;scanf("%d",&t);int mc;int cache;getchar();
    while(t--)
    {
        bp = 0;cache = 0;
        scanf("%d%d",&n,&k);
        while(k--)
        {scanf("%d",&mc);bp|=1LL<<(mc-1);}
        bbp = bp;nsize = n*(n+1)*2;n21=n+n+1;
        memset(ct,0,sizeof(unsigned long)*10);
        for(int i =1;i<=n;++i)
          {
            for(int j = 0;j<i;++j)
              {
                ct[i-1]|=1LL<<(j);
                ct[i-1]|=1LL<<((n21)*j+n);
                ct[i-1]|=1LL<<((n21)*j+n+i);
                ct[i-1]|=1LL<<((n21)*(i)+j);
              }
          }

        for(maxd = 0;;++maxd)
        {
            llmax = 100000;
            if(solve(0,0))break;
            bp =bbp;
        }
        cout << maxd << endl;
    }
    return 0;
}
