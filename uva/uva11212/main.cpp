//#include <iostream>
//#include <queue>
//#include <cstdio>
//#include <cstring>

//using namespace std;
//int n;unsigned int nb;
//queue<unsigned int> sts;
//queue<int> tq;
//int mosttime,maxd;
//int qs[10],calltimecnt;
//bool visited[9*8*7*6*5*4*3*2];

//void movetofront(int* a,int b,int e)
//{
//    int cachespace[10];
////    cout   << b << " " << e << endl;

//    memcpy(cachespace,a+b,sizeof(int)*(e-b));
//    memcpy(a+e-b,a,sizeof(int)*(b));
//    memcpy(a,cachespace,sizeof(int)*(e-b));
//}

//void mtf(int *a,int b,int e,int cf)
//{
//    int c[10];
//    for(int i = 0;i<e-b;++i)
//        c[i] = a[b+i];
//    for(int i = b-cf-1;i>=0;--i)
//        a[e-b+i+cf] = a[i+cf];
//    for(int i = 0;i<e-b;++i)
//        a[cf+i] = c[i];
//}

//unsigned int id(int *a)
//{
//    int c = 1,cc=0;
//    for(int i = 0;i<n;++i)
//    {cc+=a[i]*c;c*=10;}
//    return cc;
//}

//int gr(int* a)
//{
//    int index = 0,cn;
//    for(int i = 0;i<n-1;++i)
//    {
//        cn = 0;
//        for(int j = i+1;j<n;++j)
//            if(a[i]>a[j])++cn;
//        index+=cn*qs[n-i-1];
//    }
//    return index;
//}

//int geth(int *a)
//{
//    int cnt =0;
//    for(int i = 1;i<n;++i)
//        if(a[i]-a[i-1]!=1)
//            ++cnt;
//    return cnt;
//}

//bool  ida(unsigned int in,int time)
//{
//    int a[10],b[10];
//    for(int i = 0;i<n;++i)
//    {a[i] = in%10;in/=10;}
////    int index= gr(a);
////    if(visited[index])return false;else visited[index] = true;
//    int changes = geth(a);
//    ++calltimecnt;
//    if(changes == 0) return true;
//    else if(changes>3*(maxd-time))return false;
////    cout <<  3*(maxd-time) << endl;
//    memcpy(b,a,sizeof(int)*n);
//    int cf = -1;
//    for(int i = 0;i<n;++i)
//        if(a[i]>(i+1)){cf=i;break;}
//    if(cf == -1) return true;
//    for(;cf<n-1;++cf)
//    {
//        for(int j = cf+1;j<n;++j)
//        {

//            int c = j+1;bool canmoveit;
//            if(a[j]<a[cf])
//               canmoveit =true;
//            else
//                canmoveit =false;
//            for(;c<=n;++c){
//                if(a[c-1]<a[cf]) canmoveit = true;
//                if(!canmoveit) continue;
////                j-=cf;c-=cf;
////                cout << "cf: " << cf << endl;

//                mtf(a,j,c,cf);
////                  if(geth(a)==0) return true;
//                  if(ida(id(a),time+1)) return true;
//                memcpy(a,b,sizeof(int)*10);
//                while((c+1)<n&&a[c+1]-a[j] == 1) ++c;
//            }
//        }
//    }
//    return false;
//}
//int main()
//{
//    int cnt = 1;
//    qs[0]=1;
//    for(int i = 1;i<10;++i)
//        qs[i] = qs[i-1]*i;
//    while(scanf("%d",&n)&&n)
//    {
//        unsigned int cache,nc=1;
//        mosttime = -1;nb=0;
//        for(int i = 0;i<n;++i)
//        {
//            scanf("%d",&cache);
//            nb+=cache*nc;nc*=10;
//        }
////        cout << "begin at:" << nb <<endl;
//        sts.push(nb);tq.push(0);
//        maxd= 0;
//        calltimecnt  = 0;
//        while(mosttime==-1)
//        {
//            memset(visited,0,sizeof(visited));
//                if(ida(nb,0))break;
//                else ++maxd;
//                cout << maxd << " use time:"<<calltimecnt <<endl;
////                cout << maxd  <<endl;
//        }
//        printf("Case %d: %d\n",cnt++,maxd);
//    }
//    return 0;
//}
/*************************************
 * NEXT
 * **********************************/
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;
int n,cf,cachespace[10];unsigned int nb;
queue<unsigned int> sts;
queue<int> tq;
int mosttime,maxd;
int qs[10],calltimecnt;
bool visited[9*8*7*6*5*4*3*2];

