#include "main.h"

/**
 * free_2d_arr - Frees memory allocated for a two-dimensional array of str.
 * @fre: A pointer to a pointer to strings (2D array).
 */

void free_2d_arr(char **fre)
{
	int i;

	if (!fre)
		return;

	for (i = 0; fre[i]; i++)
	{
		free(fre[i]);
	}
	free(fre);
}
