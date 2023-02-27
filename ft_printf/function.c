/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:14:59 by aroussea          #+#    #+#             */
/*   Updated: 2023/02/21 14:31:15 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	first_arg(const char *c)
{
	if (*c == '%')
	{
		c++;
		return ((char) *c);
	}
	return ('0');
}

int	get_len_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
	{
		return (11);
	}
	else if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	get_len_putnbr_un(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	get_len_add(unsigned long int addr)
{
	int	i;

	i = 0;
	if (addr == 0)
		return (1);
	while (addr > 0)
	{
		addr = addr / 16;
		i++;
	}
	return (i);
}

int	print_fucker(const char c, void *arg)
{
	if (c == 'c')
		return (ft_putchar((int)arg, 1));
	else if (c == 's')
		return (ft_putstr((char *)arg, 1));
	else if (c == 'p')
	{
		ft_putstr("0x", 1);
		print_addr((unsigned long int)arg);
		return (get_len_add((unsigned long int)arg) + 2);
	}
	else if (c == 'd')
		return (ft_putnbr((int)arg, 1));
	else if (c == 'i')
		return (ft_putnbr((int)arg, 1));
	else if (c == 'u')
		return (ft_putnbr_un((unsigned int)arg));
	else if (c == 'x' || c == 'X')
		return (print_hexa((int)arg, c));
	return (-1);
}
