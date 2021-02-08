#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int counter = 0;

void child()
{
    counter += 7;
    printf("Child counter value:%d\n",counter);
    printf("Child address:%p\n",(void*)&counter);
}

void parent()
{
    counter *= 2;
    printf("Parent counter value:%d\n",counter);
    printf("Parent address:%p\n",(void*)&counter);
}

int main(int argc, char* argv[])
{
    int rc = fork();
    if (rc == 0) // Child Process
    {
        child();
    }
    else // Parent Process
    {
        int wc = wait(NULL);
        parent();
    }

}
