/*
** print_tab.c for print_tab in /home/Max/Documents/delivery/PSU_2016_my_sokoban/bonus/graph
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat May 13 17:49:45 2017 fourrier maxence
** Last update Thu May 18 19:49:30 2017 fourrier maxence
*/

#include "my.h"

sfSprite* Charger_images(char* _sNom)
{
   sfSprite* sprite;
   sfTexture* texture;
   texture = sfTexture_createFromFile(_sNom, NULL);
   sprite = sfSprite_create();
   sfSprite_setTexture(sprite, texture, sfTrue);
   return sprite;
}


t_graph		*print_tab(char **tab, t_graph *graph, t_sprite *all)
{
  int		x;
  int		y;
  sfVector2f	a;

  x = 0;
  y = 0;
  while (tab[y])
    {
      x = 0;
      while (tab[y][x])
	{
	  a.x = 50 * x;
	  a.y = 50 * y;
	  if (tab[y][x] == ' ')
	    {
	      sfSprite_setPosition(all->floor, a);
	      sfRenderWindow_drawSprite(graph->window, all->floor, NULL);
 	    }
	  if (tab[y][x] == 'X')
	    {
	      sfSprite_setPosition(all->box, a);
	      sfRenderWindow_drawSprite(graph->window, all->box, NULL);
	    }
	  if (tab[y][x] == 'P')
	    {
	      sfSprite_setPosition(all->player, a);
	      sfRenderWindow_drawSprite(graph->window, all->player, NULL);
	    }
	  if (tab[y][x] == 'O')
	    {
	      sfSprite_setPosition(all->hole, a);
	      sfRenderWindow_drawSprite(graph->window, all->hole, NULL);
	    }
	  if (tab[y][x] == '#')
	    {
	      sfSprite_setPosition(all->wall, a);
	      sfRenderWindow_drawSprite(graph->window, all->wall, NULL);
	    }
	  x++;
	}
      y++;
    }
  sfTexture_updateFromPixels(graph->texture, graph->framebuffer->pixels,
                             SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  return (graph);
}
