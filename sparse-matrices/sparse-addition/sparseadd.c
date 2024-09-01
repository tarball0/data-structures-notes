#include <stdio.h>

void display(int[16][3]);
void add();

int mat1[16][3];
int mat2[16][3];
int sum[16][3];
int main() {
    int nr, nc, numbuf, k = 1;
    printf("enter number of rows: ");
    scanf("%d", &nr);
    mat1[0][0] = nr;
    mat2[0][0] = nr;
    printf("enter number of columns: ");
    scanf("%d", &nc);
    mat1[0][1] = nc;
    mat2[0][1] = nc;

    printf("enter matrix 1:\n");
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            printf("enter element %d, %d: ", i, j);
            scanf("%d", &numbuf);
            if (numbuf == 0)
                continue;
            else {
                mat1[k][0] = i;
                mat1[k][1] = j;
                mat1[k][2] = numbuf;
                k++;
            }
        }
    }
    mat1[0][2] = k - 1;

    k = 1;

    printf("enter matrix 2:\n");
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            printf("enter element %d, %d: ", i, j);
            scanf("%d", &numbuf);
            if (numbuf == 0)
                continue;
            else {
                mat2[k][0] = i;
                mat2[k][1] = j;
                mat2[k][2] = numbuf;
                k++;
            }
        }
    }
    mat2[0][2] = k - 1;

    display(mat1);
    display(mat2);
    add();
    display(sum);
}

void display(int spmx[16][3]) {
    int k = spmx[0][2] + 1;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d  ", spmx[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void add() {
    int k = 1, l = 1, m = 1;
    sum[0][0] = mat1[0][0];
    sum[0][1] = mat1[0][1];
    for (int i = 0; i < mat1[0][0]; i++) {
        for (int j = 0; j < mat1[0][1]; j++) {
            if (((mat1[k][0] == i) && (mat1[k][1] == j)) &&
                ((mat2[l][0] == i) && (mat2[l][1] == j))) {
                sum[m][0] = mat1[k][0];
                sum[m][1] = mat1[k][1];
                sum[m][2] = mat1[k][2] + mat2[l][2];
                m++;
                k++;
                l++;
            }

            else if (((mat1[k][0] == i) && (mat1[k][1] == j))) {
                sum[m][0] = mat1[k][0];
                sum[m][1] = mat1[k][1];
                sum[m][2] = mat1[k][2];
                m++;
                k++;

            }

            else if (((mat2[l][0] == i) && (mat2[l][1] == j))) {
                sum[m][0] = mat2[l][0];
                sum[m][1] = mat2[l][1];
                sum[m][2] = mat2[l][2];
                m++;
                l++;
            }
        }
    }
    sum[0][2] = m - 1;
}
