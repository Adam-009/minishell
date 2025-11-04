/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:31:58 by asaadi--          #+#    #+#             */
/*   Updated: 2025/10/29 20:07:12 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "../minishell.h"

int		check_op(char *command, int index);
int		get_op_len(char *command, int i);
int		skip_word(char *cmd, int i);
int		skip_spaces(char *command, int i);
int		malloc_operator(char **array, char *cmd, int i, int j);
int		malloc_word(char **array, char *cmd, int i, int j);
int		malloc_quote(char **array, char *cmd, int i, int j);
void	malloc_inside_array(char **array, char *command);

#endif
