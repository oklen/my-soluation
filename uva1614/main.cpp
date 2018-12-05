#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <unordered_map>

int ar[100005],n;
int ars[100005];
long long sum=0;
using namespace std;
vector<int> ans;
bool finded = false;

void dfs(unsigned long now,int i){
    if(i>=n)return;
    for(int j = i;j<n&&!finded;++j){
        if(now+ar[j]>sum) return;
        else if(now+ar[j]==sum){
            finded = true;ans.push_back(j);return;
        }
        else {ans.push_back(j);dfs(now+ar[j],j+1);if(!finded)ans.pop_back();}
    }
}

int main()
{

    while(~scanf("%d",&n)){
        set<int> s;sum=0;
        for(int i = 0;i<n;++i){scanf("%d",ar+i);sum+=ar[i];ars[i]=ar[i];}
        sort(ar,ar+n);finded = false;ans.clear();
        long long sum1=0,sum2 = 0;
        for(int i = n-1;i>=0;--i){
            if(sum2<sum1){sum2+=ar[i];ans.push_back(i);}
            else sum1+=ar[i];
        }
        if(sum1==sum2) finded = true;
        sort(ans.begin(),ans.end());
        if(finded){
//            cout << sum1 << " " << sum2 << endl;
            printf("Yes\n");
            unordered_map<int,int> wm;
            for(auto bb = ans.begin(),ed = ans.end();bb!=ed;++bb){
                ++wm[ar[*bb]];
            }
            for(int i = 0;i<n;++i){
                if(wm[ars[i]]){--wm[ars[i]];if(i+1<n)printf("1 ");else printf("1\n");}
                else{if(i+1<n)printf("-1 ");else printf("-1\n");}
            }
        }else printf("No\n");
    }
    return 0;
}