void movetofront(int* a,int b,int e)
{
    a+=cf;b-=cf;e-=cf;
    memcpy(cachespace,a+b,sizeof(int)*(e-b));
    memcpy(a+e-b,a,sizeof(int)*(b));
    memcpy(a,cachespace,sizeof(int)*(e-b));
}

int geth(int *a)
{
    int cnt =0;
    for(int i = 1;i<n;++i)
        if(a[i]-a[i-1]!=1)
            ++cnt;
    return cnt;
}

unsigned int id(int *a)
{
    int c = 1,cc=0;
    for(int i = 0;i<n;++i)
    {cc+=a[i]*c;c*=10;}
    return cc;
}

int gr(int* a)
{
    int index = 0,cn;
    for(int i = 0;i<n-1;++i)
    {
        cn = 0;
        for(int j = i+1;j<n;++j)
            if(a[i]>a[j])++cn;
        index+=cn*qs[n-i-1];
    }
    return index;
}

void ida(int in,int time)
{
    int a[10],b[10];
    ++calltimecnt;
    for(int i = 0;i<n;++i)
    {a[i] = in%10;in/=10;}
    int index= gr(a);
//    if(visited[index])return;else visited[index] = true;
    if(geth(a) > 3*(maxd - time)) return;
    else if(geth(a) == 0) {mosttime = time;return;}
    memcpy(b,a,sizeof(int)*n);
    cf = -1;
    for(int i = 0;i<n;++i)
        if(a[i]>(i+1)){cf=i;break;}
    if(cf == -1) {mosttime = time;return;}
    for(;cf<n-1;++cf)
    {
        for(int j = cf+1;j<n;++j)
        {

            int c = j+1;bool canmoveit;
            if(a[j]<a[cf])
               canmoveit =true;
            else
                canmoveit =false;
            for(;c<=n;++c){
                if(a[c-1]<a[cf]) canmoveit = true;
                if(!canmoveit) continue;
//                cout << id(a) << endl;
                movetofront(a,j,c);
//                                        cout << id(a) << endl;
//                                        cout << j << " " << c << endl;/*return;*/
//                                        cout << "time:" << time << endl;
                sts.push(id(a));tq.push(time+1);
                memcpy(a,b,sizeof(int)*10);
                while((c+1)<n&&a[c+1]-a[j] == 1) ++c;
            }
        }
    }
}
int main()
{
//    int t[] {1,2,3,4,5,6};
//    movetofront(t,1,3);
//    for(int i = 0;i<6;++i)
//        printf("%d ",t[i]);
//    printf("/n");return 0;
    int cnt = 1;
    qs[0]=1;
    for(int i = 1;i<10;++i)
        qs[i] = qs[i-1]*i;
    while(scanf("%d",&n)&&n)
    {
        unsigned int cache,nc=1;
        mosttime = -1;nb=0;
        memset(visited,0,sizeof(visited));
        for(int i = 0;i<n;++i)
        {
            scanf("%d",&cache);
            nb+=cache*nc;nc*=10;
        }
//        cout << "begin at:" << nb <<endl;
        calltimecnt = 0;
        for(maxd = 1;mosttime==-1;++maxd)
        {
            sts.push(nb);tq.push(0);
            while(!sts.empty()&&mosttime==-1)
            {
                ida(sts.front(),tq.front());
                sts.pop();tq.pop();
            }
            cout << maxd << " use time:" <<calltimecnt <<endl;

            while(!sts.empty())sts.pop();
            while(!tq.empty())tq.pop();
        }

        printf("Case %d: %d\n",cnt++,mosttime);
    }
    return 0;
}
