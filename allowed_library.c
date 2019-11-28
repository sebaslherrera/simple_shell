#include "holberton.h"


void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

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
	size_t n_alloc = 120;
	size_t n_read = 0;
	size_t old_size;
	size_t n_realloc;
	int c;
	static int i; /* TODO: Use static variable */

	(void) i;
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
			old_size = n_alloc; /* Save the old size allocated */
			n_realloc = *n + n_alloc;
			temp = _realloc(*lineptr, old_size, n_realloc + 1); /* TODO: n_alloc */

			if (temp == NULL)
				return (-1);

			n_alloc = n_realloc + 1; /* Update the size allocated with the new size*/
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

/**
 * *_realloc - Reallocates memory block using malloc and free
 * @ptr: Pointer of void
 * @old_size: Bytes values
 * @new_size: Bytes values
 * Return: Pointer of void reallocated with new memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *new, *another = ptr;

	if (ptr == NULL)
	{
		new = malloc(new_size);
		if (new == NULL)
			return (NULL);
		return (new);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new = malloc(new_size);
	if (new == NULL)
		return (NULL);
	for (i = 0; i < old_size; i++)
		new[i] = another[i];

	free(ptr);

	return (new);
}
