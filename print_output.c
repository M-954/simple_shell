#include "shell.h"
/**
 * print_output - writes to the standard output
 * @str: output to be displayed
 */
void print_output(char *str)
{
	write(1, str, strlen(str));
}
