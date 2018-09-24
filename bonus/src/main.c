/*
** main.c for main in /home/Max/Documents
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Tue Apr 25 13:13:22 2017 fourrier maxence
** Last update Sat May 13 11:30:47 2017 fourrier maxence
*/

#include "my.h"

int		main(int ac, char **av)
{
  char		**tab;
  t_list	*list;

  if (ac != 2)
    {
      my_putstr_error("Wrong use of my_sokoban.\n");
      my_putstr_error("To see Usage do : ./my_sokoban -h\n");
      return (84);
    }
  if (my_strcmp(av[1], "-h"))
    {
      print_usage(0);
      return (0);
    }
  tab = get_tab(av[1]);
  check_error(tab);
  list = create_list(tab);
  return (game(tab, av[1], list));
}
