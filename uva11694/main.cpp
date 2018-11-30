#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define mset(a,b) memset(a,b,sizeof(a))
#define emp 0
#define lt 1
#define rt 2
const char dx[]{-1,0,0,-1};
const char dy[]{-1,-1,0,0};
const char ddx[]{-1,1,1,-1},ddy[]{-1,-1,1,1};
const char wd[]{rt,lt,rt,lt};
const char rd[]{lt,rt,lt,rt};

char st[8][8];
char num[9][9];
bool vis[9][9];
char vals[9][9],ter;
int n,fcs;

void show()
{
    for(int i =0;i<n;++i,cout<<endl)
        for(int j= 0;j<n;++j)
        {
            if(st[i][j])cout<<(int)st[i][j];
            else cout << '*';
        }
}

bool visd(int y,int x,int fx,int fy)
{
    if(vis[y][x])return false;
    else vis[y][x] = true;
    if(vals[y][x]<=1)return true;
    for(int k = 0;k<4;++k)
    {
        if(y+dy[k]>=0&&y+dy[k]<n&&x+dx[k]>=0&&x+dx[k]<n
                &&st[y+dy[k]][x+dx[k]]==rd[k]&&(y+ddy[k]!=fy||x+ddx[k]!=fx))
            if(!visd(y+ddy[k],x+ddx[k],x,y))return false;
    }
    return true;
}

void dfs(int y,int x)
{
    //show();cout<<y<<endl;
    if(y==n||ter) {ter=true;return;}
    st[y][x] = lt;++vals[y][x];++vals[y+1][x+1];
    bool flag = true;mset(vis,0);
    if((num[y][x]!='.'&&vals[y][x]!=num[y][x])||!visd(y,x,-1,-1))
            flag=false;
    if(flag&&num[y+1][x+1]!='.')
    {
        if(vals[y+1][x+1]>num[y+1][x+1])flag=false;
    }
    if(flag&&x==n-1)
    {
        mset(vis,0);
        if((num[y][x+1]!='.'&&num[y][x+1]!=vals[y][x+1])||(vals[y][x+1]>1&&!visd(y,x+1,-1,-1)))flag=false;
    }
    if(flag&&y==n-1) //not checking the lastPoint!
    {
        mset(vis,0);
        if((num[y+1][x]!='.'&&num[y+1][x]!=vals[y+1][x])||(vals[y+1][x]>1&&!visd(y+1,x,-1,-1)))flag=false;
        if(flag&&x==n-1)
        {
            mset(vis,0);
            if((num[y+1][x+1]!='.'&&num[y+1][x+1]!=vals[y+1][x+1])||(vals[y+1][x+1]>1&&!visd(y+1,x+1,-1,-1)))
                flag = false;
        }
    }
    if(flag)
    {
        if(x==n-1)dfs(y+1,0);else dfs(y,x+1);
        if(ter)return;
    }
    flag = true;mset(vis,0);
    st[y][x] = rt;--vals[y][x];--vals[y+1][x+1];
    ++vals[y][x+1];++vals[y+1][x];
    if((num[y][x]!='.'&&vals[y][x]!=num[y][x])||!visd(y,x,-1,-1))
            flag=false;
    if(flag&&num[y][x+1]!='.'&&vals[y][x+1]>num[y][x+1])flag =false;
    if(flag&&num[y+1][x]!='.'&&vals[y+1][x]>num[y+1][x])flag = false;
    if(flag)
    {
        mset(vis,0);if(!visd(y+1,x,-1,-1))flag =false;
    }
    if(flag&&x==n-1)
    {
        mset(vis,0);
        if((num[y][x+1]!='.'&&num[y][x+1]!=vals[y][x+1])||!visd(y,x+1,-1,-1))flag=false;
    }
    if(flag&&y==n-1)
    {
        mset(vis,0);
        if((num[y+1][x]!='.'&&num[y+1][x]!=vals[y+1][x])||!visd(y+1,x,-1,-1))flag=false;
        if(flag&&x==n-1)
        {
            mset(vis,0);
            if((num[y+1][x+1]!='.'&&num[y+1][x+1]!=vals[y+1][x+1])||!visd(y+1,x+1,-1,-1))
                flag = false;
        }
    }
    if(flag){
        if(x==n-1)dfs(y+1,0);else dfs(y,x+1);
        if(ter)return;
    }
    st[y][x]=0;--vals[y][x+1];--vals[y+1][x];
}

int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);getchar();
        mset(st,0);mset(num,0);mset(vals,0);fcs=0;
        for(int i = 0;i<n+1;++i)
        {
            char now[9];cin >> now;
            for(int j = 0;j<n+1;++j)
                num[i][j] = now[j]=='.'?'.':(now[j]-'0');
        }
        ter=false;dfs(0,0);
        for(int i =0;i<n;++i,cout<<endl)
            for(int j =0;j<n;++j)
                printf("%c",st[i][j]==rt?'/':'\\');
    }
    return 0;
}
