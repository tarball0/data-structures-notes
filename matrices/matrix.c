#include <stdio.h>

// struct as a user-defined datatype using typedef
typedef struct matrix{
	int mat[32][32];
	int r;
	int c;
} matrix;

// function declarations
void def(matrix *a);

void disp(matrix);

matrix mult(matrix, matrix);

matrix add(matrix, matrix);

matrix transp(matrix);

// Begin main()
int main(){
	matrix mata, matb, matr;
	int opt, transopt, exit = 0;

	// accepting values into matrices a and b using def() (call by refernce)
	def(&mata);
	def(&matb);

	// loop infinitely until option 4 (quit) is called
	while(exit != 1){
		printf("OPTIONS\n1. Multiply\n2. Add\n3. Transpose\n4. Quit");
		printf("\nenter your option: ");
		scanf("%d", &opt);

		switch(opt){
			case 1:
				matr = mult(mata, matb);
				disp(matr);
				break;

			case 2:
				matr = add(mata, matb);
				disp(matr);
				break;

			case 3:
				printf("find transpose of:\n1. Matrix A\n2. Matrix B\n");
				printf("option: ");
				scanf("%d", &transopt);
				
				if(transopt == 1){
					matr = transp(mata);
					disp(matr);
				}
				else if(transopt == 2){
					matr = transp(matb);
					disp(matr);
				}
				else printf("invalid\n");

				break;


			case 4:
				exit = 1;
				break;

		}
		
	}
}


// Define Function (Inputs values to Matrix)
void def(matrix *a){
	printf("enter number of rows: ");
	scanf("%d", &((*a).r));
	printf("enter number of columns: ");
	scanf("%d", &((*a).c));

	for(int i = 0; i < (*a).r; i++){
		for(int j = 0; j < (*a).c; j++){
			printf("enter value (%d,%d): ", i, j);
			scanf("%d", &((*a).mat[i][j]));
		}
	}
}

// Display Function
void disp(matrix a){
	for(int i = 0; i < a.r; i++){
		for(int j = 0; j < a.c; j++){
			printf("%d  ", a.mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// Multiplication Function
matrix mult(matrix a, matrix b){
	matrix res;
	if(a.c != b.r) printf("columns of mat A must be equal to rows of mat B\n");
	else{
		res.r = a.r;
		res.c = b.c;
		for(int i = 0; i < a.r; i++){
			for(int j = 0; j < b.c; j++){
				res.mat[i][j] = 0;
				for(int k = 0; k < a.c; k++){
					res.mat[i][j] += a.mat[i][k]*b.mat[k][j];
				}
			}
		}
	}
	return res;
}
					
// Addition Function
matrix add(matrix a, matrix b){
	matrix res;
	if((a.r != b.r) || (a.c != b.c)) printf("order must be equal\n");
	else{
		res.r = a.r;
		res.c = a.c;
		for(int i = 0; i < a.r; i++){	
			for(int j = 0; j < a.c; j++){
				res.mat[i][j] = a.mat[i][j] + b.mat[i][j];
			}
		}
	}
	return res;
}

// Transpose Function
matrix transp(matrix a){
	matrix res;
	res.r = a.c;
	res.c = a.r;
	for(int i = 0; i < a.r; i++){
		for(int j = 0; j < a.c; j++){
			res.mat[j][i] = a.mat[i][j];
		}
	}
	return res;
}
