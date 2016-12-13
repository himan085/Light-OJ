#include <bits/stdc++.h>
using namespace std;
int g[101][101];
int graph[101][101],n;

int minDistance(int dist[], bool sptSet[])
{

   int min = INT_MAX, min_index;

   for (int v = 0; v <= n; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}


int maxDistance(int dist[], bool sptSet[])
{

   int max = -1, max_index;

   for (int v = 0; v <= n; v++)
     if (sptSet[v] == false && dist[v] >= max)
         max = dist[v], max_index = v;

   return max_index;
}



int prims()
{
     int dist[n+1];
     bool sptSet[n+1];

     for (int i = 0; i <=n; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     dist[0] = 0;

     for (int count = 0; count < n; count++)
     {
       int u = minDistance(dist, sptSet);
       sptSet[u] = true;

       for (int v = 0; v <= n; v++)
{
     if (!sptSet[v] && graph[u][v]!=0 && graph[u][v] < dist[v])
            dist[v] = graph[u][v];
}
     }

int sum=0;
for(int i=0;i<=n;i++){
 if(dist[i]!=INT_MAX) sum+=dist[i];
}
return(sum);
}


int anti()
{
     int dist[n+1];
     bool sptSet[n+1];

     for (int i = 0; i <=n; i++)
        dist[i] = -1, sptSet[i] = false;

     dist[0] = 0;

     for (int count = 0; count < n; count++)
     {
       int u = maxDistance(dist, sptSet);
       sptSet[u] = true;

       for (int v = 0; v <= n; v++)
{
     if (!sptSet[v] && g[u][v]!=0 && g[u][v] > dist[v])
            dist[v] = g[u][v];
}
     }

int sum=0;
for(int i=0;i<=n;i++){
 if(dist[i]!=-1) sum+=dist[i];
}
return(sum);
}



int main() {
int i,j,u,v,w,t;
scanf("%d",&t);
for(int l=1;l<=t;l++){
        scanf("%d",&n);
for( i=0;i<=n;i++)
    for( j=0;j<=n;j++){
    graph[i][j]=0;
    g[i][j]=0;
}


        while(1){scanf("%d %d %d",&u, &v,&w);

        if(u==0 && v==0 && w==0) break;
                  if(graph[u][v]==0){
                     graph[u][v]=w;
                      graph[v][u]=w;
                      g[u][v]=w;
                      g[v][u]=w;
                  }
                    else if(w<graph[u][v]){
                  graph[u][v]=w;
                   graph[v][u]=w;
              }
                  else if(w>g[u][v]){
                   g[u][v]=w;
                      g[v][u]=w;
                  }


                  }
     int a=prims();
     int b=anti();

if((a+b)%2==0) printf("Case %d: %d\n",l,(a+b)/2);
else printf("Case %d: %d/2\n",l,(a+b));
}

    return 0;
}
