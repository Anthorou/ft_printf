/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:09:56 by aroussea          #+#    #+#             */
/*   Updated: 2023/02/20 14:27:52 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(unsigned int n, char c)
{
	int	len;

	len = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n > 0)
	{
		if (n >= 16)
		{
			print_hexa(n / 16, c);
			print_hexa(n % 16, c);
		}
		else if (c == 'x')
			write(1, &"0123456789abcdef"[n % 16], 1);
		else if (c == 'X')
			write(1, &"0123456789ABCDEF"[n % 16], 1);
		len = get_len_add(n);
	}
	return (len);
}

void	print_addr(unsigned long int addr)
{
	if (addr >= 16)
	{
		print_addr(addr / 16);
		print_addr(addr % 16);
	}
	else
		write(1, &"0123456789abcdef"[addr % 16], 1);
	return ;
}
