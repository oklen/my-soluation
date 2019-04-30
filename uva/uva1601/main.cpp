#include <iostream>
#include <bits/stdc++.h>
#include <list>

using namespace std;
struct st{
                unsigned char pp[4];int ti;
                st(unsigned char ap,unsigned char bp,unsigned char cp,int ti):ti{ti}
          {pp[0] = ap;pp[1] = bp;pp[2] = cp;}st(){}
};

bool tiz[255*255*255];
char sp[16][16];
int w,h,n,ans;
const char dx[]{1,-1,0,0,0},dy[]{0,0,1,-1,0};
unsigned char dd[3];
list<st> sts;

bool inline operator==(pair<int,int>& in,unsigned char cp)
{
    return in.first == cp%w&&in.second==cp/w;
}

void solve(st& t)
{
    int i;int mtime = 0;
    for(i = 0;i<n;++i)
        mtime+=(t.pp[i]<<(i*8));

    if(tiz[mtime]) return;
    else  tiz[mtime] = true;

    for(i = 0;i<n;++i)
        if(!(dd[i]==t.pp[i]))
            break;
    if(i == n) {ans = t.ti;return;}
//    cout << t.ti <<endl;
//    for(i = 0;i<n;++i)
//        cout << (char)('a'+i) << " " << t.pp[i]%w << " " << t.pp[i]/w << endl;

     if(n==3)
      {
        for(int i = 0;i<5;++i)
        {
            unsigned char ap = t.pp[0]+dx[i]+dy[i]*w;
            if(sp[ap/w][ap%w]!='#')
            for(int j =0;j<5;++j)
            {
                unsigned char bp = t.pp[1]+dx[j]+dy[j]*w;
                if(sp[bp/w][bp%w]!='#'&&ap!=bp&&(ap!=t.pp[1]||bp!=t.pp[0]))
                for(int k=0;k<5;++k)
                {
                    unsigned char cp = t.pp[2]+dx[k]+dy[k]*w;
                    //cout << (int)ap << " " << (int)bp << " " << (int)cp <<" " <<endl;
                    if(sp[cp/w][cp%w]!='#'&&bp!=cp&&ap!=cp
                            &&(ap!=t.pp[2]||cp!=t.pp[0])&&(bp!=t.pp[2]||cp!=t.pp[1]))
                    {
                        if(!tiz[ap+(bp<<8)+(cp<<16)])
                        {
                            sts.push_back(st(ap,bp,cp,t.ti+1));
                        }
                    }
                }
            }
        }
      }
     else if(n == 1)
       {
         for(int i = 0;i<5;++i)
           {
             if(sp[t.pp[0]/w][t.pp[0]%w]!='#')
               sts.push_back(st(t.pp[0]+dx[i]+dy[i]*w,0,0,t.ti+1));
           }
       }
     else if(n == 2)
       {
         for(int i = 0;i<5;++i)
           for(int j = 0;j<5;++j)
             {
               unsigned char ap = t.pp[0]+dx[i]+dy[i]*w,bp = t.pp[1]+dx[j]+dy[j]*w;
               if(sp[ap/w][ap%w]!='#'&&sp[bp/w][bp%w]!='#'
                  && bp != ap &&(ap != t.pp[1] || bp != t.pp[0]))
                 {
                   sts.push_back(st(ap,bp,0,t.ti+1));
                 }
             }
       }
}

int main()
{
    cin.sync_with_stdio(false);
    while(true)
    {
        scanf("%d%d%d\n",&w,&h,&n);
        if(w==0&&h==0&&n==0)break;
        st ist;ans= -1;
        memset(tiz,0,sizeof(bool)*255*255*255);
        for(int i = 0;i<h;++i)
        {
            for(int j = 0;j<w;++j)
            {
                scanf("%c",&sp[i][j]);
                if(sp[i][j]!=' '&&sp[i][j]!='#')
                {
                    if(sp[i][j]>='a')
                        ist.pp[sp[i][j]-'a'] = i*w+j;
                    else if(sp[i][j]>='A')
                     dd[sp[i][j]-'A'] = i*w+j;
                }
            }
            getchar();
        }
//        sp[ist.pp[0]/w][ist.pp[0]%w] = 'G';
//        for(int i =0;i<h;++i)
//          {
//            for(int j = 0;j<w;++j)
//              cout << sp[i][j];
//            cout <<endl;
////            if(i==15)return 0;
//          }
        ist.ti = 1;
        sts.push_back(ist);
        while(!sts.empty()&&ans == -1)
        {
            solve(sts.front());sts.pop_front();
        }
        cout << ans-1 <<endl;
        sts.clear();
//        return 0;
    }
    return 0;
}
