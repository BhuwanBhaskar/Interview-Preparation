#include<iostream>

using namespace std;

#define N 5

struct node
{
  int v;          //tells identity or numbering of node  
  //int color;      //color == 0 then white, color == 1 grey, color == 2 black;
  int pre;       //mark time when it is greyed . if pre == 0 then node has not been visited yet
  int post;      //mark time when its descendents have been visited;
  int parent;    //parent of this node
  int cc;         // identifies to which connected component node belongs
  int order;     //reflects order in topological sorting if possible DAG
};

struct node vertices[N];
int graph[N][N];
static int time = 0;
int order = N-1;
int cc = 0;

void rec_dfs(int node)
{
  vertices[node].pre = ++time;
  vertices[node].cc = cc;   //for finding connected component
  for(int i = 0; i < N; i++)
  {
    if(graph[node][i] && vertices[i].pre == 0)
    {
      vertices[i].parent = node;
      rec_dfs(i);
    }
  }
  vertices[node].post = ++time;
  vertices[node].order = order--;    //for topological sorting 
}

void dfs()
{
  for(int i = 0; i < N; i++)
  {
    if(vertices[i].pre == 0)
    {
      vertices[i].cc = ++cc;
      rec_dfs(i);
    }
  }
}

void topo_sort()
{
  dfs();

  for(int i = 0;i < N; i++)
  {
    struct node temp;
    if(vertices[i].v != vertices[i].order)
    {
      int v = vertices[i].order;
      int next = vertices[i].v;
      //to avoid changing this node's position again in future !!
      vertices[i].order = vertices[i].v;   
      //swap nodes
      temp = vertices[v];
      vertices[v] = vertices[i];
      vertices[i] = temp;
      
      i = --next; 
    }
    
    if(i == N-1)
    {
      int j = 0;
      while(vertices[j].v == vertices[j].order)
        j++;
      if(j == N-1)
        break;
      else
        i = j-1;
    } 
  }
}

void reverse_graph()
{
  for(int i = 0; i < N; i++)
  {
    for(int j = i; j < N; j++)
    {
      swap(&graph[i][j])
    }
  }
}
bool is_strongly_conn()
{
  //let's do dfs first and store nodes in array in the order of post values as in topological sort
  topo_sort();
  reverse_graph();
  
}
int main()
{
  cout<<" Enter #edges : ";
  int e;
  cin>>e;
  
  struct node n;
  n.parent = n.v =  n.order = -1;
  n.post = n.pre = 0;//n.color = 0;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      graph[i][j] = 0;
  
  for(int i = 0; i < N; i++)
  {
    n.v = i;
    vertices[i] = n;
  }
    
  int src,dst;
  for(int i = 0; i < e; i++)
  {
    cin>>src>>dst;
    graph[src][dst] = 1;
    //graph[dst][src] = 1;   // for unordered graph
  }
  
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
      cout<<graph[i][j]<<" ";
    cout<<endl;
  }
  dfs();
  topo_sort();
  for(int i = 0; i < N; i++)
  {
    cout<<"\nVertex "<<vertices[i].v<<" "<<vertices[i].order<<" "<<vertices[i].pre<<" "<<vertices[i].post;
    cout<<" "<<vertices[i].parent<<" "<<vertices[i].cc;
  }
  
  return 0;
}
