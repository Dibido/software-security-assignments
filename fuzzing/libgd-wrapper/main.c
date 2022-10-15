#include "libgd/src/gd.h"
#include <string.h>

#define NAME_BUF_SIZE 250


int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Please specify an image to parse\n");
        return 0;
    }

    char fileName[NAME_BUF_SIZE];
    fileName[NAME_BUF_SIZE-1] = '\0';
    strncpy(fileName, argv[1], NAME_BUF_SIZE-1);
    printf("File name: %s\n", fileName);

    FILE *file = fopen(fileName, "rb");
	if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char tmpFileName[NAME_BUF_SIZE];
    strncpy(tmpFileName, fileName, NAME_BUF_SIZE-1);
    char* base = strtok(tmpFileName, ".");
    char* ext = strtok(NULL, " ");
    printf("Extension: %s\n", ext);

	gdImagePtr imgPtr;
    if (strcmp(ext, "png") == 0) {
        imgPtr = gdImageCreateFromPng(file);
    }
    else if (strcmp(ext, "jpeg") == 0) {
        imgPtr = gdImageCreateFromJpeg(file);
    }
    else if (strcmp(ext, "gif") == 0) {
        imgPtr = gdImageCreateFromGif(file);
	}
    else if (strcmp(ext, "tiff") == 0) {
        imgPtr = gdImageCreateFromTiff(file);
    }
    else {
        printf("File extension %s is not supported\n", ext);
    }
    fclose(file);

    return 0;
}
