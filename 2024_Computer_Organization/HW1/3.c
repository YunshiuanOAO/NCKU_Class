#include<stdio.h>
int main()
{ 
    int f, i, j;
    int h[9] = {0}, x[6] = {0}, y[6] = {0}; 
    FILE *input = fopen("../input/3.txt", "r");
    for(i = 0; i < 9; i++) fscanf(input, "%d", &h[i]);
    for(i = 0; i < 6; i++) fscanf(input, "%d", &x[i]);
    for(i = 0; i < 6; i++) fscanf(input, "%d", &y[i]);
    fclose(input);
    int *p_x = &x[0] ;
    int *p_h = &h[0] ;
    int *p_y = &y[0] ;
    for (i = 0; i < 3; i++){ 
        for (j = 0; j < 2; j++){        	
            for (f = 0; f < 3; f++){
            	asm volatile (
                    "lw t1, 0(%1)\n\t"  
                    "lw t2, 0(%2)\n\t"  
                    "mul t3, t1, t2\n\t"
                    "lw t4, 0(%0)\n\t"  
                    "add t4, t4, t3\n\t"
                    "sw t4, 0(%0)\n\t" 
                    : 
                    : "r" (p_y + i*2 + j), "r" (p_h + i*3 + f), "r" (p_x + f*2 + j)
                    : "t1", "t2", "t3", "t4", "memory"  
                );
            }
                
	}
    }
    p_y = &y[0];
    for(i = 0; i < 6; i++)
    printf("%d ", *p_y++);
    printf("\n");
    return 0; 
 
}
