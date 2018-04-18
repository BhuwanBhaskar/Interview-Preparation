#include<iostream>
#include<vector>
#include<istream>
#include<algorithm>

using namespace std;
#define N 5
int graph[N][N];
struct Edge
{
  int src,dest,wt;
};

//operator overload
istream& operator>> (istream &cin, Edge &e)
{
  cin>>e.src>>e.dest>>e.wt;
  
  return cin;
}

ostream& operator<< (ostream &cout, Edge &e)
{
  cout<<e.src<<" "<<e.dest<<" "<<e.wt<<endl;
  return cout;
}

int find_parent(int n, int parent[N])
{
  while(n != parent[n])
  {
    parent[n] = parent[parent[n]];   // not necessary..just to make tree more flat => faster 
    n = parent[n];
  }
  return parent[n];
}

int make_union(int i, int j,int parent[N], int size[N])
{
  int pi = find_parent(i,parent);
  int pj = find_parent(j,parent);
  
  if(size[i] < size[j])
  {
    parent[i] = pj;
    size[j] += size[i];
  }
  else
  {
    parent[j] = pi;
    size[i] += size[j];
  }
}

bool isConnected(int i, int j, int parent[N])
{
  return find_parent(i,parent) == find_parent(j,parent);
}

bool myComp(struct Edge e1, struct Edge e2)
{
  return e1.wt <= e2.wt;
}

void kruskal(vector<struct Edge> edges)
{
  int parent[N];
  int size[N];
  
  for(int i = 0; i < N; i++)
  {
    parent[i] = i;
    size[i] = 0;
  }
  cout<<endl;
  sort(edges.begin(),edges.end(),myComp);
  
  vector<struct Edge> mst;
  
  for(int i = 0; i < edges.size(); i++)
  {
    int s = find_parent(edges[i].src,parent);
    int d = find_parent(edges[i].dest,parent);
    
    if(s == d)   //belongs to same set
      continue;
    else
    {
      make_union(s,d,parent,size);
      mst.push_back(edges[i]);
    }
  }
  cout<<endl;
  for(int i = 0; i < mst.size(); i++)
    cout<<mst[i];
}

void prim()
{
  int included[N];
  int distance[N];
  int parent[N];
  for(int i = 0; i < N; i++)
  {
    included[i] = 0;
    distance[i] = INT_MAX;
    parent[i] = -1;
  }
  included[0] = 1;   //make 0 as root vertex(prim will begin from root)
  distance[0] = 0;
  
  vector<struct Edge>mst;
  int cnt = 1;  //total V-1 vertices to be included in MST
  while(cnt < N)
  {
    int from , min =  INT_MAX;
    for(int i = 0; i < N; i++)
    {
      if(!included[i] && min <= distance[i])
      {
        min = distance[i];
        from = i;
      }
    }
    included[from] = 1;
    
    for(int to = 0; to < N; to++)
    {
      if(!included[to] && graph[from][to] >= 1 && distance[to] != INT_MAX && distance[to] > graph[from][to])
      {
        parent[to] = from;
        distance[to] = graph[from][to];
        
        struct Edge e;
        e.src = from;
        e.dest = to;
        e.wt = graph[from][to];
        mst.push_back(e);
      }
    } 
    cnt++;
  }
}

int main()
{
  int n;
  cin>>n;
  
  vector<struct Edge> edges;
  struct Edge temp;
  while(n != 0)
  {
    cin>>temp;
    edges.push_back(temp); 
    n--;
  }
  
  kruskal(edges);
  prim();
  return 0;
}
