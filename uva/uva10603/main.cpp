#include <iostream>
#include <list>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
int status[201*201*202];
struct st{
    int a,b,c;
    int cost;
    st(int a,int b,int c,int cost):a{a},b{b},c{c},cost{cost}{}
};
int a,b,c,d;
int closev,maxcost;
list<st> sts;

void check(int a,int b,int c,int cs)
{
    if(a<=d)
    {
        if(a>closev)
        {closev = a;maxcost =cs;}
        else if(a==closev && maxcost >cs)
            maxcost = cs;
    }
    if(b<=d)
    {
        if(b>closev)
        {closev = b;maxcost =cs;}
        else if(b==closev && maxcost >cs)
            maxcost = cs;
    }
    if(c<=d)
    {
        if(c>closev)
        {closev = c;maxcost =cs;}
        else if(c==closev && maxcost >cs)
            maxcost = cs;
    }
}
void solve(st& t)
{
    status[t.a+201*t.b+(201*201+1)*t.c] = t.cost;
    check(t.a,t.b,t.c,t.cost);
    bool sa=t.a<a,sb=t.b<b,sc=t.c<c;
    if(t.a)
    {
        if(sb)
        {
            int ma = min(t.a,b-t.b);
            sts.push_back(st(t.a-ma,t.b+ma,t.c,t.cost+ma));
        }
        if(sc)
        {
            int ma = min(t.a,c-t.c);
            sts.push_back(st(t.a-ma,t.b,t.c+ma,t.cost+ma));
        }
    }
    if(t.b)
    {
        if(sa)
        {
            int ma = min(t.b,a-t.a);
            sts.push_back(st(t.a+ma,t.b-ma,t.c,t.cost+ma));
        }
        if(sc)
        {
            int ma = min(t.b,c-t.c);
            sts.push_back(st(t.a,t.b-ma,t.c+ma,t.cost+ma));
        }
    }
    if(t.c)
    {
        if(sa)
        {
            int ma = min(t.c,a-t.a);
            sts.push_back(st(t.a+ma,t.b,t.c-ma,t.cost+ma));
        }
        if(sb)
        {
            int ma = min(t.c,b-t.b);
            sts.push_back(st(t.a,t.b+ma,t.c-ma,t.cost+ma));
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        closev = -1;memset(status,127,sizeof(int)*201*201*202);
        maxcost = 1<<30;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        sts.push_back(st(0,0,c,0));
        while(!sts.empty())
        {
            if(status[sts.front().a+
                    201*sts.front().b+
                    (201*201+1)*sts.front().c]<=sts.front().cost)
            {sts.pop_front(); continue;}
            solve(sts.front());sts.pop_front();
        }
//        cout << a << " " << b << " " << c << " " << d <<endl;
        cout << maxcost << " " << closev<<endl;

    }
    return 0;
}
