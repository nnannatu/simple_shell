#include "main.h"

/**
 * _setenv - Set or modify an environment variable
 * @var: The name of the environment variable
 * @value: The value to set for the environment variable
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *var, const char *value)
{
    if (var == NULL || value == NULL)
        return (-1);

    if (setenv(var, value, 1) == -1)
    {
        perror("setenv");
        return (-1);
    }

    return (0);
}

/**
 * _unsetenv - Unset an environment variable
 * @var: The name of the environment variable to unset
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *var)
{
    if (var == NULL)
        return (-1);

    if (unsetenv(var) == -1)
    {
        perror("unsetenv");
        return (-1);
    }

    return 0;
}
