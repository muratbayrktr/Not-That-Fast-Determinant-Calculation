#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>

#define MAXLEN 4


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
	

	j = length - 1;
	while (i < j) {
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
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
    int i,j, k = 0,matrix[MAXLEN][MAXLEN] = {0}, array_of_perms[MAXLEN] = {0};
    bool availability = true;
    double sum = 0.0;
    input_matrix(matrix);
    for (i = 1; i <= MAXLEN; i++) array_of_perms[i] = i;

    do
    {
        for (i = 1; i <= MAXLEN; i++)
        {
            for ( j = 0; j < MAXLEN; j++)
            {
                printf(" %d,%d ",i,array_of_perms[j]);
            }
            printf("\n");
        }
        availability = next_permutation(array_of_perms, MAXLEN);
    } while (availability);
    printf("%f\n",sum);



    return 0;
}