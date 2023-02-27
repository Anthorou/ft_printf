/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:04:05 by aroussea          #+#    #+#             */
/*   Updated: 2023/02/20 13:24:43 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *s, ...);
char	first_arg(const char *arg);
int		print_fucker(const char c, void *arg);
int		ft_putchar(char c, int fd);
int		ft_putstr(char *s, int fd);
int		get_len_putnbr(int n);
int		get_len_putnbr_un(unsigned int n);
int		ft_putnbr(int n, int fd);
int		get_len_add(unsigned long int addr);
void	print_addr(unsigned long int addr);
int		ft_putnbr_un(unsigned int n);
int		print_hexa(unsigned int n, char c);

#endif