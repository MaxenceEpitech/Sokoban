/*
** my_tab.c for my_tab in /home/Max/Documents/delivery/PSU_2016_my_sokoban/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu May 11 09:33:21 2017 fourrier maxence
** Last update Sat May 13 09:49:02 2017 fourrier maxence
*/

#include "my.h"

char		**get_tab(char *str)
{
  char		**tab;

  tab = malloc_tab(str);
  tab = create_tab(tab, str);
  return (tab);
}

char		**malloc_tab(char *str)
{
  char		**tab;
  int		i;
  int		line;

  i = 0;
  line = get_nb_line(str);
  if ((tab = malloc(sizeof(char*) * (line + 1))) == NULL)
    my_exit(EXIT_MALLOC, "Malloc error of tab (type char **).\n");
  while (i != line + 1)
    {
      if ((tab[i] = malloc(sizeof(char) *
			   (my_nstrlen(get_line(str, i + 1)) + 1))) == NULL)
	my_exit(EXIT_MALLOC, "Malloc error of tab (type char **).\n");
      i++;
    }
  return (tab);
}

int		contains_o(char **tab, t_list *list)
{
  while (list != NULL)
    {
      if (tab[list->y][list->x] == 'P'
	  || tab[list->y][list->x] == ' '
	  || tab[list->y][list->x] == 'O')
	return (1);
      list = list->next;
    }
  return (0);
}

int		get_max_width(char **tab)
{
  int		y;
  int		x;
  int		max;

  y = 0;
  max = 0;
  while (tab[y])
    {
      x = 0;
      while (tab[y][x])
	x++;
      if (x > max)
	max = x;
      y++;
    }
  return (max);
}

int		get_max_height(char **tab)
{
  int		y;

  y = 0;
  while (tab[y])
    y++;
  return (y);
}
