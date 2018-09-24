/*
** game_lost.c for game_lost in /home/Max/Documents/delivery/PSU_2016_my_sokoban/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat May 13 11:39:04 2017 fourrier maxence
** Last update Sat May 13 17:39:52 2017 fourrier maxence
*/

#include "my.h"

int		list_contain(t_list *list, int x, int y)
{
  while (list != NULL)
    {
      if (list->x == x && list->y == y)
	return (1);
      list = list->next;
    }
  return (0);
}

int             box_blocked(char **tab, t_list *list)
{
  int           x;
  int           y;
  int		m;

  m = 0;
  x = 0;
  y = 0;
  while (tab[y])
    {
      x = 0;
      while (tab[y][x])
        {
	  if (tab[y][x] == 'X'
	      && check_directions(tab, y, x))
	    m++;
          x++;
        }
      y++;
    }
  if (m == my_list_size(list))
    return (1);
  return (0);
}

int		check_directions(char **tab, int y, int x)
{
  if (tab[y - 1][x] == '#' && tab[y][x - 1] == '#')
    return (1);
  if (tab[y + 1][x] == '#' && tab[y][x - 1] == '#')
    return (1);
  if (tab[y + 1][x] == '#' && tab[y][x + 1] == '#')
    return (1);
  if (tab[y - 1][x] == '#' && tab[y][x + 1] == '#')
    return (1);
  return (0);
}

