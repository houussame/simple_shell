#include "main.h"
/**
 * main - the main function
 * @sz: size
 * @ln: line
 * @nRead: numRead
 * @pd: pid
 * @st: status
 * Return: always 0
 */
int main(void)
{
	char *ln = NULL;
	char *args[] = {NULL, NULL};
	size_t sz;
	int nRead;
	int pd;
	int st;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		nRead = getline(&ln, &sz, stdin);
		if (nRead >= 0)
		{
			ln[nRead - 1] = '\0';/*so we can remove the new line*/
			pd = fork(); /*creat new proccess*/
			args[0] = ln;
			if (pd == 0)
				execve(ln, args, NULL);
			else if (pd > 0)
				wait(&st);
			else if (pd < 0)
				perror;
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

