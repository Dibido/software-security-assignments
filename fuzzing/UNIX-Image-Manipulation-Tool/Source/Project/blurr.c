#include "libgd/src/gd.h"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KRED  "\x1B[31m"
#define KMAG  "\x1B[35m"
#define RESET "\x1B[0m"

struct buff blurr(struct buff buffer, int radius, double sigma)
{
    char newBuff[100];
    printf("Enter name of buffer: \n");
    gets(newBuff);

    //printf("name:%s, rad:%d, sigma:%d\n", newBuff, radius, sigma);
    gdImagePtr copy;
    copy = gdImageClone(buffer.imrgb);

    struct buff result;
    char *temp = strtok(buffer.imageName, ".");
    char *ext = strtok(NULL, " ");
    strcpy(result.imageName, "blurr-");
	strcat(result.imageName, temp);
    strcat(result.imageName, ".");
    strcat(result.imageName, ext);
	strcpy(result.name, newBuff);
	result.width = buffer.width;
	result.height = buffer.height;
	result.channels = buffer.channels;
    result.imrgb = gdImageCopyGaussianBlurred(copy, radius, sigma);;
    result.isLibgd = 1;

    printf(KYEL "Done blurring!\n"RESET);

    return result;
}
