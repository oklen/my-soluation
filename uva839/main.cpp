#include <iostream>

using namespace std;

int solver()
{int dl,wl,dr,wr;
scanf("%d%d%d%d",&wl,&dl,&wr,&dr);
if(wl == 0)
    wl = solver();
if(wr == 0)
    wr = solver();
  if(wl == -1 || wr == -1 || wl*dl != dr*wr)
      return -1;
  else
      return wl+wr;
}

int main()
{
    int n;
    scanf("%d\n",&n);
    while(n--)
    {
        if(solver() == -1)
            cout << "NO" <<endl;
        else
            cout << "YES" << endl;
        if(n!=0)
        cout << endl;
    }
    return 0;
}
