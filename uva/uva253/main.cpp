#include <iostream>
#include <cstring>

using namespace std;

void vswitch(char* cu)
{
    char cache = cu[5];
    cu[5] = cu[4];
    cu[4] = cu[0];
    cu[0] = cu[1];
    cu[1] = cache;

}

void hswitch(char *cu)
{

  char cache = cu[2];
  cu[2] = cu[4];
  cu[4] = cu[3];
  cu[3] = cu[1];
  cu[1] = cache;
}

void wswitch(char* cu)
{
    char cache = cu[0];
    cu[0] = cu[3];
    cu[3] = cu[5];
    cu[5] = cu[2];
    cu[2] = cache;
}

bool isSame(char* a,char* b)
{
  for(int i =0;i < 6;i++)
    {
      if(a[i] != b[i])
        return false;
    }
  return true;
}

int main()
{
  char ca[6],cb[6];
  while(true)
    {
      for(int i = 0;i<6;i++)
        {
          ca[i] = getchar();
          if(ca[i] == EOF)
            return 0;
        }
      for(int i =0;i<6;i++)
        cb[i] = getchar();

//       cout << "ori:" <<strndup(ca,6) << endl;
//      cout << strndup(cb,6) << endl;

      //test1
//      hswitch(cb);
//      hswitch(cb);
//      wswitch(cb);
//      vswitch(cb);
//      wswitch(cb);
//      hswitch(cb);
//      wswitch(cb);
//      hswitch(cb);
//      vswitch(cb);
//      wswitch(cb);

//      wswitch(cb);
//      vswitch(cb);
//      wswitch(cb);
//      hswitch(cb);
//      wswitch(cb);
//      vswitch(cb);
//      hswitch(cb);
//            hswitch(cb);
//      vswitch(cb);
//      wswitch(cb);
//      vswitch(cb);
//      wswitch(cb);
//      hswitch(cb);
//      wswitch(cb);
//      hswitch(cb);
//     wswitch(cb);

       getchar();
      for(int i = 0;i < 4;i++)
      {
          for(int j = 0; j < 4;j++)
          {
              if(isSame(ca, cb))
              {
                  cout << "TRUE" << endl;
                  goto next;
              }
              if(i%2==0)
               wswitch(ca);
              else
               vswitch(ca);
          }
              hswitch(ca);
      }
      //cout << strndup(ca,6) << endl;
      vswitch(ca);
      for(int i = 0;i<4;i++)
      {
          if(isSame(ca, cb))
          {
              cout << "TRUE" << endl;
              goto next;
          }
          hswitch(ca);
      }
      vswitch(ca);
      vswitch(ca);
      for(int i = 0;i<4;i++)
      {
          if(isSame(ca, cb))
          {
              cout << "TRUE" << endl;
              goto next;
          }
          hswitch(ca);
      }
      cout << "FALSE" << endl;
      next:
         continue;
    }
}
