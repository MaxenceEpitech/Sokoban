/*
** my.h for include in /home/Max/Documents/delivery/PSU_2016_my_sokoban
** 
** Made by fourrier maxence
** Login   <maxence.fourrier@epitech.eu>
** 
** Started on  Sat May 13 10:23:30 2017 fourrier maxence
** Last update Wed May 17 10:20:46 2017 fourrier maxence
*/

#ifndef _MY_H_
# define _MY_H_

/*
** __ Include __
*/

# include <SFML/Graphics/RenderWindow.h>
# include <SFML/Graphics/Sprite.h>
# include <SFML/Graphics/Texture.h>
# include <SFML/Graphics/Image.h>

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <ncurses.h>

# include <math.h>


/*
** __ Define __
*/

# define EXIT_USAGE	84
# define EXIT_MALLOC	84
# define EXIT_READ	84

# define SCREEN_WIDTH	1250
# define SCREEN_HEIGHT	400

/*
** __ T_list __
*/

typedef struct		s_list
{
  int			x;
  int			y;
  struct s_list		*next;
}			t_list;

typedef struct		s_pos
{
  int			x;
  int			y;
}			t_pos;

typedef struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct		s_graph
{
  t_my_framebuffer	*framebuffer;
  sfRenderWindow	*window;
  sfSprite		*sprite;
  sfTexture		*texture;
  sfImage		*image;
}			t_graph;

typedef struct		s_sprite
{
  sfSprite		*floor;
  sfSprite		*player;
  sfSprite		*wall;
  sfSprite		*hole;
  sfSprite		*box;
}			t_sprite;

/*
** __ My sokoban BONUS __
*/

sfRenderWindow		*create_window(char *name, int width, int height);
sfUint8*		create_pixel_buffer(int width, int height);
t_my_framebuffer	*my_framebuffer_create(int width, int height);
void			my_put_pixel(t_my_framebuffer *framebuffer,
				     int y, int x, sfColor color);
t_graph			*print_tab(char **tab, t_graph *graph, t_sprite *all);
char			**change_map(char **tab, t_list *list, t_graph **graph, t_sprite *all);
t_graph			*init_all();
sfSprite* Charger_images(char* _sNom);

t_list	*create_list(char **tab);

t_pos	*get_pos_player(char **tab);

void	my_exit(int error, char *str);
void	print_map();
void	check_error(char **tab);
void	print_usage();
void	my_free_tab(char **tab);
void	my_free_list(t_list *list);

char	*my_nstrcpy(char *str);
char	*get_line_file(char *str);
char	*get_line(char *str, int i);

char	**go_down(t_pos *pos, char **tab);
char	**go_up(t_pos *pos, char **tab);
char	**go_right(t_pos *pos, char **tab);
char	**go_left(t_pos *pos, char **tab);
char	**rewrite_with_list(char **tab, t_list *list);
char	**get_tab(char *str);
char	**create_tab(char **tab, char *str);
char	**move_player(char **tab, int key);
char	**move_down(char **tab);
char	**move_up(char **tab);
char	**move_left(char **tab);
char	**move_right(char **tab);
char	**malloc_tab(char *str);

int	list_contain(t_list *list, int x, int y);
int	check_directions(char **tab, int y, int x);
int	box_blocked(char **tab, t_list *list);
int	game(char **tab, char *str, t_list *list);
int	get_max_height(char **tab);
int	get_max_width(char **tab);
int	check_player(char **tab);
int	contains_o(char **tab, t_list *list);
int	my_nstrlen(char *str);
int	get_nb_line(char *str);
int	free_return(int r, t_list *list, char **tab, t_graph *graph);

/*
** __ Lib __
*/

t_list	*my_rev_list(t_list *list);
t_list	*my_link_list(t_list *list, int x, int y);
int	my_list_size(t_list *begin);
int	my_list_is_empty(t_list *liste);

int	my_decimal_to_octal(int nb);
int	my_strlen(char *str);
int	my_str_who_bigger(char *s1, char *s2);
int	my_str_to_int(char *str);
int	my_strcmp(char *a, char *b);
int	my_swap(int *a, int *b);

void	my_putstr_error(char *str);
void	my_putnbr(int nb);
void	my_putchar(char a);
void	my_putstr(char *str);

char	*my_int_to_str(int nb);
char	*my_str_maj(char *str);
char	*my_decimal_to_hexa(int nb);
char	*supp_0(char *str);
char	*my_revstr(char *str);

#endif /* !__MY_H_ */
