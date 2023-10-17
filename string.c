#include "shell.h"
/**
 * _strdup - duplicates an original string
 * @s: original string to duplicate
 *
 * Return: char pointer to the duplicated string
 */
char *_strdup(char *s)
{
	int k;
	char *duplicate;
	int length = 0;

	if (s == NULL)
	{
		return (NULL);
	}
	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	duplicate = (char *)malloc((length + 1));
	if (duplicate == NULL)
	{
		return (NULL);
	}
	for (k = 0; k < length; k++)
	{
		duplicate[k] = s[k];
	}
	duplicate[length] = '\0';
	return (duplicate);
}
/**
 * _strcat - concatenates string in dest to src
 * @dest: pointer to destination
 * @src: pointer to source
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	char *ptr;

	ptr = dest;
	while (*ptr != '\0')
	{
		ptr++;
	}
	while (*src != '\0')
	{
		*ptr = *src;
		src++;
		ptr++;
	}
	*ptr = '\0';
	return (dest);
}
/**
 * _strlen - outputs length of a string
 * @s: string character
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = strlen(s);

	return (len);
}
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 when strings are equal
 */
int _strcmp(char *s1, char *s2)
{
	int a = 0;

	while (s1[a] != '\0' || s2[a] != '\0')
	{
		if (s1[a] != s2[a])
		{
			return (s1[a] - s2[a]);
		}
		a++;
	}
	return (0);
}
/**
 * _strchr - finds first occurance of a character
 * @str: string to search
 * @a: character to be found
 *
 * Return: pointer to character found otherwise NULL
 */
char *_strchr(char *str, char a)
{
	while (*str != '\0')
	{
		if (*str == a)
		{
			return (str);
		}
		str++;
	}
	if (a == '\0')
	{
		return (str);
	}
	return (NULL);
}

