/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:43:20 by steh              #+#    #+#             */
/*   Updated: 2022/02/16 16:37:17 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

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
	// ft_printf("%.5i\n", 2);
	// ft_printf("%i\n", -2);
	// printf("%i\n", -2);
	// ft_printf("%.6i", -3);
	// ft_printf("%3x", 0);
	// ft_printf("this %x number", 0);
	// printf("%0*i", -7, -54);
	// printf("%.*o", -3, 12345);
	// printf("%.*o", -1, 12345);
	// printf("%.*o", -1, 0);
	// ft_printf(" %x\n", 0);
	// printf(" %x\n", 0);
	// ft_printf(" %d\n", -42);
	ft_printf("%0*i\n", -7, -54);
	printf("%0*i\n", -7, -54);
	// ft_printf(" %010d\n", INT_MIN);
	// printf(" %010d\n", INT_MIN);
	// printf("Minimum value of long int %ld\n", LONG_MIN);
	// ft_printf(" %012d \n", LONG_MIN);
	// printf(" %012d \n", LONG_MIN);
	// ft_printf(" %011i \n", INT_MIN);
	// printf(" %011i \n", INT_MIN);
	// ft_printf(" %09i %010i %011i %012i %013i %014i %015i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// printf(" %09i %010i %011i %012i %013i %014i %015i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// ft_printf(" %09d %010d %011d %012d %013d %014d %015d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// printf(" %09d %010d %011d %012d %013d %014d %015d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// ft_printf("%014d %015d\n", 0, -42);
	// printf("%014d %015d\n", 0, -42);
	// ft_printf(" %x\n", LONG_MIN);
	// printf(" %x\n", LONG_MIN);
	// ft_printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
	// printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
	// ft_printf("%p\n", &a12);
	// printf("%.2p\n", &a12);
	// ft_printf("%p\n", 0);
	// printf("%p\n", 0);
	// printf("%.*p\n", -3, 0);
	// printf("%.*p\n", -1, 0);
	// ft_printf("%5p\n", 0);
	// printf("%""5p\n", 0);
	// printf("%-05%");
	// ft_printf("%-05%");
	// ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
	// printf(" %p %p \n", LONG_MIN, LONG_MAX);
	// printf(" %ld %ld \n", LONG_MIN, LONG_MAX);
	// ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	// printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	// printf("%s = %s = %sn", convert(65,8), convert(65,10), convert(65,16));
	// ft_printf("%10.p\n", 0);
	// printf("%10.p\n", 0);
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
