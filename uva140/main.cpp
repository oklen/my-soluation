#include <iostream>
#include <bits/stdc++.h>

using namespace std;
char mmp[26][26];int mid,length;
int arc[26];char answer[10];
bool ok;
void solve(int cur)
{
    bool isok;
//    for(int i = 0;i<cur;++i)
//        cout << (char)(answer[i] + 'A') << " ";
//    cout  <<endl;
    for(int i = 0,j;i < 26&&!ok;++i)
    {
        if(arc[i])
        {
            isok = true;
            for(j =0 ;j<26;++j)
            {
                if(mmp[i][j]==1)
                {
                    for(int k = 0;k<cur;++k)
                        if(answer[k]==j)
                            if(cur - k>mid)
                            {isok=false;break;}
                }
            }
            if(isok)
            {
                answer[cur] = i;
                if(cur == length-1) {ok=true;return;}
                arc[i] = 0;
                solve(cur+1);
                arc[i] = 1;
            }
        }
    }
}
int main()
{
    char parent,child;
    while(true)
    {
        parent = getchar();
        if(parent == '#') break;
        else if(parent == ' ') continue;
        getchar();
        arc[parent-'A']=1;
        while(true)
        {
            child = getchar();
            if(child == ';')
                break;
            else if(child == '\n')
            {
               int wmax=8,wmin = 1;
               for(int i = 0;i<26;++i)
                   if(arc[i])
                   {++length;}
               char saveda[10];int savedlength;
               while(wmin<wmax)
               {
                   mid = (wmax+wmin)/2;
                   solve(0);
                   if(ok)
                   {
                       wmax = mid;savedlength = mid;
                       for(int i = 0;i<length;++i)
                           saveda[i]  = answer[i];
                   }
                   else
                      wmin = mid+1;
                   ok = false;
               }
               for(int i = 0;i<length;++i)
                   cout << (char)('A'+saveda[i]) << " ";
               cout << "-> " << savedlength << endl;
               memset(mmp,0,sizeof(char)*26*26);length=0;
               memset(arc,0,sizeof(int)*26);
               break;}
            else if(child == ' ') continue;
//            cout << parent << " " <<child <<endl;
            mmp[parent - 'A'][child - 'A'] = 1;
            mmp[child - 'A'][parent - 'A'] = 1;
            arc[child-'A']=1;
        }
    }
    return 0;
}
