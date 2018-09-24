/*
** my_link_list.c for my_link_list in /home/maxence.fourrier/lib/my
** 
** Made by Maxence Fourrier
** Login   <maxence.fourrier@epitech.net>
** 
** Started on  Tue Mar 14 23:20:05 2017 Maxence Fourrier
** Last update Thu May 11 09:46:26 2017 fourrier maxence
*/

#include "my.h"

t_list		*my_link_list(t_list *list, int x, int y)
{
  t_list	*tmp;

  tmp = malloc(sizeof(t_list));
  if (tmp)
    {
      tmp->x = x;
      tmp->y = y;
      tmp->next = list;
    }
  return (tmp);
}
