#include "create_procs.h"
#include "child_procs.h"

void create_procs()
{
    int rc = fork();
    int status;
    //parent
    if (rc != 0){
        wait(NULL);
        wait(NULL);
        parent();
        exit(0);
    }
    //
    else{//child 
        int gc = fork();
        if (gc == 0) {//grandchild
            grandchild();
            exit(0);
        }
        else { //child
            wait(NULL);
            child();
            exit(0);
        }
    }
}
