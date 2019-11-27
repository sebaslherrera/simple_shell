#include "holberton.h"


/**
 * _puts - Prints a string in stdout followed by a new line
 *
 * @str: Pointer of char[] variable
 */
void _puts(int fd, char *str)
{
	char *t;

	for (t = str; *t != '\0'; t++)
	{
		_putchar(fd, *t);
	}
	_putchar(fd, '\n');
}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int fd, char c)
{
	return (write(fd, &c, 1));
}
