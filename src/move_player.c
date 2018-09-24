/*
** move_player.c for move_player in /home/Max/Documents/delivery/PSU_2016_my_sokoban/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue May  9 15:17:47 2017 fourrier maxence
** Last update Thu May 11 14:54:57 2017 fourrier maxence
*/

#include "my.h"

char		**move_player(char **tab, int key)
{
  if (key == KEY_DOWN)
    tab = move_down(tab);
  if (key == KEY_UP)
    tab = move_up(tab);
  if (key == KEY_LEFT)
    tab = move_left(tab);
  if (key == KEY_RIGHT)
    tab = move_right(tab);
  return (tab);
}

char		**move_down(char **tab)
{
  t_pos		*pos;

  pos = get_pos_player(tab);
  tab = go_down(pos, tab);
  free(pos);
  return (tab);
}

char		**move_up(char **tab)
{
  t_pos		*pos;

  pos = get_pos_player(tab);
  tab = go_up(pos, tab);
  free(pos);
  return (tab);
}

char		**move_left(char **tab)
{
  t_pos		*pos;

  pos = get_pos_player(tab);
  tab = go_left(pos, tab);
  free(pos);
  return (tab);
}

char		**move_right(char **tab)
{
  t_pos		*pos;

  pos = get_pos_player(tab);
  tab = go_right(pos, tab);
  free(pos);
  return (tab);
}
