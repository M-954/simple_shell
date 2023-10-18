#include "shell.h"
/**
 * _path - handles the shell's path
 * @argv: pointer to an array of strings
 */
void _path(char *argv[])
{
	int commandcount = 0;
	char delimeter[] = ":";
	char *path = getenv("PATH");
	char cmds_fullpath[MAXIMUM_BUFFER];
	char *newpath, *tokenpath;
	pid_t child;
	int status;

	newpath = _strdup(path);
	if (newpath == NULL)
	{
		exit(EXIT_FAILURE);
	}
	tokenpath = strtok(newpath, delimeter);
	while (tokenpath)
	{
		cmds_fullpath[0] = '\0';
		_strcat(_strcat(_strcat(cmds_fullpath, tokenpath), "/"), argv[0]);
		if (access(cmds_fullpath, X_OK) == 0)
		{
			commandcount++;
			child = fork();
			if (child < 0)
			{
				fprintf(stderr, "Fork failed\n");
				exit(EXIT_FAILURE);
			}
			if (child == 0)
			{
				fprintf(stderr, "before execve\n");
				execve(cmds_fullpath, argv, NULL);
				fprintf(stderr, "after execve\n");
				exit(EXIT_FAILURE);
			}
			else
			{
				waitpid(child, &status, 0);
				if (WIFEXITED(status))
				{
				}
			}
		}
		if (commandcount == 1)
		{
			free(newpath);
			return;
		}
		tokenpath = strtok(NULL, delimeter);
	}
	if (commandcount == 0)
	{
		perror("command not found");
		return;
	}
	free(newpath);
}
