#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
    int fd;
    char buffer[] = "Hello, world!";
    ssize_t count;
    
    fd = -1;   
    count = write(fd, buffer, sizeof(buffer) - 1); 

    if (count == -1) {        
        printf("count = -1.\n");
    } else {
        printf("Записано %zd байт.\n", count);
    }
    return 0;
}