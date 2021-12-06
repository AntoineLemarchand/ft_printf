#include"libftprintf.h"
#include<stdio.h>

int	main(void)
{
	// percent
	printf("je me donne a 42%%");
	ft_printf("je me donne a 42%%");

	// char
	printf("%cou%cou\n", 'c', 'c');
	ft_printf("%cou%cou\n", 'c', 'c');

	// str
	printf("coucou les %s et %s\n", "potes", "les autres potes");
	ft_printf("coucou les %s et %s\n", "potes", "les autres potes");
	printf("coucou les %8s et %s\n", "potes", "les autres potes");
	ft_printf("coucou les %8s et %s\n", "potes", "les autres potes");

	// int
	printf("je me donne a %i pourcents, voire %d pourcents\n", 42, -42);
	ft_printf("je me donne a %i pourcents, voire %d pourcents\n", 42, -42);
	
	printf("l'int max c'est %i", 2147483647);
	ft_printf("l'int max c'est %i", 2147483647);

	printf("0 = %i", 0);
	ft_printf("0 = %i", 0);

	printf("l'int min c'est %i", -2147483647);
	ft_printf("l'int min c'est %i", -2147483647);

	// uint
	printf("je me donne a %u pourcents, voire %u pourcents\n", 42, -42);
	ft_printf("je me donne a %u pourcents, voire %u pourcents\n", 42, -42);
	
	unsigned int nb = 4294967295;
	printf("l'uint max c'est %u", nb);
	ft_printf("l'uint max c'est %u", nb);

	printf("0 = %u", 0);
	ft_printf("0 = %u", 0);

	// hex
	printf("je me donne a %x pourcents, voire %X pourcents\n", 42, 42);
	ft_printf("je me donne a %x pourcents, voire %X pourcents\n", 42, 42);

	printf("je me donne a %x pourcents, voire %X pourcents\n", -42, -42);
	ft_printf("je me donne a %x pourcents, voire %X pourcents\n", -42, -42);
	
	printf("l'int max c'est %x", 2147483647);
	ft_printf("l'int max c'est %x", 2147483647);

	printf("0 = %x", 0);
	ft_printf("0 = %x", 0);

	printf("l'int min c'est %x", -2147483647);
	ft_printf("l'int min c'est %x", -2147483647);

	// ptr
	char *str = "ma maison";
	printf("l'adresse de ma maison %p\n", str);
	ft_printf("l'adresse de ma maison %p\n", str);

	printf("chez les null :%p\n", NULL);
	ft_printf("chez les null :%p\n", NULL);
}
