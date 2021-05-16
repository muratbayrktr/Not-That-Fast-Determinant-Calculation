#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>
#include <time.h>
#define MAXLEN 7

/* this static variable is for calculating whether the permutation is even or odd */
static int total_swaps = 0;

/* 
 * Computes the next lexicographical permutation of the specified array of integers in place,
 * returning a Boolean to indicate whether a next permutation existed.
 * (Returns false when the argument is already the last possible permutation.)
 */
bool next_permutation(int array[], size_t length) {

    size_t i, j;
    int temp;
	if (length == 0)
		return false;
	i = length - 1;
	while (i > 0 && array[i - 1] >= array[i])
		i--;
	if (i == 0)
		return false;
	

	j = length - 1;
	while (array[j] <= array[i - 1])
		j--;
	temp = array[i - 1];
	array[i - 1] = array[j];
	array[j] = temp;
	total_swaps++;

	j = length - 1;
	while (i < j) {
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		total_swaps++;
        i++;
		j--;
	}
	return true;
}

void input_matrix(int matrix[MAXLEN][MAXLEN])
{
    int i,j;
    for (i = 0; i < MAXLEN; i++){
        for (j = 0; j < MAXLEN; j++) {
            scanf(" %d",&matrix[i][j]);
        }
    }
}

int main(void)
{
    int i,num, matrix[MAXLEN][MAXLEN] = {0}, array_of_perms[MAXLEN] = {0};
    bool availability = true;
    double sum = 0.0,time_taken;
    clock_t t;
    
    input_matrix(matrix);

    for (i = 0; i < MAXLEN; i++) array_of_perms[i] = i+1;

    
    t = clock();
    while (availability)
    {   
        num=1;
        /* printf("sign: %.0f",sign); */
        for (i = 0; i < MAXLEN; i++) 
        {
            num *= matrix[i][array_of_perms[i]-1];
            /*printf(" %d,%d -> %d \t\t",i,array_of_perms[i]-1,num);*/
            if (num == 0) break;
        }
        /* printf("Product: %.0f\n",sign*num); */
        sum += pow(-1,total_swaps)*num;
        availability = next_permutation(array_of_perms, MAXLEN);
    }
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("%.0f\n",sum);
    printf("Program took %f seconds to execute \n", time_taken);
    return 0;
}