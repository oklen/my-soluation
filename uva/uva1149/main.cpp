#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,l;
int main()
{
    int t;scanf("%d",&t);
    while(t--){
      scanf("%d%d",&n,&l);
      vector<int> wi;int cache,result = 0;
      for(int i = 0;i<n;++i){
          scanf("%d",&cache);
          wi.push_back(cache);}
      sort(wi.begin(),wi.end());
      int be = 0,ed = wi.size()-1;
      while(be<=ed){
          if(wi[be]+wi[ed]<=l){
              ++be;--ed;++result;
          }else{
              --ed;++result;
          }
      }
      if(t>0)
      printf("%d\n\n",result);
      else printf("%d\n",result);
    }
    return 0;
}
