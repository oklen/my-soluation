#include <cstring>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: The majority number that occurs more than 1/3
     */
    int majorityNumber(vector<int> &nums) {
        // write your code here
        int mx[12],cnt[12],cou=0;int now = 0,cursize = 0,suma=0;
        memset(cnt,0,sizeof(int)*12);
        memset(mx,0,sizeof(int)*12);
        auto data = nums.data();
        while(nums.size()-now>=6)
        {
            for(int j = 0;j<6;++j)
            {
               for(int i = 0;i<=cursize;++i)
            {
                if(cnt[i]!=0&&mx[i]==*(data+now))
                 ++cnt[i];
                 else if(cnt[i]==0)
                   {
                       mx[i] = *(data+now);
                       cnt[i] = 1;++cursize;
                   }
            }
            ++now;
            }
            suma+=6;
            for(int i = 0;i<=cursize;++i)
            {
                if(cnt[i]<suma/3)
                  {suma-=cnt[i];cnt[i]=0;}
            }
            int b=0,e=0;
            while(cnt[b]!=0){++b;++e;}
            for(;e<=cursize;)
            {
                while(cnt[e]==0)++e;
                cnt[b] = cnt[e];
                mx[b] = mx[e];
                cnt[e] = mx[e] = 0;
                while(cnt[b]!=0)++b;
            }
            cursize = b-1;
        }

        while(nums.size()-now>1)
        {
            for(int i = 0;i<=cursize;++i)
            {
                if(cnt[i]!=0&&mx[i]==*(data+now))
                    ++cnt[i];
                else if(cnt[i]==0)
                    {
                       mx[i] = *(data+now);
                       cnt[i] = 1;++cursize;
                    }
           ++suma;
            }
        }

        map<int,int> result;
        for(int i = 0;i<cursize;++i)
        {
            if(!cnt[i]) result[mx[i]]=cnt[i];
        }
        for(auto bb= result.begin();bb!=result.end();++bb)
        {
            if(bb->second > suma/3)
            {
                int ccnt = 0;
                for(auto aa = nums.begin();aa!=nums.end();++aa)
                {
                    if(*aa = bb->second) ++ccnt;
                }
                if(ccnt > nums.size()/3)
                return bb->second;
            }
        }
    }
};
