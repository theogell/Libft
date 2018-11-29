/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:21:38 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/14 19:50:02 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 546

#include "../libft/libft.h"

typedef struct		s_tetri
{
	uint16_t		tetrimino;
	char			index;
	int				height;
	int				width;
	struct s_tetri	*next;
}					t_tetri;

int					main(int ac, char **av);
void				main_solve(t_tetri *tetri_list);
int					valid_map(int i, char c);
int					ft_power(int nb, int power);
void				take_power(t_tetri **tetri_list, int i, int count);
int					ft_sqrt(uint16_t area);
uint16_t			top_left(uint16_t tetrimino);
int					valid_shape(uint16_t tetri);
void				do_list(t_tetri **tetri_list, int i);
int					len_list(t_tetri **tetri_list);
void				grid(char ***display_map);
void				fill(char ***map, t_tetri *tetri, int x, int y);
void				ft_display(char **map, uint16_t size);

#endif
