/*
** tools.c for tools in /home/Max/Documents/delivery/PSU_2016_my_sokoban/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu May 11 09:33:31 2017 fourrier maxence
** Last update Sat May 13 18:08:04 2017 fourrier maxence
*/

#include "my.h"

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
