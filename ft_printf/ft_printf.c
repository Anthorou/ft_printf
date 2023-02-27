/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:58:34 by aroussea          #+#    #+#             */
/*   Updated: 2023/02/20 16:09:01 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list		args;
	char		type;
	int			len;

	va_start(args, s);
	len = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			type = first_arg(s);
			if (type == '%')
				len += write(1, "%", 1);
			else
				len += print_fucker(type, va_arg(args, void *));
			s++;
		}
		else
		{
			ft_putchar_fd(*s, 1);
			len++;
		}
		s++;
	}
	return (len);
}

// gcc ft_printf.c libftprintf.a && ./a.out

// int main(void)
// {
// 	// int val = 59742;

// 	int a = ft_printf("\001\002\007\v\010\f\r\n");
// 	int b = printf("\001\002\007\v\010\f\r\n");
// 	ft_printf("i : %d, b : %d", a, b);
// 	// ft_printf("\n");
// 	// ft_printf("\n");
// 	// int c = ft_printf("%s\n", val);
// 	// int d = printf("%s\n", val);
// 	// ft_printf("i : %d, b : %d", c, d); 
// 	// ft_printf("\n");
// 	// ft_printf("\n");
// 	// int e = ft_printf("%p\n", val);
// 	// int f = printf("%p\n", val);
// 	// ft_printf("i : %d, b : %d", e, f);
// 	// ft_printf("\n");
// }
