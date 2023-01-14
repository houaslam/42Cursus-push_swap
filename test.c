/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:53:29 by houaslam          #+#    #+#             */
/*   Updated: 2023/01/14 19:54:31 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sort_main(int *a)
// {
//     int i;
//     int size;

//     i = 0;
//     size = sizeof(a)/sizeof(int);
//     sort(a, size);
//     while(i < size)
//     {
//         printf("//%d\n", a[i]);
//         i++;
//     }
// }
int main(int ac, char **av)
{
    sort()
}

void sort(int *tab, int size)
{
    int i;
    int j;
    int b;

    j = 0;
    i = j + 1;
    while(j < size)
    {
        i = 0;
        while(i < size)
        {
            if(tab[j] < tab[i])
                swap(&tab[j], &tab[i]);
            i++;
        }
        j++;
    }
}

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}