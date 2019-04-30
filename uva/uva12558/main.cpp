#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;
char* ans;
const int tl[5] = {1,10,100,1000,10000};
const char nove = '-';

int glcnt = 0,maxd;
vector<char*> rresult;

struct mv{
  char n[4],bc[4];bool cg[4];int l,csn=0,sn;//CSN is the const part of the number
  mv(){memset(n,0,sizeof(char)*4);l=0;memset(cg,4,sizeof(bool)*4);sn=0;}
    void insert(char in){
      if(in =='*'){cg[l] = true;n[l]=(l==0?1:0);++sn;}
      else {cg[l]=false;csn+=tl[l]*(in-'0');n[l] = in-'0';}
      ++l;
    }
    int inline getnum(){int result=0;
      for(int i = 0;i<l;++i)
        {result*=10;result+=n[i];
        }return result;}

    bool inline check(int in)
    {
      if(in>=tl[l] || in<tl[l-1] ) return false;
//      int inc = in;
        for(int i = l-1;i>=0;--i){
            if(!cg[i]&&n[i] != in%10) return false;
            in/=10;
        }
//        cout << "in:" << inc << " " << tl[l-1]<<endl;

        return true;
    }

    void inline clear()
    {
        if(cg[0]) n[0] = 1;
        for(int i = 1;i<l;++i)
        {
            if(cg[i])
                n[i] = 0;
        }
        csn = getnum();
    }
};

mv mvs[3];
void save()
{
  char*cc = new char[8];int cnt = 0;
  for(int i = 0;i<mvs[0].l;++i)
      if(mvs[0].cg[i])
          cc[cnt++] = '*';
      else cc[cnt++] = '0'+mvs[0].n[i];
  cc[cnt++] = ' ';
  for(int i = 0;i<mvs[1].l;++i)
      if(mvs[1].cg[i])
          cc[cnt++] = '*';
      else cc[cnt++] = '0'+mvs[1].n[i];
  cc[cnt++] = ' ';
  for(int i = 0;i<mvs[2].l;++i)
      if(mvs[2].cg[i])
          cc[cnt++] = '*';
      else cc[cnt++] = '0'+mvs[2].n[i];
  cc[cnt++] = 0;
  if(ans == nullptr|| memcmp(ans,cc,strlen(cc)*sizeof(char))>0)
       ans = cc;
}

bool check(int num)
{
//    if(num == 1)
//    {
//        cout << mvs[0].csn << " " << mvs[1].csn << endl;
//    }
  if(num==2)
    {
//      cout << mvs[0].csn << " " << mvs[1].csn << " " << endl;
      if(mvs[2].check(mvs[0].csn*mvs[1].csn))
      {
          ++glcnt;
      }
//      mvs[num].clear();
      return true;
    }
  mvs[num].csn = mvs[num].getnum();
  int addpoint = mvs[num].l-1,bp;
//  cout << "addpoint:" << addpoint << endl;
  while(!mvs[num].cg[addpoint]&&addpoint>=0) --addpoint;
  bp = addpoint;
  while(true&&glcnt<2)
    {
      check(num+1);
      if(addpoint<0)break;
      ++mvs[num].n[addpoint];
      if(mvs[num].n[addpoint]==10)
        {
          mvs[num].n[addpoint] = 0;
          if(addpoint!=0&&mvs[num].cg[addpoint-1]&&mvs[num].n[0]<9)
          {++mvs[num].n[0];}
          else break;
        }
      mvs[num].csn = mvs[num].getnum();
    }
  mvs[num].clear();
  if(glcnt==1)return true;
  else return false;
}

void solve(int dep,int mi,int pos)
{
  if(dep == 0)
    {
      bool allstar = true;
      for(int i = 0;i<3;++i)
        {
          for(int j = 0;j<mvs[i].l;++j)
              if(!mvs[i].cg[j])
              {allstar =false;break;}
        }
      if(allstar) return;
      if(check(0))save();glcnt = 0;return;
    }
  for(int i = mi;i<3;++i)
    for(int j = (i==mi?pos:0);j<mvs[i].l;++j)
      {
        char cc  = mvs[i].n[j];bool cb = mvs[i].cg[j];/*int ccsn = mvs[i].csn;*/
        while(true)
        {
//            cout << "origin:" << (int)cc << " " << cb << endl;
//            cout  << (int)mvs[i].n[j] << " " <<
//                    mvs[i].cg[j] << " j:"<<j <<endl;
          if(mvs[i].n[j]<9&&!mvs[i].cg[j]){++mvs[i].n[j];}
          else if(mvs[i].n[j]==9&&!mvs[i].cg[j])
           {
              if(j==0){mvs[i].n[j]=1;}
              else {mvs[i].n[j] = 0;}
              mvs[i].cg[j] = true;
           }
          else {
            mvs[i].cg[j] = false;
            if(j==0)mvs[i].n[j]=1;
            else mvs[i].n[j] = 0;
          }
          if(j == mvs[i].l-1)
            solve(dep-1,i+1,0);
          else
            solve(dep-1,i,j+1);
          if(mvs[i].n[j] == cc && mvs[i].cg[j] == cb) {
              break;}
        }

//        mvs[i].n[j] = cc;mvs[i].cg[j] = cb;mvs[i].csn=ccsn;
      }
}
int main()
{
//    freopen("/media/root/Dstore/LENOVO/Qt_Project/build-uva12558-Desktop_Qt_5_11_1_GCC_64bit-Debug/input2","r",stdin);
    char cache;int casecnt = 1;
    while(true)
    {
        memset(mvs[0].n,' ',sizeof(char)*2);memset(mvs[1].n,' ',sizeof(char)*2);memset(mvs[2].n,' ',sizeof(char)*4);
        mvs[0].l=mvs[1].l=mvs[2].l=0;mvs[0].csn=mvs[1].csn=mvs[2].csn=0;
      if((cache = getchar()) == '0' )break;
       while(cache == ' ') cache = getchar();
        while(cache !=' '){mvs[0].insert(cache);cache = getchar();}
        while (cache == ' ') cache = getchar();
        while (cache !=' ') {mvs[1].insert(cache);cache=getchar();}
        while(cache == ' ') cache = getchar();
        while(cache != '\n'&&cache !=' '){mvs[2].insert(cache);cache=getchar();}
        while(cache != '\n') cache = getchar();
        mvs[1].clear();mvs[0].clear();
        //mvs[0].clear();mvs[0].csn=mvs[0].getnum();
        mvs[2].clear();
//        cout << mvs[1].csn << endl;
        for(int i = 0;i<3;++i) memcpy(mvs[i].bc,mvs[i].n,sizeof(char)*4);
//           ans = false;
//           check(0);
        ans = nullptr;
        for(maxd=0;ans==nullptr;maxd++)
          solve(maxd,0,0);
//        cout << "maxd:"<< maxd << endl;
//        cout << "result size:" << rresult.size() <<endl;
//        int mp = 0;
//        int len = strlen(*rresult.begin());
//        for(int i =1;i<rresult.size();++i)
//        {
//            if(memcmp(rresult.at(mp),rresult.at(i),len*sizeof(char))>0)
//                mp = i;
//        }
//        cout << rresult.size() << endl;
        cout << "Case "<< casecnt++ << ": " << ans <<endl;
    }
    return 0;
}
