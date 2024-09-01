#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	
	int expo;
	int coeff;
}poly;

void polyRead(poly *p, int n_terms)
{
	printf("\n");
	for (int i = 0; i < n_terms; i++)
	{
		
		printf("Coefficient %d: ", i + 1);
		scanf("%d", &(p + i) -> coeff);
		printf("Exponent %d: ", i + 1);
		scanf("%d", &(p + i) -> expo);
	}
}

void polyDisplay(poly *p, int n)
{
	printf("%dx^%d ", p -> coeff, p -> expo);
	for (int i = 1; i < n; i++)
	{
		
		printf("+ %dx^%d ", (p + i) -> coeff, (p + i) -> expo);
	}
	
	printf("\n");
}

void polySum(poly *p1, poly *p2, int n1, int n2)
{
	poly  *result;
	result = (poly *) malloc((n1 + n2) * sizeof(poly));
	
	int i = 0, j = 0, k = 0;
	
	while (i < n1 && j < n2 )
	{
		
		if (((p1 + i) -> expo) > ((p2 + j) -> expo))
		{

			(result + k) -> coeff = (p1 + i) -> coeff;
			(result + k) -> expo = (p1 + i) -> expo;
			i++;
			k++;
		}
		
		else if (((p2 + j) -> expo) > ((p1 + i) -> expo))
		{

			(result + k) -> coeff = (p2 + j) -> coeff;
			(result + k) -> expo = (p2 + j) -> expo;
			j++;
			k++;
		}
		
		else if (((p1 + i) -> expo) == ((p2 + j) -> expo))
		{

			(result + k) -> coeff = (((p1 + i) -> coeff) + ((p2 + j) -> coeff));
			(result + k) -> expo = (p1 + i) -> expo;
			i++;
			j++;
			k++;
		}
	}
	
	while (i < n1)
	{
		
		(result + k) -> coeff = (p1 + i) -> coeff;
		(result + k) -> expo = (p1 + i) -> expo;
		i++;
		k++;
	}
	
	while (j < n2)
	{
		
		(result + k) -> coeff = (p2 + j) -> coeff;
		(result + k) -> expo = (p2 + j) -> expo;
		j++;
		k++;
	}

	printf("First Polynomial: \n");
	polyDisplay(p1, n1);
	printf("Second Polynomial: \n");
	polyDisplay(p2, n2);
	printf("Resultant Polynomial: \n");
	polyDisplay(result, k);
}

int main()
{

	poly *poly1, *poly2;

	int n_terms1, n_terms2;
	
	printf("Enter number of terms of both polynomials: ");
	scanf("%d%d", &n_terms1, &n_terms2);
	
	poly1 = (poly *) malloc(n_terms1 * sizeof(poly));
	poly2 = (poly *) malloc(n_terms2 * sizeof(poly));
	
	printf("Enter terms of first polynomial: \n");
	polyRead(poly1, n_terms1);
	printf("Enter terms of second polynomial: \n");
	polyRead(poly2, n_terms2);
	
	polySum(poly1, poly2, n_terms1, n_terms2);
}
