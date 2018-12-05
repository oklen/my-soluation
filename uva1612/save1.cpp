//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//using namespace std;

//int main()
//{
//    int n,cnt = 1;
//    while(scanf("%d",&n)&&n){
//        vector<priority_queue<float,vector<float>,greater<float>>> scores(
//                    n,priority_queue<float,vector<float>,greater<float>>());
//        vector<float> allsum(n,0);vector<float> cc(3,0),cl;
//        for(int i = 0;i<n;++i)
//        {
//            for(int j = 0;j<3;++j){
//                float cache;scanf("%f",&cache);
//                cc[j] = cache;
//                allsum[i]+=cache;
//            }
//            for(int j = 0;j<3;++j){
//                for(int k = 0,sz = cl.size();k<sz;++k){
//                    cl.push_back(cl[k]+cc[j]);
//                }cl.push_back(cc[j]);
//            }
//            for(auto bb = cl.begin();bb!=cl.end();++bb){
//                scores[i].push(*bb);
//            }scores[i].push(0);
//            cl.clear();
////            while(!scores[i].empty()){cout << scores[i].top() << endl;scores[i].pop();}
////            cout << allsum[i] <<endl;
////            exit(0);
//        }
//        int rks,lrks;scanf("%d",&rks);
//        lrks = rks;float mx = allsum[rks-1];
//        for(int i = 1;i<n;++i){
//            scanf("%d",&rks);
//            if(rks>lrks){
//                while((!scores[rks-1].empty())){
//                    if(allsum[rks-1]-scores[rks-1].top() -mx >= -0.01||
//                          allsum[rks-1]-scores[rks-1].top() -mx <= 0.01){
//                        allsum[rks-1]-=scores[rks-1].top();break;
//                    }
//                    scores[rks-1].pop();
//                }
//            }else {
//                while((!scores[rks-1].empty())){
//                    if(allsum[rks-1]-scores[rks-1].top()-mx>-0.01||
//                            allsum[rks-1]-scores[rks-1].top()-mx<0.01){
//                        allsum[rks-1]-=scores[rks-1].top();break;
//                    }
//                    scores[rks-1].pop();
//                }
//            }
////            cout << allsum[rks-1] << endl;
//            if(scores[rks-1].empty())
//                mx = 0;
//            else mx = allsum[rks-1];
//            if((rks<lrks&&mx==0)/*||mx<=0*/){mx = -1;
//                while(++i<n)scanf("%d",&rks);break;}
//            lrks = rks;
//        }
//        printf("Case %d: ",cnt++);
//        if(mx==-1)cout << "No solution"<<endl;
//        else printf("%.2f\n",mx);
//    }
//    return 0;
//}
