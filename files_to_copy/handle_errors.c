#include "holberton.h"

/**
 * handle_errors - manage errors to printl
 *
 * @argv: arguments of main
 * @commands: commands to print
 * Return: Nothing
 */

void handle_errors(char **argv, char **commands)
{
	char *error = NULL;

	error = _strcat(argv[0], ": 1: ");
	error = _strcat(error, commands[0]);
	error = _strcat(error, ": No such file or directory\n");
	write(STDOUT_FILENO, error, _strlen(error));
	exit(EXIT_FAILURE);
}
