#include <iostream>
#include <vector>
using namespace std;
string ans;
int n,d;

int main()
{
    while(scanf("%d%d",&n,&d)&&n){
        getchar();
        string rec;int now = 0;
        for(int i = 0;i<n;++i)rec.push_back(getchar());ans.clear();
        while(d&&now<n-d){
            int nowt = -1,nextt = -1,npos=-1,beg = now;vector<int> np;
            //cout << now << ' ' << d <<endl;
            for(int i = 0;i<=d&&now<rec.size();++i,++now){
//                if(rec[now]>nextt){nextt=rec[now];np.clear();np.push_back(now);}
//                else if (rec[now]==nextt){np.push_back(now);}
                if(rec[now]>nowt){
                    np.clear();nowt = rec[now];npos=now;nextt=-1;
                }
            }
            if(npos==-1)break;
            d-=npos-beg;ans.push_back(nowt);int usedi = -1;
/*            cout << npos + 1<< " " << d<<endl;
            for(int i = 0;i<np.size()&&d-(np[i]-npos)+1+i>=0&&np[i]<n-(d-(np[i]-npos)+1+i);++i){
                if(d-(np[i]-npos)+1+i>=0){
                    ans.push_back(rec[np[i]]);usedi = i;
                }else break;
            }
            if(usedi!=-1){now = np[usedi]+1;d-=np[usedi]-npos;d+=1+usedi;}
            else */now = npos+1;
        }
        while(now<n-d){ans.push_back(rec[now++]);}
        cout << ans <<endl;
    }
    return 0;
}
