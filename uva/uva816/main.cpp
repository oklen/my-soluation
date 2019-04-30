#include <iostream>
#include <list>
#include <cstring>
#include <stdio.h>

using namespace std;
enum MoveD{n,f,l,r,fl,fr,lr,flr};

string name;
pair<int,int> start;
pair<int,int> eend;

struct path{
    path* back;
    path* forward;
    pair<int,int> pos;
    int dep = 0;
    path(pair<int,int> pos):pos{pos}{}
};

struct node{
    MoveD left;
    MoveD right;
    MoveD up;
    MoveD down;
  node():left{n},right{n},up{n},down{n}{}
};

struct pos{
    pos(int y,int x,char nd):y{y},x{x},nd{nd}{}
    pos(int y,int x,char nd,path* oldpath,path* newpath):y{y},x{x},nd{nd}{
        newpath->back = oldpath;
        if(oldpath!=nullptr)
        oldpath->forward = newpath;
        pp = newpath;
    }
    int y,x;
    char nd;
    path* pp = nullptr;
};
list<pos> ma;
char desc[10];
node nodes[11][11];

void process(int x,int y,char dir,path* mp)
{
//  cout << y << " " << x << " " << dir << endl;
//    cout << "left:" << nodes[y][x].left << endl;
//    cout << "right:" << nodes[y][x].right << endl;
//    cout << "up:" << nodes[y][x].up << endl;
//    cout << "down:" << nodes[y][x].down << endl;
    switch (dir) {
    case 'S': switch(nodes[y][x].up)
        {
          case l:ma.push_back(pos(y,x+1,'W',mp,new path({x,y})));break;
          case r:ma.push_back(pos(y,x-1,'E',mp,new path({x,y})));break;
          case  f:ma.push_back(pos(y+1,x,'S',mp,new path({x,y})));break;
          case lr:ma.push_back(pos(y,x-1,'E',mp,new path({x,y})));ma.push_back(pos(y,x+1,'W',mp,new path({x,y})));break;
          case fl:ma.push_back(pos(y+1,x,'S',mp,new path({x,y})));ma.push_back(pos(y,x+1,'W',mp,new path({x,y})));break;
          case fr:ma.push_back(pos(y+1,x,'S',mp,new path({x,y})));ma.push_back(pos(y,x-1,'E',mp,new path({x,y})));break;
          case flr:ma.push_back(pos(y+1,x,'S',mp,new path({x,y})));ma.push_back(pos(y,x+1,'W',mp,new path({x,y})));ma.push_back(pos(y,x-1,'E',mp,new path({x,y})));break;
        }
        break;
    case 'N': switch(nodes[y][x].down)
        {
        case l:ma.push_back(pos(y,x-1,'E',mp,new path({x,y})));break;
        case r:ma.push_back(pos(y,x+1,'W',mp,new path({x,y})));break;
        case  f:ma.push_back(pos(y-1,x,'N',mp,new path({x,y})));break;
        case lr:ma.push_back(pos(y,x-1,'E',mp,new path({x,y})));ma.push_back(pos(y,x+1,'W',mp,new path({x,y})));break;
        case fl:ma.push_back(pos(y-1,x,'N',mp,new path({x,y})));ma.push_back(pos(y,x-1,'E',mp,new path({x,y})));break;
        case fr:ma.push_back(pos(y-1,x,'N',mp,new path({x,y})));ma.push_back(pos(y,x+1,'W',mp,new path({x,y})));break;
        case flr:ma.push_back(pos(y,x-1,'E',mp,new path({x,y})));ma.push_back(pos(y-1,x,'N',mp,new path({x,y})));ma.push_back(pos(y,x+1,'W',mp,new path({x,y})));break;
        }
        break;
    case 'E':switch (nodes[y][x].right) {
        case l:ma.push_back(pos(y+1,x,'S',mp,new path({x,y})));break;
        case r:ma.push_back(pos(y-1,x,'N',mp,new path({x,y})));break;
        case  f:ma.push_back(pos(y,x-1,'E',mp,new path({x,y})));break;
        case lr:ma.push_back(pos(y-1,x,'N',mp,new path({x,y})));ma.push_back(pos(y+1,x,'S',mp,new path({x,y})));break;
        case fl:ma.push_back(pos(y+1,x,'S',mp,new path({x,y})));ma.push_back(pos(y,x-1,'E',mp,new path({x,y})));break;
        case fr:ma.push_back(pos(y,x-1,'E',mp,new path({x,y})));ma.push_back(pos(y-1,x,'N',mp,new path({x,y})));break;
        case flr:ma.push_back(pos(y+1,x,'S',mp,new path({x,y})));ma.push_back(pos(y,x-1,'E',mp,new path({x,y})));ma.push_back(pos(y-1,x,'N',mp,new path({x,y})));break;
}
        break;
    case 'W':switch (nodes[y][x].left) {
        case r:ma.push_back(pos(y+1,x,'S',mp,new path({x,y})));break;
        case l:ma.push_back(pos(y-1,x,'N',mp,new path({x,y})));break;
        case  f:ma.push_back(pos(y,x+1,'W',mp,new path({x,y})));break;
        case lr:ma.push_back(pos(y+1,x,'S',mp,new path({x,y})));ma.push_back(pos(y-1,x,'N',mp,new path({x,y})));break;
        case fr:ma.push_back(pos(y+1,x,'S',mp,new path({x,y})));ma.push_back(pos(y,x+1,'W',mp,new path({x,y})));break;
        case fl:ma.push_back(pos(y-1,x,'N',mp,new path({x,y})));ma.push_back(pos(y,x+1,'W',mp,new path({x,y})));break;
        case flr:ma.push_back(pos(y+1,x,'S',mp,new path({x,y})));ma.push_back(pos(y-1,x,'N',mp,new path({x,y})));ma.push_back(pos(y,x+1,'W',mp,new path({x,y})));break;
        }
    }
    switch (dir) {
    case 'S': nodes[y][x].up = n;break;
    case 'N': nodes[y][x].down = n;break;
    case 'E':nodes[y][x].right = n;break;
    case 'W':nodes[y][x].left = n;break;
    }
};
MoveD getmov(char* now)
{
    int len = 0;

    while(*(now+(++len))!=0);

    if(len == 1)
    {
        switch (*now) {
        case 'L':return l;
        case 'R':return r;
        case 'F':return f;
        }
    }
    else if(len == 2)
    {
        if(strcmp(now,"LR")==0 || strcmp(now,"RL") ==0)return lr;
        else if(strcmp(now,"LF")==0 || strcmp(now,"FL") == 0)return fl;
        else return fr;
    }
    else return flr;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("/media/root/Dstore/LENOVO/Qt_Project/build-uva816-Desktop_Qt_5_11_1_GCC_64bit-Debug/input","r",stdin);
#endif
    freopen("/media/root/Dstore/LENOVO/Qt_Project/build-uva816-Desktop_Qt_5_11_1_GCC_64bit-Debug/output","w+",stdout);
    while(true)
    {
        cin >> name;
        //getline(cin,name);
        if(name == "END") break;
        int row,column;
        scanf("%d %d",&row,&column);
        getchar();
//        cout << (char)getchar() <<endl; return 0;
                int ccdn = getchar();
//        cout << row << " " << column << " " << (char)ccdn << endl;;
        switch (ccdn) {
        case 'N':ma.push_back(pos(row-1,column,'N',nullptr,new path({column,row})));break;
        case 'E':ma.push_back(pos(row,column+1,'W',nullptr,new path({column,row})));;break;
        case 'S':ma.push_back(pos(row+1,column,'S',nullptr,new path({column,row})));;break;
        case 'W':ma.push_back(pos(row,column-1,'E',nullptr,new path({column,row})));;break;
        }
//        process(ma.front().x,ma.front().y,ma.front().nd,ma.front().pp);
//        if(ma.size() > 0)
//        ma.pop_front();
        scanf("%d %d\n",&row,&column);

        eend = {column,row};
        while(true)
        {
            scanf("%d %d",&row,&column);
            if(row == 0)break;
            while(true)
            {
                memset(desc,0,sizeof(char)*10);
                scanf("%s",desc);
                if(strcmp(desc,"*")==0)break;
                switch (*desc) {
                case 'N':nodes[row][column].down = getmov(desc+1);break;
                case 'E':nodes[row][column].left = getmov(desc+1);break;
                case 'S':nodes[row][column].up = getmov(desc    +1);break;
                case 'W':nodes[row][column].right = getmov(desc+1);break;

                }
            }
        }
        bool finded = false;
        bool begg = false;

        while(true){
                if(ma.size() == 0) break;
                if(ma.front().x == eend.first && ma.front().y == eend.second)
                {
                    cout << name << endl << "  ";
                    path* np = ma.front().pp;
                    int count = 0;
                    list<pair<int,int>> li;
                    while(np!=nullptr)
                    {
                        li.push_back(np->pos);
                        np= np->back;
                    }
                    for(auto lii = li.rbegin();lii!= li.rend();lii++)
                    {
                        printf("(%d,%d)",lii->second,lii->first);
                        if(++count==10)
                        {cout << endl << "  ";count=0;}
                        else printf(" ");
                    }
                    printf("(%d,%d)\n",eend.second,eend.first);
                    finded = true;
                    break;
                }
                begg=true;
                process(ma.front().x,ma.front().y,ma.front().nd,ma.front().pp);
                ma.pop_front();
        }
            if(!finded)
            {cout << name << endl <<  "  " << "No Solution Possible" <<endl;}
            ma.clear();
            for(int i = 0;i<10;i++)
            {
                for(int j = 0;j<10;j++)
                {
                    nodes[i][j].down = n;
                    nodes[i][j].left = n;
                    nodes[i][j].right = n;
                    nodes[i][j].up = n;
                }
            }
    }
    return 0;
}
