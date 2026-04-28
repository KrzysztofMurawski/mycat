#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){


    for (int i = 1; i<argc; ++i){
        int fd = open(argv[i], O_RDONLY);

        if (fd < 0){
            perror(argv[i]);
            continue;
        }

        ssize_t bytes_read = 0;
        char buffer[4096];

        do{
            
            bytes_read = read(fd, buffer, sizeof(buffer));

            if (bytes_read < 0){
                perror("reading");
                close(fd);
                return 1;
            }
            

            ssize_t total_written = 0;

            while (total_written < bytes_read){
                ssize_t written = write(STDOUT_FILENO, buffer+total_written, bytes_read-total_written);
                if (written < 0){
                    perror("writing");
                    close(fd);
                    return 1;
                }
                total_written = total_written + written;
            }

        } while (bytes_read > 0);


        if (close(fd) != 0){ 
            perror("Error closing fd");
            return 1;
        };

    }

    return 0;
}