#include "shell.h"
/**
 * _strdup - strdup
 *@str: string
 *
 * Return: ptr.
 */
char *_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		ptr[i] = str[i];
	return (ptr);
}
/**
 * _strcmp - strcmp
 *@s1: string 1
 *@s2: string2
 *
 * Return: result.
 */
int _strcmp(char *s1, char *s2)
{
	int result = 0;

	while (*s1 == *s2)
	{
		if (*s1 == '\0' && *s2 == '\0')
		{
			result = 0;
			return (result);
		}
		s1++;
		s2++;
	}
	result = 1;
	return (result);
}
/**
 * _strlen - str length
 *@s: string
 *
 * Return: len.
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);

}
/**
 * _strcat - strcat
 *@dest: dest
 *@src: src
 *
 * Return: dest.
 */
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;
	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = *src;
	return (dest);
}
/**
 * _strcpy - str copy
 *@dest: dest
 *@src: src
 *
 * Return: dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

