#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int,vector<int>,greater<int>> mq;
    int cnt;
    while(scanf("%d",&cnt)&&cnt){
        int now;while(!mq.empty())mq.pop();
        while(cnt--){scanf("%d",&now);mq.push(now);}
        unsigned long sum = 0;int cn = 0;
        while(mq.size()>1){
            cn = 0;cn+=mq.top();mq.pop();cn+=mq.top();mq.pop();
            sum+=cn;mq.push(cn);
        }
        cout << sum << endl;
    }
    return 0;
}
