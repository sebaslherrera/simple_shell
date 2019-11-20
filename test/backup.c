#include "holberton.h"


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

void processTokens(char ***tokens, char **buffer, int countToken)
{
	char *token = NULL
	int i;

	*tokens = malloc(sizeof(char *) * countToken);
	token = strtok(buffer, " ");
	for (i = 0; token != NULL; i++)
	{
		(*tokens)[i] = token;
		token = strtok(NULL, " ");
	}
	(*tokens)[i] = token; /*Save the NULL token*/
}

int lenTokens(ssize_t lenReaded, char **buffer)
{
	char *tempToken = NULL, copyBuffer = NULL;
	int i;

	*copyBuffer = malloc(sizeof(char) * lenReaded);
	_strcpy(copyBuffer, *buffer);
	tempToken = strtok(copyBuffer, " ");
	for (i = 0; tempToken != NULL; i++)
		tempToken = strtok(NULL, " ");
	i++ /* One more to save NULL */
	free(copyBuffer);
	return (i);
}

void replaceNewLine(char **buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
		continue;
	buffer[i - 1] = '\0';  /* Replace '\n' by '\0' */

}

ssize_t readLine(char **buffer, char ***tokens)
{
	size_t bufferSize = 0;
	ssize_t gl;
	int countToken;

	gl = _getline(buffer, &bufferSize, stdin);

	if (**buffer != '\n')
	{
		replaceNewLine(buffer);
		countToken = lenTokens(gl, buffer);
		processTokens(tokens, buffer, countToken);
	}

	return (gl);
}

int executeLine(char **buffer, char ***tokens)
{
	int p_child, exec, status;

	p_child =  fork();
	if (p_child == -1)
	{
		perror("Failed to fork");
		return (-1);
	}
	if (p_child == 0)
	{
		exec = execve((*tokens)[0], *tokens, NULL);
		if (exec == -1)
		{
			perror((*tokens)[0]);
			free(tokens);
			free(buffer);
			exit(99);
		}
	}
	else
	{
		wait(&status);
	}
	free(tokens);
	return (1);
}

void shellLoop()
{
	ssize_t getLine = 1;
	char **tokens = NULL, *buffer = NULL;
	int status;

	while (getLine != EOF)
	{
		printf("($) ");
		getLine = readLine(&buffer, &tokens);
		status = executeLine(&buffer, &tokens);
	}
	free(buffer);
}


int main(void)
{
	size_t bufferSize = 0;
	ssize_t gl = 1;
	char *buffer = NULL, *copyBuffer;
	char **tokens, *token, *tempToken;
	int i = 0, countToken = 0;
	int exec, p_child, status;
	/*char *copyPath = NULL;*/

	while (gl != EOF)
	{
		printf("($) ");
		fflush(stdout);
		gl = _getline(&buffer, &bufferSize, stdin);
		if (*buffer != '\n')
		{
			for (i = 0; buffer[i] != '\0'; i++)
				continue;
			buffer[i - 1] = '\0'; /* Replace '\n' by null char */
			copyBuffer = malloc(sizeof(char) * gl);
			_strcpy(copyBuffer, buffer);

			tempToken = strtok(copyBuffer, " ");
			for (countToken = 0; tempToken != NULL; countToken++)
				tempToken = strtok(NULL, " ");

			countToken++; /* One more to save NULL */
			tokens = malloc(sizeof(char *) * countToken);
			token = strtok(buffer, " ");
			for (i = 0; token != NULL; i++)
			{
				tokens[i] = token;
				token = strtok(NULL, " ");
			}
			tokens[i] = token;
			/* Creates a child process */
			p_child = fork();
			if (p_child == -1)
				return (-1);
			if (p_child == 0)
			{
				/*copyPath = addPath(&tokens);
				if (copyPath != NULL)
					tokens[0] = copyPath;
				*/
				/* Execute the binary in the child process */
				exec = execve(tokens[0], tokens, NULL);
				if (exec == -1)
				{
					perror(tokens[0]);
					free(copyBuffer);
					free(tokens);
					free(buffer);
					exit(99); /* Delete the child process */
				}
				/*if (copyPath != NULL)
				{
					printf("HOLA\n");
					free(copyPath);
				}*/
			}
			else
			{
				wait(&status);
			}
			/** Free the allocated memory */
			free(copyBuffer);
			free(tokens);
		}
	}
	free(buffer);
	return (0);
}
