#include "binary_trees.h"
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 *
 * @tree: a pointer to the root node of the tree to count the of leaves
 *
 * Return: leaves count
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}


/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of a tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_level = 0, right_level = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_level = 1 + binary_tree_height(tree->left);

	if (tree->right)
		right_level = 1 + binary_tree_height(tree->right);

	return (right_level > left_level ? right_level : left_level);
}


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance factor
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	/**
	 * Add +1 afterwards, to differenciate btn passing
	 * NULL and passing a leaf node
	 */
	left = binary_tree_height(tree->left);
	if (tree->left)
		left++;

	right = binary_tree_height(tree->right);
	if (tree->right)
		right++;

	return (left - right);
}


/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 *
 * @tree: pointer to the node to measure the depth
 *
 * Return: depth of a node
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth  = 0;

	if (tree == NULL)
		return (0);

	for (; tree->parent; tree = tree->parent)
		depth++;

	return (depth);
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if binary tree is perfect, 0 if otherwise
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int exp_leafno = binary_tree_leaves(tree);
	int act_leafno = 1, depth;

	if (tree == NULL)
		return (0);

	if (!binary_tree_balance(tree))
	{
		while (tree->left)
			tree = tree->left;
		/**
		 * compare the expected leave no. to the actual
		 * leave no. (2^depth of leftmost leave)
		*/
		depth = binary_tree_depth(tree);

		while (depth)
		{
			act_leafno *= 2;
			depth--;
		}
		if (exp_leafno == act_leafno)
			return (1);
	}
	return (0);
}
