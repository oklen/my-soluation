#include <iostream>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n,m,cm,cn;
int mmp[26][26];
int posc[26][2];
bool vistied[26];
char cc[1000];

void dfs(int bg)
{
    if(vistied[bg] == false) ++cm;
    vistied[bg] = true;

    if(cm == cn) return;
    for(int i = 0;i<26;++i)
    {
        if(mmp[bg][i]>0 && vistied[i] == false)
        {
            dfs(i);
            if(cm == cn) return;
        }
    }
    //cout << endl;
}

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        for(int i =0;i<m;++i)
        {
            scanf("%s",cc);
            ++posc[cc[0]-97][0];++posc[cc[strlen(cc)-1]-97][1];
            ++mmp[cc[0]-97][cc[strlen(cc)-1]-97];
            memset(cc,0,1000);
        }
        int mostodd = 0;
        for(int i = 0;i<26;++i)
            if(posc[i][0]!=0||posc[i][1]!=0){++cn;
                if(posc[i][0] != posc[i][1])
                    ++mostodd;
                if(abs(posc[i][0] - posc[i][1]) > 1){mostodd=5;break;}}
        //cout << "CN:" << cn <<endl;

        if(mostodd <=2)
        for(int i = 0;i<26;++i)
        {
            if(cm < cn)
            {memset(vistied,0,sizeof(bool)*26);dfs(i);if(cm<cn) {cm=0;}}
            else
                break;
        }

        if(cm == cn && mostodd <=2 ) cout << "Ordering is possible."<<endl;
        else cout << "The door cannot be opened." << endl;
        cm = 0;memset(mmp,0,sizeof(int)*26*26);cn = 0;memset(posc,0,sizeof(int)*26*2);
    }
    return 0;
}
