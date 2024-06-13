#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR *directory;
    struct dirent *dir_entry;
    if (argc != 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        exit(1);
    }

    directory = opendir(argv[1]);

    if (directory == NULL) {
        printf("Error opening directory.\n");
        exit(1);
    }
    printf("Contents of directory '%s':\n", argv[1]);
    while ((dir_entry = readdir(directory)) != NULL) {
        printf("%s\n", dir_entry->d_name);
    }

    closedir(directory);

    return 0;
}
