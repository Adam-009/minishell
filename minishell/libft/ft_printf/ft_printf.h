/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:42:39 by asaadi--          #+#    #+#             */
/*   Updated: 2024/12/05 16:30:00 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_p(void *ptr);
int		ft_x(int nb, int value);
int		ft_u(unsigned int i);
int		ft_c(char arg);
int		ft_s(char *ptr);
int		ft_i(int i);

#endif