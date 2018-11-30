#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;
vector<string> ssize[1000];
char buf[180];
int maxwl[1000];

int main()
{
    int count = 0;
    char cache;
    int lineNum = 0;
    memset(maxwl,0,sizeof(int)*1000);
    while(!cin.eof())
    {
        cache = getchar();
        if((int)cache == EOF) break;
        while(cache!='\n')
        {
            count = 0;
            while(cache==' ')
                cache = getchar();
            if(cache=='\n') break;
            memset(buf,0,sizeof(char)*180);
            while(cache !=' ' && cache != '\n')
            {
                buf[count++] = cache;
                cache = getchar();
            }
            ssize[lineNum].push_back(buf);
            if(maxwl[ssize[lineNum].size()-1] < ssize[lineNum].back().length()+1)
                maxwl[ssize[lineNum].size()-1] = ssize[lineNum].back().length()+1;
        }
        lineNum++;
    }
    int lins = 0;
    while((ssize+lins)->size()!=0)
    {
        auto bb = (ssize+lins)->begin();
        while(bb != (ssize+lins)->end())
        {
            if(bb+1 != (ssize+lins)->end())
             cout << left << setw(maxwl[bb - (ssize+lins)->begin()]) << *(bb);
            else
             cout << *(bb);
            bb++;
        }
        cout << endl;
        lins++;
    }
    return 0;
}
