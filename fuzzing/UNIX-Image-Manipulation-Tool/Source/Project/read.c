#include <stdio.h>
#include <stdint.h>
#include <errno.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define KYEL  "\x1B[33m"
#define KRED  "\x1B[31m"
#define RESET "\x1B[0m"


struct buff readToBuff(char *imageName, char *const buffName)
{
	char name[25];
	strcpy(name, imageName);
	char *temp = strtok(name, ".");
	char *ext = strtok(NULL, " ");
	FILE *in;
	struct buff buffer;

	if (strcmp(ext, "wht") == 0)
	{
		printf(KYEL"Reading %s into %s..."RESET"\n", imageName, buffName);
		in = fopen(strcat(temp, ".wht"), "rb");
		fread(&buffer.width, sizeof(int), 1, in);
		fread(&buffer.height, sizeof(int), 1, in);
		fread(&buffer.channels, sizeof(int), 1, in);
		int size = buffer.width * buffer.height * buffer.channels;
		//printf("size: %d\n", size);
		buffer.wht = malloc(size * sizeof(double));
		fread(buffer.wht, sizeof(double), size, in);
		buffer.img = NULL;
		strcpy(buffer.name, buffName);
		strcpy(buffer.imageName, imageName);
		buffer.isLibgd = false;
		buffer.has_wht = 1;
		fclose(in);
		//print_matrixf(buffer.wht, buffer.width);
		
		return buffer;
	}

	printf(KYEL"Reading %s into %s..."RESET"\n" , imageName, buffName);
	int width, height, ch;
	unsigned char *buff = stbi_load(imageName, &width, &height, &ch, 0);
	if (buffName == NULL || buff == NULL)
	{
		printf(KRED "Error: "RESET " Cannot read file\n");
		stbi_failure_reason();
	}
	printf("ext:%s\n",ext);
	if (strcmp(ext, "png") == 0)
	{
		in = fopen(strcat(temp, ".png"), "rb");
		buffer.imrgb = gdImageCreateFromPng(in);
	}
	else if (strcmp(ext, "jpeg") == 0)
	{
		in = fopen(strcat(temp, ".jpeg"), "rb");
		buffer.imrgb = gdImageCreateFromJpeg(in);
	}
	else if (strcmp(ext, "gif") == 0)
	{
		in = fopen(strcat(temp, ".gif"), "rb");
		buffer.imrgb = gdImageCreateFromGif(in);
	}
	else if (strcmp(ext, "tiff") == 0)
	{
		in = fopen(strcat(temp, ".tiff"), "rb");
		buffer.imrgb = gdImageCreateFromTiff(in);
	}
	

	buffer.img = buff;
	strcpy(buffer.name, buffName);
	strcpy(buffer.imageName, imageName);
	buffer.width = width;
	buffer.height = height;
	buffer.channels = ch;
	buffer.isLibgd = false;
	buffer.has_wht = 0;
	printf(KYEL "Done reading!\n"RESET);
	return buffer;
}
