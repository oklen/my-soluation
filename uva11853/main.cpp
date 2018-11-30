#include <iostream>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
bool visited[1000],imc;
int n;
int vicn,mcount,bp;
float lmmbeg = 1000.00,rmmbeg = 1000.00;
enum dir{top,down,mleft,mright};

struct edge{
    int b;dir dr;float pos;
    edge(int b,dir dr,float pos):b{b},dr{dr},pos{pos}{}
    edge(){}
};

struct op{
    float x,y,r;
    op(float x,float y,float pos):x{x},y{y},r{pos}{}
    op(){}
};

edge td[2000];
op ops[1000];

void dfs(int index)//pos is index in td array
{
    if(visited[index]||imc)return;
    else visited[index] = true;
    if(ops[index].x-ops[index].r<=0)
    {
        float mi = ops[index].y - sqrt(ops[index].r*ops[index].r - ops[index].x*ops[index].x);
        if(mi < lmmbeg)
            lmmbeg = mi;
    }
    if(ops[index].x + ops[index].r >= 1000.00)
    {
        float mi = ops[index].y - sqrt(ops[index].r*ops[index].r - (1000-ops[index].x)*(1000 - ops[index].x));
        if(mi < rmmbeg)
            rmmbeg = mi;
    }
    float wx=ops[index].x,wy=ops[index].y,wr=ops[index].r;
    if(ops[index].y - ops[index].r <= 0) {imc = true;return;}
    for(int i = bp;i<mcount;++i)
        if(visited[i])
            continue;
         else if (((wx-ops[i].x)*(wx-ops[i].x) + (wy-ops[i].y)*(wy-ops[i].y)) <= (wr+ops[i].r)*(wr+ops[i].r))
            dfs(i);
}

int main()
{
    while(~scanf("%d",&n))
    {
        mcount = 0;
        while(n--)
        {
            scanf("%f%f%f",&ops[mcount].x,&ops[mcount].y,&ops[mcount].r);
            ++mcount;
        }
        //big to small
        sort(ops,ops+mcount,[](op& t1,op& t2){return t1.y+t1.r > t2.y+t2.r;});
        for(int i = 0;i<mcount&&!imc;++i)
        {
            if(ops[i].y+ops[i].r<1000.00)
                break;
            dfs(i);++bp;
        }
        if(imc)
            cout << "IMPOSSIBLE" << endl;
        else
            printf("0.00 %.2f 1000.00 %.2f\n",lmmbeg,rmmbeg);
        memset(td,0,sizeof(edge)*2000);bp = 0;
        lmmbeg = 1000.00,rmmbeg = 1000.00;memset(visited,0,sizeof(bool)*1000);imc = false;
    }
    return 0;
}
