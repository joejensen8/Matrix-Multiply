#include <stdio.h>
#include <time.h>

// Joe Jensen
// jpj35
// part b

void test_mm(int);
void my_mm(int);
void mm(int, int*, int*, int*);
void fill_matrix(int, int*, int);
void fill_matrix_co(int, int*, int);
void print_matrix(int, int*);

int main(int argc, char **argv) {
	printf("Starting mm2.c\n");	
	test_mm(1000);
	printf("Finished mm2.c\n");
	return 0;
}

void test_mm(int start_size) {
	int i;
	int j = 1;
	for (i = 0; i < 5; i++) {
		int size = j*start_size;
		fflush(stdout);
		printf("Testing MM on array size [%d]\n", size);
		fflush(stdout);
		my_mm(size);
		printf("\n");
		j++;
	}
}

void my_mm(int size) {
	int *A = (int *)malloc(sizeof(int) * size * size);
	int *B = (int *)malloc(sizeof(int) * size * size);
	int *C = (int *)malloc(sizeof(int) * size * size);
	fill_matrix(size, A, 0);
	fill_matrix_co(size, B, 1);
	clock_t t;
	t = clock();
	mm(size, A, B, C);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Time to multiply (sec): [%f]\n", time_taken);
}

void mm (int n, int* A, int* B, int* C) {
	/* For each row i of A */
	int i; int j; int k;
	for (i = 0; i < n; i++) {
		/* For each column j of B */
		for (j = 0; j < n; j++) {
      			/* Compute C(i,j) */
      			int cij = C[i*n+j];
			for(k = 0; k < n; k++) {
				cij += A[i*n + k] * B[j*n + k];
			}
			C[i*n+j] = cij;
		}
	}
}

void fill_matrix (int n, int* A, int start_val) {
	int i;
	for (i = 0; i < n*n; i++) {
		A[i] = i + start_val;
	}
}

void fill_matrix_co (int n, int* A, int start_val) {
	int i;
	int index = 0;
	int index_count = 0;
	for (i = 0; i < n*n; i++) {
		if (index > n*n - n + index_count) {
			index_count++;
			index = index_count;
		}
		A[index] = i + start_val;
		index += n;
	}
}

void print_matrix (int n, int* a) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			int temp = a[i*n + j];
			printf("%d ", temp);
		}
		printf("\n");
	} 
}
