/*
** create_list.c for create_list in /home/Max/Documents/delivery/PSU_2016_my_sokoban/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Thu May 11 09:40:28 2017 fourrier maxence
** Last update Thu May 11 09:57:31 2017 fourrier maxence
*/

#include "my.h"

t_list		*create_list(char **tab)
{
  t_list	*list;
  int		x;
  int		y;

  y = 0;
  if ((list = malloc(sizeof(t_list))) == NULL)
    my_exit(EXIT_MALLOC, "Malloc error of t_list.\n");
  list = NULL;
  while (tab[y])
    {
      x = 0;
      while (tab[y][x])
	{
	  if (tab[y][x] == 'O')
	    {
	      list = my_link_list(list, x, y);
	    }
	  x++;
	}
      y++;
    }
  return (list);
}

char		**rewrite_with_list(char **tab, t_list *list)
{
  while (list != NULL)
    {
      if (tab[list->y][list->x] == ' ')
	{
	  tab[list->y][list->x] = 'O';
	}
      list = list->next;
    }
  return (tab);
}
