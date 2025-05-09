#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
    int fd;
    char buffer[4];
    char initial_data[] = {4, 5, 2, 2, 3, 3, 7, 9, 1, 5};
    
    fd = open("data.bin", O_RDWR | O_TRUNC, 0644);

    if (fd == -1) {
        printf("Помилка при відкритті файлу\n");
        return 1;
    }
   
    write(fd, initial_data, sizeof(initial_data));
    
    lseek(fd, 3, SEEK_SET);
    
    read(fd, buffer, 4);
    
    printf("Вміст буфера: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", buffer[i]);
    }   
    printf("\n"); 
    close(fd);
    return 0;
}