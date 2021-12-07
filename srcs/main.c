#include"libftprintf.h"
#include<stdio.h>
#define KNRM  "\x1B[0m"
#define KYEL  "\x1B[33m"
#define KCYN  "\x1B[36m"

int	main(void)
{
	unsigned int	max_uint = 4294967295;
	int				max_int = 2147483647;
	int				min_int = -2147483648;

	// percent
	printf(KYEL "je me donne a 42%%\n" KNRM);
	ft_printf(KCYN "je me donne a 42%%\n" KNRM);

	// char
	printf(KYEL "%cou%cou\n" KNRM, 'c', 'c');
	ft_printf(KCYN "%cou%cou\n" KNRM, 'c', 'c');

	// str
	printf(KYEL "coucou les %s et %s\n" KNRM, "potes", "les autres potes");
	ft_printf(KCYN "coucou les %s et %s\n" KNRM, "potes", "les autres potes");

	// int
	printf(KYEL "je me donne a %i pourcents, voire %d pourcents\n" KNRM, 42, -42);
	ft_printf(KCYN "je me donne a %i pourcents, voire %d pourcents\n" KNRM, 42, -42);
	
	printf(KYEL "l'int max c'est %i\n" KNRM, max_int);
	ft_printf(KCYN "l'int max c'est %i\n" KNRM, max_int);

	printf(KYEL "0 = %i\n" KNRM, 0);
	ft_printf(KCYN "0 = %i\n" KNRM, 0);

	printf(KYEL "l'int min c'est %i\n" KNRM, min_int);
	ft_printf(KCYN "l'int min c'est %i\n" KNRM, min_int);

	// uint
	printf(KYEL "je me donne a %u pourcents, voire %u pourcents\n" KNRM, 42, -42);
	ft_printf(KCYN "je me donne a %u pourcents, voire %u pourcents\n" KNRM, 42, -42);
	
	printf(KYEL "l'uint max c'est %u\n" KNRM, max_uint);
	ft_printf(KCYN "l'uint max c'est %u\n" KNRM, max_uint);

	printf(KYEL "0 = %u\n" KNRM, 0);
	ft_printf(KCYN "0 = %u\n" KNRM, 0);

	// hex
	printf(KYEL "je me donne a %x pourcents, voire %X pourcents\n" KNRM, 42, 42);
	ft_printf(KCYN "je me donne a %x pourcents, voire %X pourcents\n" KNRM, 42, 42);

	printf(KYEL "je me donne a %x pourcents, voire %X pourcents\n" KNRM, -42, -42);
	ft_printf(KCYN "je me donne a %x pourcents, voire %X pourcents\n" KNRM, -42, -42);
	
	printf(KYEL "l'int max c'est %x\n" KNRM, max_uint);
	ft_printf(KCYN "l'int max c'est %x\n" KNRM, max_uint);

	printf(KYEL "0 = %x\n" KNRM, 0);
	ft_printf(KCYN "0 = %x\n" KNRM, 0);

	printf(KYEL "l'int min c'est %x\n" KNRM, min_int);
	ft_printf(KCYN "l'int min c'est %x\n" KNRM, min_int);

	// ptr
	char *str = "ma maison";
	printf(KYEL "l'adresse de ma maison %p\n" KNRM, str);
	ft_printf(KCYN "l'adresse de ma maison %p\n" KNRM, str);

	printf(KYEL "chez les null :%p\n" KNRM, NULL);
	ft_printf(KCYN "chez les null :%p\n" KNRM, NULL);
}
