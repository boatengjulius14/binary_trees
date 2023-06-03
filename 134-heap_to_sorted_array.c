#include "binary_trees.h"
/**
 * heap_to_sorted_array - converts a Binary Max Heap to sorted array
 * of integers
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 * Return: sorted arary, NULL on failure
*/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *ptr;

	if (heap == NULL || size == 0)
		return (NULL);
	*size = tree_sum(heap) + 1;

	ptr = malloc(sizeof(int) * (*size));
	if (ptr == NULL)
		return (NULL);

	for (i = 0; heap; i++)
		ptr[i] = heap_extract(&heap);
	return (ptr);
}
