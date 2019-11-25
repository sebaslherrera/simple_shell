#include "holberton.h"

/**
 * _strlen - Length of the string
 *
 * @s: Pointer of char variable
 * Return: Integer value
 */
int _strlen(char *s)
{
	char *t;
	int counter = 0;

	for (t = s; *t != '\0'; t++)
		counter++;

	return (counter);
}

/**
 * *_strcpy - Copy the string pointed
 *
 * @dest: Pointer of a char[] variable
 * @src: Pointer of a char[] variable
 * Return: Copy of the pointer char
 */
char *_strcpy(char *dest, char *src)
{
	int counter = 0;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		counter++;
	}
		*dest = '\0';
		dest -= counter;
		return (dest);
}

/**
 * *_strcat - Concatenates two strings
 * @dest: String of destiny, pointer to a char[]
 * @src: Source string, pointer to a char[]
 * Return: Char[] concatenated
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; *dest != 0; i++)
		dest++;

	for (j = 0; src[j] != 0; j++)
	{
		*dest = src[j];
		dest++;
	}
	*dest = '\0';
	dest -= (i + j);
	return (dest);
}

/**
 * *_strdup - Function returns a pointer to a new string
 * which is a duplicate of the string str.
 * @str: String
 * Return: Pointer to a new string
 */
char *_strdup(char *str)
{
	char *dupli, *copy;
	int len = 0;

	if (str == NULL)
		return (NULL);

	for (copy = str; *copy != '\0'; copy++)
		len++;

	dupli = malloc(len + 1);
	if (dupli == NULL)
		return (NULL);

	_strcpy(dupli, str);
	return (dupli);

}

