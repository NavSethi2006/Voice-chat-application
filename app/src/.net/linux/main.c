#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *dir = "../../../Cwrite";
    char strin[10000];

    if (mkfifo(dir, 0777) == -1)
    {
        if (errno != EEXIST)
        {
            printf("file already exist. ENDING PROGRAM");
        }
    }

    int fd_cwrite = open(dir, O_WRONLY);
    int fd_jswrite = open("../../../JSwrite", O_RDONLY);


    // Send msg
    char conn_mesg_out[200] = "Established connection to C";
    conn_mesg_out[strlen(conn_mesg_out)] = '\0';
    write(fd_cwrite, conn_mesg_out, strlen(conn_mesg_out));

    // Recv message
    

    while(1) {
        
        int msg = read(fd_jswrite, strin, sizeof(char) * sizeof(strin));

        if(msg > 0) {
            strin[msg] = '\0';
            printf("message recived: %s\n", strin);
            fflush(stdout);
        }

        switch(strin[0]) {
            case '1':
                printf("shits to login");
                break;
            case '2':
                printf("shit for signup");
                break;
        }

    }


    close(fd_cwrite);
    close(fd_jswrite);

    return 0;
}