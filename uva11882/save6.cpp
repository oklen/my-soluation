//#include <iostream>
//#include <cstring>
//#include <queue>
//#include <unordered_map>

//using namespace std;
//char mp[16][16];
//bool vis[15][15];
//bool vis2[15][15];

//unordered_map<unsigned,int> viss[15][15];
//int c,r,ls,cnts,havis,neb;
//vector<pair<char,char>> viso[9];
//const char dx[]{-1,1,0,0};
//const char dy[]{0,0,-1,1};
//vector<char> bn;
//struct cmp{
//    bool operator() (const pair<char,char>& a,const pair<char,char>& b ){
//        return a.first>b.first;}
//};

//unsigned vissave()
//{
//    unsigned n = 0;
//    for(int i = 0;i<c;++i)
//        for(int j = 0;j<r;++j)
//        {
//            if(vis[i][j])n|=1<<(i*c+j);
//        }
//    return n;
//}

//void closedet(int x,int y)
//{
//    int cnt = 0;
//    if(vis2[x][y])return;
//    else {vis2[x][y] = true;++cnts;}
//    for(int i = 0;i<4;++i)
//    {
//        if(x+dx[i]>=0&&x+dx[i]<c&&y+dy[i]>=0&&y+dy[i]<r
//                &&mp[x+dx[i]][y+dy[i]])
//        {
//            if(vis[x+dx[i]][y+dy[i]])++cnt;
//            else if(!vis2[x+dx[i]][y+dy[i]])
//                closedet(x+dx[i],y+dy[i]);
//        }
//    }
//    if(cnt>0)++neb;
//    //return  cnt;
//}

//void vis2f(int x,int y)
//{
//    if(!vis[x][y]/*&&!vis2[x][y]*/)
//    {vis2[x][y]=true;++cnts;}
//    for(int i = 0;i<4;++i)
//    {
//        if(x+dx[i]>=0&&x+dx[i]<c&&y+dy[i]>=0&&y+dy[i]<r
//                &&mp[x+dx[i]][y+dy[i]]&&!vis2[x+dx[i]][y+dy[i]]&&!vis[x+dx[i]][y+dy[i]])
//            vis2f(x+dx[i],y+dy[i]);
//    }
//}

//bool operator>(const vector<char>&a,const vector<char>&b){
//    if(a.size()==b.size())
//    {
//        for(auto aa = a.begin(),bb=b.begin();bb!=b.end();++aa,++bb)
//            if(*aa!=*bb)return *aa>*bb;
//    }
//    return a.size()>b.size();
//}

//void dfs(int x,int y,vector<char>& num)
//{
//    priority_queue<pair<char,char>,vector<pair<char,char>>> vo;
//    if(!vis[x][y])vis[x][y] = true;

//    //if(num.size()>min(c,r))
////    if(r>2&&c>2)
////    {
////    exit(0);

//        int cc = 0;int z2c = 0;neb=0;
//        memset(vis2,0,sizeof(vis2));cnts=0;
//        for(int i = 0;i<4;++i)
//        {
//            if(x+dx[i]>=0&&x+dx[i]<c&&y+dy[i]>=0&&y+dy[i]<r
//                    &&mp[x+dx[i]][y+dy[i]]&&!vis2[x+dx[i]][y+dy[i]]&&!vis[x+dx[i]][y+dy[i]])
//            {
//                //int lastcnts = cnts;
//                closedet(x+dx[i],y+dy[i]);
//                //if(cnts-lastcnts<=1)cc=0;
//                if(neb>1)++z2c;neb=0;
//                if(z2c>1)return;
//            }
//            if(havis+cnts==ls){break;}
//        }
//        num.push_back(mp[x][y]);if(num>bn)bn=num;
//        //z2c=0;
////        if(havis+cnts<ls)
////        for(int i = 0;i<c;++i)
////            for(int j=0;j<r;++j)
////            {
////                if(mp[i][j]&&!vis[i][j]&&!vis2[i][j]){
////                    //int lastcnts = cnts;
////                    closedet(i,j);
////                    if(neb>1)++z2c;neb=0;
////                    if(z2c>2)return;
////                    if(havis+cnts==ls){i=j=15;break;}
////                }
////             }

////    if(cnts+havis==ls)
////    {
////        memset(vis2,0,sizeof(vis2));cnts=0;
////    }
//    for(int i = 0;i<4;++i)
//    {
//        if(x+dx[i]>=0&&x+dx[i]<c&&y+dy[i]>=0&&y+dy[i]<r&&mp[x+dx[i]][y+dy[i]]
//                &&!vis[x+dx[i]][y+dy[i]])
//        {
//            vo.push({mp[x+dx[i]][y+dy[i]],i});}
//    }

//    while(!vo.empty()/*&&bn.size()<ls*/)
//    {
//        //cout << (int)mp[x+dx[vo.top().second]][y+dy[vo.top().second]] <<endl;
//        vis[x+dx[vo.top().second]][y+dy[vo.top().second]] = true;++havis;
//        dfs(x+dx[vo.top().second],y+dy[vo.top().second],num);
//        vis[x+dx[vo.top().second]][y+dy[vo.top().second]] = false;--havis;
//        vo.pop();
//    }
//    num.pop_back();
//}

//int main()
//{   char cs = ' ';
//    while(scanf("%d%d",&c,&r)&&c&&r)
//    {
//        ls=0;
//        while(cs==' '||cs=='\n')cs=getchar();
//        for(int i = 0;i<c;++i)
//        {
//            for(int j = 0;j<r;++j)
//            {
//                if(cs=='#')
//                mp[i][j] = 0;
//                else
//                {
//                    mp[i][j] = cs-'0';
//                    //cout << cs << " " i << " " << j << " " << int(mp[i][j]-1) <<endl;
//                    viso[mp[i][j]-1].push_back({i,j});
//                    ++ls;
//                }
//                cs = getchar();
//            }
//            if(i!=c-1)
//            while(cs==' '||cs=='\n')cs=getchar();
//        }
//        for(int i = 8;i>=0&&bn.size()<ls;--i)
//        {
//            for(int j = 0;j<viso[i].size();++j)
//            {
//                vis[viso[i].at(j).first][viso[i].at(j).second]=true;
//                ++havis;vector<char> tcc;
//                dfs(viso[i].at(j).first,viso[i].at(j).second,tcc);
//                tcc.clear();
//                --havis;
//                vis[viso[i].at(j).first][viso[i].at(j).second]=false;
////                break;
//            }
////         break;
//        }
//        for(auto bb = bn.begin();bb!=bn.end();++bb)
//            cout << (int)*bb;cout <<endl;
//        for(int i = 0;i<9;++i)viso[i].clear();
//        memset(mp,0,sizeof(mp));memset(vis,0,sizeof(vis));bn=vector<char>();
//    }
//    return 0;
//}
