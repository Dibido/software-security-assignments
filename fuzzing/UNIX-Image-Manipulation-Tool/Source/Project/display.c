// #include <sdl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <gtk/gtk.h>
// use sdl lib
// use qt lib

void destroy(void)
{
  gtk_main_quit();
}

void displayImage(char *img, int argc, char **argv)
{
  GtkWidget *window;
  GtkWidget *image;

  gtk_init(&argc, &argv);

  //input.img
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  image = gtk_image_new_from_file(img);

  gtk_signal_connect(GTK_OBJECT(window), "destroy",
                     GTK_SIGNAL_FUNC(destroy), NULL);

  gtk_container_add(GTK_CONTAINER(window), image);

  gtk_widget_show_all(window);

  gtk_main();
//	char text[25];
//	strcpy(text, "explorer.exe ");
//	strcat(text, img);
//	system(text);
	printf("\nPress enter to continue.\n");
	gets();
}
