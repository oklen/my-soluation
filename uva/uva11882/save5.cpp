//#include <iostream>
//#include <cstring>
//#include <queue>
//#include <unordered_map>

//using namespace std;
//char mp[16][16];
//bool vis[15][15];
//bool vis2[15][15];

//unordered_map<unsigned,int> viss[15][15];
//int c,r,ls,cnts,havis;
//vector<pair<int,int>> viso[9];
//const int dx[]{-1,1,0,0};
//const int dy[]{0,0,-1,1};
//vector<char> bn;
//struct cmp{
//    bool operator() (const pair<int,int>& a,const pair<int,int>& b ){
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

//int closedet(int x,int y)
//{
//    int cnt = 0;
//    if(vis[x][y]) return 1;
//    else if(vis2[x][y])return 0;
//    else {vis2[x][y] = true;++cnts;}
////    int u=0,l=0;
//    for(int i = 0;i<4;++i)
//    {
//        if(x+dx[i]>=0&&x+dx[i]<c&&y+dy[i]>=0&&y+dy[i]<r
//                &&mp[x+dx[i]][y+dy[i]])
//                cnt+=closedet(x+dx[i],y+dy[i]);
//    }
//    return  cnt;
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

//void dfs(int x,int y,vector<char> num)
//{
//    priority_queue<pair<int,int>,vector<pair<int,int>>> vo;
//    if(!vis[x][y])vis[x][y] = true;
//    num.push_back(mp[x][y]);if(num>bn)bn=num;
//    //if(num.size()>min(c,r))
////    if(r>2&&c>2)
////    {
////    exit(0);

//        int cc = 0;int z2c = 0;
//        memset(vis2,0,sizeof(vis2));cnts=0;
//        for(int i = 0;i<4;++i)
//        {
//            if(x+dx[i]>=0&&x+dx[i]<c&&y+dy[i]>=0&&y+dy[i]<r
//                    &&mp[x+dx[i]][y+dy[i]]&&!vis2[x+dx[i]][y+dy[i]]&&!vis[x+dx[i]][y+dy[i]])
//            {
//                int lastcnts = cnts;
//                cc=closedet(x+dx[i],y+dy[i]);
//                //if(cnts-lastcnts<=1)cc=0;
//                if(cc>1&&cnts-lastcnts>1)++z2c;cc=0;
//                if(z2c>1)return;
//            }
//            if(havis+cnts==ls){break;}
//        }
//        //z2c=0;
//        if(havis+cnts<ls)
//        for(int i = 0;i<c;++i)
//            for(int j=0;j<r;++j)
//            {
//                if(mp[i][j]&&!vis[i][j]&&!vis2[i][j]){
//                    //int lastcnts = cnts;
//                    cc=closedet(i,j);
//                    if(cc>1/*&&cnts-lastcnts>=1*/)
//                        ++z2c;
//                    if(z2c>2)return;
//                    if(havis+cnts==ls){i=j=15;break;}
//                }
//             }
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
//                ++havis;
//                dfs(viso[i].at(j).first,viso[i].at(j).second,vector<char>());
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
