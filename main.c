/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:35:44 by steh              #+#    #+#             */
/*   Updated: 2021/12/24 10:33:58 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	a;
	int *p;
	char *str = NULL;

	a = 1;
	p = &a;
	//ft_printf("%-123");
	//ft_printf("%%-5.3s LYDI == |%-5.3s|", "LYDI");
	ft_printf("%s%s", "hi");
	ft_printf("%s!", str);
	ft_printf("test\n");
	ft_printf("%c\n", 'z');
	ft_printf("%s\n", "abce");
	ft_printf("%s\n", "abcdefg");
	ft_printf("%d\n", 123);
	ft_printf("%p\n", p);
	ft_printf("%%asd\n");
	ft_printf("%u\n", 26);
	ft_printf("%u\n", -26);
	ft_printf("%x\n", 23123);
	ft_printf("%X\n", 23423);
	return (1);
}
