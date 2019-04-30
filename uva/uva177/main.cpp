#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int R = 1<<3,L=1<<2,U=1<<1,D=1<<0;
vector<vector<vector<char>>> ans;
vector<vector<vector<char>>> aans;

void rotate(int y,int x){
    vector<vector<char>> &last = ans.back();
    int h = last.size(),l = last[0].size();
    int dy = y-x-1<0?1+x-y:0,dx = y+x-h+1<0?h-x-y-1:0;
    vector<vector<char>> nl(h*2+dy,vector<char>(l*2+dx,0));
    for(int i = 0;i<last.size();++i)
        for(int j = 0;j<last[i].size();++j)
        {
            if(last[i][j])
            {
                nl[i+dy][j+dx]|=last[i][j];
                nl[y+dy-(x-j)][x+dx+(y-i)]|=(last[i][j]&D?L:0)+(last[i][j]&R?D:0);
            }
        }
    for(int i = 0;i<nl.size();++i)
        for(int j =0;j<nl[i].size();++j){
            if(nl[i][j]&L){
                nl[i][j]&=~L;nl[i][j-1]|=R;
            }
        }
    for( auto bb = nl.begin();bb!=nl.end();++bb){
        bool empty = true;
        for(int i = 0;i<bb->size();++i){
            if(bb->at(i)){empty = false;break;}
        }
        if(empty)nl.erase(bb);else break;
    }
    for( auto bb = nl.rbegin();bb!=nl.rend();++bb){
        bool empty = true;
        for(int i = 0;i<bb->size();++i){
            if(bb->at(i)){empty = false;break;}
        }
        if(empty)nl.pop_back();else break;
    }
//    while(true){
//        bool allempty = true;
//        for(int i = 0;i<nl.size();++i){
//            if(*nl[i].rbegin()){allempty = false;break;}
//        }
//        if(allempty)
//        for(int i = 0;i<nl.size();++i)nl[i].pop_back();
//        else break;
//    }
    while(true){
        bool allempty = true;
        for(int i = 0;i<nl.size();++i){
            if(*nl[i].begin()){allempty = false;break;}
        }
        if(allempty)
        for(int i = 0;i<nl.size();++i)nl[i].erase(nl[i].begin());
        else break;
    }
    ans.push_back(nl);
//    for(int i = 0;i<nl.size();printf("X%dX\n",nl[i].size()),++i)
//        for(int j = 0;j<nl[i].size();++j){
//            if(nl[i][j])switch((int)nl[i][j]){
//            case D:printf("D");break;
//            case U:printf("U");break;
//            case L:printf("L");break;
//            case R:printf("R");break;
//            default:printf("W");
//            }else printf(" ");
//        }
    auto cps = nl;
    for(int i = 0;i<cps.size();++i)
        for(int j =0;j<cps[i].size();++j){
            if(cps[i][j]&D){
                cps[i][j]&=~D;cps[i+1][j]|=U;
            }
        }
    bool empty = true;
    for(int i = 0;i<cps[0].size();++i){
        if(cps[0][i]) {empty = false;break;}
    }
    if(empty)cps.erase(cps.begin());
    for(int i = 0;i<cps.size();++i){
        for(auto bb = cps[i].rbegin();bb!=cps[i].rend();++bb)
            if(*bb==0)cps[i].pop_back();else break;
    }
    aans.push_back(cps);
//    for(int i = 0;i<cps.size();++i,printf("\n"))
//        for(int j = 0;j<cps[i].size();++j){
//            if(cps[i][j]&U)printf("|");else if(j+1<cps[i].size()||cps[i][j]&R)printf(" ");
//            if(cps[i][j]&R)printf("_");else if(j+1<cps[i].size())printf(" ");
//        }
//    printf("^\n");
}
int main()
{
    ans.push_back(vector<vector<char>>{vector<char>{0,D},vector<char>{R,0}});
    aans.push_back(vector<vector<char>>{vector<char>{R,U}});
    for(int ci = 0;ci<12;++ci){
        for(int i = 0;i<ans[ci][0].size();++i)
            for(int j = 0;j<ans[ci].size();++j){
                if(ans[ci][j][i]==D&&(i==0||!(ans[ci][j][i-1]&R)))
                {
                    rotate(j,i);i=ans[ci][0].size();break;
                }
            }
    }
    int now;
//    cout << aans.size() << endl;
    while(scanf("%d",&now)&&now){
        if(now==1){
            printf("_|\n");
        }else
        for(int i = 0;i<aans[now-1].size();++i,printf("\n"))
            for(int j = 0;j<aans[now-1][i].size();++j){
                if(aans[now-1][i][j]&U)printf("|");else if(j+1<aans[now-1][i].size()||aans[now-1][i][j]&R)printf(" ");
                if(aans[now-1][i][j]&R)printf("_");else if(j+1<aans[now-1][i].size())printf(" ");
            }
        printf("^\n");
    }
    return 0;
}
