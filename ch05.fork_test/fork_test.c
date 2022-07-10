#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int x = 0;
    int rc = fork();
    if(rc < 0)
    {
        printf("fork error\n");
        return -1;
    }
    else if(rc == 0)
    {
        x = 5;
        printf("child : x = %d \n", x);
    }
    else
    {
        int wc = wait(NULL);
        x = 10;
        printf("parent : x = %d \n", x);
    }
    return 0;
}