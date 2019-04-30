#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int L,D,n,cnt,D2;
    while(~scanf("%d%d%d",&L,&D,&n)){
        vector<pair<int,int>> pts(n,{0,0});D2=D*D;
        for(int i = 0;i<n;++i){
            scanf("%d%d",&pts[i].first,&pts[i].second);
        }cnt = 0;
        sort(pts.begin(),pts.end(),[D2](pair<int,int>&a,pair<int,int>&b){
            return a.first<b.first;
        });
        while(!pts.empty()){
            float l=0,r=L;
            for(int i = pts.size()-1;i>=0;--i)
            {
                float dx = sqrt(D2-pts[i].second*pts[i].second);
                if(pts[i].first+dx<l) break;
                else{
                    l = max(l,pts[i].first-dx);
                    r = min(r,pts[i].first+dx);
                    pts.pop_back();
                }
            }
            ++cnt;
        }
        cout << cnt<<endl;cnt=0;
    }
    return 0;
}
