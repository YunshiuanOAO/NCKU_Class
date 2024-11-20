#include <stdio.h>
int main ()
{
    int a[10] = {0}, b[10]= {0}, c[10] = {0}; 
    int i, arr_size = 10;
    FILE *input = fopen("../input/2.txt", "r");
    for(i = 0; i < arr_size; i++) fscanf(input, "%d", &a[i]);
    for(i = 0; i < arr_size; i++) fscanf(input, "%d", &b[i]);
    for(i = 0; i < arr_size; i++) fscanf(input, "%d", &c[i]);
    fclose(input);
    int *p_a = &a[0];
    int *p_b = &b[0];
    int *p_c = &c[0];
    /* Original C code segment
    for (int i = 0; i < arr_size; i++){
    *p_c++ = *p_a++ / *p_b++;
    }
    */
    for (int i = 0; i < arr_size; i++)
    asm volatile("lw t1, 0(%1)\n\t" 
		    "lw t2, 0(%2)\n\t" 
		    "div t3, t1, t2\n\t" 
		    "sw t3, 0(%0)\n\t" 
		    "addi %0, %0, 4\n\t" 
		    "addi %1, %1, 4\n\t" 
		    "addi %2, %2, 4\n\t" 
		    : "+r" (p_c), "+r" (p_a), "+r" (p_b) 
		    :
		    : "t1", "t2", "t3", "memory");
    p_c = &c[0];
    for (int i = 0; i < arr_size; i++)
    printf("%d ", *p_c++);
    printf("\n");
    return 0;
}
