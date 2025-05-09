#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

void delayed_write(int fd, const void *buf, size_t count) {
    usleep(1000);
    write(fd, buf, count);
}

int main() {
    int fd;
    char buffer[1024];
    clock_t start, end;
    double time_used;

    for (int i = 0; i < 1024; i++) {
        buffer[i] = 'a';
    }

    fd = open("test.txt", O_WRONLY | O_TRUNC , 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    start = clock();
    for (int i = 0; i < 100; i++) {
        delayed_write(fd, buffer, 1024);
    }
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Час запису без буферизації: %f секунд\n", time_used);
    close(fd);

    FILE *fp = fopen("test.txt", "w");

    start = clock();
    for (int i = 0; i < 100; i++) {
        fwrite(buffer, 1, 1024, fp);
    }
    fclose(fp);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Час запису з буферизацією: %f секунд\n", time_used);

    return 0;
}