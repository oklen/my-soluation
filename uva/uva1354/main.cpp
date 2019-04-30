#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;
double wid;
int s;double r;
vector<vector<int>> ss[6];

vector<vector<int>> subset(int n,int cur,vector<vector<int>> begin)
{
  if(n == cur) return begin;
  int bs = begin.size();
  for(int i = 0;i<bs;++i)
    {
      vector<int> cache = begin.at(i);
      cache.push_back(cur);
      begin.push_back(cache);
    }
  return subset(n,cur+1,begin);
}

vector<pair<double,double>> solve(vector<double> nw,vector<double> bps)
{
  vector<pair<double,double>> result;
  if(nw.size()==1)
  {
      for(auto bp = bps.begin();bp != bps.end();++bp)
      {
          {result.push_back(pair<double,double>(*bp,*bp));continue;}
      }
      return result;
  }
      auto& subs = ss[nw.size()-1];
      vector<double> lnw,rnw;double lw,rw;
      for(int i = 0;i<subs.size()/2;++i)
      {
          lw=rw=0;lnw.clear();rnw.clear();
//          cout << "use i:" << i << " " << subs.size()-1-i << endl;
//          cout << "size:" << subs[i].size() <<endl;
          for(int j = 0;j<subs[i].size();++j)
          {
//              cout << subs[i][j] << endl;
              lnw.push_back(nw[subs[i][j]]);
              lw+=nw[subs[i][j]];
          }
          for(int j = 0;j<subs[subs.size()-1-i].size();++j)
          {
//              cout << subs[subs.size()-1-i][j] << endl;
              rnw.push_back(nw[subs[subs.size()-1-i][j]]);
              rw+=nw[subs[subs.size()-1-i][j]];
          }
          //finished fill set and weight
          double lp = rw/(lw+rw),rp=lw/(lw+rw);
//          cout << "give lnw:" << lnw.size() << endl;
//          cout << "give rnw:" << rnw.size() << endl;
          vector<pair<double,double>> lr=solve(lnw,bps),rr=solve(rnw,bps);
          for(auto& le:lr)
              for(auto& re:rr)
                  result.push_back(pair<double,double>
                              (min(min(le.first,le.second)+lp,min(re.first,re.second)-rp),
                                   max(max(le.first,le.second)+lp,max(re.first,re.second)-rp)));
//          cout << "Begin" << endl;
          for(auto& le:lr)
              for(auto& re:rr)
              {
                  result.push_back(pair<double,double>
                                   (min(min(le.first,le.second)-lp,min(re.first,re.second)+rp),
                                    max(max(le.first,le.second)-lp,max(re.first,re.second)+rp)));
              }
      }
//      exit(0);

  return result;
}

int main()
{
for(int i = 1;i<=6;++i)
  {
   vector<vector<int>> cv;
   cv.push_back(*new vector<int>());
   ss[i-1] = subset(i,0,cv);
   ss[i-1].pop_back();ss[i-1].erase(ss[i-1].begin());
  }
  int t;scanf("%d",&t);
  while(t--){
    scanf("%lf\n%d",&r,&s);
    double cc;vector<double> begin;
    for(int i = 0;i<s;++i)
      {scanf("%lf",&cc);begin.push_back(cc);}
    vector<double> init {0};
    auto result = solve(begin,init);
    double nearest = 11,nearw = -1;
    for(auto& bb:result)
        if(abs(bb.first-bb.second)<r&&nearest>r-abs(bb.first-bb.second))
        {nearest = abs(r-abs(bb.first-bb.second));
        nearw = abs(bb.first-bb.second);
    printf("%.12lf\n",nearw);
  }
    return 0;
}}
