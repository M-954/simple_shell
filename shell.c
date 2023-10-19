#include "shell.h"
/**
 * main - Entry point
 * Return: 0 on success
 */
int main(void)
{
	char *command = NULL;
	size_t command_size = 0;
	ssize_t readcommand;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			display_prompt();
			readcommand = getline(&command, &command_size, stdin);
			if (readcommand == -1)
			{
				free(command);
				exit(EXIT_SUCCESS);
			}
		}
		else
		{
			readcommand = getline(&command, &command_size, stdin);
			if (readcommand == -1)
			{
				free(command);
				exit(EXIT_SUCCESS);
			}
		}
		if (command[readcommand - 1] == '\n')
			command[readcommand - 1] = '\0';
		if (_strcmp(command, "env") == 0)
		{
			_env();
			continue;
		}
		if (_strcmp(command, "exit") == 0)
		{
			break;
		}
		execute(command);
	}
	free(command);
	return (0);
}
