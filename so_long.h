/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oimzilen <oimzilen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:24:56 by oimzilen          #+#    #+#             */
/*   Updated: 2025/03/16 01:31:12 by oimzilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define USAGE 1
# define INVALID 2
# define OP_FAIL 3
# define EMPTY 4
# define MAP_GAP 5
# define SYMBOL 6
# define RECT 7
# define PARAMS 8
# define MALLOC_F 9
# define PATH_BLOCKED 10
# define IMAGE 11
# define BIG_MAP 12

# define PIXELS 96
# define TITLE "ESCAPE MINECRAFT"
# define GRASS "textures/simple.xpm"
# define COBBLE "textures/cobble_block.xpm"
# define COBBLE_T "textures/cobble_block_top.xpm"
# define CATR "textures/cat_right.xpm"
# define CATL "textures/cat_left.xpm"
# define CATU "textures/cat_up.xpm"
# define CATD "textures/cat_down.xpm"
# define FOOD "textures/food.xpm"
# define EXITC "textures/exit_closed.xpm"
# define EXITO "textures/exit_open.xpm"

# define VALID_SYMBOL 0
# define INVALID_S -1

# define ESC 65307
# define RIGHT 65363
# define LEFT 65361
# define UP 65362
# define DOWN 65364

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include ".mlx_linux/mlx.h"

typedef struct s_blocks
{
	void	*grass;
	void	*cobble;
	void	*cobble_t;
	void	*catr;
	void	*catl;
	void	*catu;
	void	*catd;
	void	*food;
	void	*exit_c;
	void	*exit_o;
}	t_blocks;

typedef struct s_player
{
	int	p_x;
	int	p_y;
	int	old_pos_x;
	int	old_pos_y;
}	t_player;

typedef struct s_game
{
	int			food;
	int			pxl;
	char		**map;
	t_blocks	blocks;
	t_player	player;
	void		*mlx;
	void		*win;
	int			map_w;
	int			map_h;
	int			blocks_x;
	int			blocks_y;
	int			door_x;
	int			door_y;
	int			moves;
}	t_game;

typedef struct s_parse
{
	int	x;
	int	y;
	int	x_max;
	int	y_max;
	int	p_count;
	int	c_count;
	int	e_count;
	int	player_x;
	int	player_y;
	int	found_c;
	int	found_e;
	int	door_x;
	int	door_y;
}	t_parse;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

void	input_check(int argc, char **av);
void	primary_parse(char *map_name, t_parse *parse, int fd);
void	process_map(int fd, t_parse *parse);
bool	cmp_symbol(char c);
void	ft_bzero(void *s, size_t n);
void	count_params(char symbol, t_parse *parse);
void	width_check(char *row, int fd, t_parse *parse);
void	params_check(t_parse *parse);
char	*cut_row(char *row_uncut);

void	parse_path(char *map_name, t_parse *parse);
char	**grid_dup(char **grid, t_parse *parse);
void	coll(char **grid, t_pos p, t_parse *prs);

void	load_game(char *map_name, t_parse *parse, int fd);
char	**create_2d_grid(int fd, t_parse *parse);
void	fill_map(t_game *game);
void	game_loop(t_game *game);
void	update_map(t_game *game);
void	update_player(t_game *game, int *flag);
void	free_grid(char **grid);
void	destroy_images(t_game *game);
void	clean_up(t_game *game);
char	*ft_itoa(int n);

void	player_fill(t_game *game, int x, int y);
void	update_blocks(t_game *game, int x, int y);
void	player_dir(t_game *game);
void	fill_blocks(t_game *g, int x, int y);
void	render_player(t_game *game, int x, int y);
void	render_exit(t_game *game, int x, int y);
void	update_y_dir(t_game *game);
bool	is_door(t_game *game, int x, int y);
void	destroy_images(t_game *game);

void	print_error(int error);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);

#endif //SO_LONG_H