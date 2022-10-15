#include "libgd/src/gd.h"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KRED  "\x1B[31m"
#define KMAG  "\x1B[35m"
#define RESET "\x1B[0m"

struct buff detectEdge(char *orientation, char *type, struct buff image)
{
    float kirsch_mask_horiz[3][3] = {
        {5, 5, 5},
        {-3, 0, -3},
        {-3, -3, -3}};
    float kirsch_mask_vert[3][3] = {
        {5, -3, -3},
        {5, 0, -3},
        {5, -3, -3}};
    float prewitt_mask_vert[3][3] = {
        {1, 0, -1},
        {1, 0, -1},
        {1, 0, -1}};
    float prewitt_mask_horiz[3][3] = {
        {1, 1, 1},
        {0, 0, 0},
        {-1, -1, -1}};
    float sobel_mask_horiz[3][3] = {
        {1, 0, -1},
        {2, 0, -2},
        {1, 0, -1}};
    float sobel_mask_vert[3][3] = {
        {1, 2, 1},
        {0, 0, 0},
        {-1, -2, -1}};
    

    gdImagePtr src = image.imrgb, copy;
    gdImageGrayScale(src);
    if (strcmp(type, "kirsch") == 0)
    {
        struct buff temp = image;
        if (strcmp(orientation, "vertical") == 0)
        {
            gdImageConvolution(src, kirsch_mask_vert, 1.0, 0.0);
            temp.imrgb = src;
        }
        else if (strcmp(orientation, "horizontal") == 0)
        {
            gdImageConvolution(src, kirsch_mask_horiz, 1.0, 0.0);
            temp.imrgb = src;
        }
        else if (strcmp(orientation, "combined") == 0)
        {
            struct buff temp1 = detectEdge("vertical", type, image);
			struct buff temp2 = detectEdge("horizontal", type, image);
			temp.imrgb = combine(temp1, temp2).imrgb;
        }
        char name[50];
        strcpy(name, "kirsch-");
        strcat(name, orientation);
        strcat(name, "-");
        strcat(name, temp.imageName);
        strcpy(temp.imageName, name);
        return temp;
    }
    else if (strcmp(type, "prewitt") == 0)
    {
        struct buff temp = image;
        if (strcmp(orientation, "vertical") == 0)
        {
            gdImageConvolution(src, prewitt_mask_vert, 1.0, 0.0);
            temp.imrgb = src;
        }
        else if (strcmp(orientation, "horizontal") == 0)
        {
            gdImageConvolution(src, prewitt_mask_horiz, 1.0, 0.0);
            temp.imrgb = src;
        }
        else if (strcmp(orientation, "combined") == 0)
        {
            struct buff temp1 = detectEdge("vertical", type, image);
			struct buff temp2 = detectEdge("horizontal", type, image);
			temp.imrgb = combine(temp1, temp2).imrgb;
        }
        char name[50];
        strcpy(name, "prewitt-");
        strcat(name, orientation);
        strcat(name, "-");
        strcat(name, temp.imageName);
        strcpy(temp.imageName, name);
        return temp;
    }
    else if (strcmp(type, "sobel") == 0)
    {
        struct buff temp = image;
        if (strcmp(orientation, "vertical") == 0)
        {
            gdImageConvolution(src, sobel_mask_vert, 1.0, 0.0);
            temp.imrgb = src;
        }
        else if (strcmp(orientation, "horizontal") == 0)
        {
            gdImageConvolution(src, sobel_mask_horiz, 1.0, 0.0);
            temp.imrgb = src;
        }
        else if (strcmp(orientation, "combined") == 0)
        {
           struct buff temp1 = detectEdge("vertical", type, image);
			struct buff temp2 = detectEdge("horizontal", type, image);
			temp.imrgb = combine(temp1, temp2).imrgb;
        }
        char name[50];
        strcpy(name, "sobel-");
        strcat(name, orientation);
        strcat(name, "-");
        strcat(name, temp.imageName);
        strcpy(temp.imageName, name);
        return temp;
    }
    else
    {
        printf(KRED "Error:"RESET" edge detection method not supported.\n\n");
    }
}

struct buff convolve3X3(struct buff buffer, char* row1, char* row2, char* row3 ){

    struct buff temp;
    temp = buffer;    

    char input[100];
    printf("Enter name of the output buffer: \n");
    gets(input);   
    strcpy(temp.name, input);

    char Row1[20], Row2[20], Row3[20];

    for(int i = 0; i < strlen(row1)-1; i++){
        Row1[i] = row1[i+1];
    }
    Row1[strlen(row1)-1] = '\0';

    for(int i = 0; i < strlen(row2)-1; i++){
        Row2[i] = row2[i+1];
    }
    Row2[strlen(row2)-1] = '\0';

    for(int i = 0; i < strlen(row3)-1; i++){
        Row3[i] = row3[i+1];
    }
    Row3[strlen(row3)-1] = '\0';

    // Row 1
    char* x1y1 = strtok(Row1, " ");
    char* x2y1 = strtok(NULL, " ");
    char* x3y1 = strtok(NULL, " ");

    float X1Y1;
    sscanf(x1y1, "%f", &X1Y1);

    float X2Y1;
    sscanf(x2y1, "%f", &X2Y1);

    float X3Y1;
    sscanf(x3y1, "%f", &X3Y1);

    // Row 2
    char* x1y2 = strtok(Row2, " ");
    char* x2y2 = strtok(NULL, " ");
    char* x3y2 = strtok(NULL, " ");

    float X1Y2;
    sscanf(x1y2, "%f", &X1Y2);

    float X2Y2;
    sscanf(x2y2, "%f", &X2Y2);

    float X3Y2;
    sscanf(x3y2, "%f", &X3Y2);

    // Row 3
    char* x1y3 = strtok(Row3, " ");
    char* x2y3 = strtok(NULL, " ");
    char* x3y3 = strtok(NULL, " ");

    float X1Y3;
    sscanf(x1y3, "%f", &X1Y3);

    float X2Y3;
    sscanf(x2y3, "%f", &X2Y3);

    float X3Y3;
    sscanf(x3y3, "%f", &X3Y3);   

    float mask[3][3] = {
        {X1Y1, X2Y1, X3Y1},
        {X1Y2, X2Y2, X3Y2},
        {X1Y3, X2Y3, X3Y3}
    };
   
    gdImageConvolution(temp.imrgb, mask, 1.0, 0.0);

    char name[50];
    strcat(name, "convolve3x3");
    strcat(name, "-");
    strcat(name, temp.imageName);
    strcpy(temp.imageName, name);
    temp.isLibgd = 1;
    return temp;
}
