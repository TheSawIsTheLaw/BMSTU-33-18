#include "../d_trees_headers/simonenko_d6n_tree_titanicgame.h"
#include "../f_headers/add_titanicgame.h"
#include "../f_headers/create_titanicgame.h"


bool malfcage(passenger leo)
{
    if (leo.age > 11 && leo.age < 40)
    {
        return TRUE;
    }

    return FALSE;
}

bool malscage(passenger leo)
{
    if (leo.age > 16 && leo.age < 35 )
    {
        return TRUE;
    }

    return FALSE;
}

bool maltcage(passenger leo)
{
    if (leo.age > 16 && leo.age < 32 )
    {
        return TRUE;
    }

    return FALSE;
}

bool femfcage(passenger kate)
{
    if (kate.age > 11 && kate.age < 64)
    {
        return TRUE;
    }

    return FALSE;
}

bool femscage(passenger kate)
{
    if (kate.age > 12 && kate.age < 45)
    {
        return TRUE;
    }

    return FALSE;
}

bool femtcage(passenger kate)
{
    if (kate.age > 13 && kate.age < 42)
    {
        return TRUE;
    }

    return FALSE;
}

bool ifmale(passenger leokate)
{
    if (leokate.sex[0]=='m')
    {
        return TRUE;
    }

    return FALSE;
}

bool isfircl(passenger leokate)
{
    if (leokate.pclass == 1)
    {
        return TRUE;
    }

    return FALSE;
}

bool isseccl(passenger leokate)
{
    if (leokate.pclass == 2)
    {
        return TRUE;
    }

    return FALSE;
}

/*
mytree:
yes/liv                                   no/ded
                first class?
        t  /                    \  f
         ifmal                 sclass
      tt /    \   tf     ft  /        \ ff
    MalFcAge FemFcAge      ifmal      ifmal
      /\       /\       ftt/  \ftf fft/   \fff
                        msa  fsa    mta   fta
                        /\    /\     /\    /\
*/

node *simonenko_d6n_tree_titanicgame()
{
    node *root = create(isfircl); 
    node *t = create(ifmale);
    node *tt = create(malfcage);
    node *tf = create(femfcage);
    node *f = create(isseccl);
    node *ft = create(ifmale);
    node *ftt = create(malscage);
    node *ftf = create(femscage);
    node *ff = create(ifmale);
    node *fft = create(maltcage);
    node *fff = create(femtcage);
    
    add(root, TRUE, t);
    add(root, FALSE, f);
    
    add(t, TRUE, tt);
    add(t, FALSE, tf);
    add(f, TRUE, ft);
    add(f, FALSE, ff);
    
    add(ft, TRUE, ftt);
    add(ft, FALSE, ftf);
    add(ff, TRUE, fft);
    add(ff, FALSE, fff);
    
    return root;
}
