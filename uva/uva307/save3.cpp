//#include <iostream>
//#include <set>
//#include <vector>
//#include <algorithm>

//using namespace std;
//vector<int> numc;
//vector<pair<int,int>> cnts;
//vector<int> bpc;
//vector<set<int>> vis;
//int mn,divs,asum,glbc;

//bool tryfill(int nw,int pos)
//{
//    //tryfill(mn,cnts.size()-1)
//    if(nw==0){
//        if(++glbc==divs)return true;
//        //cout << "divs:" << divs << " glbc:" <<glbc <<endl;
//        if(tryfill(mn,cnts.size()-1)&&glbc==divs)return true;
//        --glbc;return false;
//    }
//    if(nw==mn)
//    {
//        if(glbc!=0){
//            pos = bpc.at(glbc-1);
//        }

//        bpc.at(glbc) = pos;
//    }
//    if(vis.at(pos).count(nw))return false;

//    while(pos>=0&&(cnts.at(pos).first>nw||cnts.at(pos).second==0))--pos;
//        int ori = pos;
//    if(pos<0){return false;}
//    for(;pos>=0;--pos)
//    {
////        cout << mn <<" work in:"<< nw << " " << cnts.at(pos).first <<endl;
//        if(nw==mn)
//        {bpc.at(glbc) = pos;//cout << "get pos:"<<glbc << " " << pos <<endl;
//        if(glbc==0&&pos!=cnts.size()-1)return false;}
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
//            vis.at(pos).erase(nw-cnts.at(pos).first*i);
//        }
//    }
//    vis.at(ori).insert(nw);
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
//        while(asum%mn&&mn<asum)++mn;
//        divs=asum/mn;if(divs==1){cout<<asum<<endl;continue;}
////        cout << divs << " " << mn << endl;return 0;
//        glbc = 0;bpc = vector<int>(divs,cnts.size()-1);
//        vis = vector<set<int>>(cnts.size(),set<int>());
//        while(divs>1)
//        {
//            //cout << numc.size() << " mn:"<<mn<<endl;
//                if(!tryfill(mn,cnts.size()-1))
//                {
//                    for(int i = 0;i<cnts.size();++i)vis.at(i).clear();
//                    while(--divs>1&&asum%divs);
//                    mn = asum/divs;
//                    bpc = vector<int>(divs,cnts.size()-1);
//                }else break;
//        }
//        cout << mn << endl;
//    }
//    return 0;
//}
