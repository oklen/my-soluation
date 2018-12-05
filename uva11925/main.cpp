#include <iostream>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)&&n){
        deque<int> nd;int nn,cnt=0;
        stack<char> od;
        for(int i = 0;i<n;++i){
            scanf("%d",&nn);
            nd.push_back(nn);
        }
        if(n==1){printf("\n");continue;}
        int rd = 0;
        while(true){
            if(nd.at(0)>nd.at(1))
            {
                int cache = nd.at(0);nd.at(0) = nd.at(1);
                nd.at(1) = cache;
                od.push('1');
                //printf("1");
            }
            else
            {
                ++cnt;++rd;
//                nd.push_back(nd.front());nd.pop_front();
                bool isSorted = true;
                for(int i = 1;i<nd.size();++i){
                    if(nd[i-1]>nd[i]){isSorted = false;break;}

                }if(isSorted)break;
                nd.push_front(nd.back());nd.pop_back();
                //printf("2");
                od.push('2');
            }
            if(rd==n-1){
//                nd.push_back(nd.front());nd.pop_front();

                bool isSorted  = true;
//                for(int i = 0;i<nd.size();++i)cout <<nd[i]<<" ";cout << "|" << rd << endl;
                for(int i = 1;i<nd.size();++i){
                    if(nd[i-1]>nd[i]){isSorted = false;break;}}
                if(isSorted) break;
                nd.push_front(nd.back());nd.pop_back();
/*                nd.push_front(nd.back());nd.pop_back();
                od.push('2');*/od.push('2');
                //printf("22");
                rd = 0;cnt = 0;
            }
        }
        while(!od.empty()){printf("%c",od.top());od.pop();}
        printf("\n");
//                bool sorted = true;
//                for(int i = 1;i<nd.size();++i){
//                    if(nd[i-1]>nd[i]){
//                        sorted =false;
//                        cout << i << " "<< nd.size() << endl;
//                        break;
//                    }
//                }
//                if(sorted) cout << "Yes!" <<endl;
//                else cout << "Wrong!" <<endl;
    }
    return 0;
}
