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
