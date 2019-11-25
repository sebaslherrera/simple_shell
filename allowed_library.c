#include "holberton.h"


/**
 * _getchar - Get char function
 * Return: Integer that represent the char
 */
int _getchar(void)
{
	int rd;
	char buff[2];

	rd = read(STDIN_FILENO, buff, 1);

	if (rd == 0)
		return (EOF);
	if (rd == -1)
		exit(99);

	return (*buff);
}

/**
 * _getline - something
 * @lineptr: a
 * @n: a
 * @stream: a
 * Return: some
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *temp;
	const size_t n_alloc = 120;
	size_t n_read = 0;
	size_t n_realloc;
	int c;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	if (*lineptr == NULL)
	{
		*lineptr = malloc(n_alloc);
		if (*lineptr == NULL)
			return (-1);
		*n = n_alloc;
	}
	while ((c = _getchar()) != EOF)
	{
		if (n_read >= *n)
		{
			n_realloc = *n + n_alloc;
			temp = realloc(*lineptr, n_realloc + 1);

			if (temp == NULL)
				return (-1);

			*lineptr = temp;
			*n = n_realloc;
		}
		n_read++;
		(*lineptr)[n_read - 1] = (char) c;

		if (c == '\n')
			break;

	}
	if (c == EOF)
		return (-1);
	(*lineptr)[n_read] = '\0';
	return ((ssize_t) n_read);
}
