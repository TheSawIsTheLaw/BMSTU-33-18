#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../d_trees_headers/chelyadinov_d6n_tree_titanicgame.h"
#include "../f_headers/add_titanicgame.h"
#include "../f_headers/create_titanicgame.h"
#include "../headers/struct.h"

bool check_age(passenger man)
{
  int rand_p;
  rand_p = rand() % 100 + 1;
  if (strcmp(man.sex, "female") == 0 && man.age >= 25 && rand_p >= 25)
  {
    return TRUE;
  }
  if (strcmp(man.sex, "male") == 0 && man.age >= 25 && rand_p >= 80)
  {
    return TRUE;
  }
  if (rand_p >= 97)
  {
    return TRUE;
  }
  return FALSE;
}

bool check_sex(passenger man)
{
  if (strcmp(man.sex, "female") == 0)
        return TRUE;
    return FALSE;
}

bool check_pclass(passenger man)
{
  int rand_p;
  rand_p = rand() % 100 + 1;
  if (man.pclass == 1 && i >= 70)
  {
    return TRUE;
  }
  return FALSE;
}

bool check_parch(passenger man)
{
  if (man.parch > 0)
        return TRUE;
    return FALSE;
}

node* chelyadinov_d6n_tree_titanicgame()
{
    node *root = create(check_age);
    node *yes = create(check_sex);
    node *yes_yes = create(check_pclass);
    node *no = create(check_parch);
    node *no_yes = create(check_sex);

    add(root, TRUE, yes);
    add(yes, TRUE, yes_yes);
    add(root, FALSE, no);
    add(no, TRUE, no_yes);
    
    return root;
}
