/*
** info_tab.c for info_tab in /home/Max/Documents/delivery/PSU_2016_my_sokoban/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed May 10 09:44:43 2017 fourrier maxence
** Last update Thu May 11 14:43:01 2017 fourrier maxence
*/

#include "my.h"

char		**go_down(t_pos *pos, char **tab)
{
  if (tab[pos->y + 1][pos->x] == 'X')
    {
      if (tab[pos->y + 2][pos->x] == ' '
	  || tab[pos->y + 2][pos->x] == 'O')
	{
	  tab[pos->y][pos->x] = ' ';
	  tab[pos->y + 1][pos->x] = 'P';
	  tab[pos->y + 2][pos->x] = 'X';
	  pos->x = pos->x + 1;
	}
    }
  else if (tab[pos->y + 1][pos->x] == ' '
	   || tab[pos->y + 1][pos->x] == 'O')
    {
      tab[pos->y][pos->x] = ' ';
      tab[pos->y + 1][pos->x] = 'P';
      pos->x = pos->x + 1;
    }
  return (tab);
}

char		**go_up(t_pos *pos, char **tab)
{
  if (tab[pos->y - 1][pos->x] == 'X')
    {
      if (tab[pos->y - 2][pos->x] == ' '
	  || tab[pos->y - 2][pos->x] == 'O')
	{
	  tab[pos->y][pos->x] = ' ';
	  tab[pos->y - 1][pos->x] = 'P';
	  tab[pos->y - 2][pos->x] = 'X';
	  pos->x = pos->x - 1;
	}
    }
  else if (tab[pos->y - 1][pos->x] == ' '
	   || tab[pos->y - 1][pos->x] == 'O')
    {
      tab[pos->y][pos->x] = ' ';
      tab[pos->y - 1][pos->x] = 'P';
      pos->x = pos->x - 1;
    }
  return (tab);
}

char		**go_left(t_pos *pos, char **tab)
{
  if (tab[pos->y][pos->x - 1] == 'X')
    {
      if (tab[pos->y][pos->x - 2] == ' '
	  || tab[pos->y][pos->x - 2] == 'O')
	{
	  tab[pos->y][pos->x] = ' ';
	  tab[pos->y][pos->x - 1] = 'P';
	  tab[pos->y][pos->x - 2] = 'X';
	  pos->y = pos->y - 1;
	}
    }
  else if (tab[pos->y][pos->x - 1] == ' '
	   || tab[pos->y][pos->x - 1] == 'O')
    {
      tab[pos->y][pos->x] = ' ';
      tab[pos->y][pos->x - 1] = 'P';
      pos->y = pos->y - 1;
    }
  return (tab);
}

char		**go_right(t_pos *pos, char **tab)
{
  if (tab[pos->y][pos->x + 1] == 'X')
    {
      if (tab[pos->y][pos->x + 2] == ' '
	  || tab[pos->y][pos->x + 2] == 'O')
	{
	  tab[pos->y][pos->x] = ' ';
	  tab[pos->y][pos->x + 1] = 'P';
	  tab[pos->y][pos->x + 2] = 'X';
	  pos->y = pos->y + 1;
	}
    }
  else if (tab[pos->y][pos->x + 1] == ' '
	   || tab[pos->y][pos->x + 1] == 'O')
    {
      tab[pos->y][pos->x] = ' ';
      tab[pos->y][pos->x + 1] = 'P';
      pos->y = pos->y + 1;
    }
  return (tab);
}

t_pos		*get_pos_player(char **tab)
{
  t_pos		*pos;
  int		i;
  int		j;

  if ((pos = malloc(sizeof(t_pos))) == NULL)
    my_exit(EXIT_MALLOC, "Malloc error of struct t_pos.\n");
  i = 0;
  j = 0;
  while (tab[j] != NULL)
    {
      i = 0;
      while (tab[j][i] != '\0')
        {
          if (tab[j][i] == 'P')
            {
	      pos->x = i;
	      pos->y = j;
	      return (pos);
            }
          i++;
        }
      j++;
    }
  return (NULL);
}
