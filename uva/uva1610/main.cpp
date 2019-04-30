#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)&&n){
        vector<string> cache;
        for(int i = 0;i<n;++i){
            string cs;cin>> cs;
            cache.push_back(move(cs));
        }
        sort(cache.begin(),cache.end());
        string ans;int keyp = cache.size()/2-1,nowc = 0;
        while(ans.size()+1<cache[keyp].size()&&ans.size()<cache[keyp+1].size()-1){
            if(cache[keyp+1][nowc]-cache[keyp][nowc]==0){
                ans.push_back(cache[keyp][nowc]);++nowc;
            }else {
                ans.push_back(cache[keyp][nowc]+1);++nowc;break;
            }
        }
        if(ans>=cache[keyp]&&ans<cache[keyp+1])
                    cout << ans << endl;
        else if(nowc == cache[keyp].size()-1)
            cout << cache[keyp]<<endl;
        else {
            if(cache[keyp][nowc]+1<cache[keyp+1][nowc])
            {
                ans.push_back(cache[keyp][nowc]+1);
                cout << ans << endl;
                continue;
            }else {ans.push_back(cache[keyp][nowc]);++nowc;}
            while(nowc<cache[keyp].size()&&cache[keyp][nowc]=='Z'){
                ans.push_back('Z');++nowc;
            }
            if(nowc==cache[keyp].size()){}
            else if(nowc<cache[keyp].size()-1){ans.push_back(cache[keyp][nowc]+1);}
            else ans.push_back(cache[keyp][nowc]);
            cout << ans << endl;
        }
    }
    return 0;
}
