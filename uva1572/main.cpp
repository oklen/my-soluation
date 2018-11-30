#include <iostream>
#include <vector>
#include<stdio.h>
#include <bits/stdc++.h>
#include <set>
using namespace std;

int n,cf[4];
char cc[8];
bool visited[52];
vector<pair<int,bool>> mmp[52];
bool terminated;
int chg(int pos)
{
    //cout << cc[pos]  << " ";
    if(cc[pos]!='0')
    return 2*(cc[pos]-65)+(cc[pos+1]=='+'?1:0);
    else return -1;
}

void dfs(int pos)
{
    //cout << "when visite:" << pos << endl;
    while(mmp[pos].size()!=0 && !terminated)
    {
        int c = mmp[pos].back().first;
        //cout <<  (char)(65+pos/2) << " " << (char)(65+c/2) << endl;
        if(mmp[pos].back().second == true) {terminated = true;break;}
        else mmp[pos].back().second = true;
        c = c%2?c-1:c+1;
        dfs(c);
        mmp[pos].pop_back();

    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        while(n--)
        {
            getchar();scanf("%8c",cc);
            //cout << cc << endl;
            //return 0;
            for(int i = 0;i<4;++i)
            {
                cf[i] = chg(2*i);
            }
            for(int i = 0;i<4;++i)
            {
                if(cf[i]!=-1)
                {
                    for(int j = 0;j<4;++j)
                    {
                        if(cf[j]!=-1 && i!=j)
                            mmp[cf[i]].push_back(pair<int,bool>(cf[j],false));
                    }
                }
            }
        }
//        for(int pos = 0;pos<52;++pos)
//        {
//            if(mmp[pos].size() == 0) continue;
//            sort(mmp[pos].begin(),mmp[pos].end());
//            int ns = unique(mmp[pos].begin(),mmp[pos].end()) - mmp[pos].begin();
//            mmp[pos].resize(ns);
//            cout << "pos:" << pos << " ";
//            for(auto b = mmp[pos].begin();b!=mmp[pos].end();++b)
//                cout << *b << " ";
//            cout << endl;
//        }
//        for(int i = 0;i<mmp[1].size();++i)
//            cout << mmp[1].at(i) << endl;
//        return 0;
        for(int i = 0;i<52;++i)
        {
            while(mmp[i].size()!=0 && !terminated) {
                int c = mmp[i].back().first;
                mmp[i].back().second = true;
                dfs(c%2?c-1:c+1);
                mmp[i].pop_back();
//                memset(visited,0,sizeof(bool)*52);
            }
        }
        if(terminated) cout << "unbounded" << endl;
        else cout << "bounded" << endl;
        terminated = false;
//        memset(visited,0,sizeof(bool)*52);
        for(int i = 0;i<52;++i)
            mmp[i].clear();
    }
    return 0;
}
