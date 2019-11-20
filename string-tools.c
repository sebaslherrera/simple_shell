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
 * *_strpbrk - Searches a string for any of set of bytes
 * @s: Char pointer
 * @accept: Char pointer
 *
 * Return: Locates the first ocurrence in the string s
 * of any of the bytes in the  string accept.
 */
char *_strpbrk(char *s, char *accept)
{
	int j, flag = 0;

	while (*s != '\0')
	{
		flag = 0;
		for (j = 0; accept[j] != '\0';  j++)
		{
			if (*s == accept[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
		s++;
	}

	if (flag)
		return (s);
	else
		return (0);
}



/**
 * _strspn - Gets the length of a prefix substring
 * @s: Char pointer
 * @accept: Char pointer
 *
 * Return: Returns the number of bytes in the initial
 * segment of s which consist
 * only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	int i, j, flag;
	unsigned int ans = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		flag = 1;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				ans++;
				flag = 0;
			}
		}
		if (flag)
			break;
	}

	return (ans);
}
