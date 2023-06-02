#include "binary_trees.h"
/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL
 * tree, or NULL on failure
*/
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (array == NULL)
		return (NULL);

	for (size_t i = 0; i < size; i++)
	{
		int is_duplicate = 0;

		for (size_t j = 0; j < i; j++)
		{
			if (array[j] == array[i])
			{
				is_duplicate = 1;
				break;
			}
		}

		if (!is_duplicate && avl_insert(&tree, array[i]) == NULL)
			return (NULL);
	}
	return (tree);
}
