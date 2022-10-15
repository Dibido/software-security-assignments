#include "libgd/src/gd.h"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KRED  "\x1B[31m"
#define KMAG  "\x1B[35m"
#define RESET "\x1B[0m"

//struct buff sharpen(struct buff input, char * resultName){
struct buff sharpen(struct buff buffer, char* choice)
{
    char newBuff[100];
    printf("Enter name of buffer: \n");
    gets(newBuff);

    gdImagePtr copy;
    copy = gdImageClone(buffer.imrgb);

    struct buff result;
    if (strcmp(choice, "high") == 0){
        //Mean Image Removal Option "simple sharpen"
        char *temp = strtok(buffer.imageName, ".");
        char *ext = strtok(NULL, " ");
        strcpy(result.imageName, "sharp-");
        strcat(result.imageName, temp);
        strcat(result.imageName, ".");
        strcat(result.imageName, ext);
        strcpy(result.name, newBuff);
        result.width = buffer.width;
        result.height = buffer.height;
        result.channels = buffer.channels;
        gdImageMeanRemoval(copy);
        result.imrgb = copy;
        result.isLibgd = 1;
    }
    else {
        float mask[3][3] = {
            {0, -1, 0},
            {-1, 5, -1},
            {0, -1, -0}
        };

        result = buffer;
        result.isLibgd = 1;
        gdImagePtr src = buffer.imrgb;
        strcpy(result.name, newBuff);

        char name[50];
        strcpy(name, "sharp-");
        strcat(name, result.imageName);
        strcpy(result.imageName, name);

        gdImageConvolution(src, mask, 1.0, 0.0);
        result.imrgb = src;
    }

    printf(KYEL "Done sharpening!\n"RESET);

    return result;
}

