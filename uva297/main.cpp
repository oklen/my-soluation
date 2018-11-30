#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
struct tr{
    tr(){c1=c2=c3=c4=nullptr;}
    tr(char sy){w= sy;}
    char w;
    tr*c1,*c2,*c3,*c4;
};

char ins[1024];

int buildtree(tr* parent,int count)
{
    //cout << ins[count] <<" " <<count << endl;
    if(ins[count] == 'p')
        count = buildtree(parent->c1 = new tr('p'),count+1);
    else
        parent->c1 = new tr(ins[count++]);
    //cout << ins[count] <<" " <<count << endl;
    if(ins[count] == 'p')
        count =buildtree(parent->c2 = new tr('p'),count+1);
    else
        parent->c2 = new tr(ins[count++]);
    //cout << ins[count] <<" " <<count << endl;
    if(ins[count] == 'p')
        count = buildtree(parent->c3= new tr('p'),count+1);
    else
        parent->c3 = new tr(ins[count++]);
    //cout << ins[count] <<" " <<count << endl;
    if(ins[count] == 'p')
        count =buildtree(parent->c4 = new tr('p'),count+1);
    else
        parent->c4 = new tr(ins[count++]);
    //cout << count << endl;
    return count;
}
int gets(tr* r1,int s)
{
    if(r1->w == 'f') return s;
    else if(r1->w == 'p') return gets(r1->c1,s/4)+gets(r1->c2,s/4)+gets(r1->c3,s/4)+gets(r1->c4,s/4);
    else return 0;
}

int draw(tr* r1,tr* r2,int score)
{
    //cout << r1->w <<endl;
   if(r1->w == 'f' || r2->w == 'f')
       return score;
   if(r1->w == 'e')
   {
       if(r2->w == 'e') return 0;
       else return gets(r2,score);
   }
   else
   {
       if(r2->w == 'e') return gets(r1,score);
       else return draw(r1->c1,r2->c1,score/4) + draw(r1->c2,r2->c2,score/4)
               + draw(r1->c3,r2->c3,score/4) + draw(r1->c4,r2->c4,score/4);
   }
}



int main()
{
    int n;
    cin >> n;
    while(n-- && !cin.eof())
    {
        memset(ins,0,sizeof(char)*1024);
        cin >> ins;
        tr root('p');
        if(ins[0]=='p')
           buildtree(&root,1);
        else
            root.w = ins[0];
        memset(ins,0,sizeof(char)*1024);
        cin >> ins;
        tr root2('p');
        if(ins[0]=='p')
           buildtree(&root2,1);
        else
            root2.w = ins[0];
        cout << "There are " << draw(&root,&root2,1024) << " black pixels." <<endl;
    }
    return 0;
}
