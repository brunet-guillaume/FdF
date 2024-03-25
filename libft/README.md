# Libft 2.0 (42 school)

This is an improved version of the [Libft](https://gitlab.com/uotiug42/libft/) project of 42 school.

It is advisable to improve our Libft, project after project. So, here is the functions I added to the initial library :

## Binary tree

```c
typedef struct s_btree
{
	void		*data;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;
```

<table style="text-align:center;">
    <tr><td width="150">bt_add_left</td><td width="150">bt_add_right</td><td width="150">bt_clear</td></tr>
    <tr><td>bt_del</td><td>bt_new</td><td>bt_print</td></tr>
</table>

## Double linked list

```c
typedef struct s_dlist
{
	void		*data;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;
```

<table style="text-align:center;">
    <tr><td width="150">dl_add_back</td><td width="150">dl_add_front</td><td width="150">dl_clear</td></tr>
    <tr><td>dl_del</td><td>dl_last</td><td>dl_new</td></tr>
    <tr><td>dl_remove_from</td><td>dl_size</td><td>dl_sort</td></tr>
    <tr><td>dl_swap</td><td></td><td></td></tr>
</table>

## Get next line

[get_next_line](https://gitlab.com/uotiug42/get_next_line) project (42 school) added to this library.

## Printf

[ft_printf](https://gitlab.com/uotiug42/ft_printf) project (42 school) added to this library.

## Others

<table style="text-align:center;">
    <tr><td width="150">ft_free</td><td width="150">rgba_from_int</td><td width="150">rgba</td></tr>
    <tr><td>min</td><td>max</td><td>clamp</td></tr>
    <tr><td>minf</td><td>maxf</td><td>clampf</td></tr>
</table>

### Compilation
```bash
git clone https://gitlab.com/uotiug42/libft_2.0.git
cd libft_2.0
make
```