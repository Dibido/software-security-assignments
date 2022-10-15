#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KRED  "\x1B[31m"
#define KMAG  "\x1B[35m"
#define RESET "\x1B[0m"


// Convert an image to a 1-channel grayscale image
struct buff grayscale(struct buff img, char* buffname) {
	struct buff result;
	char* ext;
	ext = strstr(img.imageName, ".png");
	if (ext == NULL)
		ext = strstr(img.imageName, ".jpg");
	if (ext == NULL)
		ext = strstr(img.imageName, ".tiff");
	if (ext == NULL)
		ext = strstr(img.imageName, ".gif");	// Use extension of a for extension of result

	strcpy(result.imageName, "gray-");
	strcat(result.imageName, img.imageName);
	strcpy(result.name, buffname);
	strcpy(result.status, "true");
	result.has_wht = 1;
	result.isLibgd = 0;
	result.height = img.height;
	result.width = img.width;
	result.channels = 1;

	int w = result.width;
	int h = result.height;
	int c = img.channels;
	
	if (c == 1) {
		printf("Image is already grayscale, no new buffer created.");
		return img;
	}
	
	result.img = malloc(w * h);

	if (img.isLibgd == 0) {
		for (int i = 0; i < (w * h); i++) {
			uint8_t avg = 0;
			int r = *(img.img + (i * c) + 1);
			int b = *(img.img + (i * c) + 2);
			int g = *(img.img + (i * c) + 3);
			avg = (r + b + g) / 3;
			*(result.img + i) = avg;
		}
		return result;
	}

	else {
		for (int r = 0; r < img.width; r++)
		{
			for (int col = 0; col < img.height; col++)
			{
				int pos = gdImageGetPixel(img.imrgb, r, col);
				int grey = (gdTrueColorGetRed(pos) + gdTrueColorGetGreen(pos) + gdTrueColorGetBlue(pos)) / 3;
				*(result.img + (col * w) + (r)) = grey;
			}
		}
		return result;
	}
}