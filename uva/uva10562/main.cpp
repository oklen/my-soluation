#include <iostream>
#include <string>
#include <bits/stdc++.h>

#define maxn 210
using namespace std;
string empty;
string endss = {"()"};
char mmap[maxn][maxn];
string dfs(int l,int p)
{
    string result {mmap[l][p],'('};
   if(mmap[l+1][p] == ' ' || mmap[l+1][0] == '#')
       return result+')';
   while(mmap[l+2][p-1]=='-')--p;
   while(mmap[l+2][p]=='-')
   {
       if(mmap[l+3][p]!=' ' && mmap[l+3][p]!='#')
           result+=dfs(l+3,p);
       ++p;
   }
   return result+')';
}
int main()
{
    int n ;
    cin >> n;
    char cc;
    getchar();
    //cout << (char)getchar()<< endl;return 0;
    for(int i = 0;i<n;++i)
    {
        memset(mmap,' ',sizeof(char)*maxn*maxn);
            int count = 0,cl= 0;
        while(true)
        {
            cc = getchar();
            //cout << cc <<endl;
            if(cc == '#') {getchar();break;}
            else mmap[cl][count++] = cc;
            while((cc=getchar()) != '\n')
            {
                mmap[cl][count++] = cc;
            }
            count = 0;++cl;
        }
        count = -1;
        while(++count < maxn && mmap[0][count] == ' ');
        //cout << count << endl;
//        return 0;
        //cout << (char)mmap[0][count] << endl;
        if(count < maxn)
           cout << '(' << dfs(0,count) << ')' << endl;
        else cout << "()" << endl;
    }
    return 0;
}
