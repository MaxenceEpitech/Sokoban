/*
** create_pixel_buffer.c for create_pixel_buffer in /home/Max/Documents/delivery/wireframe/lib/my
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed Apr 12 13:04:19 2017 fourrier maxence
** Last update Sat May 13 19:10:21 2017 fourrier maxence
*/

#include "my.h"

sfUint8*	create_pixel_buffer(int width, int height)
{
  int		i;
  sfUint8*	pixels;

  pixels = malloc(width * height * 4 * sizeof(*pixels));
  if (pixels == NULL)
    {
      exit(EXIT_FAILURE);
    }
  i = 0;
  while (i < width * height * 4)
    {
      pixels[i] = 0;
      i = i + 1;
    }
  return pixels;
}
