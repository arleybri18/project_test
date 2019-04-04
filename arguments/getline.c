#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int input(char *s,int length);

int main()
{
    /*
     * getline function
     *
     */
    pid_t new_pid;
    char *buffer;
    size_t bufsize = 32;
    size_t characters;
    int count = 1;
    /* string to save data result of strtok*/
    char *string;
    /*array with values for execve*/
    char **commands;

    buffer = (char *)malloc(bufsize * sizeof(char));

    commands = malloc(30 * sizeof(char));

    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    printf("$");
    characters = getline(&buffer,&bufsize,stdin);


    /*
     * read every string  with stok
     */

    string = strtok(buffer, " ");
    commands[0] = string;

    while (string != NULL)
    {
	    printf("%s\n", string);
	    string = strtok(NULL," ");
	    commands[count] = string;
	    count++;
    }


    /*
     * execve
     *
     */
    count = 0;
    while (commands[count])
    {
	    printf("%d - %s\n",count, commands[count]);
	    count++;
    }

    new_pid = fork();
    printf("pid %u\n",new_pid);
    execve(commands[0], commands, NULL);


    return(0);
    free(buffer);
}
