#include "libgd/src/gd.h"
#include <string.h>

#define TYPE_BUF_SIZE 5
#define NAME_BUF_SIZE 500

#define TRANSFORMATIONS_BUF_SIZE 10
#define TRANSFORMATION_NAME_BUF_SIZE 10
#define NR_EXPECTED_NON_TRANSFORM_ARGS 3

#ifndef min
#define min(a,b) ((a < b) ? a : b)
#endif


int main(int argc, char **argv) {
    char transformations[TRANSFORMATIONS_BUF_SIZE][TRANSFORMATION_NAME_BUF_SIZE];
    int transformationsAmount = 0;

    if (argc < NR_EXPECTED_NON_TRANSFORM_ARGS) {
        printf("Please specify at least a file type and an image to parse.\n");
        printf("  Additional arguments would be interpreted as image transformations.\n");
        printf("  Up to %d image transformations may be specified.\n", TRANSFORMATIONS_BUF_SIZE);
        printf("  Any additional arguments after these %d transformations would be ignored.\n", TRANSFORMATIONS_BUF_SIZE);
        return 0;
    } else if (argc > NR_EXPECTED_NON_TRANSFORM_ARGS) {
        if ((argc-NR_EXPECTED_NON_TRANSFORM_ARGS) > TRANSFORMATIONS_BUF_SIZE) {
            printf("Warning: More than %d transformations are specified.\n", TRANSFORMATIONS_BUF_SIZE);
            printf("  The last %d transformation(s) will not be performed.\n", (argc-NR_EXPECTED_NON_TRANSFORM_ARGS) - TRANSFORMATIONS_BUF_SIZE);
        }
        transformationsAmount = min(TRANSFORMATIONS_BUF_SIZE, argc-NR_EXPECTED_NON_TRANSFORM_ARGS);
        printf("Number of transformations to apply: %d.\n", transformationsAmount);
        
        for (int i = 0; i < transformationsAmount; ++i) {
            transformations[i][TRANSFORMATION_NAME_BUF_SIZE-1] = '\0';
            strncpy(transformations[i], argv[i+NR_EXPECTED_NON_TRANSFORM_ARGS], TRANSFORMATION_NAME_BUF_SIZE-1);
        }
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

    // Apply transformations
    if (transformationsAmount > 0) {
        printf("Applying transformations:\n");
        for (int i = 0; i < transformationsAmount; ++i) {
            if (strcmp(transformations[i], "fliph") == 0) {
                gdImageFlipHorizontal(imgPtr);
                printf("  Flipped image horizontally.\n");
            } else if (strcmp(transformations[i], "flipv") == 0) {
                gdImageFlipVertical(imgPtr);
                printf("  Flipped image vertically.\n");
            } else if (strcmp(transformations[i], "flipb") == 0) {
                gdImageFlipBoth(imgPtr);
                printf("  Flipped image both horizontally and vertically.\n");
            } else if (strcmp(transformations[i], "gblur") == 0) {
                if (gdImageGaussianBlur(imgPtr) == GD_TRUE) {
                    printf("  Applied Gaussian blur to image.\n");
                } else {
                    printf("  Failed to apply Gaussian blur to image.\n");
                }
            } else if (strcmp(transformations[i], "gray") == 0) {
                if (gdImageGrayScale(imgPtr) == GD_TRUE) {
                    printf("  Transformed image to grayscale.\n");
                } else {
                    printf("  Failed to transform image to grayscale.\n");
                }
            } else if (strcmp(transformations[i], "negate") == 0) {
                if (gdImageNegate(imgPtr) == GD_TRUE) {
                    printf("  Negated image.\n");
                } else {
                    printf("  Failed to negate image.\n");
                }
            } else {
                printf("  Transformation %s is not supported.\n", transformations[i]);
            }
        }
    }

    return 0;
}
