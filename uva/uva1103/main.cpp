#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#define getPos(x,i) x&(1<<i)
using namespace std;
int h,w,hh,ww;
short graps[200][50*4*2];
int number = 20;
int cache = 0;
string finW;

void fillit(int x,int y,int index)
{
    if(x>=0&&x<ww&&y>=0&&y<h)
    {
        if(graps[y][x] !=0)
            return;
        else
            graps[y][x] = index;
        fillit(x,y+1,index);
        fillit(x,y-1,index);
        fillit(x+1,y,index);
        fillit(x-1,y,index);
        fillit(x+1,y+1,index);
        fillit(x+1,y-1,index);
        fillit(x-1,y+1,index);
        fillit(x-1,y-1,index);
    }
}


void collect(int index,int& result,int x,int y)
{
    if(x>=0&&x<ww&&y>=0&&y<h)
    {
        if(graps[y][x] == -1 || graps[y][x] == index) return;
        else if(graps[y][x] == 0)
        {
            fillit(x,y,index);
            result+=1;
        }
        else graps[y][x] = index;
        collect(index,result,x+1,y);
        collect(index,result,x-1,y);
        collect(index,result,x,y+1);
        collect(index,result,x,y-1);
        collect(index,result,x+1,y+1);
        collect(index,result,x+1,y-1);
        collect(index,result,x-1,y+1);
        collect(index,result,x-1,y-1);
    }
}

void search()
{
    for(int i= 0;i<h;i++)
    {
        if(graps[i][0] == 0) fillit(0,i,-1);
        if(graps[i][ww-1]==0)fillit(ww-1,i,-1);
    }
    for(int i = 0;i<ww;i++)
    {
        if(graps[0][i]==0)fillit(i,0,-1);
        if(graps[h-1][i]==0)fillit(i,h-1,-1);
    }
    for(int i =0;i<h;i++)
    {
        for(int j = 0;j < ww;j++)
        {
            if(graps[i][j] == 1)
            {
                int result= 0;
                collect(number,result,j,i);
                switch (result) {
                case 0:
                    finW.push_back('W');
                    break;
                case 1:
                    finW.push_back('A');
                    break;
                case 2:
                    finW.push_back('K');
                    break;
                case 3:
                    finW.push_back('J');
                    break;
                case 4:
                    finW.push_back('S');
                    break;
                case 5:
                    finW.push_back('D');
                    break;
                default:
                    cout << "bug:" << result << endl;
                }
            }
        }
    }
}

int main()
{
    int coun = 1;
    while(true)
    {
        cin >> h >> w;
        if(h == 0 && w == 0) break;
        hh = h;
        ww = 4*w;
        short n1 =1;
        short n2 = n1<<1;
        short n3 = n2<<1;
        short n4 = n3<<1;
        for(int i = 0;i < h;i++)
        {
            for(int j = 0;j < w;j++)
            {
                scanf("%1x",&cache);
                if(cache)
                {
                        graps[i][j*4+3]=(n1&cache)!=0;
                        graps[i][j*4+2]=(n2&cache)!=0;
                        graps[i][j*4+1]=(n3&cache)!=0;
                        graps[i][j*4+0]=(n4&cache)!=0;
                }
                else
                    memset(&graps[i][j*4],0,sizeof(short)*4);
            }
        }
        search();
//        for(int i = 0;i<h;i++)
//        {
//            for(int j = 0;j<ww;j++)
//                cout<<graps[i][j];
//            cout << endl;
//        }
        sort(finW.begin(),finW.end());
        printf("Case %d: %s\n",coun++,finW.data());
        finW.clear();
    }
    return 0;
}
