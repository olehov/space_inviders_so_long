/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogrativ <ogrativ@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:44:30 by ogrativ           #+#    #+#             */
/*   Updated: 2024/08/03 14:36:31 by ogrativ          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_UTILS_H
# define FT_MAP_UTILS_H

# include "so_long.h"

// 12 cannot allocate memory

# define ERROR_MAP_NOT_RECTANGULAR "Map not rectangular"
# define ERROR_EXIT_NOT_FOUND "Exit not found"
# define ERROR_MORE_THAN_ONE "More than 1 "
# define ERROR_PLAYER_NOT_FOUND "Player not found or player not at the bottom"
# define ERROR_COLLECTIBLE_NOT_FOUND "Collectible not found"
# define ERROR_MISSED_WALL "Missed wall"
# define ERROR_INVALID_PATH "Invalid file name or path"
# define ERROR_FILE_NOT_FOUND "File not found"
# define ERROR_INVALID_FILE_EXTENSION "Invalid file extension"
# define ERROR_INVALID_CHARACTER "Invalid character present"

int	ft_chech_valid_enemy_pos(t_game_field *game_field);
int	ft_check_valid_map_size(t_game_field *game_field);
int	ft_check_unsuported_chars(t_game_field *game_field);
int	ft_check_valid_path(char *map_path);
int	ft_check_walls(int i, int j, t_game_field *game_field);
int	ft_check_collectible(t_game_field *game_field);
int	ft_check_player(t_game_field *game_field);
int	ft_check_exit(t_game_field *game_field);
int	ft_check_if_rectangle(t_game_field *game_field);
int	ft_check_valid_map(t_game_field *game_field);

#endif