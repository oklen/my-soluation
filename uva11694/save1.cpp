//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//#define mset(a,b) memset(a,b,sizeof(a))
//#define emp 0
//#define lt 1
//#define rt 2
//const int dx[]{-1,0,0,-1};
//const int dy[]{-1,-1,0,0};
//const int ddx[]{-1,1,1,-1},ddy[]{-1,-1,1,1};
//const int wd[]{rt,lt,rt,lt};
//const int rd[]{lt,rt,lt,rt};

//char st[8][8];
//char num[9][9];
//bool vis[9][9];
//bool vals[9][9];
//int n,fcs;

//void show()
//{
//    for(int i =0;i<n;++i,cout<<endl)
//        for(int j= 0;j<n;++j)
//        {
//            if(st[i][j])cout<<(int)st[i][j];
//            else cout << '*';
//        }
//}

//void dfs()
//{

//}

//bool dirf()
//{
//    bool changed = false;
//    for(int i = 0;i<=n;++i)
//        for(int j  =0;j<=n;++j)
//            if(num[i][j]!='.'&&!vals[i][j])
//            {

//                if(num[i][j])
//                {
//                    int val = 0;
//                    for(int k = 0;k<4;++k)
//                    {
//                        if(i+dy[k]>=0&&i+dy[k]<n&&j+dx[k]>=0&&j+dx[k]<n
//                                &&(st[i+dy[k]][j+dx[k]]==emp||st[i+dy[k]][j+dx[k]]==rd[k]))
//                            ++val;
//                    }
//                     if(val==num[i][j])
//                    {
//                        for(int k = 0;k<4;++k)
//                        {
//                            if(i+dy[k]>=0&&i+dy[k]<n&&j+dx[k]>=0&&j+dx[k]<n
//                                    &&st[i+dy[k]][j+dx[k]]==0)
//                            {st[i+dy[k]][j+dx[k]] = rd[k];++fcs;}
//                        }
//                        vals[i][j] = 1;
//                        //cout << "val s:"<< i << " " << j <<endl;
//                        changed = true;
//                        //show();
//                    }
//                }
//                else
//                {
//                    for(int k = 0;k<4;++k)
//                    {
//                        if(i+dy[k]>=0&&i+dy[k]<n&&j+dx[k]>=0&&j+dx[k]<n
//                                &&st[i+dy[k]][j+dx[k]]==emp)
//                        {st[i+dy[k]][j+dx[k]] = wd[k];++fcs;}
//                        else if(st[i+dy[k]][j+dx[k]]!=emp)
//                            runtime_error("0 intsection,have none-wd border!");
//                    }
//                    //cout << "0 val s:"<< i << " " << j <<endl;
//                    vals[i][j] = 1;changed = true;
//                    //show();
//                }
//            }
////    cout << fcs << endl;
//    return changed;
//}

//bool visd(int y,int x,int fx,int fy)
//{
//    if(vis[y][x])return false;
//    else vis[y][x] = true;
//    for(int k = 0;k<4;++k)
//    {
//        if(y+dy[k]>=0&&y+dy[k]<n&&x+dx[k]>=0&&x+dx[k]<n
//                &&st[y+dy[k]][x+dx[k]]==rd[k]&&(y+ddy[k]!=fy||x+ddx[k]!=fx))
//            if(!visd(y+ddy[k],x+ddx[k],x,y))return false;
//    }
//    return true;
//}

//void rodf()
//{
//    for(int i = 0;i<n;++i)
//        for(int j =0;j<=n;++j)
//        {
//            for(int k =2;k<4;++k)
//            {
//                if(i+dy[k]>=0&&i+dy[k]<n&&j+dx[k]>=0&&j+dx[k]<n
//                        &&st[i+dy[k]][j+dx[k]]==emp)
//                {
//                    st[i+dy[k]][j+dx[k]] = rt;mset(vis,0);
//                    if(!visd(i,j,-1,-1))st[i+dy[k]][j+dx[k]]=lt;
//                    else{mset(vis,0);
//                        st[i+dy[k]][j+dx[k]] = lt;
//                        if(!visd(i,j,-1,-1)) st[i+dy[k]][j+dx[k]] = rt;
//                        else {
//                            st[i+dy[k]][j+dx[k]] = 0;continue;
//                        }
//                    }
//                    ++fcs;
//                }
//            }
//        }
//}

//int main()
//{
//    int t;scanf("%d",&t);
//    while(t--)
//    {
//        scanf("%d",&n);getchar();
//        mset(st,0);mset(num,0);mset(vals,0);fcs=0;
//        for(int i = 0;i<n+1;++i)
//        {
//            char now[9];cin >> now;
//            for(int j = 0;j<n+1;++j)
//                num[i][j] = now[j]=='.'?'.':(now[j]-'0');
//        }
//        while(fcs!=n*n)
//        {
//            while (dirf());//show();
//            rodf();
//            show();
//        }
//        for(int i =0;i<n;++i,cout<<endl)
//            for(int j =0;j<n;++j)
//                printf("%c",st[i][j]==rt?'/':'\\');
//        //exit(0);
//    }
//    return 0;
//}
