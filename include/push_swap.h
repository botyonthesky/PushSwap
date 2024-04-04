/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:02:47 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/11 08:00:45 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include "../libft/include/libft.h"

# define OK 42
# define KO -42

typedef struct s_stack
{
	int				value;
	int				i;
	int				pos;
	int				goal_pos;
	int				price_a;
	int				price_b;
	struct s_stack	*next;
}	t_stack;

/*---------------MANDATORY--------------------------------------*/

/*-----------------Base-----------------*/

int					main(int argc, char **argv);
void				ft_free(char **av);
void				ft_free_list(t_stack **a);
void				exit_with_error(t_stack **a, t_stack **b);
void				exe_ps_cmd(t_stack **a, t_stack **b, int size);

/*-----------------Manage stack-----------------*/

t_stack				*add_to(int argc, char **argv);
t_stack				*get_last(t_stack *x);
t_stack				*get_previous_last(t_stack *x);
t_stack				*add_front(long nb);
void				add_to_until_last_three(t_stack **a, t_stack **b);
void				fill_by_end(t_stack **a, t_stack *new);

/*--------------------Sort------------------------*/

void				exe_ps_cmd(t_stack **a, t_stack **b, int size);
void				little_sort(t_stack **x);
void				real_sort(t_stack **a, t_stack **b);
void				find_price(t_stack **a, t_stack **b);
void				find_best_price(t_stack **a, t_stack **b);
void				make_move(t_stack **a, t_stack **b, int p_a, int p_b);
void				manage_position(t_stack **a, t_stack **b);
void				find_position(t_stack **x);
int					extract_position(t_stack **a, int tmp_i, int max, int pos);
int					get_position(t_stack **a, int max, int pos);
void				find_best_rotate(t_stack **a);
int					get_best(t_stack **x);

/*--------------------Command------------------------*/

void				push(t_stack **a, t_stack **b);
void				swap(t_stack *x);
void				manage_push(t_stack **a,
						t_stack **b, int size, int is_push);
void				exe_sa(t_stack **a);
void				exe_sb(t_stack **b);
void				exe_pa(t_stack **a, t_stack **b);
void				exe_pb(t_stack **a, t_stack **b);
void				exe_ra(t_stack **a);
void				exe_rb(t_stack **b);
void				exe_rr(t_stack **a, t_stack **b);
void				exe_rra(t_stack **a);
void				exe_rrb(t_stack **b);
void				exe_rrr(t_stack **a, t_stack **b);
void				rotate(t_stack **x);
void				rotate_a(t_stack **a, int *price);
void				rotate_b(t_stack **b, int *price);
void				rotate_for_ab(t_stack **a,
						t_stack **b, int *p_a, int *p_b);
void				rev_rotate_for_ab(t_stack **a,
						t_stack **b, int *p_a, int *p_b);
void				reverse_rotate(t_stack **x);

/*-----------------Check-----------------*/

int					check_argv(char **argv);
int					check_for_identical(char **argv);
int					check_min_max(long int n);
int					ft_isnumber(char *str);
int					is_digit(char c);
int					is_sign(char c);
int					is_zero(char *str);

/*-----------------Utils-----------------*/

int					is_sort(t_stack *x);
int					compare_int(void *a, void *b);
int					get_bigger(t_stack *x);
int					stack_size(t_stack *x);
void				define_idx(t_stack *a, int size);
int					ft_abs(int nb);
long int			ft_atoli(const char *nptr);

/*-----------------BONUS-------------------------------------*/

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

int					load_stack(t_stack **a, char **argv);
void				stack_back(t_stack **x, t_stack *new);
t_stack				*stack_new(int n);
void				free_s(t_stack **stack);

/*-----------------Utils-----------------*/

int					is_duplicate(t_stack **a);
int					is_sorted(t_stack **x);
int					is_valid_command(char *str);
int					is_valid_argv(char **args);
long long int		ft_atoll(char *nbr, t_stack **a, char **t);

#endif
