#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libgd/src/gd.h"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KRED "\x1B[31m"
#define KMAG "\x1B[35m"
#define RESET "\x1B[0m"

int compare_doubles(const void* a, const void* b);

struct buff histogramEqualization(struct buff a, char* buffName)
{
	// gdImageGrayScale(a.imrgb);
	/*calculate frequencies & get max grey level value*/
	struct buff temp;
	int max = 0;
	int freq[256];
	int msize = a.width * a.height * a.channels;
	strcpy(temp.imageName, a.imageName);
	strcat(strcpy(temp.imageName, a.name), "-histEQ");
	temp.img = malloc(msize);
	temp.channels = a.channels;
	temp.width = a.width;
	temp.height = a.height;
	
	int has_wht = 0;
	for (int i = 0; i < 256; i++)
	{
		freq[i] = 0;
	}
	if (a.channels > 2 && a.isLibgd == 1) {
		//printf("LibGD Mode\n");
		// Color version of histEQ.
		// This distorts colors heavily.
		temp.isLibgd = 1;
		for (int r = 0; r < temp.width; r++)
		{
			for (int c = 0; c < temp.height; c++)
			{
				int pos = gdImageGetPixel(temp.imrgb, r, c);
				int grey = (gdTrueColorGetRed(pos) + gdTrueColorGetGreen(pos) + gdTrueColorGetBlue(pos)) / 3;
				freq[grey]++;
				if (grey > max)
					max = grey;
			}
		}

		//printf("frequency list \n");
		//for (int i = 0; i < 256; i++) {
		//    printf("%d: %d\n", i, freq[i]);
		//}

		/*frequency divided by total num of pixels*/
		//printf("pdf list \n");
		int total = temp.height * temp.width;
		float pdf[256];
		int check = 0;
		for (int i = 0; i < 256; i++)
		{
			pdf[i] = (float)freq[i] / (float)total;
			//printf("%d: %f\n", i, pdf[i]);
			check += freq[i];
		}

		// printf("check: %d \ntotal: %d\n\n", check, total);

		//printf("cdf\n");

		/*cummulative distribution function*/
		float cdf[256];
		for (int i = 0; i < 256; i++)
		{
			if (i != 0)
				cdf[i] = cdf[i - 1] + pdf[i];
			else
				cdf[i] = pdf[i];
			//printf("%f\n", cdf[i]);
		}

		//printf("map\n");

		//cdf * max grey level
		int histmap[256];
		for (int i = 0; i < 256; i++)
		{
			histmap[i] = max * cdf[i];
			//printf("%d\n", histmap[i]);
		}

		/*map orginial*/

		gdImagePtr out = gdImageCreateTrueColor(temp.width, temp.height);

		for (int r = 0; r < temp.width; r++)
		{
			for (int c = 0; c < temp.height; c++)
			{
				int pos = gdImageGetPixel(temp.imrgb, r, c);
				int red = gdTrueColorGetRed(pos);
				int green = gdTrueColorGetGreen(pos);
				int blue = gdTrueColorGetBlue(pos);
				int grey = (red + green + blue) / 3;
				int numerator = histmap[grey];
				float ratio;
				if (grey == 0)
				{
					ratio = 0;
				}
				else
				{
					ratio = (float)numerator / (float)grey;
				}
				int newRed = ratio * red;
				int newBlue = ratio * blue;
				int newGreen = ratio * green;
				int color = gdImageColorExact(out, newRed, newGreen, newBlue);
				if (color == -1) {
					gdImageSetPixel(out, r, c, gdImageColorAllocate(out, newRed, newGreen, newBlue));
					//color = gdImageColorAllocate(temp.imrgb, newRed, newGreen, newBlue);

					//printf("color = %d\n", color);

				}
				else {
					gdImageSetPixel(out, r, c, gdImageColorExact(out, newRed, newGreen, newBlue));
				}

				//gdImageColorDeallocate(temp.imrgb, color);
			}
		}
		temp.isLibgd = 1;
		char name[50];
		strcpy(name, "HistEQ-");
		strcat(name, a.imageName);
		strcpy(temp.imageName, name);
		temp.wht = a.wht;
		temp.has_wht = a.has_wht;
		temp.whtimg = a.whtimg;
		memcpy(temp.img, a.img, msize);
		temp.imrgb = out;
		temp.isLibgd = 1;

		printf(KYEL "Done equalizing!\n" RESET);

	}
	else if (a.channels <= 2) {
		//printf("Gray Mode\n");
		// One channel version, grayscale image.
		// This distorts colors heavily.
		int size = a.height * a.width * a.channels;
		
		
		for (int c = 0; c < size; c += a.channels)
		{
			int grey = (a.img[c]);
			freq[grey]++;
			if (grey > max)
				max = grey;
		}

		//printf("frequency list \n");
		//for (int i = 0; i < 256; i++) {
		//    printf("%d: %d\n", i, freq[i]);
		//}

		/*frequency divided by total num of pixels*/
		//printf("pdf list \n");
		int total = temp.height * temp.width;
		float pdf[256];
		int check = 0;
		for (int i = 0; i < 256; i++)
		{
			pdf[i] = (float)freq[i] / (float)total;
			//printf("%d: %f\n", i, pdf[i]);
			check += freq[i];
		}

		// printf("check: %d \ntotal: %d\n\n", check, total);

		//printf("cdf\n");

		/*cummulative distribution function*/
		float cdf[256];
		for (int i = 0; i < 256; i++)
		{
			if (i != 0)
				cdf[i] = cdf[i - 1] + pdf[i];
			else
				cdf[i] = pdf[i];
			//printf("%f\n", cdf[i]);
		}

		//printf("map\n");

		//cdf * max grey level
		int histmap[256];
		for (int i = 0; i < 256; i++)
		{
			histmap[i] = max * cdf[i];
			//printf("%d\n", histmap[i]);
		}

		/*map orginial*/

		
		for (int c = 0; c < size; c += a.channels)
		{
			int grey = a.img[c];
			int numerator = histmap[grey];
			float ratio;
			if (grey == 0)
			{
				printf("gray == 0\n");
				ratio = 0;
			}
			else
			{
				ratio = ((float)numerator) / ((float)grey);
			}
			int old = temp.img[c];
			int newGrey = ratio * grey;
			
			temp.img[c] = newGrey;
			if (temp.img[c] != old) {
				printf("Changed a pixel from %d to %d\n", old, temp.img[c]);
			}
		}

		temp.isLibgd = 0;
		char name[50];
		strcpy(name, "HistEQ-");
		strcat(name, a.imageName);
		strcpy(temp.imageName, name);
		temp.isLibgd = 0;
		temp.wht = a.wht;
		temp.has_wht = a.has_wht;
		temp.whtimg = a.whtimg;
		printf(KYEL "Done equalizing!\n" RESET);
		return temp;
	}
	else if (a.channels > 2) {
		//printf("RGB Mode\n");
		// Color version of histEQ without imrgb.
		// This distorts colors heavily.
		int size = a.height * a.width * a.channels;

		for (int c = 0; c < size; c += a.channels)
		{
			int grey = ((int)a.img[c] + (int)a.img[c + 1] + (int)a.img[c + 2]) / 3;
			freq[grey]++;
			if (grey > max)
				max = grey;
		}


		//printf("frequency list \n");
		//for (int i = 0; i < 256; i++) {
		//    printf("%d: %d\n", i, freq[i]);
		//}

		/*frequency divided by total num of pixels*/
		//printf("pdf list \n");
		int total = temp.height * temp.width;
		float pdf[256];
		int check = 0;
		for (int i = 0; i < 256; i++)
		{
			pdf[i] = (float)freq[i] / (float)total;
			//printf("%d: %f\n", i, pdf[i]);
			check += freq[i];
		}

		// printf("check: %d \ntotal: %d\n\n", check, total);

		//printf("cdf\n");

		/*cummulative distribution function*/
		float cdf[256];
		for (int i = 0; i < 256; i++)
		{
			if (i != 0)
				cdf[i] = cdf[i - 1] + pdf[i];
			else
				cdf[i] = pdf[i];
			//printf("%f\n", cdf[i]);
		}

		//printf("map\n");

		//cdf * max grey level
		int histmap[256];
		for (int i = 0; i < 256; i++)
		{
			histmap[i] = max * cdf[i];
			//printf("%d\n", histmap[i]);
		}

		/*map orginial*/


		for (int c = 0; c < size; c += a.channels)
		{
			int red = a.img[c];
			int green = a.img[c + 1];
			int blue = a.img[c + 2];
			int grey = (red + green + blue) / 3;
			int numerator = histmap[grey];
			float ratio;
			if (grey == 0)
			{
				ratio = 0;
			}
			else
			{
				ratio = (float)numerator / (float)grey;
			}
			int newRed = ratio * red;
			int newBlue = ratio * blue;
			int newGreen = ratio * green;

			if (newRed > 255 || newBlue > 255 || newGreen > 255) {
				if(newRed > 255)
					temp.img[c] = red;
				else
					temp.img[c] = newRed;
				if (newBlue > 255)
					temp.img[c + 2] = blue;
				else
					temp.img[c + 2] = newBlue;
				if (newGreen > 255)
					temp.img[c + 1] = green;
				else
					temp.img[c + 1] = newGreen;
			}
			else {
				temp.img[c] = newRed;
				temp.img[c + 1] = newGreen;
				temp.img[c + 2] = newBlue;
			}
			
		}

		temp.isLibgd = 0;
		char name[50];
		strcpy(name, "HistEQ-");
		strcat(name, a.imageName);
		strcpy(temp.imageName, name);
		temp.isLibgd = 0;
		temp.wht = a.wht;
		temp.has_wht = a.has_wht;
		temp.whtimg = a.whtimg;
		printf(KYEL "Done equalizing!\n" RESET);

	}

