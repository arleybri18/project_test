#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	pid_t parent_id;
	int new_id, i;
	pid_t child_id;

	i = 0;
	while (i < 5)
	{
		wait(&child_id);
		if (new_id = fork() == 0)
		{
			child_id = getpid();
			parent_id = getppid();
			printf("Este es el hijo %u mi padre es %u\n", child_id, parent_id);
			break;
		}
		sleep(5);
		i++;
	}

	printf("last line\n");

	return 0;

}
