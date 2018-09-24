/*
** game.c for game in /home/Max/Documents/delivery/PSU_2016_my_sokoban/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue May  9 15:13:15 2017 fourrier maxence
** Last update Sat May 13 15:33:18 2017 fourrier maxence
*/

#include "my.h"

void    my_exit(int error, char *str)
{
  my_putstr_error(str);
  exit(error);
}

char		**check_key(char **tab, int key, char *str)
{
  if (is_a_key(key))
    tab = move_player(tab, key);
  if (key == 32)
    tab = get_tab(str);
  if (key == 410)
    check_dim(tab);
  return (tab);
}

int		free_return(int r, t_list *list, char **tab)
{
  endwin();
  my_free_tab(tab);
  my_free_list(list);
  return (r);
}

int		game(char **tab, char *str, t_list *list)
{
  int		key;

  initscr();
  curs_set(0);
  keypad(stdscr, TRUE);
  check_dim(tab);
  print_tab(tab);
  refresh();
  while (contains_o(tab, list))
    {
      if (box_blocked(tab, list))
	return (free_return(1, list, tab));
      key = getch();
      tab = check_key(tab, key, str);
      clear();
      tab = rewrite_with_list(tab, list);
      print_tab(tab);
      refresh();
    }
  return (free_return(0, list, tab));
}
