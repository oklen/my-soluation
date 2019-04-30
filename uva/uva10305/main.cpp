#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;
struct node{
int pres[100];
int key;
int pot;
};

node nodes[100];
int n,m,pre,nex;
int arrs[100];

int main()
{

    for(int i = 0;i<100;++i)
    {
        nodes[i].key = i+1;
        nodes[i].pot = -1;
    }
    while(true)
    {
        set<int> haveouter;
    cin >> n >> m;
    if(n==0&&m==0)break;
    for(int i = 0;i<m;i++)
    {
        cin >> pre >> nex;
        --nex;--pre;
        nodes[nex].pres[++(nodes[nex].pot)] = pre;
    }
    int num = 0;
    while(haveouter.size() < n)
    {
        while(haveouter.count(num)!=0)(++num)%=n;
        while(nodes[num].pot != -1) if(haveouter.count(nodes[num].pres[nodes[num].pot])!=0)
            --nodes[num].pot; else num = nodes[num].pres[nodes[num].pot];
        if(nodes[num].pot==-1){haveouter.insert(num);cout << (num+1) << " ";}
    }
    cout << endl;
    }
}
