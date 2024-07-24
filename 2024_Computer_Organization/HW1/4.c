#include<stdio.h>
int main()
{ 
    int i = 0;
    int h[9] = {0}, x[6] = {0}, y[6] = {0}; 
    FILE *input = fopen("../input/4.txt", "r");
    for(i = 0; i < 9; i++) fscanf(input, "%d", &h[i]);
    for(i = 0; i < 6; i++) fscanf(input, "%d", &x[i]);
    for(i = 0; i < 6; i++) fscanf(input, "%d", &y[i]);
    fclose(input);
    
    int *p_x = &x[0];
    int *p_h = &h[0];
    int *p_y = &y[0];
    
    asm volatile(
    	"li t0, 0\n"                   
        "li t3, 3\n"                   
    "outer_loop:\n"
        "bge t0, t3, end_outer_loop\n" 
        "li t1, 0\n"                   

    "middle_loop:\n"
        "li t2, 0\n"                  
        "li t4, 2\n"              
        "bge t1, t4, end_middle_loop\n"  

    "inner_loop:\n"
        
        "li t5,0\n"
        "add t5,t5, t0\n" // tmp = i
        "mul t5, t5 ,t4\n"// tmp = i*2
        "add t5, t5 ,t1\n" // tmp = i*2 + j
        "slli t5, t5 , 2\n"
        
        "add t6,t5,%[p_y]\n" // locate p_y[i * 2 + j]
        
        
        "li t5,0\n"
        "add t5,t5, t0\n" // tmp = i
        "mul t5, t5 ,t3\n"// tmp = i*3
        "add t5, t5 ,t2\n" // tmp = i*3 + f
        "slli t5, t5 , 2\n"
        
        "add a1,t5,%[p_h]\n" // locate p_h[i * 3 + f]
       
        
        "li t5,0\n"
        "add t5,t5, t2\n" // tmp = f
        "mul t5, t5 ,t4\n"// tmp = f*2
        "add t5, t5 ,t1\n" // tmp = f*2 + j
        "slli t5, t5 , 2\n"
        
        "add a2,t5,%[p_x]\n" //locate p_x[f * 2 + j]
        
        
        "lw a4,0(a1)\n"
        "lw a5,0(a2)\n"
        "lw a6,0(t6)\n"
        "mul a3,a4,a5\n"
        "add a6,a6,a3\n"
        "sw a6,0(t6)\n"
        
        "addi t2, t2, 1\n"             
        "bge t2, t3, end_inner_loop\n"   
        "j inner_loop\n"

    "end_inner_loop:\n"
        "addi t1, t1, 1\n"            
        "j middle_loop\n"

    "end_middle_loop:\n"
        "addi t0, t0, 1\n"             
        "j outer_loop\n"

    "end_outer_loop:\n"
        :
        : [p_y]"r" (p_y), [p_h]"r" (p_h), [p_x]"r" (p_x)
        : "t0", "t1", "t2", "t3", "t4", "t5","t6","a1","a2","a3","a4","a5","a6"
    );

    p_y = &y[0];
    for(i = 0; i < 6; i++)
        printf("%d ", *p_y++);
    printf("\n");
    return 0; 
 
}
