#include "create_procs.h"
#include "child_procs.h"

void create_procs()
{
    int rc = fork();
    //grandparent
    if (rc == 0){
        parent();
        wait(NULL);
    }
    //child
    else{
        int gc = fork();
        if (gc == 0) {//parent
            wait(NULL);
            child();
        }
        else { //grandchild
            grandchild();
        }
    }
}
