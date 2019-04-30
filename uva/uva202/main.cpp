#include <iostream>

using namespace std;

int main()
{
    unsigned long a,b,kep;
    cin >> a >> b;
    a=a%b;
    kep = a;
    unsigned long sum = 0;
    while(a<b)
    {
        a*=10;
        sum++;
    }
    int count = 0;
    while((a%b)!=kep && a%b != 0)
    {
        unsigned long cache = 1;
        cout << a/b;
        while((a/b)/cache > 0)
        {
            sum++;
            cache*=10;
        }
        a=a%b;
        while(a<b)
        {
            a*=10;
            if(count++>0)
            {
                cout << 0;
                sum++;
            }
        }
        count=0;
    }
    if(a%b!=0)
    cout << kep;
    else
    {
        cout << 0;
        sum= 1;
    }
    cout << endl;
    cout<< sum << endl;
    return 0;
}
