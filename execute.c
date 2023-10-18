#include "shell.h"
/**
 * execute - executes a command and handles PATH
 * @input: the command to execute
 */
void execute(char *input)
{
	pid_t child;
	char *token;
	char del[] = " \n\t";
	char *argv[MAXIMUM_BUFFER];
	int i = 0;
	int status;

	token = strtok(input, del);
	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, del);
		i++;
	}
	argv[i] = NULL;
	if (argv[0] == NULL)
		return;
	if (_strchr(argv[0], '/') != NULL)
	{
		if (access(argv[0], F_OK | X_OK) == 0)
		{
			child = fork();
			if (child < 0)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			if (child == 0)
			{
				if (execve(argv[0], argv, NULL) == -1)
					exit(2);
			}
			else
			{
				waitpid(child, &status, 0);
				if (WIFEXITED(status))
				{
					if (WEXITSTATUS(status) == 2)
					{
						status = 2;
					}
				}
			}
		}
		else
		{
			perror("command not found");
			status = 2;
			exit(2);
		}
	}
	else
		_path(argv);
	exit(status);
}
