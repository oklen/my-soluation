#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <bitset>
#include <unordered_set>
#include <list>

using namespace std;
queue<unsigned int> result;
queue<unsigned int> midresult;
list<unsigned int> ddl;
unordered_set<unsigned int> revers;
unordered_set<unsigned int> used,rused;
const char w=1,r=2,b=3;
const int dx[]{0,1,0,-1},dy[]{1,0,-1,0};
//const char dw[]{r,b,r,b},dr[]{w,b,w,b},db[]{r,w,r,w};
const int dcc[2][3][4]{{{r,b,r,b},{w,b,w,b},{r,w,r,w}},
                      {{b,r,b,r},{b,w,b,w},{w,r,w,r}}};
const int rcc[2][3][4]{{{0,0,0,0},{0,1,0,1},{1,0,1,0}},
                        {{1,1,1,1},{0,1,0,1},{1,0,1,0}}};
int maxd,tar,glc;
bool fin;

void bfs()
{
  unsigned int in = result.front();
  unsigned int bc = in;
  if((in>>27) > 20) {maxd= 40;return;}
  result.pop();
  if(used.count(0x7ffffff&in)!=0) return;
  else used.insert(0x7ffffff&in);
  if((0x3ffff&in) == tar) {
    maxd = in>>27;return;
  }
  int px,py;
  for(int i = 0;i<9;++i)
    {
      if((in&3)==0)
        {
          px = i %3;py = i/3;
          break;
        }
      in>>=2;
    }
//  cout << px << " " << py <<endl;
  for(int i = 0;i<4;++i)
    {
//      cout << px+dx[i] << " " << py+dy[i] << endl;
      if(px+dx[i]>=0&&px+dx[i]<3&&
         py+dy[i]>=0&&py+dy[i]<3)
        {
          unsigned int cc = bc;
          char dir = 1u&(cc>>(px+dx[i]+3*(py+dy[i]) + 18u));
//          cout << bitset<32>(cc) << "before:"<<(int)dir<< endl;
          cc&=~(cc&(1u<<(px+dx[i]+3*(py+dy[i]) + 18u)));
          cc|=rcc[dir][(3u&(cc>>(2*(px+dx[i]+3*(py+dy[i]))))) - 1][i]
                  <<((unsigned)(px+3*py + 18u));
//          cout << bitset<32>(cc) <<endl;
//          cout << "shift:" << (2*(px+dx[i]+3*(py+dy[i]))) << " color:" << ((3&(cc>>(2*(px+dx[i]+3*(py+dy[i]))))) - 1) << " i:"
//               << i << endl;
//          exit(0);
          cc|= dcc[dir][(3u&(cc>>(2*(px+dx[i]+3*(py+dy[i]))))) - 1][i]<<(2*(px+3*py));
//          cout << bitset<32>(cc) << "|end"<<endl;;
          cc&=~(cc&(3u<<(2*(px+dx[i]+3*(py+dy[i])))));


          cc&=0x7ffffff;cc|=((bc>>27)+1u)<<27;

          result.push(cc);
        }
    }
//  exit(0);
}

void rbfs()
{
    unsigned int in = midresult.front();
//    cout << (glc++) << ":"<<bitset<32>(in) << " index:" <<  (in>>27)<< endl;
    unsigned int bc = in;
    midresult.pop();
    if(rused.count(in&0x7ffffff))return;
    else rused.insert(in&0x7ffffff);
    if(used.count(in&0x7ffffff)){
        maxd = (in>>27)+20;return;
    }
    if(in>>27>10) {maxd=40;return;}
    int px,py;
    for(int i = 0;i<9;++i)
      {
        if((in&3)==0)
          {
            px = i %3;py = i/3;
            break;
          }
        in>>=2;
      }
  //  cout << px << " " << py <<endl;
    for(int i = 0;i<4;++i)
      {
  //      cout << px+dx[i] << " " << py+dy[i] << endl;
        if(px+dx[i]>=0&&px+dx[i]<3&&
           py+dy[i]>=0&&py+dy[i]<3)
          {
            unsigned int cc = bc;
            char dir = 1u&(cc>>(px+dx[i]+3*(py+dy[i]) + 18u));
            cc&=~(cc&(1u<<(px+dx[i]+3*(py+dy[i]) + 18u)));
            cc|=rcc[dir][(3u&(cc>>(2*(px+dx[i]+3*(py+dy[i]))))) - 1][i]
                    <<((unsigned)(px+3*py + 18u));
            cc|= dcc[dir][(3u&(cc>>(2*(px+dx[i]+3*(py+dy[i]))))) - 1][i]<<(2*(px+3*py));
            cc&=~(cc&(3u<<(2*(px+dx[i]+3*(py+dy[i])))));
            cc&=0x7ffffff;cc|=((bc>>27)+1u)<<27;
            if(cc>>27==11)continue;
            midresult.push(cc);
          }
      }
}

void intinsert(int dep)
{
//    ddl.back() = ddl.back()|=0x1f<<22;
//    cout << bitset<32>(ddl.back()) << endl;
//    cout << bitset<32>(1u<<18) <<endl;
//    cout << bitset<32>(1u<<(18+8)) <<endl;
    if(dep == 9) return;

    if(dep !=8-glc)
    {
        auto bb = ddl.begin();int cont = ddl.size();
        while(cont--)
        {
            ddl.push_back(*bb|(1u<<(18+dep)));++bb;
        }
    }
    intinsert(dep+1);
}

int main()
{
  char cache;int cnt,xx,yy,gc;
  while(scanf("%d%d",&xx,&yy)&&xx&&yy)
    {
      --xx;--yy;
      cnt=0;tar=0;maxd=-1;gc=0;fin=false;
      while(cnt < 9)
        {
          cache = getchar();if(cache == ' ' || cache == '\n') continue;
          tar<<=2;
          switch(cache){
          case 'W':tar|=w;break;
          case 'B':tar|=b;break;
          case 'R':tar|=r;break;
          case 'E':glc=cnt;
          }
          ++cnt;
        }
      for(int i = 0;i<9;++i)
        {
          gc<<=2;
          if(i==xx+3*yy)continue;
          gc|=w;
        }

//      cout << ddl.size() << endl;return 0;
//      midresult.push(tar);
      result.push(gc);
      while(maxd==-1)
        bfs();
      if(maxd==40) {
          fin = true;
          ddl.push_back(tar);
          intinsert(0);
//          cout << "size:" << ddl.size() << " " << bitset<32>(ddl.back()) << endl;
          for(auto bb = ddl.begin();bb!=ddl.end();++bb)
              midresult.push(*bb);
          maxd = -1;
//          cout << midresult.size() <<endl;return 0;
//              cout << "begin in:"<<bitset<32>(ddl.back()) << endl;
              rused.clear();
              while(maxd==-1&&!midresult.empty()) rbfs();
//          if(maxd==21){
//              cout << bitset<32>(gc) << endl;
//              exit(0);
//          }
      }
      if(maxd >30) maxd = -1;
      printf("%d\n",maxd);
      while(!result.empty())result.pop();
      while(!midresult.empty())midresult.pop();
      used.clear();revers.clear();rused.clear();ddl.clear();
    }
    return 0;
}
