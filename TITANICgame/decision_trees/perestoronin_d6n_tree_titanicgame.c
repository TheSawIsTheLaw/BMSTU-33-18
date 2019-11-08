#include "../d_trees_headers/perestoronin_d6n_tree_titanicgame.h"
#include "../headers/struct.h"

bool is_female(passenger a)
{
	return (a.sex[0] == 'f') ? TRUE : FALSE;
}

bool is_1_or_2_class(passenger a)
{
	return (a.pclass == 1 || a.pclass == 2) ? TRUE : FALSE;
}

bool is_child(passenger a)
{
	return (a.age < 18 && a.age != -1) ? TRUE : FALSE;
}

bool good_parch_amount(passenger a)
{
	return (a.parch < 2 && a.parch != -1) ? TRUE : FALSE;
}

bool good_sibl_amount(passenger a)
{
	return (a.siblings_sp < 2 && a.siblings_sp != -1) ? TRUE : FALSE;
}

node *perestoronin_d6n_tree_titanicgame()
{
	node *vertex = create(is_female);
	node *vertex1 = create(is_child);
	node *vertex12 = create(is_1_or_2_class);
	node *vertex2 = create(good_parch_amount);
	node *vertex22 = create(good_sibl_amount);

	add(vertex, FALSE, vertex1);
	add(vertex, TRUE, vertex2);
	add(vertex1, TRUE, vertex12);
	add(vertex, TRUE, vertex22);
}
