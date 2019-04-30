#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
int n,k;
char omp[30][30];
char vmp[30][30];
bool filldone = false;

bool check(int x)
{
    for(int i = 0;i<n;++i)
    {
        if(x>0&&!vmp[x-1][i]&&vmp[x][i])return false;
        if(omp[x+1][i]=='.'&&vmp[x+1][i]&&!vmp[x][i]) return  false;
        for(int j = 1;j<x;++j)
        {
            if(!vmp[j-1][i]&&vmp[j][i])return  false;
        }
    }
    return true;
}

void fill(int x,int y)
{
    if(x>=n){
        filldone = true;return;
    }
    for(;y<n;++y)
    {
        if(omp[x][y]!='.')
        {
            int l =y;while(l-1>=0&&!vmp[x][l-1]&&y-l<omp[x][y])--l;
            int r =y;while(r+1<n&&!vmp[x][r+1]&&r-y<omp[x][y])++r;
            char used = vmp[x][y];

            for(;l<=y;++l)
            {
                for(int h = max(0,x-omp[x][y]+1);h<=x;++h)
                {
                    if(vmp[h][l]&&(h!=x||l!=y))continue;

                    for(int dh = x-h;h+dh<n&&dh<omp[x][y];++dh)
                    {
                        if(omp[x][y]/(dh+1)+l-1>r||omp[x][y]/(dh+1)+l-1<y)continue;
                        if(omp[x][y]%(dh+1)==0)
                        {
                            bool cap = true;
                            vmp[x][y]=0;
                            for(int i=0;i<=dh&&cap;++i)
                                for(int j = omp[x][y]/(dh+1)-1;j>=0;--j)
                                {
                                    if(vmp[h+i][l+j]){cap=false;break;}
                                }
                            vmp[x][y]=used;
                            if(cap)
                            {
                                for(int i=0;i<=dh&&cap;++i)
                                    for(int j = omp[x][y]/(dh+1)-1;j>=0;--j)
                                    {
                                        vmp[h+i][l+j]=used;
                                    }
                                fill(x,y+1);
                                if(filldone)return;
                                for(int i=0;i<=dh&&cap;++i)
                                    for(int j = omp[x][y]/(dh+1)-1;j>=0;--j)
                                    {
                                        vmp[h+i][l+j]=0;
                                    }
                                vmp[x][y] = used;
                            }
                        }
                    }
                }
            }
            return;
        }
    }
    if(!check(x))return;
    fill(x+1,0);
}

int main()
{
    cin.sync_with_stdio(false);
    while(scanf("%d%d",&n,&k)&&n&&k)
    {
        int nc = 0;memset(omp,0,sizeof(omp));memset(vmp,0,sizeof(vmp));
        char now = getchar();while(now!='\n')now=getchar();
        filldone = false;
        for(int i = 0;i<n;++i)
        {
            for(int j = 0;j<n;++j)
            {
                scanf("%c",&omp[i][j]);
                if(omp[i][j]!='.'){omp[i][j]-='0';vmp[i][j]='A'+nc++;}
            }
            now = getchar();while(now!='\n')now=getchar();
        }
        fill(0,0);
        for(int i = 0;i<n;++i)
        {
            for(int j = 0;j<n;++j)
                cout << vmp[i][j];
            cout << endl;
        }
    }
    return 0;
}
