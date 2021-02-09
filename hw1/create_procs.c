#include "create_procs.h"
#include "child_procs.h"

void create_procs()
{
    int rc = fork();
<<<<<<< HEAD
    int status;
    //grandparent
    if (rc == 0){
        parent();
        waitpid(rc, &status, 1);
=======
    //grandparent
    if (rc == 0){
        parent();
        wait(NULL);
>>>>>>> 3aceea365ed6048aa19f54d30d846b43abdec9d4
    }
    //child
    else{
        int gc = fork();
        if (gc == 0) {//parent
<<<<<<< HEAD
            waitpid(gc, &status, 1);
=======
            wait(NULL);
>>>>>>> 3aceea365ed6048aa19f54d30d846b43abdec9d4
            child();
        }
        else { //grandchild
            grandchild();
        }
    }
}
