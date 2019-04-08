#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	printf("DIRECCION  ENVIRON %p\n",environ);
	printf("DIRECCION env %p\n",env);
	return (0);

}
