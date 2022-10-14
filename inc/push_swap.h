/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:21:38 by eclark            #+#    #+#             */
/*   Updated: 2022/10/14 13:46:58 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
/*# include <stdio.h>*/

/*linked list for stack a and stack b*/
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/*error handling*/
int		error_man(char **argv);
int		error_man_str(char **list);
int		check_num(char *argv);
int		check_int(char *argv);
int		seeing_double(char *argv, char **av, int i);
int		invalid_input(int error);

/*init*/
int		sizeofstack(t_stack *stack);
t_stack	*create_node(int n);
t_stack	*initialise(int argc, char **argv);
void	indexstack(t_stack *stack, int stacksize);
void	addtostack(t_stack **stack, t_stack *node);

/*init_string*/
t_stack	*init_string(char **argv);

/*cost*/
void	cost(t_stack **stack_a, t_stack **stack_b);
void	execute_cheapest(t_stack **stacka, t_stack **stackb);
void	movetstack(t_stack **stack_a, t_stack **stack_b, int costa, int costb);

/*utils*/
int		ft_atoi(const char *str);
int		abs(int n);
t_stack	*secondlast(t_stack *stack);
t_stack	*gettobottom(t_stack *stack);
char	**ft_split(char const *s, char c);

/*push*/
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);

/*swap*/
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

/*rotate*/
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

/*rev_rotate*/
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/*sort*/
int		issorted(t_stack *stack);
void	sortthree(t_stack **stack_a);
void	sort(t_stack **stack_a, t_stack **stack_b);
void	pushtob(t_stack **stack_a, t_stack **stack_b);

/*positions*/
int		lowest_index_pos(t_stack **stack_a);
void	get_pos(t_stack **stack);
void	get_target_pos(t_stack **stack_a, t_stack **stack_b);

#endif
