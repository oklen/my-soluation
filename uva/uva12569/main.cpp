#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <set>

using namespace std;
int n,m,s,t;unsigned ts;

struct path{
    path(unsigned from,unsigned to,path* parent):from{from},
    to{to},parent{parent}{}
    unsigned from,to;
    path* parent;
};

path* req;
unordered_set<unsigned int> es[15];
unordered_set<unsigned int> sts;
queue<pair<unsigned,path*>> works;
unsigned int norn[16];
queue<pair<int,int>> tqs;
bool visited[15];int needpath;
//use bfs to boost up?

//void bfs(int now)
//{
//    if(visited[now])return;

//}
void tbfs(int x,int dep)
{
    if(visited[x])return;
    else visited[x]=true;
    if(x==t) {needpath = dep;return;}
    for(auto bb = es[x].begin();bb!=end(es[x])&&needpath==-1;++bb)
    {
        tqs.push({*bb,dep+1});
    }
}

void bfs(unsigned ss,path* parent)
{
    if(ts&ss)
    {
        req = parent;return;
    }
    //cout << bitset<32>(ss) <<endl;
        //cout << "dep:" <<dep << " " << bitset<32>(ss) << endl;
    if(sts.count(ss)||req)
        return;
    else sts.insert(ss);

    unsigned ns =ss,cnt=0;
    while(ns!=0&&!req)
    {
        if(ns&3u)
        {
            for(auto bb = es[cnt].begin();bb!=es[cnt].end()&&!req;++bb)
            {

                if((norn[*bb]&ss)==0)
                {

                    works.push({(ss&(~(ss&norn[cnt])))|((ns&3u)<<(2u*(*bb))),new path(cnt,*bb,parent)});
                }
            }
        }
        ns>>=2u;++cnt;
    }
}

int main()
{
    for(int i = 0;i<16;++i)
      norn[i]=3u<<(i*2);
    return 0;
    //freopen("/media/root/Dstore/LENOVO/Qt_Project/build-uva12569-Desktop_Qt_5_11_1_GCC_64bit-Debug/input","r",stdin);
    int T,cnt=0;scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&s,&t);
        unsigned int bs = 0,cm=0;
        --s;--t;
        for(int i = 0;i<m;++i)
        {
            scanf("%d",&cm);
            bs|=1u<<(2*(--cm));
        }
        unsigned int r,l;
        for(int i = 1;i<n;++i)
        {
            scanf("%d%d",&r,&l);--r;--l;
            es[r].insert(l);
            es[l].insert(r);
        }
        ts = 0;ts|=2u<<(2*t);
        bs|=2u<<(2*s);req=nullptr;

//        tqs.push({s,0});needpath =-1;memset(visited,0,sizeof(bool)*15);
//        while(!tqs.empty()&&needpath==-1)
//        {
//            tbfs(tqs.front().first,tqs.front().second);
//            tqs.pop();
//        }
//        while(!tqs.empty()) tqs.pop();
//        if(needpath+m>=n)
//        {
//            cout << "Case " << ++cnt<<": "<< -1 <<endl<<endl;
//            for(int i =0;i<15;++i)es[i].clear();
//            continue;
//        }
        works.push(pair<unsigned,path*>(bs,nullptr));
        bool eout = false;
        while(req==nullptr)
        {
            bfs(move(works.front().first),move(works.front()).second);
            works.pop();
            if(works.empty()) {eout=true;break;}
        }
        sts.clear();
        while(!works.empty())works.pop();
        vector<pair<int,int>> result;
        while(req!=nullptr)
        {
            result.push_back({req->from,req->to});
            req = req->parent;
        }
        if(!eout||result.size()!=0)
        cout << "Case " << ++cnt<<": "<< result.size() <<endl;
        else cout << "Case " << ++cnt<<": "<< -1 <<endl;
        for(auto bb = result.rbegin();bb!=result.rend();++bb)
            printf("%d %d\n",bb->first+1,bb->second+1);
        printf("\n");
        for(int i =0;i<15;++i)es[i].clear();
    }
}
