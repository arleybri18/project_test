#include <fcntl.h>
#include <stdio.h>

int main(void)
{
        printf("O_RDONLY = %03x\n", O_RDONLY);
        printf("O_WRONLY = %03x\n", O_WRONLY);
        printf("O_RDWR   = %03x\n", O_RDWR);
        printf("O_CREAT  = %03x\n", O_CREAT);
        printf("O_EXCL   = %03x\n", O_EXCL);
        printf("O_TRUNC  = %03x\n", O_TRUNC);
        printf("O_APPEND = %03x\n", O_APPEND);
        printf("O_CREAT | O_WRONLY = %03x\n", O_CREAT | O_WRONLY);
        printf("O_CREAT | O_WRONLY | O_TRUNC = %03x\n", O_CREAT | O_WRONLY | O_TRUNC);
        printf("O_EXCL  | O_CREAT = %03x\n", O_EXCL | O_CREAT);
        printf("O_CREAT | O_WRONLY | O_TRUNC | O_APPEND = %03x\n", O_CREAT | O_WRONLY | O_\
TRUNC | O_APPEND);
        printf("O_CREAT | O_CREAT  | O_CREAT | O_CREAT  = %03x\n", O_CREAT | O_CREAT | O_C\
REAT | O_CREAT);
        return (0);
}
