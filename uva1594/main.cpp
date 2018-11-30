#include <iostream>
#include <cmath>
using namespace std;

int in[15];
int in2[15];
int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        cin >>n;
        for(int i =0;i <n;i++)
            cin >> in[i];
        for(int i = 0;i<500;i++)
        {
            for(int j = 0;j<n;j++)
              in2[j] = abs(in[j] - in[(j+1)%n]);
            for(int j = 0;j<n;j++)
              in[j] = abs(in2[j] - in2[(j+1)%n]);
        }

        int i;
        for( i = 0;i<n;i++)
        {
            if(in[i]!=0)
            {

                printf("LOOP\n");
                i = 20;
            }
        }
        if(i!=21)
                printf("ZERO\n");
    }
    return 0;
}
