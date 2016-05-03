#include<iostream>

using namespace std;

int main()
{
  string players;
  cin>>players;
  int cnt = 0,same = 0;
  int p = 0, i = 0;
  int seen0 = players[0];
  for(i = 0; i < players.length(); i++)
  {
     
    {
      if(players[p] == '1' && players[i] == '0' && i > p)
      {
        cnt++;
        same = 0;
      }
      else if(players[p] == '1' && players[i] == '1')
      {
        //cout<<p<<" "<<cnt<<endl;
        p = i-cnt;
        if(players[i-1] == '0')
        {
          seen0 = 1;
          i--;
        }
        cnt = 0;
        same++;
      }
      else if(players[p] == '0' && players[i] == '1' && i > p)
      {
        cnt++;
        same = 0;
      }
      else if(players[p] == '0' && players[i] == '0')
      {
        //cout<<p<<" "<<cnt<<endl;
        p = i-cnt;
        //i = i-1;   //we have seen 1 so we need to process
        if(players[i-1] == '1')
        {
          seen0 = 0;
          i--;
        }
        cnt = 0;
        same++;
      }
      
      //cout<<p<<" "<<cnt<<" "<<i<<" "<<same<<endl;
    }
    
    if(cnt >= 7 || same >= 7)
    {
      cout<<"YES";
      break;
    }
  }
  if(i <= players.length() && cnt < 7 && same < 7)
    cout<<"NO";
  return 0;
}
