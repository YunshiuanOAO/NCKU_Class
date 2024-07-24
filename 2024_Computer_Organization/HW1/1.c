#include <stdio.h>
int main(){
	int a, b,result;
	FILE *input = fopen("../input/1.txt", "r");
	fscanf(input, "%d %d", &a, &b);
	fclose(input);
	//a = a / b;
	
	asm volatile(
		"div %0, %1, %2\n"  
		: "=r" (result)
		: "r" (a), "r" (b)
		:
    	);
	printf("%d\n",result);
	return 0;
}


