//#include <iostream>
//#include <set>
//#include <vector>
//#include <algorithm>

//using namespace std;
//vector<int> numc;
//vector<pair<int,int>> cnts;
//int mn,divs,asum;

//bool tryfill(int nw,int pos)
//{
//    if(nw==0)return  true;
//    while(pos>=0&&(cnts.at(pos).first>nw||cnts.at(pos).second==0))--pos;
//    if(pos<0){return false;}
//    for(;pos>=0;--pos)
//    {
//        if(cnts.at(pos).second==0)continue;
//        for(int i = 1;i<=cnts.at(pos).second&&nw-cnts.at(pos).first*i>=0;++i)
//        {
//            //cout << "nw:"<<nw<<endl;
//            cnts.at(pos).second-=i;
//            if(tryfill(nw-cnts.at(pos).first*i,
//                       lower_bound(cnts.begin(),cnts.begin()+pos,
//                                   pair<int,int>{nw-cnts.at(pos).first*i,0},
//                                   [](const pair<int,int>&a,const pair<int,int>& b)
//            {return a.first<b.first;})-cnts.begin()))return true;
//            cnts.at(pos).second+=i;
//        }
//    }
//    return false;
//}

//int main()
//{
//    int cntt;
//    while(~scanf("%d",&cntt)&&cntt)
//    {
//        int ca;numc.clear();cnts.clear();asum=0;
//        while(cntt--){scanf("%d",&ca);numc.push_back(ca);asum+=ca;}
//        sort(numc.begin(),numc.end());
//        for(auto bb = numc.begin();bb!=numc.end();)
//        {
//            ca = *(bb++);cnts.push_back({ca,1});
//            while(ca==*bb&&bb!=numc.end()){++cnts.back().second;++bb;}
//        }
//        if(cnts.size()==1)
//        {cout<< cnts.front().first <<endl;continue;}
//        mn = cnts.front().first+cnts.back().first;
//        while(asum%mn&&mn<asum)++mn;divs=asum/mn;if(divs==1){cout<<asum<<endl;continue;}
////        cout << divs << " " << mn << endl;return 0;
//        bool passed;
//        while(divs>1)
//        {
//            passed = true;
//            for(int i = 0;i<divs;++i)
//            {
//                if(!tryfill(mn,cnts.size()-1))
//                {
//                    while(--divs>1&&asum%divs);
//                    mn = asum/divs;passed=false;break;
//                }
//                cout << i << " " << divs <<endl;
////                for(auto cc = cnts.begin();cc!=cnts.end();++cc)
////                    cout << cc->first << " " << cc->second <<endl;
//            }if(passed)break;
//        }
//        cout << mn << endl;
//    }
//    return 0;
//}
