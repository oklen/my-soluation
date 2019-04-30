//#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <vector>

//using namespace std;
//int n,k;
//char omp[20][20];
//char vmp[20][20];
////vector<pair<int,int>> cons[365];
//bool filldone = false;

//bool check(int x)
//{
//    for(int i = 0;i<n;++i)
//    {
//        if(x>0&&!vmp[x-1][i]&&vmp[x][i])return false;
//        if(vmp[x][i]==0)
//        {

//            int beg = i,end=i+1;
//            while(vmp[x][end]==0&&end<n)++end;
//            for(int it = beg;it<=end&&it<n;++it)
//            {
//                for(int j =x;j<n;++j)
//                {
//                    if(omp[j][it]!='.'){
//                        cout <<"cal:"<<(int)omp[j][it]<<" "<<j-x+1<<endl;
//                        if(it==beg)
//                        {beg+=omp[j][it]/(j-x+1);
//                            cout << "beg:"<<beg <<" it:"<<it<<" end:"<<end<<endl;break;}
//                        else if(omp[j][it]/(j-x+1)>it-beg){beg+=omp[j][it]/(j-x+1);
//                        it = beg-1;
//                        cout << "beg:"<<beg <<" it:"<<it<<" end:"<<end<<endl;break;}

//                        if(beg>=end)
//                        break;
//                    }
//                }
//                if(beg>=end){i=beg;break;}
//            }
//            if(beg<end)return false;
//        }
//    }
//    cout << "return true" <<endl;
//    return true;
//}

//void fill(int x,int y)
//{
//    if(x>=n){
//        filldone = true;return;
//    }
//    for(int i = 0;i<n;++i)
//    {
//        for(int j = 0;j<n;++j)
//            cout << (vmp[i][j]?vmp[i][j]:'*');
//        cout << endl;
//    } cout << endl;
//    for(;y<n;++y)
//    {
//        if(omp[x][y]!='.')
//        {
////            if(vmp[x][y]=='L')exit(0);
//            int l =y;while(l-1>=0&&!vmp[x][l-1]&&y-l<omp[x][y])--l;
//            int r =y;while(r+1<n&&!vmp[x][r+1]&&r-y<omp[x][y])++r;
//            char used = vmp[x][y];

//            for(;l<=y;++l)
//            {
//                for(int h = max(0,x-omp[x][y]+1);h<=x;++h)
//                {
////                    if(omp[x][y]/(x-h+1)<y-l+1||omp[x][y]%(x-h+1)||(vmp[h][l]&&(h!=x||l!=y)))
////                        continue;

//                    if(vmp[h][l]&&(h!=x||l!=y))continue;

//                    for(int dh = x-h;h+dh<n&&dh<omp[x][y];++dh)
//                    {
//                        if(omp[x][y]/(dh+1)+l-1>r||omp[x][y]/(dh+1)+l-1<y)continue;
//                        if(omp[x][y]%(dh+1)==0)
//                        {
//                            bool cap = true;
//                            cout << used << " x:"<<x<<" y:"<<y<<" h:"<<h<<" l:"<<l<<
//                                    " dh:"<<dh<< " omp:"<<static_cast<int>(omp[x][y])<<endl;
//                            vmp[x][y]=0;
//                            for(int i = 0;i<n;++i)
//                            {
//                                for(int j = 0;j<n;++j)
//                                    cout << (vmp[i][j]?vmp[i][j]:'*');
//                                cout << endl;
//                            } cout << endl;
//                            for(int i=0;i<=dh&&cap;++i)
//                                for(int j = omp[x][y]/(dh+1)-1;j>=0;--j)
//                                {
//                                    if(vmp[h+i][l+j]){cap=false;break;}
//                                }
//                            vmp[x][y]=used;
//                            if(cap)
//                            {
//                                for(int i=0;i<=dh&&cap;++i)
//                                    for(int j = omp[x][y]/(dh+1)-1;j>=0;--j)
//                                    {
//                                        vmp[h+i][l+j]=used;
//                                    }
//                                cout << "do filled!" <<endl;
//                                for(int i = 0;i<n;++i)
//                                {
//                                    for(int j = 0;j<n;++j)
//                                        cout << (vmp[i][j]?vmp[i][j]:'*');
//                                    cout << endl;

//                                } cout << endl;
//                                fill(x,y+1);
//                                if(filldone)return;
//                                for(int i=0;i<=dh&&cap;++i)
//                                    for(int j = omp[x][y]/(dh+1)-1;j>=0;--j)
//                                    {
//                                        vmp[h+i][l+j]=0;
//                                    }
//                                vmp[x][y] = used;
//                                for(int i = 0;i<n;++i)
//                                {
//                                    for(int j = 0;j<n;++j)
//                                        cout << (vmp[i][j]?vmp[i][j]:'*');
//                                    cout << endl;
//                                } cout << endl;

//                                //exit(0);
//                            }
//                        }
//                    }
//                }
//            }
//            return;
//        }
//    }
//    if(!check(x))return;
//    fill(x+1,0);
//}

//int main()
//{

////    for(int i  = 1;i<365;++i)
////    {
////        for(int w = i;w>=1;--w)
////        {
////            if(w%i==0)cons[i].push_back({w,i/w});
////        }
////    }
////    return 0;
//    while(scanf("%d%d",&n,&k)&&n&&k)
//    {
//        int nc = 0;memset(omp,0,sizeof(omp));memset(vmp,0,sizeof(vmp));
//        char now = getchar();while(now!='\n')now=getchar();
//        filldone = false;
//        for(int i = 0;i<n;++i)
//        {
//            for(int j = 0;j<n;++j)
//            {
//                scanf("%c",&omp[i][j]);
//                if(omp[i][j]!='.'){omp[i][j]-='0';vmp[i][j]='A'+nc++;}
//            }
//            now = getchar();while(now!='\n')now=getchar();
//        }
//        fill(0,0);
//        for(int i = 0;i<n;++i)
//        {
//            for(int j = 0;j<n;++j)
//                cout << vmp[i][j];
//            cout << endl;
//        }
//    }
//    return 0;
//}
