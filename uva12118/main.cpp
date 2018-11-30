#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int v,e,r,cost,gc;
using namespace std;
vector<int> mmp[10001];
vector<int> path;
set<int> visited;

void dfs(int pos)
{
    path.push_back(pos);
    visited.insert(pos);
    if(!mmp[pos].size())
        return;
    int next = mmp[pos].back();
    if(mmp[next].size())
    mmp[next].erase(lower_bound(mmp[next].begin(),mmp[next].end(),pos));
//#ifdef MDB332
//  cout << pos<<"->"<<next<<endl;
//#endif
    mmp[pos].pop_back();
    dfs(next);
}

int main()
{
    path.reserve(1001*1000/2);
    while(true)
    {
        cost = -1;
        scanf("%d%d%d",&v,&e,&r);
        if(v==0&&e==0&&r==0)break;
        int bb,ee;
        for(int i = 0;i<e;++i)
        {
            scanf("%d%d",&bb,&ee);
            mmp[bb].push_back(ee);
            mmp[ee].push_back(bb);
        }
        for(int i = 1;i<=v;++i)
            if(mmp[i].size())
            sort(mmp[i].begin(),mmp[i].end());
        for(int i = 1;i<=v;++i)
        {
//            cout << "visite:"<<i <<endl;
            while(mmp[i].size()%2)
            {
//#ifdef MDB332
//              cout << "trip:"<<endl;
//#endif
                dfs(i);dfs(i);++cost;
                path.clear();
            }
        }
        for(int i = 1;i<=v;++i)
        {
//            cout << "visite:"<<i <<endl;
            while(mmp[i].size())
            {
#ifdef MDB332
              cout << "trip:"<<endl;
#endif
              bool hv = visited.count(i);
                dfs(i);
                if(path.back() == i)
                {
                    if(hv)
                      continue;
                    if(mmp[i].size())dfs(i);
                    else
                    {
                        bool find2 = false;
                        for(auto b = path.begin();b!=path.end();++b)
                            if(mmp[*b].size()>1)
                            {dfs(*b);dfs(*b);find2=true;break;}
                        if(!find2)
                            for(auto b = path.begin();b!=path.end();++b)
                                if(mmp[*b].size()!=0)
                                {dfs(*b);break;}
                    }
                }
                else
                    dfs(i);
                ++cost;
                path.clear();
            }
        }
        if(cost == -1)cost = 0;
        cost+=e;
        cost*=r;
        visited.clear();
        cout << "Case "<<++gc <<": "<<cost << endl;
    }
    return 0;
}
