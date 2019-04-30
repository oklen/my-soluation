#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<long long,int> result;
char cc[20];
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        long long dep = 0;long long nown;char ca;
        //cout << "case:" << n << endl;
        while(*cc = getchar())
        {
            if(*cc == '[') ++dep;
            else if (*cc == ']')--dep;
            else if (*cc == '\n')break;
            else if (*cc == ',')continue;
            else {
                int i = 0;
                while(*(cc+i)>=48&&*(cc+i)<=57)
                    *(cc + ++i) = getchar();
                ca = *(cc+i);
                *(cc + i) = '\0';
                 ++result[atoll(cc)<<dep];
//                cout << "getnumber:" << atoi(cc) << endl;
                if(ca == ']')--dep;
                else if(ca == '\n')break;
            }
        }
        unsigned long cou = 0,max = 0;
        for(auto bb = result.begin();bb!=result.end();++bb)
        {
            cou+=bb->second;
            if(bb->second>max)
                max = bb->second;
        }
        cout << cou -max <<endl;
        result.clear();
    }
    return 0;
}
