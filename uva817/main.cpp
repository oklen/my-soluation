#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool ib = true;
vector<int> str;
vector<vector<pair<int,char>>> result;
vector<pair<int,char>> nstr;
vector<pair<int,char>> lnum;
const char opr[]={'*','+','-'};

void search(int b)
{
    int ins = b;int k = 0;
    if(b!=str.size())
    {
        while(b!=str.size())
        {
            k*=10;k+=str.at(b);
            if(lnum.size()==0)
            {
                for(int i = 0;i<3;++i)
                {
                    nstr.push_back({k,opr[i]});
                    lnum.push_back({k,opr[i]});
                    //cout << "k:"<<k <<" b:"<<b <<endl;
                    search(b+1);
                    nstr.pop_back();lnum.pop_back();
                    if(b==str.size()-1)
                    {
                        break;
                    }
                }
            }
            else
            {
                bool isori = lnum.back().second=='*'?true:false;
                int lastsave;
                if(isori){lastsave = lnum.back().first;lnum.back().first*=k;}
                for(int i = 0;i<3;++i)
                {
                    nstr.push_back({k,opr[i]});
                    if(isori)
                    {lnum.back().second=opr[i];}
                    else lnum.push_back({k,opr[i]});
                    search(b+1);
                    nstr.pop_back();
                    if(!isori)
                    lnum.pop_back();
                    if(b==str.size()-1)
                    {
                        break;
                    }
                }
                if(isori){lnum.back().first = lastsave;lnum.back().second='*';}
            }
            ++b;
            if(str.at(ins)==0&&b!=str.size())return;
        }return;
    }
    if(b==str.size())
    {
        int sum = 0;
        auto bb = lnum.begin();
        if(lnum.size()==0)return;
        sum = bb->first;
//2*100*10+0
        while(bb+1!=lnum.end())
        {
            sum+=bb->second=='+'?(bb+1)->first:-((bb+1)->first);++bb;
        }
        if(sum==2000){/*cout << nstr.at(0).first << nstr.at(0).second<<endl;*/result.push_back(nstr);}
    }
}

int main()
{
    char now;int cnt = 0;
    while(true)
    {
        now = getchar();
        while(now==' '||now=='\n')now=getchar();
        while(now!='='){str.push_back(now-'0');now=getchar();}
        if(str.size()==0)break;
        lnum.clear();nstr.clear();
//        for(auto bb = str.begin();bb!=str.end();++bb)
//            cout << *bb;
//        cout <<endl; return 0;
        search(0);
        printf("Problem %d\n",++cnt);
        if(result.size()==0)
        {
            printf("  IMPOSSIBLE\n");
        }
        else
        {
            if(result.size()==1&&result.at(0).size()==1)
            {
                printf("  IMPOSSIBLE\n");
            }
            else for(auto bb = result.begin();bb!=result.end();++bb)
            {
                auto cc = bb->begin();printf("  ");
                while(cc+1!=bb->end())
                {printf("%d%c",cc->first,cc->second);++cc;}
                printf("%d=\n",cc->first);
            }
        }
        result.clear();str.clear();
    }
    return 0;
}
