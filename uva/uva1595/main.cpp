#include <iostream>
#include <set>
using namespace std;

struct node
{
    int x, y;
    node(int x,int y):x{x},y{y}{}
    bool operator<(node n) const
    {return n.x==x?n.y>y:n.x>x;}
};

int main()
{
    set<node> sn;
    int t,n,a,b;
    cin >> t;
    while(t--)
    {
        sn.clear();
        cin >> n;
        for(int i = 0;i<n;i++)
        {
            cin >> a >> b;
            sn.insert(node(a,b));
        }
        double mid;
        auto bb = sn.begin();
        auto ee = sn.rbegin();
        int count = sn.size()/2;
        mid = (1.0*(*bb).x+ee->x)/2;
        bool yes = true;
//        cout << sn.size() << endl;
//        auto ss = sn.begin();
//        cout << "MID:" << mid << endl;
//        while(ss!=sn.end())
//        {cout << ss->x << " " << ss->y << endl;ss++;}
        if(sn.size()%2==0)
        {
            for(int i= 0;i<count&&yes;i++)
            {
//                cout << bb->x << " " << bb->y << endl;
//                cout << ee->x << " " << ee->y << endl;
                if((bb->x+ee->x)*1.0/2 != mid)
                {yes = false;break;}
                else if(bb->y != ee->y)
                {
                    yes = false;
                    auto finc= ee;
                    while(ee->x==(++finc)->x)
                        if(finc->y == bb->y)
                        {
                            yes = true;
                            break;
                        }
                        else if(finc==sn.rend())
                            break;
                    auto finc2 = ee;
                    while(ee->x==(--finc2)->x)
                    {
                        if(finc2->y == bb->y)
                        {
                            yes = true;
                            break;
                        }
                        else if(finc2==sn.rbegin())
                            break;
                    }
                }
                bb++;ee++;
            }
        }
        else
        {
            for(int i= 0;i<count;i++)
            {
//                cout << bb->x << " " << bb->y << endl;
//                cout << ee->x << " " << ee->y << endl;
                if((bb->x+ee->x)*1.0/2 != mid)
                {yes = false;break;}
                else if(bb->y != ee->y)
                {
                    yes = false;
                    auto finc= ee;
                    while(ee->x==(++finc)->x)
                        if(finc->y == bb->y)
                        {
                            yes = true;
                            break;
                        }
                        else if(finc==sn.rend())
                            break;
                    auto finc2 = ee;
                    while(ee->x==(--finc2)->x)
                        if(finc2->y == bb->y)
                        {
                            yes = true;
                            break;
                        }
                        else if(finc2==sn.rbegin())
                            break;
                }
                bb++;ee++;
            }
            if((bb)->x != mid) yes =false;
        }
        if(yes)
            cout << "YES" <<endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
