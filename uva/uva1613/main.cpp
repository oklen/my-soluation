#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <queue>

using namespace std;
int color[10000];
vector<int> rod[10000];
queue<int> tovis;

int n,m,cnt,k;

void bfs(int beg){
    if(color[beg])return;
    unordered_set<int> usedColor;
    for(int i = 0;i<rod[beg].size();++i){
        if(color[rod[beg][i]])usedColor.insert(color[rod[beg][i]]);
        else tovis.push(rod[beg][i]);
    }
    for(int i = 1;i<=k;++i){
        if(!usedColor.count(i)) {color[beg] = i;++cnt;return;}
    }
}

int main()
{
    bool first = true;
    while(~scanf("%d%d",&n,&m)){
        if(first)first= false;
        else printf("\n");

        for(int i = 0;i<m;++i){
            int a,b;scanf("%d%d",&a,&b);
            rod[a-1].push_back(b-1);
            rod[b-1].push_back(a-1);
            if(max(rod[a-1].size(),rod[b-1].size())>k)k = max(rod[a-1].size(),rod[b-1].size());
        }
        if(!(k%2))++k;
        tovis.push(0);
        while(cnt!=n&&!tovis.empty()){
            bfs(tovis.front());
            tovis.pop();
        }
        printf("%d\n",k);
        for(int i = 0;i<n;++i) printf("%d\n",color[i]);
        for(int i = 0;i<=n;rod[i].clear(),++i);
        memset(color,0,sizeof(color));k=0;cnt = 0;while(!tovis.empty())tovis.pop();
    }
    return 0;
}
