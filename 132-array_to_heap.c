#include "binary_trees.h"
/**
 * array_to_heap -builds a Max Binary Heap tree from an array
 * @array: A pointer to the first element of the array
 * @size: The number of element in the array.
 * Return: A pointer to the root node of the created binary heap,
 * NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t i = 0;
	heap_t *tree = NULL;

	for (; i < size; i++)
		heap_insert(&tree, array[i]);

	return (tree);
}
