#include "create_procs.h"
#include "child_procs.h"

void create_procs()
{
    int rc = fork();
    int status;
    //grandparent
    if (rc == 0){
        parent();
        waitpid(rc, &status, 1);
    }
    //child
    else{
        int gc = fork();
        if (gc == 0) {//parent
            waitpid(gc, &status, 1);
            child();
        }
        else { //grandchild
            grandchild();
        }
    }
}
