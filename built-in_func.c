#include "holberton.h"

int _strcmp(char *s1, char *s2);

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

	if (_strcmp(firstOne, "exit") == 0)
	{
		*gl = -1;
		free(*tokens);
		*tokens = NULL;
	}
}

/**
 * isEnv - Check if get an env
 * @tokens: n
 * @countToken: n
 * return: nothing
 */
void isEnv(char ***tokens, int countToken)
{
	char *firstOne = NULL;
	int i;

	if (countToken != 2 || *tokens == NULL)
		return;

	firstOne = (*tokens)[0];

	if (_strcmp(firstOne, "env") == 0)
	{
		i = 0;
		while (environ[i])
		{
			_puts(STDOUT_FILENO, environ[i++]);
			_puts(STDOUT_FILENO, "\n");
		}
		free(*tokens);
		*tokens = NULL;
	}
}

/**
 * _strcmp - Compares two strings
 * @s1: Pointer to a char[]
 * @s2: Pointer to a char[]
 * Return: Integer value
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}

	return (0);
}
