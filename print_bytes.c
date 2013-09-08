#include <stdio.h>
#include <stdlib.h>

void print_char(char c) {
    // If the character is printable, print it. If not, print a dot.
    if (c >= 32 && c < 127) {
        printf("%c", c);
    } else {
        printf(".");
    }
}

int main() {
    unsigned char *buf = malloc(4 * sizeof(char));
    FILE *file;
    size_t nread;

    file = fopen("ascii.txt", "r");

    if (file == NULL) {
        printf("No such file.\n");
        return 1;
    }
    
    while ((nread = fread(buf, 1, 4 * sizeof(unsigned char), file)) > 0) {

        printf("0x");

        // Print the raw bytes.
        switch (nread) {
        case 1:
            printf(" %02x         ", buf[0]);
            break;
        case 2:
            printf(" %02x %02x      ", buf[0], buf[1]);
            break;
        case 3:
            printf(" %02x %02x %02x   ", buf[0], buf[1], buf[2]);
            break;
        case 4:
            printf(" %02x %02x %02x %02x", buf[0], buf[1], buf[2], buf[3]);
            break;
        }

        printf("\t");

        // Print as ASCII
        if (nread >= 1) {
            print_char(buf[0]);
        }
        if (nread >= 2) {
            print_char(buf[1]);
        }
        if (nread >= 3) {
            print_char(buf[2]);
        }
        if (nread >= 4) {
            print_char(buf[3]);
        }

        printf("\n");
            
        // fixme: what if the file doesn't fit in four byte blocks?
    }
    if (ferror(file)) {
        printf("Error reading file!\n");
    }
    fclose(file);
    
    return 0;
}
