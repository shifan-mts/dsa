#include<stdio.h>
int a[20][20],q[20],visited[20],n,i,j,f=0,r=1;
void bfs(int v){
    for(i=1;i<=n;i++)
    if(a[v][i] && !visited[i])
    q[++r] =1;
    if(f<=r){
        visited[q[f]] = 1;
        bfs(q[f++]);
    }
}
int main(){
    int v;
    printf("\n enter the number of vertices");
    scanf("%d",&n);
    for(i = 1;i<=n;i++){
        q[i] = 0;
        visited[i] = 0;
        printf("\n enter graph data in matrix form:\n");
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
        printf("\n enter the starting vertex:");
        scanf("%d",&v);
        bfs(v);
        printf("\n the node which are reachable are:\n");
        for(i=1;i<=n;i++)
        if(visited[i])
        printf("%d \t",i);
        else
        printf("\n bfs is not possible");
    }
    return 0;
}

#include<stdio.h>
int i,j,n,G[20][20],visited[20];

void dfs(int i){
    printf("\n %d",i);
    visited[i] = 1;
    for(j=0;j<n;j++){
if(!visited[j] && G[i][j]==1)
dfs(j);
    }
}
void main(){
    printf("enter the no of vertices:");
    scanf("%d",&n);
    printf("neter the adjancency matrix");
    for(i = 0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&G[i][j])
        }
    }
    for(i =0 ;i<n;i++){
        visited[i] = 0;
        dfs(0);
    }
}
