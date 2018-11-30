#include <iostream>
#include <list>
#include <bits/stdc++.h>

using namespace std;
int mmp[21][21];
int dx,dy,t,minl;
int visited[21][21];
struct node{int x,y,thr,length;node(int x,int y,int thr,int length)
        :x{x},y{y},thr{thr},length{length}{}};
list<node> worklist;

void bfs(int x,int y,int thr,int length)
{
    if(mmp[y][x] == 1) --thr;
    else thr = t;
    if(thr <= 0|| minl!=-1 || visited[y][x] >= thr)return;
    else visited[y][x] = thr;
//    cout << "visite:"<<x<<" "<<y<<endl;

    if(y == dy && x == dx) {minl = length;return;}
    ++length;
    if(x-1>=1&&!visited[y][x-1])
        worklist.push_back(node(x-1,y,thr,length));
    if(x+1<=dx&&!visited[y][x+1])
        worklist.push_back(node(x+1,y,thr,length));
    if(y+1<=dy&&!visited[y+1][x])
        worklist.push_back(node(x,y+1,thr,length));
    if(y-1>=1&&!visited[y-1][x])
        worklist.push_back(node(x,y-1,thr,length));
}


int main()
{
    int nn;
    scanf("%d",&nn);
    while(nn--)
    {
        minl = -1;
        scanf("%d%d%d",&dy,&dx,&t);
        //cout << dy << " " << dx << " " << t << endl;
        for(int i = 1;i<=dy;++i)
        {
            for(int j = 1;j<=dx;++j)
            {
                scanf("%d",&mmp[i][j]);
            }
        }
        ++t;
        worklist.push_back(node(1,1,t,0));
        while(!worklist.empty()&&minl==-1)
        {
            bfs(worklist.front().x,worklist.front().y,worklist.front().thr,worklist.front().length);
            worklist.pop_front();
        }
        worklist.clear();

        if(minl!=-1)
            cout << minl <<endl;
        else
            cout << -1 << endl;
        minl = -1;memset(visited,0,sizeof(int)*21*21);
    }
    return 0;
}
