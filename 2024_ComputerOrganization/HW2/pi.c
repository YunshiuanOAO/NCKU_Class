"li t1, 0\n\t"
"addi %[lw_cnt],%[lw_cnt],1\n\t"

"loop_1:\n\t"

	"mv t2,t1\n"
	"addi %[others_cnt],%[others_cnt],1\n"
	
	"slli t2,t2,1\n"
	"addi %[others_cnt],%[others_cnt],1\n"	
	
	"addi t2,t2,1\n"
	"addi %[add_cnt],%[add_cnt],1\n"
		
	"fcvt.d.w f1,t2\n\t"
	"addi %[others_cnt],%[others_cnt],1\n"	
	
	"mv t2,t1\n"
	"addi %[others_cnt],%[others_cnt],1\n"	
	
	"li t3,0\n"
	"addi %[lw_cnt],%[lw_cnt],1\n"	
	
	"andi t2,t2,1\n"
	"addi %[others_cnt],%[others_cnt],1\n"
	
	"addi %[others_cnt],%[others_cnt],1\n"	
	"beq t2,t3,odd\n"

	"li t2,-1\n"
	"addi %[lw_cnt],%[lw_cnt],1\n"	
	
	"fcvt.d.w f2,t2\n\t"
	"addi %[others_cnt],%[others_cnt],1\n"	
	
	"fdiv.d f1,f2,f1\n\t"
	"addi %[div_cnt],%[div_cnt],1\n"	
	
	"addi %[others_cnt],%[others_cnt],1\n"	
	"j out\n"
	
	"odd:\n"
	
	"li t2,1\n"
	"addi %[lw_cnt],%[lw_cnt],1\n"	
	
	"fcvt.d.w f2,t2\n\t"
	"addi %[others_cnt],%[others_cnt],1\n"	
	
	"fdiv.d f1,f2,f1\n\t"
	"addi %[div_cnt],%[div_cnt],1\n"	
	
	
	"out:\n"
	
	"fadd.d %[pi],%[pi],f1\n"
	"addi %[add_cnt],%[add_cnt],1\n"
	
	"addi t1,t1,1\n\t"
	"addi %[add_cnt],%[add_cnt],1\n\t"
	
	"addi %[others_cnt],%[others_cnt],1\n\t"
	"bge t1, %[N], end_loop_1\n\t"
	
	"addi %[others_cnt],%[others_cnt],1\n\t"
	"j loop_1\n\t"
"end_loop_1:\n"
