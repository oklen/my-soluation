#include <iostream>

using namespace std;
int n,l,gc,le;
bool ok;
char arr[1024];

bool check(int now)
{
    int checksize = 1;
    bool checked = false;
    while(checksize)
    {
        if((now+1)/checksize<2) return true;
        for(int i = 1;i<=checksize;++i)
        {
            if(arr[now-2*checksize+i]!=arr[now-checksize+i])
            {checked = true;break;}
        }
        if(!checked) return false;
        checked = false;
        ++checksize;
    }
}
void cons(int now)
{
    if(gc == n) ok = true;
    if(now > le)le = now;
    for(int i = 0;i<l&&!ok;++i)
    {
        arr[now] = 65+i;
        if(check(now))
        {
            ++gc;
            cons(now+1);
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n,&l))
    {
        if(n == 0&&l==0)break;
        gc = 0,le =0,ok = false;
        cons(0);
        for(int i = 0;i<le;++i)
        {
            if(i/64>0&&i%64==0)
                cout << endl;
            else if(!(i%4)&&i!=0&&((i%64)%63))
                cout << " ";
            cout << arr[i];
        }
        cout <<endl<< le << endl;

    }
   return 0;
}
