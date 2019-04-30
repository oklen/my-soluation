#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <list>

using namespace std;
char space[105][105][105];
int cn,n,vv,ar,xls,yls,zls;
int xl[105],yl[105],zl[105];
int xaa[]{1,-1,0,0,0,0};
int yaa[]{0,0,1,-1,0,0};
int zaa[]{0,0,0,0,1,-1};

struct square{
    int lx,ly,lz,rx,ry,rz;
    void ass(int xl,int yl,int zl,int xr,int yr,int zr)
    {lx=xl;ly=yl;lz=zl;rx=xr;ry=yr;rz=zr;}
};
struct d3{int x;int y;int z;
          d3(int x,int y,int z):x{x},y{y},z{z}{}};
list<d3> works;
square sqs[50];


void cal(int xi,int yi,int zi)
{
  if(xi<0||xi>xls||yi<0||yi>yls||zi<0||
     zi>zls||space[xi][yi][zi] & 1||space[xi][yi][zi]&4) return;
//  cout << (int)space[xi][yi][zi] << " ";
//  cout << xl[xi] << endl;
  if(xi+1<xls&&yi+1<yls&&zi+1<zls)
  vv+=(xl[xi+1]-xl[xi])*(yl[yi+1]-yl[yi])*(zl[zi+1]-zl[zi]);
  space[xi][yi][zi]+=4;
  if((space[xi+1][yi][zi]^4)&1/*&&(space[xi+1][yi+1][zi]^4)&3&&(space[xi+1][yi][zi+1]^4)&3*/)
  {
      ar+=2*(yl[yi+1]-yl[yi])*(zl[zi+1]-zl[zi]);
  }
  if((space[xi][yi+1][zi]^4)&1/*&&(space[xi+1][yi+1][zi]^4)&3&&(space[xi][yi+1][zi+1]^4)&3*/)
  {
      //cout << xl[xi] << " " << xl[xi+1] << endl;
      ar+=2*(xl[xi+1]-xl[xi])*(zl[zi+1]-zl[zi]);
  }
  if((space[xi][yi][zi+1]^4)&1/*&&(space[xi+1][yi][zi+1]^4)&3&&(space[xi][yi+1][zi+1]^4)&3*/)
  {
      ar+=2*(xl[xi+1]-xl[xi])*(yl[yi+1]-yl[yi]);
  }
  for(int i = 0;i<6;i++)
  {
      works.push_back(d3(xi+xaa[i],yi+yaa[i],zi+zaa[i]));
      //cal(xi+xaa[i],yi+yaa[i],zi+zaa[i]);
  }
}

int main()
{
    cin >> n;
    while(n--)
    {
        cin >> cn;
        int mcn = cn;
        xl[2*cn] = 0;yl[2*cn] = 0;zl[2*cn] = 0;
        xl[2*cn+1] = 1001;yl[2*cn+1]=1001;zl[2*cn+1]=1001;
        while(cn--)
          {scanf("%d%d%d%d%d%d",&sqs[cn].lx,&sqs[cn].ly,&sqs[cn].lz,
              &sqs[cn].rx,&sqs[cn].ry,&sqs[cn].rz);
        sqs[cn].rx+=sqs[cn].lx;sqs[cn].ry+=sqs[cn].ly;sqs[cn].rz+=sqs[cn].lz;
        xl[2*cn+1] = sqs[cn].lx;yl[2*cn+1] = sqs[cn].ly;zl[2*cn+1] = sqs[cn].lz;
        xl[2*cn] = sqs[cn].rx;yl[2*cn] = sqs[cn].ry;zl[2*cn] = sqs[cn].rz;}
        mcn+=1;
        sort(xl,xl+2*mcn);sort(yl,yl+2*mcn);sort(zl,zl+2*mcn);
         xls = unique(xl,xl+2*mcn) - xl;
         yls = unique(yl,yl+2*mcn) - yl;
         zls = unique(zl,zl+2*mcn) - zl;
//         for(int i = 0;i<xls;++i)
//             cout << xl[i] << endl;
//         return 0;
        int xpos,xpos2,ypos,ypos2,zpos,zpos2;
        mcn-=1;

        while(mcn--)
          {
            int i = mcn;
            xpos = find(xl,xl+xls,sqs[i].lx)-xl;
            xpos2 = find(xl,xl+xls,sqs[i].rx) - xl;
            ypos = find(yl,yl+yls,sqs[i].ly) - yl;
            ypos2=  find(yl,yl+yls,sqs[i].ry) - yl;
            zpos = find(zl,zl+zls,sqs[i].lz) - zl;
            zpos2 = find(zl,zl+zls,sqs[i].rz) - zl;
//            cout << yl[ypos] << " " << yl[ypos2]<< endl;
            for(i = xpos;i<xpos2;++i)
            {
                for(int j  = ypos;j<ypos2;++j)
                {
                    for(int k = zpos;k<zpos2;++k)
                    {
                        space[i][j][k] = 1;
                    }
//                    if(space[i][j][zpos2]!=1)
//                        space[i][j][zpos2] = 2;
                }
//                for(int k = zpos;k<=zpos2;++k)
//                {
//                    if(space[i][ypos2][k]!=1)
//                        space[i][ypos2][k] = 2;
//                }
            }
//            for(int j = ypos;j<=ypos;++j)
//            {
//                for(int k = zpos;k<=zpos2;++k)
//                if(space[xpos2][j][k]!=1)
//                    space[xpos2][j][k] = 2;
//            }
          }
        //printf("%d %d %d\n",xl[0],yl[0],zl[0]);
        works.push_back(d3(0,0,0));
        while (!works.empty()) {
            cal(works.front().x,works.front().y,works.front().z);
            works.pop_front();
        }
        cout << ar << " " << 1001*1001*1001 - vv << endl;
        ar= 0;vv = 0;
        memset(space,0,sizeof(char)*105*105*105);
        //return 0;
    }
    return 0;
}
