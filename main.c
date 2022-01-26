/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:43:20 by steh              #+#    #+#             */
/*   Updated: 2022/01/26 20:06:20 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	a;
	int *p;
	char *str = NULL;
	static char *a12;

	a = 1;
	p = &a;
	
	// char *pointer;
    
    // pointer = convert(11, 8);
    // printf("%s", pointer);
	// ft_printf("%5p\n", p);
	// ft_printf("%5%\n", p);
	// ft_printf("%p\n", p);
	// ft_printf("%p", NULL);
	ft_printf("%p", &a12);
	// ft_printf("%5p", NULL);
	// ft_printf("%-1c %-2c 	%-3c", '0', 0, '1');
	// ft_printf("%-1c %-2c %-3c", '2', '1', 0);
	// ft_printf("%-1c %-2c %-3c", 0, '1', '2');
	// ft_printf("%1s", "hello");
	// ft_printf("%123s", "hello");
	// ft_printf("<%-10s>", "hello");
	// ft_printf("<%10s>", "hello");
	// ft_printf("%s\n", "hello");
	// ft_printf("%110.3s", "hello");
	// ft_printf("%5s", "goes over");
	// ft_printf("%.s", 0);
	// ft_printf("%.*s", -3, 0);
	// ft_printf("%.*s", -1, 0);
	// ft_printf("%s", "String");
	// ft_printf("%.5s%7s", "|yo|", "<boi>");
	// ft_printf("%.5s", "<boi>");
	// ft_printf("%.09s", "hello");
	// ft_printf("%-32s", "abc");
	// ft_printf("%s%s", "abc", "def");
	// ft_printf("%c%c", 'a', 'b');
	// ft_printf("%2.3s", "hello");
	// ft_printf("%.19s", "hello");
	// ft_printf("%.192s", "hello");
	// ft_printf("%d\n", 42);
	// ft_printf("%i\n", 42);
	// ft_printf("|%5c|\n", '\0');
	// ft_printf("|%-5c|\n", '\0');
	// ft_printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	// ft_printf("%-3c\n", 'a');
	// ft_printf("%c\n", 'q');
	// ft_printf("%%-5.3s LYDI == |%-5.3s|", "LYDI");
	// ft_printf("%s%s", "hi");
	// ft_printf("%s!", str);
	// ft_printf("test\n");
	// ft_printf("%c\n", 'z');
	// ft_printf("%s\n", "abce");
	// ft_printf("%s\n", "abcdefg");
	// ft_printf("%d\n", 123);
	// ft_printf("%%asd\n");
	// ft_printf("%u\n", 26);
	// ft_printf("%u\n", -26);
	// ft_printf("%x\n", 23123);
	// ft_printf("%X\n", 23423);
	return (0);
}
