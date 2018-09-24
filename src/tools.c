/*
** tools.c for tools in /home/Max/Documents/delivery/PSU_2016_my_sokoban/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu May 11 09:33:31 2017 fourrier maxence
** Last update Thu May 11 14:58:06 2017 fourrier maxence
*/

#include "my.h"

void		print_tab(char **tab)
{
  int		y;

  y = 0;
  while (tab[y])
    {
      mvprintw(y, 0, tab[y]);
      y++;
    }
}

int		is_a_key(int key)
{
  if (key == KEY_DOWN || key == KEY_LEFT
      || key == KEY_RIGHT || key == KEY_UP || key == 27)
    return (1);
  return (0);
}

void		print_usage()
{
  my_putstr("USAGE\n");
  my_putstr("           ./my_sokoban map\n\n");
  my_putstr("DESCRIPTION\n");
  my_putstr("           map   file representing the warehouse ");
  my_putstr("map, containing '#' for walls,\n           ");
  my_putstr("'P' for the player, 'X' for boxes and 'O' ");
  my_putstr("for storage locations.\n");
}

void		my_free_tab(char **tab)
{
  int		y;

  y = 0;
  while (tab[y])
    {
      free(tab[y]);
      y++;
    }
  free(tab);
}

void		my_free_list(t_list *list)
{
  t_list	*save;

  while (list != NULL)
    {
      save = list;
      list = list->next;
      free(save);
    }
  free(list);
}
