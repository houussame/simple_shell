#include "main.h"
/**
 * main - the main function
 * @sz: size
 * @ln: line
 * Return: always 0
 */
int main(void)
{
	char *ln = NULL;
	char *args[] = {NULL, NULL};
	size_t sz;
	int numRead;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		numRead = getline(&ln, &sz, stdin);
		if (numRead >= 0)
		{

			args[0] = ln;
			execve(ln, args, NULL);
			free(ln);   /*because you used getline*/
			ln = NULL; /*always give line a NULL when you use free*/
		}
		else
		{
			free(ln);
			break;
		}
	}
	return (0);
}
