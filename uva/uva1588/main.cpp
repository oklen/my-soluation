#include <iostream>
#include <cstring>
using namespace std;
constexpr int intsize = sizeof(int);

int fillstr(char *ar)
{
    int count = 0;
    char cache = getchar();
    if(cache == EOF)
        exit(0);
    while(cache!='\n')
    {
        ar[count++] = cache;
        cache = getchar();
    }
    return count;
}

int fillstrb(char *ar)
{
    int count = 0;
    char cache = getchar();
    if(cache == EOF)
        exit(0);
    while(cache!='\n')
    {
        if(cache=='1')
            ar[count++] = '2';
        else
            ar[count++] = '1';
        cache = getchar();
    }
    return count;
}

int mycmp(char *a,char *b,int le)
{
    int i =0;
    while (i<le) {
        if(*(a+i) == '2' && *(b+i) == '2')
            return  1;
        i++;
    }
    return 0;
}

int main()
{
    char at[100];
    char ag[100];
    char *aa = at;
    char *ab = ag;
    int count = 0,aal,abl;
    memset(aa,0,100*sizeof(char));
    memset(ab,0,100*sizeof(char));
    while(!cin.eof())
    {
        abl = fillstr(ab);
        aal = fillstr(aa);
        if(abl < aal)
        {
            char* cache = ab;
            ab = aa;
            aa = cache;
            int c = abl;
            abl = aal;
            aal = c;
        }
        int shift = 0,comparesize,apos;
        int min = abl+aal;

        while(++shift < aal+abl)
        {
            if(shift<aal)
            {
                comparesize = shift;
                apos = aal - shift;
            }
            else if (shift >abl)
            {
                comparesize = aal - shift + abl;
                apos = 0;
            }
            else
            {
                comparesize = aal;
                apos = 0;
            }
//            cout << shift <<"Compare:"
//                 <<strndup(aa+apos,comparesize) << ":" << strndup(ab+(shift>aal?shift-aal:0),comparesize)
//                 << endl;
            if(mycmp(aa+apos,ab+(shift>aal?shift-aal:0),comparesize) == 0)
            {

                if(shift < aal && min > abl+aal-shift)
                {
                    min = abl+aal-shift;
//                    cout << "1 cae" << endl;
                }
                else if(shift > abl && min > shift)
                {
                    min = shift;
//                    cout << "2 cae" << endl;
                }
                else if(shift <= abl && shift>=aal)
                {
                    min = abl;
//                    cout << "min" << endl;
                }
            }
        }
        cout << min << endl;
    }
}
