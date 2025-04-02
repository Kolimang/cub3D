/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngharian <ngharian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:38:54 by ngharian          #+#    #+#             */
/*   Updated: 2025/04/02 14:19:15 by ngharian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <math.h>
# include <sys/time.h>
# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"

//contexte d'affichage
# define FOV 66
# define TXNO 6
# define TX_W 64
# define TX_H 64
# define TXSIZE 64
# define WIN_W 1920
# define WIN_H 1080
# define NAME "cub3D"
# define O_DOOR "img/door_open.xpm"
# define C_DOOR "img/door_closed.xpm"

//couleurs mini-map
# define WALL_C 0x00FFB3B3
# define FLOOR_C 0x00FFCCFF
# define PLAYER_C 0x00FF6666
# define DOOR_C 0x00A52A2A

//key_hook
enum
{
	ON_KEYPRESS = 2,
	ON_KEYRELEASE = 3,
	ON_DESTROY = 17,
	W_KEY = 119,
	Z_KEY = 122,
	A_KEY = 97,
	Q_KEY = 113,
	S_KEY = 115,
	D_KEY = 100,
	X_KEY = 120,
	F_KEY = 102,
	ESC_KEY = 65307,
	L_ARROW = 65361,
	R_ARROW = 65363,
	U_ARROW = 65362,
	D_ARROW = 65364,
	MOUSE_MOVE = 6
};

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_moves
{
	char	go_fwd;
	char	go_bckwd;
	char	strafe_l;
	char	strafe_r;
	char	rot_l;
	char	rot_r;
	int		mouse_rotation;
	int		mouse_move;
	int		prev_mouse_x;
	int		trigger;
	int		win_focus;
}	t_moves;

typedef struct s_rc
{
	// raycast stripe (screen x)
	int				x;
	// current map cell
	int				map_x;
	int				map_y;
	// ray position and direction
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	// ray calculations
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	// wall hit
	int				hit;
	int				side;
	// texture calculations
	double			wall_x;
	int				tx_x;
	int				tx_y;
	double			tx_step;
	double			tx_pos;
	// draw data
	int				tx_id;
	int				line_height;
	int				draw_start;
	int				draw_end;
	uint32_t		color;
	int				px_index;
	unsigned char	*px;
	int				door;
	int				door_x;
	int				door_y;
}	t_rc;

typedef struct s_info
{
	int			map_len;
	int			max_len;
	int			y_start;
	int			x_start;
	char		direction;
	int			in_map;
	char		**map;
	void		*mlx;
	void		*windw;
	void		*tx[TXNO];
	t_rc		*rc;
	t_data		img;
	t_data		txtr[5];
	t_moves		moves;
	char		*no_tx_path;
	char		*so_tx_path;
	char		*we_tx_path;
	char		*ea_tx_path;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	char		*f_color;
	char		*c_color;
	int			*c_color_clean;
	int			*f_color_clean;
	int			hitted_x;
	int			hitted_y;
	uint64_t	time;
	uint64_t	old_time;
	double		frame_time;
}	t_info;

//utils.c
void		free_print_exit_error(char *message, t_info *infos);
void		init_infos(t_info *infos);
void		ft_free(t_info *infos);

//checking.c
void		check_infos(t_info *info);
void		check_horizontal(t_info *infos, char **map, int i \
					, int start_trigger);
void		check_vertical(char **map, int i, int j, t_info *infos);

// parsing.c
void		parsing(t_info *infos, int fd);

// render.c
int			start_rendering(t_info *infos);
int			put_img(t_info *infos, int id, int x, int y);
int			on_destroy(t_info *infos);

// raycast.c
void		dda_algo(t_info *infos, t_rc *rc);
void		get_perp_wall_dist(t_info *infos);
void		get_stripe_data(t_info *infos);
int			raycast(t_info *infos, t_rc *rc);

// raycast_utils.c
void		get_ray_pos_and_dir(t_info *infos);
void		get_current_map_cell(t_info *infos);
void		get_delta_dist(t_info *infos);
void		get_side_dist(t_info *infos);

//key_press_and_release.c
int			on_keypress(int key, t_info *infos);
int			on_keyrelease(int key, t_info *infos);

// move.c
void		rotate_r(t_info *infos);
void		rotate_l(t_info *infos);
int			mouse_rotate(t_info *infos, int x);
int			mouse_moved(int x, int y, t_info *infos);
int			move_player(t_info *infos);
int			mouse_focus(t_info *infos);

// draw.c
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		select_texture(t_info *infos);
void		get_texture_coord(t_info *infos);
void		fill_env_color(t_info *infos, int start, int end, int *color);
void		fill_img(t_info *infos);

// render_utils.c
void		set_textures(t_info *infos);
void		set_mlx_screen_img(t_info *infos);
uint64_t	get_time_ms(void);
void		draw_minimap(t_info *infos, int i);

//doors.c
void		check_door(t_info *infos);
void		open_close_door(t_info *infos);
void		get_door_texture(t_info *infos, t_rc *rc);

#endif