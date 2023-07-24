#include "path1.h"

/**
 * _strcpy - copies the contents of the source string
 * to the destination string.
 * @dest: a pointer to the destination buffer.
 * @src: a pointer to the source string.
 *
 * Return: to the destination string on success.
 */

char *_strcpy(char *dest, const char *src)
{
	if (dest == NULL || src == NULL)
	{
		 return (NULL);
	}

	return (strcpy(dest, src));
}

/**
 * _strcat - concatenates the source string to the end of the destination string.
 * @dest: a pointer to the destination string.
 * @src: a pointer to the source string.
 *
 * Return: to the destination string on success.
 */

char *_strcat(char *dest, const char *src)
{
	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}

	return (strcat(dest, src));
}

/**
 * _strcmp - compares two strings.
 * @str1: the first pointer of string.
 * @str2: the second pointer of string.
 *
 * Return: posetive if 'str1' greater than 'str2'
 * negative if 'str1' less than 'str2'
 * zero if 'str1' is equal to 'str2'
 */

int _strcmp(const char *str1, const char *str2)
{
	if (str1 == NULL || str2 == NULL)
	{
		 return (-1);
	}

	return (strcmp(str1, str2));
}

/**
 * _strlen - computes the length of a strings.
 * @str: a pointer to a null-terminated string.
 *
 * Return: on unsuccess(the string has zero length) - 0.
 * on success - the length of a size_t value.
 */

size_t _strlen(const char *str)
{
	if (str == NULL)
	{
		return (0);
	}

	return (strlen(str));
}
