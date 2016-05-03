#include<iostream>
#include<cmath>
using namespace std;

int city[7][7];

struct point
{
  int x,y;
};

struct wormhole
{
  struct point ps,pd;
  int tm;
};

int input()
{
  cout<<"\n********* WELCOME TO SPACE TRAVEL *********\n";
  cout<<"Please tell us your departure galaxy : ";
  point s;
  cin>>s.x>>s.y;
  cout<<"\nPlease tell us your destined galaxy : ";
  point d;
  cin>>d.x>>d.y;
  cout<<"\nPlease tell us maximum number of hops #WORMHOLE you want to take :";
  int w = 0;
  cin>>w;
  cout<<"\nList wormhole entrance and exit points : ";
  struct wormhole list_wh[w];
  int i = 0;
  while(i < w)
  {
    point pent,pexit;
    int time;
    cin>>pent.x>>pent.y>>pexit.x>>pexit.y>>time;
    struct wormhole wh;
    wh.ps = pent;
    wh.pd = pexit;
    wh.tm = time;
    list_wh[i] = wh;
    i++;
  }
  
  cout<<"\nThank you For Your Time....";
  
  //we have 2(src and dest) + w points to travel
  int dist[w+2][w+2];
  
  for(int i = 0; i < w+2; i++)
    for(int j = 0; j < w+2; j++)
      dist[i][j] = 0;
      
  //filling src to wormhole dist and wormhole to dest dist
  for(int i = 0; i < w; i++)
  {
    int st = abs(list_wh[i].ps.x - s.x) + abs(list_wh[i].ps.y - s.y);
    int dt = abs(list_wh[i].pd.x - s.x) + abs(list_wh[i].pd.y - s.y);
    
    if(st <= dt)
    {
      dist[0][i+1] = st + list_wh[i].tm;
      dist[i+1][w+1] = abs(list_wh[i].pd.x - d.x) + abs(list_wh[i].pd.y - d.y);;
    }
    else
    {
      dist[0][i+1] = dt + list_wh[i].tm;
      dist[i+1][w+1] = abs(list_wh[i].ps.x - d.x) + abs(list_wh[i].ps.y - d.y);
    }
  }
  
  //filling src to dest distance
  dist[0][w+1] = abs(s.x - d.x) + abs(s.y - d.y);
  
  for(int i = 0; i < w; i++)
  {
    for(int j = 0; j < w;j++)
    {
      if(i != j)
      {
        int t = list_wh[j].tm;
        dist[i+1][j+1] =abs(list_wh[i].pd.x - list_wh[j].ps.x) + abs(list_wh[i].pd.y - list_wh[j].ps.y)+t;
      }
    }
  }
  
  cout<<"\nHere is distance matrix : \n";
  for(int i = 0; i < w+2; i++)
  {
    for(int j = 0; j < w+2; j++)
      cout<<dist[i][j]<<"  ";
    cout<<"\n";
  }
  //let's find minimum time to travel from src to dest via wormholes
  //using dijkstra
  
  bool visited[w+2] = {false};
  int time[w+2] = {INT_MAX};
  time[0] = 0;
  
  for(int i = 1; i < w+2; i++)
  {
    time[i] = INT_MAX;
    visited[i] = false;
  }
    
  for(int i = 0; i < w+1; i++)
  {
    int min = INT_MAX, ind = 0;
    //find vertex which is not included and is at minimum distance from root..first time it is root itself
    for(int j = 0; j < w+2; j++)
    {
      if(!visited[j] && time[j] < min)
      {
        min = time[j];
        ind = j;
      }
    }
    //cout<<"\nNew src is : "<<ind<<endl;
    int src = ind;
    visited[src] = true;
    
    for(int adj = 0; adj < w+2; adj++)
    {
      //cout<<"entering \n";
      //cout<<!visited[adj] << dist[src][adj] << time[src] + dist[src][adj] << time[adj]<<endl;
      if(!visited[adj] && (dist[src][adj] != 0) && ((time[src] + dist[src][adj]) < time[adj]))
      {
        time[adj] = time[src] + dist[src][adj];
        //cout<<"\nUpdating for : "<<adj<<" with "<<time[adj];
      }
    }
  }
  
  for(int i = 0; i < w+2; i++)
    cout<<time[i]<<"\t";
    
  return time[w+1];
}

int main()
{
  cout<<"\n ***Welcome to Hitchhiker's Guide to Galaxy ***\n";
  cout<<"We will find minimum time to travel from Source to Destination through wormholes : ";
  cout<<input()<<endl;
  
  return 0;
}
