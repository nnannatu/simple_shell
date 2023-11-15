#include "main.h"
/**
 *_strcmp -  compares two strings
 *@str_one: A pointer to an char that will be updated
 *@str_two: A pointer to an char that will be updated
 *Return: dest
 */

int _strcmp(const char *str_one, const char *str_two)

{

	/*WHILE*/
	while (*str_one && *str_two &&  *str_one == *str_two)
	{
		str_one++; /*Add string one and string two*/
		str_two++;
	}

	return ((int)(*str_one - *str_two));
}
