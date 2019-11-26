#include "holberton.h"

/**
 * isBasicExit - Check if get an exit
 * @tokens: n
 * @countToken: n
 * @gl: n
 * Return: nothing
 */
void isBasicExit(char ***tokens, int countToken, ssize_t *gl)
{
	char *firstOne = NULL;

	if (countToken != 2 || *tokens == NULL)
		return;

	firstOne = (*tokens)[0];

	if (strcmp(firstOne, "exit") == 0)
	{
		*gl = -1;
		free(*tokens);
	}
}
