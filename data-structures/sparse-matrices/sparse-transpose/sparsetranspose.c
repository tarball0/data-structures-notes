#include <stdio.h>

void display(int[16][3]);
void transpose(int[16][3]);

int tspmat[16][3];
int main(){
	int spmat[16][3]; 
	int nr, nc, numbuf, k = 1;
	printf("enter number of rows: ");
	scanf("%d", &nr);
	spmat[0][0] = nr;
	printf("enter number of columns: ");
	scanf("%d", &nc);
	spmat[0][1] = nc;
	for (int i = 0; i < nr; i++) {
		for (int j = 0; j < nc; j++) {
			printf("enter element %d, %d: ", i, j);
			scanf("%d", &numbuf);
			if (numbuf == 0) continue;
			else {
				spmat[k][0] = i;
				spmat[k][1] = j;
				spmat[k][2] = numbuf;
				k++;
			}
		}
	}
	spmat[0][2] = k-1;

	display(spmat);
	transpose(spmat);
	display(tspmat);

	}

void display(int spmx[16][3]){
	int k = spmx[0][2] + 1;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d  ", spmx[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

void transpose(int spmx[16][3]){
	tspmat[0][0] = spmx[0][1];
	tspmat[0][1] = spmx[0][0];
	tspmat[0][2] = spmx[0][2];
	int c = 0;
	int k = 1;
	while(c < spmx[0][1]){
		for (int i = 1; i <= spmx[0][2]; i++) {
			if (spmx[i][1] == c) {
				tspmat[k][1] = spmx[i][0];
				tspmat[k][0] = spmx[i][1];
				tspmat[k][2] = spmx[i][2];
				k++;
			}

		}
		c++;
	}
}
