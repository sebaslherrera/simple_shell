#include "holberton.h"

/**
 * controlC - Helper to capture the signal of CTRL+C
 * @var: Integer variable
 */
void controlC(int var)
{
	write(1, "\n($) ", 5);
	(void) var;
}

/**
 * main - Simple Shell Project
 * @argc: Number of arguments - Integer
 * @argv: Array of arguments - Array of strings
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	int status = 0;

	(void) argc;
	signal(SIGINT, controlC);
	status = shellLoop(argv);

	return (status);
}
