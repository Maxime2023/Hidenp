/*
** EPITECH PROJECT, 2019
** hidenp
** File description:
** hidenp
*/

#include <unistd.h>
#include <stdlib.h>

char    my_putchar(char c)
{
    write (1, &c, 1);
}

int    my_putstr(char *str)
{
    int d = 0;

    while (str[d] != '\0') {
        write(2, &str[d], 1);
        d++;
    }
    return (0);
}

int    my_strlen(char *str)
{
    int a = 0;

    while (str[a] != '\0')
        a++;
    return (a);
}

int    hidenp(char *str, char *str_two)
{
    int lenght = my_strlen(str);
    int d = 0;
    int a = 0;
    int compteur = 0;

    while (str_two[d] != '\0') {
        if (a <= lenght && str[a] == str_two[d]) {
            compteur++;
            a++;
        }
        d++;
    }
    if (compteur == lenght) {
        my_putstr("1\n");
        return (1);
    }
    else {
        my_putstr("0\n");
        return (0);
    }
}

int    main(int ac, char **av)
{
    char *a = av[1];
    char *b = av[2];

    if (ac != 3) {
        my_putstr("Usage: ./hidenp needle haystack\n");
        return (84);
    }
    hidenp(av[1], av[2]);
}
