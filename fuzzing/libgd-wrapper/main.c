#include "libgd/src/gd.h"
#include <string.h>

#define TYPE_BUF_SIZE 5
#define NAME_BUF_SIZE 500


int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Please specify a file type and an image to parse.\n");
        return 0;
    }

    char fileType[TYPE_BUF_SIZE];
    fileType[TYPE_BUF_SIZE-1] = '\0';
    strncpy(fileType, argv[1], TYPE_BUF_SIZE-1);
    printf("Specified file type: %s\n", fileType);

    char fileName[NAME_BUF_SIZE];
    fileName[NAME_BUF_SIZE-1] = '\0';
    strncpy(fileName, argv[2], NAME_BUF_SIZE-1);
    printf("Specified file name: %s\n", fileName);

    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    gdImagePtr imgPtr;
    if (strcmp(fileType, "png") == 0) {
        printf("Parsing file as png.\n");
        imgPtr = gdImageCreateFromPng(file);
    }
    else if (strcmp(fileType, "jpeg") == 0) {
        printf("Parsing file as jpeg.\n");
        imgPtr = gdImageCreateFromJpeg(file);
    }
    else if (strcmp(fileType, "gif") == 0) {
        printf("Parsing file as gif.\n");
        imgPtr = gdImageCreateFromGif(file);
    }
    else if (strcmp(fileType, "tiff") == 0) {
        printf("Parsing file as tiff.\n");
        imgPtr = gdImageCreateFromTiff(file);
    }
    else if (strcmp(fileType, "bmp") == 0) {
        printf("Parsing file as bmp.\n");
        imgPtr = gdImageCreateFromBmp(file);
    }
    else if (strcmp(fileType, "tga") == 0) {
        printf("Parsing file as tga.\n");
        imgPtr = gdImageCreateFromTga(file);
    }
    else if (strcmp(fileType, "wbmp") == 0) {
        printf("Parsing file as wbmp.\n");
        imgPtr = gdImageCreateFromWBMP(file);
    }
    else {
        printf("File type %s is not supported.\n", fileType);
    }
    fclose(file);

    // It seems that AFL never reports new finds if we don´t dereference imgPtr.
    if (imgPtr == NULL) {
        printf("Failed to parse image.\n");
    }

    return 0;
}
