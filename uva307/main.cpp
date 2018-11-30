#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> numc;
vector<pair<int,int>> cnts;
vector<int> bpc;
vector<set<int>> vis;
int mn,divs,asum,glbc;

bool tryfill(int nw,int pos)
{
    //tryfill(mn,cnts.size()-1)
    if(nw==0){
        if(++glbc==divs)return true;
        //cout << "divs:" << divs << " glbc:" <<glbc <<endl;
        if(tryfill(mn,cnts.size()-1)&&glbc==divs)return true;
        --glbc;return false;
    }
//    if(vis.at(pos).count(nw))return false;
//    int ori = pos;
    while(pos>=0&&(cnts.at(pos).first>nw||cnts.at(pos).second==0))--pos;
    if(pos<0){return false;}
    for(;pos>=0;--pos)
    {
        if(cnts.at(pos).second==0)continue;
            cnts.at(pos).second-=1;
            if(tryfill(nw-cnts.at(pos).first,
                       lower_bound(cnts.begin(),cnts.begin()+pos,
                                   pair<int,int>{nw-cnts.at(pos).first,0},
                                   [](const pair<int,int>&a,const pair<int,int>& b)
            {return a.first<b.first;})-cnts.begin()))return true;
            cnts.at(pos).second+=1;
            if(nw==mn)return false;
    }
//    vis.at(ori).insert(nw);
    return false;
}

int main()
{
    int cntt;
    while(~scanf("%d",&cntt)&&cntt)
    {
        int ca;numc.clear();cnts.clear();asum=0;
        while(cntt--){scanf("%d",&ca);numc.push_back(ca);asum+=ca;}
        sort(numc.begin(),numc.end());
        for(auto bb = numc.begin();bb!=numc.end();)
        {
            ca = *(bb++);cnts.push_back({ca,1});
            while(ca==*bb&&bb!=numc.end()){++cnts.back().second;++bb;}
        }
        if(cnts.size()==1)
        {cout<< cnts.front().first <<endl;continue;}
        mn = cnts.back().first;
        while(asum%mn&&mn<asum)++mn;
        divs=asum/mn;if(divs==1){cout<<asum<<endl;continue;}
        glbc = 0;
//        vis = vector<set<int>>(cnts.size(),set<int>());
        while(divs>1)
        {
            //cout << numc.size() << " mn:"<<mn<<endl;
                if(!tryfill(mn,cnts.size()-1))
                {
                    while(--divs>1&&asum%divs);
                    mn = asum/divs;
                }else break;
        }
        cout << mn << endl;
    }
    return 0;
}
