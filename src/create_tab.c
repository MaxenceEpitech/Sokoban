/*
** create_tab.c for create_tab in /home/Max/Documents/delivery/PSU_2016_my_sokoban/src
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Wed May 10 09:32:19 2017 fourrier maxence
** Last update Sat May 13 19:48:51 2017 fourrier maxence
*/

#include "my.h"

char		**create_tab(char **tab, char *str)
{
  int		i;
  int		taille;

  i = 0;
  taille = get_nb_line(str);
  while (i != taille)
    {
      tab[i] = my_nstrcpy(get_line(str, i + 1));
      i++;
    }
  tab[i] = '\0';
  return (tab);
}

char		*my_nstrcpy(char *str)
{
  char		*new;
  int		i;

  i = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    my_exit(EXIT_MALLOC, "Malloc error of new (type char *).\n");
  while (str[i] != '\0')
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  free(str);
  return (new);
}

char		*get_line(char *str, int i)
{
  FILE		*fp;
  char		*line;
  size_t	len;
  int		y;

  len = 0;
  line = NULL;
  y = 0;
  if ((fp = fopen(str, "r")) == NULL)
    my_exit(EXIT_MALLOC, "Open error of file.\n");
  while (y != i)
    {
      getline(&line, &len, fp);
      y++;
    }
  fclose(fp);
  return (line);
}

int		get_nb_line(char *str)
{
  FILE		*fp;
  char		*line;
  size_t	len;
  ssize_t	read;
  int		i;

  len = 0;
  line = NULL;
  i = 0;
  if ((fp = fopen(str, "r")) == NULL)
    my_exit(EXIT_MALLOC, "Open error of file.\n");
  while ((read = getline(&line, &len, fp)) != -1)
    i++;
  free(line);
  fclose(fp);
  return (i);
}

int		my_nstrlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
