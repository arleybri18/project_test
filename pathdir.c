#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
extern char **environ;
char *_getenv(const char *);
typedef struct paths
{
  char *str;
  struct paths *next;
}path;
path **_extractpath(char *);
void print_list(const path *h);
int main(int ac, char **av)
{
  int i = 0;
  char *pathstr;
  path **store_paths;

 printf("env:%s\n", getenv(av[1]));
 /*printf("localenv:%s\n", _getenv(av[1]));*/
 pathstr = _getenv(av[1]);
 printf("mi path es %s\n", pathstr);

 /*funcion para mostrar cada ruta del path*/
 store_paths = _extractpath(pathstr);
 /*print_list(*store_paths);*/
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
       if (strlen(name) == c && test[i][b] == '=')
	 {
	   /*printf("Entre en el if ");*/
	   strtok(environ[i], "=");
	   return(strtok(NULL, "="));
	 }
       i++;
     }
   return (NULL);
 }
path **_extractpath(char *string)
{
	char *store_path;
	int count = 1, len = 0;
	path **head = NULL;
	path *newnode;
	path *lastnode;
	newnode = malloc(sizeof(path));
	if (newnode == NULL)
	  {
	    free(newnode);
	    return (0);
	  }
	store_path = strtok(string, ":");
	newnode->str = store_path;
	printf("new:%s", newnode->str);
	newnode->next = NULL;
	lastnode = *head;
	while (store_path != NULL)
	{
	 store_path = strtok(NULL, ":");
	 newnode = malloc(sizeof(path));
	 if (newnode == NULL)
	   {
	     free(newnode);
	     return (0);
	   }
	 newnode->str = store_path;
	 printf("newhile:%s", newnode->str);
	 newnode->next = NULL;
	 lastnode = *head;
	 while (lastnode->next)
	   lastnode = lastnode->next;
	 lastnode->next = newnode;
	}
	return (head);
}
void print_list(const path *h)
{
  path *thisnode = (path *)h;
  int nodes = 0;

  while (thisnode != NULL)
    {
      if (!thisnode->str)
	{
	  thisnode->str = "(nil)";
	  
	}
      printf("%s\n", thisnode->str);
      thisnode = thisnode->next;
      nodes++;
    }
  
}
