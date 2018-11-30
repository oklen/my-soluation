#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;
const char dx[]{0,0,-1,1};
const char dy[]{1,-1,0,0};

struct node{int m[10];};
int w,h,n,mostcot;
char emch[10];
char emcht[100],g[25][25],empg[10][10];

struct savep{
    char nn;char x[10],y[10];
    void save()
    {
        nn = 0;
        for(int i =0;i<21;++i)
            for(int j =0;j<21;++j)
                if(g[i][j]){y[nn]=i;x[nn++]=j;}
    }
    bool operator==(const savep& in)const
    {
        if(in.nn!=nn)return false;
        for(int i = 0;i<nn;++i)
            if(x[i]!=in.x[i]||y[i]!=in.y[i])
                return false;
        return true;
    }
    void Sort()
    {
        pair<int,int> s[10];
        for(int i = 0;i<nn;++i)
        {s[i].first = y[i];s[i].second = x[i];}
        sort(s,s+nn);
        for(int i = 0;i<nn;++i)
        {y[i] = s[i].first;x[i]=s[i].second;}
    }

    void Translate(int d,int t)
    {
        for(int i = 0;i<nn;++i)
        {
            x[i]+=dx[d]*t;
            y[i]+=dy[d]*t;
        }
    }

    void TranslateToUpLeft()
    {
        char mnx=20,mny=20;
        for(int i = 0;i<nn;++i)
        {
            mnx = min(mnx,x[i]);
            mny = min(mny,y[i]);
        }
        Translate(2,mnx);
        Translate(1,mny);
    }
    void Rotate()
    {
        for(int i = 0;i<nn;++i)
        {
            int tx = x[i],ty=y[i];
            x[i] = ty;
            y[i] = -tx;
        }
        TranslateToUpLeft();
    }
    void Flip()
    {
        for(int i =0;i<nn;++i)
            x[i]=-x[i];
        TranslateToUpLeft();
    }
};

struct Hash{
    size_t operator()(const savep& in)const
    {
        size_t res = 0;
        for(int i =0;i<in.nn;++i)
        {
            res*=100u;res+=10u*in.y[i]+in.x[i];
        }
//        cout << res <<endl;
        return res;
    }
};
unordered_set<savep,Hash> sp;
savep ms,mc;

bool check()
{
    mc = ms;
    mc.TranslateToUpLeft();

    for(int i = 0;i<4;++i)
    {
        mc.Sort();
        if(sp.count(mc))
            return false;
        mc.Rotate();
    }
    mc.Flip();
    for(int i = 0;i<4;++i)
    {
        mc.Sort();
        if(sp.count(mc))
            return false;
        mc.Rotate();
    }
    mc.Sort();
    sp.insert(mc);
    return true;
}

void dfs(int dep)
{
    if(dep>n-1)return;
        ms.save();
//        cout << "size:"<<(int)ms.nn <<endl;
//        memset(empg,0,sizeof(char)*10*10);
//        for(int i = 0;i<ms.nn;++i)
//            empg[ms.y[i]][ms.x[i]]=1;
//        cout << "n:"<<(int)n << " dep:" << dep <<endl;
//        for(int i = 0 ;i<10;++i)
//        {
//            for(int j = 0;j<10;++j)
//                cout << (int)empg[i][j];
//            cout << endl;
//        }
        if(!check())
            return;
        else if(dep == n-1)
        {
            char minx = 22,miny=22,maxx=-1,maxy=-1;
            for(int i = 0;i<mc.nn;++i)
            {
                minx = min(minx,mc.x[i]);maxx = max(maxx,mc.x[i]);
                miny = min(miny,mc.y[i]);maxy = max(maxy,mc.y[i]);
            }
//            cout << maxx-minx << " " << maxy-miny << endl;
                if((maxx-minx <h &&maxy-miny< w) ||
                        (maxx-minx <w &&maxy-miny< h))
                     ++mostcot;
        }
//            else
//            cout << "insert it" <<endl;

    for(int i = 0;i<21;++i)
        for(int j = 0;j<21;++j)
        {
            if(!g[i][j])continue;
            else {
                for(int k = 0;k<4;++k)
                {
                    if(i+dx[k]>=0&&i+dx[k]<21&&j+dy[k]>=0
                            &&j+dy[k]<21&&!g[i+dx[k]][j+dy[k]])
                    {
                        g[i+dx[k]][j+dy[k]] = 1;
                        dfs(dep+1);
                        g[i+dx[k]][j+dy[k]] = 0;
                    }
                }
            }
        }
}

int main()
{
//    freopen("/media/root/Dstore/LENOVO/Qt_Project/build-uva1600-Desktop_Qt_5_11_1_GCC_64bit-Debug"
//            "/input3","r",stdin);
    while(~scanf("%d%d%d",&n,&w,&h))
    {
        if(w<h)
        {int c = w;w=h;h=c;}
        mostcot=0;
        g[10][10] = 1;
        dfs(0);
        sp.clear();
        memset(g,0,sizeof(char)*25*25);
        cout << mostcot << endl;
    }
    return 0;
}
