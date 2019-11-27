#include "holberton.h"


/**
 * pfError - fadf
 * @av: a
 * @count: a
 * @firstOne: a
 * @message: a
 */
void pfError(char *av, char *count, char *firstOne, char *message)
{
	char *colon = ": ";

	print_error(av);
	print_error(colon);
	print_error(count);
	print_error(colon);
	print_error(firstOne);
	print_error(colon);
	print_error(message);
}

/**
 * print_error - ddfa
 * @str: a
 */
void print_error(char *str)
{
	_puts(STDERR_FILENO, str);
}

/**
 * _puts - Prints a string in stdout followed by a new line
 * @fd: File descriptor
 * @str: Pointer of char[] variable
 */
void _puts(int fd, char *str)
{
	char *t;
	int len = 0;

	for (t = str; *t != '\0'; t++)
		len++;
	write(fd, str, len);
}

