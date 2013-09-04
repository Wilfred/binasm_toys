#include <stdio.h>

int main() {
    char buf[4];
    FILE *file;
    size_t nread;

    file = fopen("ascii.txt", "r");
    if (file) {
        while ((nread = fread(buf, 1, sizeof buf, file)) > 0) {
            printf("0x%x%x%x%x %s\n", buf[0], buf[1], buf[2], buf[3], buf);

            // fixme: what if the file doesn't fit in four byte blocks?
        }
        if (ferror(file)) {
            printf("Error reading file!\n");
        }
        fclose(file);
    }
    
    return 0;
}
