#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KRED  "\x1B[31m"
#define KMAG  "\x1B[35m"
#define RESET "\x1B[0m"

//Brightening routine can accept darken or brightne commandds based on bool choice
struct buff brighten(struct buff input, char* buffName, bool choice, int amount) {

	struct buff result;
	
	// Fill in info for buffer
	if (choice){
		strcpy(result.imageName, "brightened_");
	}
	else {
		strcpy(result.imageName, "darkened_");
	}
	strcat(result.imageName, input.imageName);
	strcpy(result.name, buffName);
	result.width = input.width;
	result.height = input.height;
	result.channels = input.channels;
	result.isLibgd = 0;

	size_t size = result.width * result.height * result.channels; // Allocate memory for result
	unsigned char* result_img = malloc(size);
	if (result_img == NULL) {
		printf(KRED"Error: "RESET"Unable to allocate memory for the image.\n");
		exit(1);
	}

	result.img = result_img;
	unsigned char *oldPtr = input.img, *newPtr = result.img;

	// Loop through image pixels and brighten or darken
	for (unsigned char *oldPtr = input.img, *newPtr = result.img; oldPtr != input.img + size; oldPtr += result.channels, newPtr += result.channels) {
		if (choice){
			for (int i = 0; i < 3; i++) {
				if ((*(oldPtr + i) + amount) > 255)
					*(newPtr + i) = (uint8_t)255;
				else if ((*(oldPtr + i) + amount) < 0)
					*(newPtr + i) = (uint8_t)0;
				else
					*(newPtr + i) = (uint8_t)(*(oldPtr + i) + amount);
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				if ((*(oldPtr + i) - amount) < 0)
					*(newPtr + i) = (uint8_t)0;
				else if ((*(oldPtr + i) + amount) > 255)
					*(newPtr + i) = (uint8_t)255;
				else
					*(newPtr + i) = (uint8_t)(*(oldPtr + i) - amount);
			}
		}
		
		if (result.channels == 4)
			*(newPtr + 3) = *(oldPtr + 3);

	}

	if (choice){
		printf(KYEL"\nBrightening completed into %s\n" RESET, result.imageName);
	}
	else {
		printf(KYEL"\nDarkening completed into %s\n"RESET, result.imageName);
	}

	return result;
}

