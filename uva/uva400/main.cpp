#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int num,maxl = 0;
    vector<string> mv;
    string cache;
    while(true)
    {
        cin >> num;
        mv.clear();
        maxl = 0;
        if(num == EOF || (char)num == EOF || cin.eof()) break;

        for(int i = num;i>0;i--)
        {
            //memset(cache,0,60*sizeof(60));
            cin >> cache;
            //cout << "Get:" << cache << endl;
            if(cache.length() > maxl)
                maxl = cache.length();
            mv.push_back(cache);
        }

        sort(mv.begin(),mv.end());
        int coln = (60-maxl)/(maxl+2)+1;
        int count = 1,outlength = mv.size();
        int h =  ceil((1.0*mv.size())/(coln));
//        cout << (1.0*mv.size()) << " " << (coln) << endl;
        //auto bb = mv.begin();
        int ccc = 60;
        while(ccc-->0)
            putchar('-');
        printf("\n");
//        /cout << "use h:" << h << " " << "use col:" << coln << endl;
        int skip = 0;
        while(outlength+skip >0)
        {
            int nu = mv.size() - outlength--;
            //cout << "nu:" << nu << endl
            int index = max(((nu)/coln) +(nu%(coln))*h,0);
            if(index >= mv.size()) {count = 1;cout << endl;skip++; continue;}
            int rem = maxl -  mv.at(index).length();
               printf("%s",mv.at(index).c_str());
               while(2+rem-- > 0)
                   putchar(' ');
               if(count++ == coln /*|| ((nu - outlength-1)>((num%h)*coln) && outlength%(coln-1)==0)*/) {
                   {
                       count = 1;
                       while(rem-- > 0)
                           putchar(' ');
                       cout << endl;
                   }
               }
        }
        if(count!=1)
            cout << endl;
    }
}
