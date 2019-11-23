#include "holberton.h"

/**
 * addPath - Get and check if the command is available
 * @tokens: n
 * Return: Pointer to the filename where is the path to use
 */
char *addPath(char ***tokens)
{
	struct stat st;
	Node *pathDirs;
	char *firstOne, *copyPath = NULL;
	int lenOne, lenTwo;

	if (tokens == NULL)
		return (NULL);

	pathDirs = listpath();
	if (pathDirs == NULL)
		return (NULL);

	firstOne = *(tokens)[0];
	lenOne = _strlen(firstOne);

	/*print_list(pathDirs);*/

	while (pathDirs != NULL)
	{
		lenTwo = _strlen(pathDirs->str);
		copyPath = malloc((lenTwo + lenOne + 2) * sizeof(char));
		_strcat(copyPath, pathDirs->str);
		_strcat(copyPath, "/");
		_strcat(copyPath, firstOne);
		if (stat(copyPath, &st) == 0)
		{
			/*free_list(pathDirs);*/
			/*return (copyPath);*/
			break;
		}

		free(copyPath);
		copyPath = NULL;
		pathDirs = pathDirs->next;
	}
	/*free_list(pathDirs);*/
	return (copyPath);

}
/**
 * processTokens - Get all of the strings separated by a delimiter in
 * an array of strings
 * @tokens: n
 * @buffer: n
 * @countToken: n
 *
 * Return: nothing
 */
void processTokens(char ***tokens, char **buffer, int countToken)
{
	char *token = NULL;
	int i;

	*tokens = malloc(sizeof(char *) * countToken);
	token = strtok(*buffer, " ");
	for (i = 0; token != NULL; i++)
	{
		(*tokens)[i] = token;
		printf("mi token i: %d, %s\n", i, (*tokens)[i]);
		token = strtok(NULL, " ");
	}
	(*tokens)[i] = token; /*Save the NULL token*/
	printf("mi token i: %d, %s\n", i, (*tokens)[i]);
}

/**
 * lenTokens - Get the number of words separated by a delimiter
 * @lenReaded: n
 * @buffer: n
 * Return: (int) of words in the buffer
 */
int lenTokens(ssize_t lenReaded, char **buffer)
{
	char *tempToken = NULL, *copyBuffer = NULL;
	int i;

	copyBuffer = malloc(sizeof(char) * lenReaded);
	_strcpy(copyBuffer, *buffer);
	tempToken = strtok(copyBuffer, " ");
	for (i = 0; tempToken != NULL; i++)
		tempToken = strtok(NULL, " ");
	i++; /* One more to save NULL */
	free(copyBuffer);
	return (i);
}

/**
 * replaceNewLine - Replace the new line in the buffer
 * by a null character
 * @buffer: n
 * Return: nothing
 */
void replaceNewLine(char **buffer)
{
	int i;

	for (i = 0; (*buffer)[i] != '\0'; i++)
		continue;
	(*buffer)[i - 1] = '\0';  /* Replace '\n' by '\0' */

}

/**
 * readLine - Get and process the data in the stdin
 * @buffer: n
 * @tokens: n
 * Return: (ssize_t) The number of chars readed in stdin
 */
ssize_t readLine(char **buffer, char ***tokens)
{
	size_t bufferSize = 0;
	ssize_t gl;
	int countToken;

	gl = _getline(buffer, &bufferSize, stdin);

	if (gl > 0 && **buffer != '\n')
	{
		printf("Entro al if != new line\n");
		replaceNewLine(buffer);
		countToken = lenTokens(gl, buffer);
		printf("count of tokens %d\n", countToken);
		processTokens(tokens, buffer, countToken);
	}
	if (gl == -1)
		printf("return of getline es -1\n");
	return (gl);
}

/**
 * executeLine - Executes the command entered in the child process
 * @buffer: n
 * @tokens: n
 * Return: (int) status
 */
int executeLine(char **buffer, char ***tokens)
{
	int p_child, exec, status;

	if (**buffer == '\n')
	{
		return (1);
	}

	p_child =  fork();
	if (p_child == -1)
	{
		perror("Failed to fork");
		return (-1);
	}
	if (p_child == 0)
	{
		printf("Execute line func (*tokens)[0]: %s\n", (*tokens)[0]);
		exec = execve((*tokens)[0], *tokens, NULL);
		if (exec == -1)
		{
			printf("Exec -1 \n");
			perror((*tokens)[0]);
			free(*tokens);
			free(*buffer);
			exit(99);
		}
	}
	else
	{
		wait(&status);
	}
	printf("Before free the *tokens in exec\n");
	free(*tokens);
	return (1);
}
/**
 * shellLoop - Run the shell
 * Return: nothing
 */
void shellLoop(void)
{
	ssize_t getLine = 1;
	char **tokens = NULL, *buffer = NULL;
	int status = 0;

	while (getLine != EOF)
	{
		printf("($) ");
		fflush(stdout);
		getLine = readLine(&buffer, &tokens);
		if (getLine > 0)
			status = executeLine(&buffer, &tokens);
		if (status == 1)
			printf("EXITO STATUS\n");
	}
	printf("OUT OF LOOP\n");
	free(buffer);
}

/**
 * main - Simple Shell Project
 * Return: nothing
 */
int main(int argc, char **argv, char **argenv)
{
	(void) argc;
	(void) argv;
	(void) argenv;

	shellLoop();

	return (0);
}
