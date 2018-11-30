#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cstring>
#include <list>
#include <map>
using namespace std;
int insorder;
int idorder;
map<int,vector<int>> dp;
map<int,vector<int>> bp;
map<int,int> insc;
map<int,bool> malins;
map<string,int> idmmp;
map<int,string> namemmp;
string DEPEND {"DEPEND"},INSTALL{"INSTALL"},REMOVE{"REMOVE"},LIST{"LIST"};
string cc;

int getid(const char* name)
{
    if(name == nullptr)
        throw (name);
    if(idmmp[name] == 0)
     {idmmp[name] = ++idorder;
        namemmp[idorder] = name;
        return idorder;}
    else
        return idmmp[name];
}

void install(int cp,bool tl)
{
    if(insc[cp] !=0){
        if(tl)
            printf("   %s is already installed.\n",namemmp[cp].data());
        return;
    }
    if(tl)
    malins[cp] = true;
    //cout <<  "  now:" <<cp  << " " << endl;
    char* cs = (char*)namemmp[cp].data();
    cs =cs;
    int sizz = dp[cp].size();
    if(dp[cp].size() > 0)
    {
        auto el = dp[cp].end();
        for(auto bb = dp[cp].begin();bb!=el;++bb)
        {
            if(insc[*bb] ==0)
            {
                install(*bb,false);
            }
        }
    }
    printf("   Installing %s\n",namemmp[cp].data());
    insc[cp]=++insorder;
}


void depend(char* pars)
{
    while(*pars == ' ')++pars;
    int master = getid(strndup(pars,strchr(pars,' ')-pars));
    //cout << "master:" << strndup(pars,strchr(pars,' ')-pars) <<endl;
    pars= strchr(pars,' ');
    while(*pars == ' ')++pars;
//    cout << "pars:" <<pars << endl;
    while(true)
    {
        string child;
        while(*pars!=' '&&*pars!='\0'){child.push_back(*pars);++pars;}
        dp[master].push_back(getid(child.data()));
        bp[getid(child.data())].push_back(master);
        while(*pars == ' ')++pars;
        if(*pars == '\0')break;
    }
}

void removE(int cp,bool tl)
{
    if(insc[cp] == 0)
    {
        if(tl)
        {
            char* c = (char*)namemmp[cp].c_str();
            printf("   %s is not installed.\n",c);
        }

        return;
    }

    auto el = bp[cp].end();
    for(auto bb = bp[cp].begin();bb!=el;++bb)
    {
        if(insc[*bb]!=0)
        {
            if(tl)
                printf("   %s is still needed.\n",namemmp[cp].data());
            return;
        }
    }
    if(tl)
        malins[cp] = false;
    printf("   Removing %s\n",namemmp[cp].data());
    insc[cp] = 0;
     el = dp[cp].end();
    for(auto bb = dp[cp].begin();bb!=el;++bb)
    {
        if(insc[*bb]&&!malins[*bb])
            removE(*bb,false);
    }
}

void mlist()
{
    vector<pair<int,int>> result;

    for(auto bb = insc.begin();bb!=insc.end();++bb)
    {
        //cout << bb->first << endl;
        //cout << bb->first << " " << bb->second <<endl;
        if(bb->second != 0)
            result.push_back(pair<int,int>(bb->first,bb->second));
    }
    //cout << "finish list!" << endl;
    sort(result.begin(),result.end(),[](pair<int,int>a,pair<int,int>b){return a.second<b.second;});
    for(auto bb = result.begin();bb!=result.end();++bb)
    {
        //cout << bb->first << endl;
        cout << "   " <<  namemmp[bb->first]<< endl;
    }
}

int main()
{
   char* pos;int commandsize = 3;
    while(getline(cin,cc))
    {
        printf("%s\n",cc.data());
        pos  = strchr((char*)cc.c_str(),' ');
        //cout << "pos:" <<pos <<endl;
        if(strncmp(cc.c_str(),INSTALL.data(),commandsize)==0)
        {
            while(*pos==' ')++pos;
            if(strchr(pos,' ') != nullptr)
            {
                pos=  strndup(pos,strchr(pos,' ') - pos);
            }
//          cout << getid(pos) << ":"<< strlen(pos) << ":" <<endl;
            install(getid(strdup(pos)),true);
        }
        else if(strncmp(cc.data(),DEPEND.data(),commandsize)==0)
            depend(pos);
        else if(strncmp(cc.data(),REMOVE.data(),commandsize)==0)
        {
            while(*pos==' ')++pos;
//            cout << "remove:" << pos << endl;
            if(strchr(pos,' ') != nullptr)
            {
                pos[strchr(pos,' ') - pos] = '\0';
            }
            removE(getid(strdup(pos)),true);
        }
        else if(strncmp(cc.data(),LIST.data(),commandsize)==0)
            mlist();
        else
            break;
        cc.clear();
    }
    return 0;
}
