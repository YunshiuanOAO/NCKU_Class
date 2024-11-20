void matrix_multiplication(int *a, int *b, int *output, int i, int k, int j) {
    int tmp = 0;
    for (int z = 0; z < k; z++) {
    	for (int y = z + 1; y < j; y++) {
        	tmp = b[y * k + z];
        	b[y * k + z] = b[z * k + y]; 
        	b[z * k + y] = tmp;
    	}
    }
    for (int x = 0; x < i; x++) {
        for (int y = 0; y < j; y++) {
            int sum = 0;
            for (int z = 0; z < k; z++) {
                sum += a[x * k + z] * b[y * j + z];
            }
            output[x * j + y] = sum;
        }
    }
    return;

}

