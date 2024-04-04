/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:33:16 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/19 17:33:19 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include "../libft/include/libft.h"

typedef struct s_stack
{
	int				value;
	int				i;
	struct s_stack	*next;
}					t_stack;

/*-----------------Base-----------------*/

int					main(int argc, char **argv);
int					checker(t_stack **a, t_stack **b);
int					check_split_argv(t_stack **a, int argc, char **argv);

/*-----------------Check Command-----------------*/

void				check_command(t_stack **a, t_stack **b, char *str);
void				check_next(t_stack **a, t_stack **b, char *str);
void				check_pa(t_stack **b, t_stack **a);
void				check_pb(t_stack **a, t_stack **b);
void				check_reverse(t_stack **x);
void				check_rra(t_stack **a);
void				check_rrb(t_stack **b);
void				check_rrr(t_stack **a, t_stack **b);
void				check_rotate(t_stack **x);
void				check_ra(t_stack **a);
void				check_rb(t_stack **b);
void				check_rr(t_stack **a, t_stack **b);
void				check_swap(t_stack **x);
void				check_ss(t_stack **a, t_stack **b);
void				check_lst(t_stack *a, int check);

/*-----------------Stack-----------------*/

int					check_and_load(t_stack **a, char **argv, int x);
int					load_stack(t_stack **a, char **argv, int x);
void				stack_back(t_stack **x, t_stack *new);
t_stack				*stack_new(int n);
void				free_s(t_stack **stack);

/*-----------------Utils-----------------*/

int					is_duplicate(t_stack **a);
int					is_sorted(t_stack **x);
int					is_valid_command(char *str);
int					is_valid_argv(char **args, int i);
long long int		ft_atoll(char *nbr, t_stack **a, char **t);
void				ft_free(char **av);
long int			ft_atoli(const char *nptr);
int					check_min_max(long int n);

#endif
