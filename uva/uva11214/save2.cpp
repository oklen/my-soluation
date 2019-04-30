//#include <iostream>
//#include <cstring>
//#include <vector>

//using namespace std;
//char bd[10][10],bc[10][10];
//int m,n,cnt,maxd,bccnt;
//bool fin;

//void inline fill(int ii,int jj)
//{
//    for(int i = 0;i<n;++i)
//        if(bd[ii][i]>=1) {if(bd[ii][i]==1)--cnt;
//                           ++bd[ii][i];}
//    for(int i =0;i<m;++i)
//        if(i!=ii&&bd[i][jj]>=1) {if(bd[i][jj]==1)--cnt;
//                          ++bd[i][jj];}
//    for(int i = -min(jj,m-ii);ii-i>=0&&jj+i<n;++i)
//        if(i!=0&&bd[ii-i][jj+i]>=1) {if(bd[ii-i][jj+i]==1)--cnt;
//                             ++bd[ii-i][jj+i];}
//    for(int i = -min(jj,ii);ii+i<m&&jj+i<n;++i)
//        if(i!=0&&bd[ii+i][jj+i]>=1) {if(bd[ii+i][jj+i]==1)--cnt;
//                               ++bd[ii+i][jj+i];}
////    if(bd[ii][jj]>=1)
////       bd[ii][jj]-=3;
//}

//void inline revs(int ii,int jj)
//{
//    for(int i = 0;i<n;++i)
//        if(bd[ii][i]>=2) {--bd[ii][i];
//                          if(bd[ii][i]==1)++cnt;}
//    for(int i =0;i<m;++i)
//        if(i!=ii&&bd[i][jj]>=2) {--bd[i][jj];
//                          if(bd[i][jj]==1)++cnt;}
//    for(int i = -min(jj,m-ii);ii-i>=0&&jj+i<n;++i)
//        if(i!=0&&bd[ii-i][jj+i]>=2) {--bd[ii-i][jj+i];
//                                if(bd[ii-i][jj+i]==1)++cnt;}
//    for(int i = -min(jj,ii);ii+i<m&&jj+i<n;++i)
//        if(i!=0&&bd[ii+i][jj+i]>=2) {--bd[ii+i][jj+i];
//                              if(bd[ii+i][jj+i]==1)++cnt;}
////    if(bd[ii][jj]>=2)
////      bd[ii][jj]+=3;
//}


//void show()
//{
////    cout << "split----"<<endl;
//    for(int i = 0;i<m;++i)
//    {
//        for(int j = 0;j<n;++j)
//            cout << (int)bd[i][j];
//        cout <<endl;
//    }
//}

//void solve(int dep,int ii)
//{
//    if(dep==0)return;
//    int ccnt = cnt,maxd = 0,bi;
//    for(int i = ii;i<m;++i)
//    {
//        for(int j = 0;j<n;++j)
//        {
//            fill(i,j);
//            if(cnt == 0){fin=true;return;}
//            if(ccnt - cnt >maxd)
//            {
//                maxd=  ccnt -cnt;
//                bi = j;
//            }
//            revs(i,j);
//        }
//        if(maxd == 0) continue;
//        fill(i,bi);
//        if(cnt == 0){fin=true;return;}
////        show();
//        solve(dep-1,ii);
//        revs(i,bi);
//        maxd = 0;
//    }
//}

//int main()
//{
////    freopen("/media/root/Dstore/LENOVO/Qt_Project/build-uva11214-Desktop_Qt_5_11_1_GCC_64bit-Debug/input",
////            "r",stdin);
//    int glc = 1;
//    while(scanf("%d",&m)&&m&&scanf("%d",&n))
//    {
//        for(int i = 0;i<m;++i)
//            scanf("%s",bd[i]);
//        cnt=0;
//        for(int i = 0;i<m;++i)
//            for(int j =0;j<n;++j)
//                if(bd[i][j]=='X') {
//                    bd[i][j] = 1;++cnt;
//                }
//            else bd[i][j]=0;fin=false;
//        memcpy(bc,bd,sizeof(char)*10*10);bccnt = cnt;

//        for(maxd=1;;++maxd)
//        {
//            solve(maxd,0);
////            cout << "maxd:"<<maxd << endl;
//            cnt = bccnt;memcpy(bd,bc,sizeof(char)*10*10);
//            if(fin) break;
//        }
//        memset(bd,0,sizeof(char)*10*10);
//        printf("Case %d: %d\n",glc++,maxd);
//    }
//    return 0;
//}
