"li t0,8\n"
"addi %[lw_cnt],%[lw_cnt],1\n"
"addi %[others_cnt],%[others_cnt],1\n"

"bge %[arr_size],t0,greater\n"
"vsetivli t0, 2, e16,m1,ta,mu\n\t"
"mv t2,%[arr_size]\n"
"addi %[others_cnt],%[others_cnt],2\n"
"improved_loop:\n\t"
		
	"vle16.v v0,(%[h])\n\t"
	"addi %[lw_cnt],%[lw_cnt],1\n"
	
	"addi %[h],%[h],4\n\t"
    	"addi %[add_cnt],%[add_cnt],1\n"
	
	"vle16.v v4,(%[x])\n\t"
	"addi %[lw_cnt],%[lw_cnt],1\n"
	"addi %[x],%[x],4\n\t"
    	"addi %[add_cnt],%[add_cnt],1\n"
    		
	"vmul.vv v8,v0,v4\n\t"
	"addi %[mul_cnt],%[mul_cnt],1\n"
	
	"vadd.vx v8,v8,%[id]\n\t"
	"addi %[add_cnt],%[add_cnt],1\n"
	
	"vse16.v v8,(%[y])\n\t"
	"addi %[sw_cnt],%[sw_cnt],1\n"
	
	"addi %[y],%[y],4\n\t"
    	"addi %[add_cnt],%[add_cnt],1\n"	
    	
	"sub t2,t2,t0\n\t"
	"addi %[sub_cnt],%[sub_cnt],1\n"
	
"addi %[others_cnt],%[others_cnt],1\n"
"bnez t2, improved_loop\n\t"
"addi %[others_cnt],%[others_cnt],1\n"
"j end\n"

"greater:\n"
"vsetivli t0, 8, e16,m1,ta,mu\n\t"
"mv t2,%[arr_size]\n"
"addi %[others_cnt],%[others_cnt],2\n"
"improved2_loop:\n\t"
		
	"vle16.v v0,(%[h])\n\t"
	"addi %[lw_cnt],%[lw_cnt],1\n"
	
	"addi %[h],%[h],16\n\t"
    	"addi %[add_cnt],%[add_cnt],1\n"
	
	"vle16.v v4,(%[x])\n\t"
	"addi %[lw_cnt],%[lw_cnt],1\n"
	"addi %[x],%[x],16\n\t"
    	"addi %[add_cnt],%[add_cnt],1\n"
    		
	"vmul.vv v8,v0,v4\n\t"
	"addi %[mul_cnt],%[mul_cnt],1\n"
	
	"vadd.vx v8,v8,%[id]\n\t"
	"addi %[add_cnt],%[add_cnt],1\n"
	
	"vse16.v v8,(%[y])\n\t"
	"addi %[sw_cnt],%[sw_cnt],1\n"
	
	"addi %[y],%[y],16\n\t"
    	"addi %[add_cnt],%[add_cnt],1\n"	
    	
	"sub t2,t2,t0\n\t"
	"addi %[sub_cnt],%[sub_cnt],1\n"
	
"addi %[others_cnt],%[others_cnt],1\n"
"bnez t2, improved2_loop\n\t"


"end:"

