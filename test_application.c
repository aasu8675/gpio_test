#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Open the GPIO device file
    int fd = open("/dev/gpio_driver", O_WRONLY);

    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write "1" and "0" with a 1-second delay
    char buffer[2] = {'1', '\n'};  // Change '\n' to '0' if newline is not needed

    while (1) {
        // Write "1"
        if (write(fd, buffer, sizeof(buffer)) != sizeof(buffer)) {
            perror("Error writing to file");
            close(fd);
            exit(EXIT_FAILURE);
        }

        // Wait for 1 second
        sleep(1);

        // Write "0"
        buffer[0] = '0';

        if (write(fd, buffer, sizeof(buffer)) != sizeof(buffer)) {
            perror("Error writing to file");
            close(fd);
            exit(EXIT_FAILURE);
        }

        // Wait for 1 second
        sleep(1);
    }

    // Close the file descriptor
    close(fd);

    return 0;
}
