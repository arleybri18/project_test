#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
extern char **environ;
char *_getenv(const char *name);
char **_extractpath(char *path);

int main(int ac, char **av)
{
	int i = 0;
	char *path;
	char **store_paths;

	printf("env:%s\n", getenv(av[1]));
	/*printf("localenv:%s\n", _getenv(av[1]));*/
	path = _getenv(av[1]);
	printf("mi path es %s\n", path);

	/*funcion para mostrar cada ruta del path*/
 	store_paths = _extractpath(path);

	while (store_paths[i] != NULL)
	{
		printf("%s\n", store_paths[i]);
		i++;
	}
	return (0);
}
 
char *_getenv(const char *name)
{
	int i = 0, b = 0, c = 0;
	char **test = environ;

	printf("name:%s \n", name);
	while (test[i])
	{
 		/*printf("test[i] es %s\n", test[i]);*/
		b = 0;

		while (name[b])
		{
		/*printf("name[b] es %c\n", name[b]);*/
		if (name[b] == test[i][b])
			c++;
		else
		{
			c = 0;
			break;
		}
		b++;
		}
		/*printf("len name es %lu y c es %d\n",strlen(name),c);*/
		if (strlen(name) == c && test[i][b] == '=' )
		{
			/*printf("Entre en el if ");*/
			strtok(environ[i], "=");
			return(strtok(NULL, "="));
		}
		i++;
	}
	return (NULL);
}

char **_extractpath(char *path)
{
	char **paths;
	char *store_path;
	int count = 1;
	
	paths = malloc(100 * sizeof(char *));
	store_path = strtok(path, ":");
	paths[0] = store_path;

	while (store_path != NULL)
	{
		store_path = strtok(NULL, ":");
 		paths[count] = store_path;
		count++;
	}

	return (paths);
}
