#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
	/*getline function*/
	char *buffer;
	size_t bufsize = 32;
	size_t characters;
	char delim[] = " \n";
	/*string to save data result of strtok*/
	char *string;
	/*array with values for execve*/
	char **commands;
	int new_id, i, count = 1;
	pid_t child_id, parent_id;
	char *env[] = { "HOME=/usr/home", "LOGNAME=home", (char *)0 };
	struct stat st;
	int terminal = 0;


	terminal = isatty(0);

	buffer = (char *)malloc(bufsize * sizeof(char));
	commands = malloc (30 * sizeof(char *));

	if (buffer = NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	
	while (1)
	{
		
		/*print promt*/
		printf("#cisfun$");
		/*getline*/
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == -1)
			exit(98);

		/*read string with strtok, split words in the buffer*/
		string = strtok(buffer, delim);
		/*save pointer to word into array commands*/
		commands[0] = string;
		count = 1;

		while (string != NULL)
		{
			/*split word in the buffer*/
			string = strtok(NULL, delim);
			/*save pointer to word into array commands*/
			commands[count] = string;
			count++;
		}
	
		/*fork and execute*/
		if (new_id = fork() == 0)
		{
			child_id = getpid();
			parent_id = getppid();
			/*printf("Este es el hijo %u mi padre es %u\n", child_id, parent_id);*/
		
			/*printf("commnads 0 es %s", commands[0]);*/

			if (stat(commands[0], &st) == 0)
			{	
				execve(commands[0],commands,env);
				sleep(1);
			}
			else
			{
				printf("./shell: No such file or directory\n");
			}
		}
		else
		{

			if (terminal == 0)
				break;
			wait(&child_id);
		}

		/*printf("last line\n");*/
	}

	free(buffer);
	return 0;

}
