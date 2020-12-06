/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_ip_with_mask.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 22:03:03 by kaye              #+#    #+#             */
/*   Updated: 2020/12/06 21:46:54 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void    calcul_ip_with_mask()
{
    char re[1];
    int part_ip1;
    int part_ip2;
    int part_ip3;
    int part_ip4;

    int part_mask1;
    int part_mask2;
    int part_mask3;
    int part_mask4;

    int mask_mode;
    int mask_ip_num;
    int tmp_mask_ip_num;
    t_ip first_ip;
    t_ip last_ip;
    long range;
restart:
    part_ip1 = 0;
    part_ip2 = 0;
    part_ip3 = 0;
    part_ip4 = 0;
    part_mask1 = 0;
    part_mask2 = 0;
    part_mask3 = 0;
    part_mask4 = 0;
    mask_mode = 0;
    mask_ip_num = 0;
    tmp_mask_ip_num = 0;
    first_ip = init_ip();
    last_ip = init_ip();
    range = 0;
    printf("\033[1;32m======================================================================\n\033[0m");
    printf("\n");
    printf("-------------------------> 4. Calcul IP/MASK. <-----------------------\n");
    printf("\n");
    printf("Entrer your ip : (separate on 4 parts)\n\n");
    printf("\033[1;36mpart 1 : \033[0m");
    scanf("%d", &part_ip1);
    printf("\033[1;36mpart 2 : \033[0m");
    scanf("%d", &part_ip2);
    printf("\033[1;36mpart 3 : \033[0m");
    scanf("%d", &part_ip3);
    printf("\033[1;36mpart 4 : \033[0m");
    scanf("%d", &part_ip4);
    if (part_ip1 > 255 || part_ip2 > 255 || part_ip3 > 255 || part_ip4 > 255)
    {
        printf("ERROR\n");
        printf("\033[1;31m-------------------------> restart ? (y/n) : \033[0m");
        scanf("%s", re);
        getchar();
        if (re[0] == 'y')
        {
            system("clear");
            goto restart;
        }
        else
            return ;
    }
    system("clear");
    printf("\033[1;32m======================================================================\n\033[0m");
    printf("-------------------------> 4. Calcul IP/MASK. <-----------------------\n");
    printf("\n");
    printf("Your IP : \033[1;36m%d.%d.%d.%d\n\033[0m", part_ip1, part_ip2, part_ip3, part_ip4);
    printf("\nMode MASK IP :\033[1;36mIP -> (1)\033[0m / \033[1;31mCIDR -> (2)\n\033[0m");
    printf("Enter mode : ");
    scanf("%d", &mask_mode);
    if (mask_mode == 1)
    {
        system("clear");
        printf("\033[1;32m======================================================================\n\033[0m");
        printf("-------------------------> 4. Calcul IP/MASK. <-----------------------\n");
        printf("\n");
        printf("Your IP : \033[1;36m%d.%d.%d.%d\n\033[0m", part_ip1, part_ip2, part_ip3, part_ip4);
        printf("Entrer your ip : (separate on 4 parts)\n\n");
        printf("\033[1;36mpart 1 : \033[0m");
        scanf("%d", &part_mask1);
        printf("\033[1;36mpart 2 : \033[0m");
        scanf("%d", &part_mask2);
        printf("\033[1;36mpart 3 : \033[0m");
        scanf("%d", &part_mask3);
        printf("\033[1;36mpart 4 : \033[0m");
        scanf("%d", &part_mask4);
    }
    else if (mask_mode == 2)
    {
        system("clear");
        printf("\033[1;32m======================================================================\n\033[0m");
        printf("-------------------------> 4. Calcul IP/MASK. <-----------------------\n");
        printf("\n");
        printf("Your IP : \033[1;36m%d.%d.%d.%d\n\033[0m", part_ip1, part_ip2, part_ip3, part_ip4);
        printf("\n\033[1;31mEnter Mask ip on number : \033[0m"); 
        scanf("%d", &mask_ip_num);
        if (mask_ip_num > 32)
        {
            printf("ERROR\n");
            printf("\033[1;31m-------------------------> restart ? (y/n) : \033[0m");
            scanf("%s", re);
            getchar();
            if (re[0] == 'y')
            {
                system("clear");
                goto restart;
            }
            else
                return ;
        }
        tmp_mask_ip_num = mask_ip_num;
        if (mask_ip_num >= 0)
        {
            if (mask_ip_num >= 0 && mask_ip_num <= 8)
            {
                tmp_mask_ip_num = mask_ip_num;
                part_mask1 = get_part_mask(tmp_mask_ip_num);
            }
            else if (mask_ip_num >= 9 && mask_ip_num <= 16)
            {
                tmp_mask_ip_num = 8;
                part_mask1 = get_part_mask(tmp_mask_ip_num);
            }
            else if (mask_ip_num >= 17 && mask_ip_num <= 24)
            {
                tmp_mask_ip_num = 8;
                part_mask1 = get_part_mask(tmp_mask_ip_num);
            }
            else if (mask_ip_num >= 25 && mask_ip_num <= 32)
            {
                tmp_mask_ip_num = 8;
                part_mask1 = get_part_mask(tmp_mask_ip_num);
            }
            if (mask_ip_num >= 9)
            {
                if (mask_ip_num >= 9 && mask_ip_num <= 16)
                {
                    tmp_mask_ip_num = mask_ip_num - 8;
                    part_mask2 = get_part_mask(tmp_mask_ip_num);
                }
                else if (mask_ip_num >= 17 && mask_ip_num <= 24)
                {
                    tmp_mask_ip_num = 8;
                    part_mask2 = get_part_mask(tmp_mask_ip_num);
                }
                else if (mask_ip_num >= 25 && mask_ip_num <= 32)
                {
                    tmp_mask_ip_num = 8;
                    part_mask2 = get_part_mask(tmp_mask_ip_num);
                }
                if (mask_ip_num >= 17)
                {
                    if (mask_ip_num >= 17 && mask_ip_num <= 24)
                    {
                        tmp_mask_ip_num = mask_ip_num - 16;
                        part_mask3 = get_part_mask(tmp_mask_ip_num);
                    }
                    else if (mask_ip_num >= 25 && mask_ip_num <= 32)
                    {
                        tmp_mask_ip_num = 8;
                        part_mask3 = get_part_mask(tmp_mask_ip_num);
                    }
                    if (mask_ip_num >= 25 &&  mask_ip_num <= 32)
                    {
                        tmp_mask_ip_num = mask_ip_num - 24;
                        part_mask4 = get_part_mask(tmp_mask_ip_num);
                    }
                }
            }
        }
    }
    else
    {
        printf("ERROR\n");
        printf("\033[1;31m-------------------------> restart ? (y/n) : \033[0m");
        scanf("%s", re);
        getchar();
        if (re[0] == 'y')
        {
            system("clear");
            goto restart;
        }
        else
            return ;
    }
    if (part_mask1 > 255 || part_mask2 > 255 || part_mask3 > 255 || part_mask4 > 255)
    {
        printf("ERROR\n");
        printf("\033[1;31m-------------------------> restart ? (y/n) : \033[0m");
        scanf("%s", re);
        getchar();
        if (re[0] == 'y')
        {
            system("clear");
            goto restart;
        }
        else
            return ;
    }
    range = get_ip_number(part_mask1, part_mask2, part_mask3, part_mask4) + 2;
    first_ip.ip1 = part_ip1 & part_mask1;
    first_ip.ip2 = part_ip2 & part_mask2;
    first_ip.ip3 = part_ip3 & part_mask3;
    first_ip.ip4 = part_ip4 & part_mask4;
    last_ip = get_range_ip(first_ip, range);
    system("clear");
    printf("\033[1;32m======================================================================\n\033[0m");
    printf("-------------------------> 4. Calcul IP/MASK. <-----------------------\n");
    printf("\n");
    printf("Your IP : \033[1;36m%d.%d.%d.%d\033[0m with Mask IP : \033[1;36m%d.%d.%d.%d\n\033[0m", part_ip1, part_ip2, part_ip3, part_ip4, part_mask1, part_mask2, part_mask3, part_mask4);
    printf("Your IP/CIDR : \033[1;36m%d.%d.%d.%d\033[0m/\033[1;36m%d\n\n\033[0m", part_ip1, part_ip2, part_ip3, part_ip4, (get_cidr(part_mask1) + get_cidr(part_mask2) + get_cidr(part_mask3) + get_cidr(part_mask4)));
    printf("your network adress : \033[1;36m%d.%d.%d.%d\n\033[0m", (part_ip1 & part_mask1), (part_ip2 & part_mask2), (part_ip3 & part_mask3), (part_ip4 & part_mask4));
    printf("The IP adress you can use : \033[31m%ld\n\033[0m", range - 2);
    printf("Your first IP : \033[1;36m%d.%d.%d.%d\n\033[0m", first_ip.ip1, first_ip.ip2, first_ip.ip3, first_ip.ip4 + 1);
    printf("Your last IP : \033[1;36m%d.%d.%d.%d\n\033[0m", last_ip.ip1, last_ip.ip2, last_ip.ip3, last_ip.ip4 - 1);
    printf("Your broast IP : \033[1;36m%d.%d.%d.%d\n\033[0m", last_ip.ip1, last_ip.ip2, last_ip.ip3, last_ip.ip4 );
    printf("\n");
    printf("\033[1;31m-------------------------> restart ? (y/n) : \033[0m");
    scanf("%s", re);
    getchar();
    if (re[0] == 'y')
    {
        system("clear");
        goto restart;
    }
    else
        return ;
}