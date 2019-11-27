#include "holberton.h"

/**
 * controlC - some
 * @var: n
 */
void controlC(int var)
{
	write(1, "\n($) ", 5);
	(void) var;
}

/**
 * main - Simple Shell Project
 * @argc: m
 * @argv: m
 * Return: nothing
 */
int main(int argc, char **argv)
{
	int status = 0;

	(void) argc;
	signal(SIGINT, controlC);
	status = shellLoop(argv);

	return (status);
}
