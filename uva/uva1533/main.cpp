#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <set>
#include <bitset>
using namespace std;
struct path{
    int from,to;path* parent;
    path(int from,int to,path* par):from{from},to{to},parent{par}{
//        cout << "from:" <<from << " to:" <<to <<endl;
    }
};

const int mv3[3][3]{{4,5,6},{4,8,13},{6,9,13}};
const int mv4[3][4]{{3,5,8,12},{2,5,9,14},{7,8,9,10}};
const int mv5[3][5]{{11,12,13,14,15},{1,2,4,7,11},{1,3,6,10,15}};
const int mv[3][3][5]{{{4,5,6},{4,8,13},{6,9,13}},
                     {{3,5,8,12},{7,8,9,10},{2,5,9,14}},
                     {{1,2,4,7,11},{1,3,6,10,15},{11,12,13,14,15}}};
unordered_set<unsigned> sts;
queue<pair<unsigned,path*>> req;
path* ansp;
//vector<pair<int,int>> moveconv(); Use symmetic to get result
unsigned t;

void bfs(unsigned in,path* parent)
{
    if(sts.count(in)/*&&in!=t*/)return;
    else sts.insert(in);
    int beg,end;

    if(in==t){
        if(ansp==nullptr)
        ansp = parent;
        return;
    }
    vector<pair<int,path*>> cash;
    for(int i = 0;i<3;++i)
    {
        for(int j = 0;j<3;++j)
        {
            for(int k = 0;k<3+i&&!ansp;++k)
            {
                if(in&(1<<(mv[i][j][k]-1)))
                {
                    beg  = k;
                    while(k<2+i&&(in&1<<(mv[i][j][k+1]-1)))++k;
                    end = k;if(beg==end)continue;
                    unsigned ci;
                    if(beg!=0)
                    {
                        ci = in|(1<<(mv[i][j][beg-1]-1));
                        ci&=~(1<<(mv[i][j][beg]-1));
                        for(int bb = beg+1;bb<=end;++bb)
                        {
                            ci&=~(1<<(mv[i][j][bb]-1));
                            //cout << mv[i][j][bb] << endl;
                            cash.push_back({ci,new path(mv[i][j][bb],mv[i][j][beg-1],parent)});
                        }
                    }
                    if(end<2+i)
                    {
                        ci = in|(1<<(mv[i][j][end+1]-1));
                        ci&= ~(1<<(mv[i][j][end]-1));
                        for(int bb = end-1;bb>=beg;--bb)
                        {
                            ci&=~(1<<(mv[i][j][bb]-1));
                            cash.push_back({ci,new path(mv[i][j][bb],mv[i][j][end+1],parent)});
                        }
                    }
                }
            }
        }
    }
    sort(cash.begin(),cash.end(),
         [](const pair<unsigned,path*>&a,const pair<unsigned,path*>&b){if (a.second->from==b.second->from)
            return  a.second->to<b.second->to;else return a.second->from<b.second->from;});
    for(auto bb = cash.begin();bb!=cash.end();++bb)
        req.push(move(*bb));
}

int main()
{
    vector<set<int>> ps;
    set<int> s1{5,8,9},s2{2,3,7,12,14,10},s3{1,11,15},s4{4,13,6};
    ps.push_back(s1);ps.push_back(s2);ps.push_back(s3);ps.push_back(s4);
    vector<pair<int,int>> ans[4];
    int T;scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&t);
        t = 1u<<(t-1);unsigned v1 = 0x7fff&(~t);
        req.push({v1,nullptr});ansp=nullptr;
        while(!req.empty()/*&&!ansp*/)
        {
            bfs(move(req.front().first),move(req.front().second));
            req.pop();
        }
        if(ansp!=nullptr)
        {
            vector<pair<int,int>> ap;
            while(ansp!=nullptr)
            {
                ap.push_back({ansp->from,ansp->to});
                ansp = ansp->parent;
            }
            cout << ap.size() << endl;
            auto bb = ap.rbegin();
            cout << bb->first << " " << bb->second;++bb;
            for(;bb!=ap.rend();++bb)
                cout << " " << bb->first << " " << bb->second;
            cout << endl;
        }
        else
            cout << "IMPOSSIBLE" <<endl;
        while(!req.empty())req.pop();sts.clear();
    }
}