	return temp;
}

void whtHistEQ(struct buff *buffer) {
	int size = buffer->width * buffer->height * buffer->channels;
	int bin = 0;
	double freq[256];
	int dim = buffer->width * buffer->height;
	double* grays = malloc(buffer->width * buffer->height * sizeof(double));
	buffer->whtimg = malloc(buffer->width * buffer->height * buffer->channels);
	//printf("test 1\n");
	if (buffer->channels > 2) {
		for (int i = 0; i < dim; i+= buffer->channels) {
			grays[i] = (double)(buffer->wht[i] + buffer->wht[1 + i] + buffer->wht[2 + i]) / 3;
			if (grays[i] != 0) {
				//printf("%f\n", grays[i]);
			}
		}
	}
	else {
		for (int i = 0; i < dim; i+=buffer->channels) {
			grays[i] = (double)(buffer->wht[i]);
		}
	}
	//printf("test 2\n");
	qsort(grays, dim, sizeof(double), compare_doubles);
	//printf("test 3\n");

	for (int i = 0; i < size; i++) {
		buffer->whtimg[i] = 0;
	}

	if (dim >= 256) {
		bin = dim / 256;
		for (int i = 0; i < 256; i += 1) {
			freq[i] = grays[bin * i];
			//printf("%f\n", freq[i]);
		}
		if (buffer->channels > 2) {
			for (int i = 0; i < dim * buffer->channels; i += buffer->channels) {
				double test = (double)(buffer->wht[i] + buffer->wht[1 + i] + buffer->wht[2 + i]) / 3;
				for (int j = 0; j < 256; j++) {
					if (j == 255) {
						buffer->whtimg[i] = 255;
						buffer->whtimg[i + 1] = 255;
						buffer->whtimg[i + 2] = 255;
					}
					else if (test >= freq[j] && test < freq[j + 1]) {
						buffer->whtimg[i] = j;
						buffer->whtimg[i + 1] = j;
						buffer->whtimg[i + 2] = j;
						break;
					}
					
				}
			}
		}
		else {
			for (int i = 0; i < dim * buffer->channels; i += buffer->channels) {
				double test = (double)(buffer->wht[i]);
				for (int j = 0; j < 256; j++) {
					if (j == 255) {
						buffer->whtimg[i] = 255;
					}
					else if (test >= freq[j] && test < freq[j + 1]) {
						buffer->whtimg[i] = j;
						break;
					}
				}
			}
		}
		
	}
	else {
		bin = 256 / (dim - 1);
		for (int i = 0; i < size; i++) {
			freq[i] = i * bin;
		}
		for (int i = 0; i < dim * buffer->channels; i += buffer->channels) {
			double test;
			if (buffer->channels > 2) {
				test = (double)(buffer->wht[i] + buffer->wht[1 + i] + buffer->wht[2 + i]) / 3;
			}
			else {
				test = (double)(buffer->wht[i]);
			}
			for (int j = 0; j < dim * buffer->channels; j++) {
				if (grays[j] == test) {
					buffer->whtimg[i] = freq[j];
					break;
				}
			}
		}
	}

	return;
}

//https://en.cppreference.com/w/c/algorithm/qsort
int compare_doubles(const void* a, const void* b)
{
	double arg1 = *(const double*)a;
	double arg2 = *(const double*)b;

	if (arg1 < arg2) return -1;
	if (arg1 > arg2) return 1;
	return 0;

	// return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
	// return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}