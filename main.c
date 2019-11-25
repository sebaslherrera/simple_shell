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
	(void) argc;
	signal(SIGINT, controlC);
	shellLoop(argv);

	return (0);
}
