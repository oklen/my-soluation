//#include <iostream>
//#include <deque>
//#include <queue>
//using namespace std;

//int main()
//{
//    int n;
//    while(scanf("%d",&n)&&n){
//        deque<int> nd;int nn,mx = -1,cnt=0,mi = 0xfffffff;
//        for(int i = 0;i<n;++i){
//            scanf("%d",&nn);
//            mx = max(mx,nn);
//            mi = min(mi,nn);
//            nd.push_back(nn);
//        }
//        mx+=1;//Additional mx
//        nd.push_back(mx);
//        queue<char> od;
//        while(true){
//            if(nd.at(0)>nd.at(1)&&nd.front()!=mx)
//            {
//                cnt = nd.at(0);nd.at(0) = nd.at(1);
//                nd.at(1) = cnt;cnt=0;
//                while(!od.empty()){
//                    printf("%c",od.front());
//                    od.pop();
//                }
//                printf("1");
//            }
//            else{
//                if(nd.front()!=mx)
//                    od.push('2');
//                else cnt = 0;
//                if(cnt!=0||nd.at(0)==mi)
//                ++cnt;
//                nd.push_back(nd.front());nd.pop_front();
//            }
//            if(cnt>=(nd.size()-1))break;
//        }
//        while(od.size()){printf("%c",od.front());od.pop();}
//        printf("\n");
////        for(int i = 0;i<nd.size();++i)
////            cout << nd[i] << " ";
////        cout << endl;
//                bool sorted = true;
//                for(int i = 2;i<nd.size();++i){
//                    if(nd[i-1]>nd[i]){
//                        sorted =false;
//                        cout << i << " "<< nd.size() << endl;
//                        break;
//                    }
//                }
//                if(sorted) cout << "Yes!" <<endl;
//                else cout << "Wrong!" <<endl;
//    }
//    return 0;
//}
