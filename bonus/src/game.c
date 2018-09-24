/*
** game.c for game in /home/Max/Documents/delivery/PSU_2016_my_sokoban/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue May  9 15:13:15 2017 fourrier maxence
** Last update Thu May 18 11:18:34 2017 fourrier maxence
*/

#include "my.h"

void    my_exit(int error, char *str)
{
  my_putstr_error(str);
  exit(error);
}

int		free_return(int r, t_list *list, char **tab,
			    t_graph *graph)
{
  if (r != 1)
    my_free_tab(tab);
  my_free_list(list);
  sfRenderWindow_destroy(graph->window);
  //sfSprite_destroy(graph->sprite);
  free(graph);
  return (r);
}

char		**change_map(char **tab, t_list *list, t_graph **graph, t_sprite *all)
{
  if (box_blocked(tab, list))
    return (NULL);
  tab = rewrite_with_list(tab, list);
  sfRenderWindow_clear((*graph)->window, sfBlack);
  *graph = print_tab(tab, *graph, all);
  sfRenderWindow_display((*graph)->window);
  return (tab);
}

t_graph			*init_all()
{
  t_graph		*graph;

  if ((graph = malloc(sizeof(t_graph))) == NULL)
    my_exit(EXIT_MALLOC, "Malloc error of t_graph.\n");
  graph->window = create_window("My sokoban", SCREEN_WIDTH, SCREEN_HEIGHT);
  if (!graph->window)
    my_exit(EXIT_MALLOC, "Malloc error of windows.\n");
  //graph->sprite = sfSprite_create();
  graph->texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  //sfSprite_setTexture(graph->sprite, graph->texture, sfTrue);
  graph->framebuffer = my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  return (graph);
}

int			game(char **tab, char *str, t_list *list)
{  
  t_graph	*graph;
  sfEvent	event;
  t_sprite	*all;

  all = malloc(sizeof(t_sprite));
  all->floor = Charger_images("floor_.jpg");;
  all->wall = Charger_images("wall_.jpg");;
  all->hole = Charger_images("hole_.jpg");;
  all->box = Charger_images("caisse_.jpg");;
  all->player = Charger_images("player.jpg");;
  graph = init_all();
  tab = get_tab(str);
  graph = print_tab(tab, graph, all);
  while (contains_o(tab, list) && sfRenderWindow_isOpen(graph->window))
    {
      while (sfRenderWindow_pollEvent(graph->window, &event))
        {
	  if (event.type == sfEvtClosed)
	    sfRenderWindow_close(graph->window);
	  if (event.type == sfEvtKeyPressed)
	    {
	      if (event.key.code == sfKeyDown)
		tab = move_player(tab, 1);
	      if (event.key.code == sfKeyUp)
		tab = move_player(tab, 2);
	      if (event.key.code == sfKeyLeft)
		tab = move_player(tab, 3);	
	      if (event.key.code == sfKeyRight)
		tab = move_player(tab, 4);
	      if (event.key.code == sfKeySpace)
		tab = get_tab(str);
	    }
	}
      if ((tab = change_map(tab, list, &graph, all)) == NULL)
	{
	  sfSprite_destroy(all->floor);
	  sfSprite_destroy(all->wall);
	  sfSprite_destroy(all->box);
	  sfSprite_destroy(all->player);
	  sfSprite_destroy(all->hole);
	  free(all);
	  return (free_return(1, list, tab, graph));
	}
    }
  sfSprite_destroy(all->floor);
  sfSprite_destroy(all->wall);
  sfSprite_destroy(all->box);
  sfSprite_destroy(all->player);
  sfSprite_destroy(all->hole);
  free(all);
  return (free_return(0, list, tab, graph));
}
