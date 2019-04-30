#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
int n;
struct path{
    int key;path* parent;
    path(int key,path* parent):key{key},parent{parent}{}
};
int cnt = 1;
vector<path> paths;
vector<vector<int>> result;bool pex;
int ps[21][21];bool visited[21];
void dfs(int b,path* parent)
{
    if(b == n)
    {paths.push_back(*new path(b,parent));return;}
    visited[b] = true;
    for(int i = 1;i<=20;++i)
    {
        if(ps[b][i]&&!visited[i])
        {
            ps[b][i]=0;ps[i][b]=0;
            dfs(i,new path(b,parent));
            ps[b][i]=1;ps[i][b]=1;
            visited[i] =false;
        }
    }
}

void checkpathexist(int b)
{
    visited[b] = true;
    if(b==n) {pex = true;return;}
    for(int i =1;i<=20&&!pex;++i)
    {
        if(ps[b][i]&&!visited[i])
        {
            checkpathexist(i);
        }
    }
}

int main()
{
    int a,b;
    while(~scanf("%d",&n))
    {
        while(scanf("%d%d",&a,&b)&&a)
        {
            ps[a][b] = 1;
            ps[b][a] = 1;
        }
        pex = false;checkpathexist(1);memset(visited,0,sizeof(bool)*21);
        if(pex)
        dfs(1,new path(-1,nullptr));
        while(!paths.empty())
        {
            vector<int> in;path* cp = &paths.back();
            while(true)
            {
                if(cp->parent == nullptr)break;
                in.push_back(cp->key);
                cp = cp->parent;
            }
            if(in.size())
            result.push_back(in);paths.pop_back();
        }
        printf("CASE %d:\n",cnt++);
        for(auto rr = result.rbegin();rr!=result.rend();++rr)
        {
            auto aa = rr->rbegin();if(aa==rr->rend())continue;
            cout << *aa;++aa;
            for(;aa!=rr->rend();++aa)
                cout << " " << *aa;
            cout << endl;
        }
        printf("There are %d routes from the firestation to streetcorner %d.\n",
               result.size(),n);
        result.clear();paths.clear();memset(ps,0,sizeof(int)*21*21);
        memset(visited,0,sizeof(bool)*21);
    }
    return 0;
}
