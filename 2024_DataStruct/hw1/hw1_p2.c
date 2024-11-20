#include<stdio.h>

int heap[1005];
void swap(int *a,int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main(){
	char op[100];
	int num;
	int size = 0;
	while(scanf("%s %d",&op,&num)!=-1){
		if(op[0] == 'i'){
			heap[++size] = num;
			int idx = size;
			while(idx >= 1 && heap[idx / 2] > heap[idx]){
				swap(&heap[idx],&heap[idx/2]);
				idx/=2;
			}
			//printf("%d\n",num);
			
		}else if(op[0] == 'd'){
			int delidx = -1;
			for(int i=0;i<=size;i++){ // force O(n)
				if(heap[i] == num){
					delidx  = i;
					break;
				}
			}
			swap(&heap[delidx],&heap[size]);
			size--;
			int idx = delidx;
			while(idx <= size){
				if(idx*2 <= size && heap[idx] > heap[idx*2] && heap[idx*2] < heap[idx*2+1]){
					swap(&heap[idx],&heap[idx*2]);
					idx *= 2;
				}else if(idx*2 + 1 <= size && heap[idx] > heap[idx*2+1] && heap[idx*2] > heap[idx*2+1]){
					swap(&heap[idx],&heap[idx*2+1]);
					idx *= 2;
					idx++;
				}else{
					break;
				}
			}
			//printf("%d\n",num);
		
		}
	}
	for(int i=1;i<=size;i++){
		printf("%d ",heap[i]);
	}
}