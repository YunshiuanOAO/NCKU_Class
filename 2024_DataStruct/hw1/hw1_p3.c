#include<stdio.h>
int queue[1000000];
int v[105][105];
int u[105];
int main(){
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&v[i][j]);
		}
	}
	int Qend = 0;
	int Qfront = 0;
	queue[Qend++] = 1; 
	u[1] = 1;
	while(Qfront != Qend){
		printf("%d ",queue[Qfront]);
		int node = queue[Qfront];
		for(int i=1;i<=m;i++){
			if(v[node][i] == 1 && u[i] == 0){
				queue[Qend++] = i;
				//printf("%d\n",i);
				u[i] = 1;
			}
		}
		Qfront++;
	}
}