#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void after(int pid, const char *second_command) {
    int status;
    while (1) {
        status = kill(pid, 0);
        if (status != 0) {
            system(second_command);
            break;
        }
        usleep(100000);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        return 1;
    }

    int pid = atoi(argv[1]);
    const char *second_command = argv[2];

    after(pid, second_command);

    return 0;
}
