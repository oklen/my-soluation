#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
char space[10][9];

bool verify(int x,int y)
{
    if(x>=0 && x<=8 && y>=0 && y <=9)
        return true;
    return false;
}

void dealH(int x,int y)
{
  for(int i = -2;i<=2;i++)
  {
      if(i ==0) continue;
      for(int j = -1;j <=1;j+=2)
      {
          if(verify(i+x,y+(i*i==1?2*j:j)) && !(space[y+(i*i==1?2*j:j)/2][x+i/2] & 2)
                  && !(space[y+(i*i==1?2*j:j)][x+i]&1))
          {
              space[y+(i*i==1?2*j:j)][x+i]+= 1;
          }
      }
  }
}

void dealC(int x,int y)
{
    bool of = false;
    for(int i = x-1;i>=0;i--)
    {
        if(space[y][i] & 2)
        {
            of = !of;
            if(of == false) {
                if(!(space[y][i] & 1))
                    space[y][i]+=1;
                break;
            }
        }
        if(of && !(space[y][i] & 1))
            space[y][i]+= 1;
    }
    of = false;
    for(int i = x+1;i<=8;i++)
    {
        if(space[y][i] & 2)
        {
            of = !of;
            if(of == false) {
                if(!(space[y][i] & 1))
                    space[y][i]+=1;
                break;
            }
        }
        if(of && !(space[y][i] & 1))
            space[y][i]+= 1;
    }
    of = false;
    for(int i =  y-1;i>=0;i--)
    {
        if(space[i][x] & 2)
        {
            of = !of;
            if(of == false) {
                if(!(space[i][x] & 1))
                    space[i][x]+= 1;
                break;
            }
        }
        if(of && !(space[i][x] & 1))
            space[i][x]+= 1;
    }
    of = false;
    for(int i = y+1;i<=9;i++)
    {
        if(space[i][x] & 2)
        {
            of = !of;
            if(of == false) {
                if(!(space[i][x] & 1))
                    space[i][x]+= 1;
                break;
            }
        }
        if(of && !(space[i][x] & 1))
            space[i][x]+= 1;
    }
}

void dealG(int x,int y)
{
  for(int i = y-1;i>=0;i--)
  {
      if(!(space[i][x]&1))
          space[i][x]+=1;
      if((space[i][x] & 2))
          break;
  }
}

void dealR(int x,int y)
{
    for(int i = x-1;i>=0;i--)
    {
        if(!(space[y][i] & 2))
        {
            if(!(space[y][i]&1))
            space[y][i]+= 1;
        }
        else
        {
            if(!(space[y][i]&1))
                space[y][i]+= 1;
            break;
        }
    }
    for(int i = x+1;i<=8;i++)
    {
        if(!(space[y][i] & 2))
        {
            if(!(space[y][i]&1))
            space[y][i]+= 1;
        }
        else
        {
            if(!(space[y][i]&1))
                space[y][i]+= 1;
            break;
        }
    }
    for(int i = y-1;i>=0;i--)
    {
        if(!(space[i][x] & 1))
            space[i][x]+=1;
        if((space[i][x] & 2))
            break;
    }

    for(int i = y+1;i<=9;i++)
    {

        if(!(space[i][x] & 1))
        space[i][x]+=1;
        if((space[i][x] & 2))
        break;
    }
}

int main()
{
    int num,x,y;
    char who[7];
    int mx[7],my[7];
    while(true)
    {
      for(int i =0 ;i <10;i++)
        memset(space[i], 0, sizeof(char)*9);

        cin >> num >> y >> x;
        --x;--y;
        if(num == 0) break;
        for(int i =0 ;i<num;i++)
        {
            cin >> who[i] >> my[i] >> mx[i];
            --my[i];--mx[i];
        }

        for(int i =0 ;i <10;i++)
          memset(space[i], 0, sizeof(char)*9);
        for(int i =0 ;i<num;i++)
        {
            if(!(space[my[i]][mx[i]]&2))
            space[my[i]][mx[i]] = 2;
            switch (who[i]) {
            case 'R':dealR(mx[i],my[i]);
                break;
            case 'H':dealH(mx[i],my[i]);
                break;
            case 'C':dealC(mx[i],my[i]);
                break;
            case 'G':dealG(mx[i],my[i]);
                break;
            }
        }

//        for(int i = 0;i<10;i++)
//        {
//            for(int j = 0;j<9;j++)
//            {
//                cout << (int)space[i][j];
//            }
//            cout << endl;
//        }
        //return 0;

        int i;
        for(i = -1;i <2;i++)
        {
            if(i==0)
            {
                for(int j = -1;j<2;j++)
                {

                        for(int i =0 ;i <10;i++)
                            memset(space[i], 0, sizeof(char)*9);
                        for(int i =0 ;i<num;i++)
                        {
                        if(!(space[my[i]][mx[i]]&2))
                          space[my[i]][mx[i]]+= 2;
                        }

                    if (space[min(max(y+j,0),2)][x]&2)
                    {
                        space[min(max(y+j,0),2)][x]=0;
//                        for(int i =0;i<num;i++)
//                        {
//                            if(min(max(y+j,0),2) == my[i] && x == mx[i])
//                            {

//                            }
//                        }
                    }
                 for(int i =0 ;i<num;i++)
                 {
                     switch (who[i]) {
                     case 'R':dealR(mx[i],my[i]);
                         break;
                     case 'H':dealH(mx[i],my[i]);
                         break;
                     case 'C':dealC(mx[i],my[i]);
                         break;
                     case 'G':dealG(mx[i],my[i]);
                         break;
                     }
                 }

                    if(!(space[min(max(y+j,0),2)][x]&1))
                    {
                        cout << "NO" << endl;
                        i = 5;
                        j = 2;
                    }
                }
                continue;
            }
            for(int i =0 ;i <10;i++)
               memset(space[i], 0, sizeof(char)*9);
            for(int i =0 ;i<num;i++)
            {
                if(!(space[my[i]][mx[i]]&2))
                space[my[i]][mx[i]] = 2;
            }
            if (space[y][min(max(x+i,3),5)]&2)
                space[y][min(max(x+i,3),5)] = 0;
            for(int i =0 ;i<num;i++)
            switch (who[i]) {
            case 'R':dealR(mx[i],my[i]);
                break;
            case 'H':dealH(mx[i],my[i]);
                break;
            case 'C':dealC(mx[i],my[i]);
                break;
            case 'G':dealG(mx[i],my[i]);
                break;
            }
            if(!(space[y][min(max(x+i,3),5)]&1))
            {
                cout << "NO" << endl;
                i = 5;
            }
        }
        if(i != 6)
          cout << "YES" << endl;
        //getchar();
    }
    return 0;
}
