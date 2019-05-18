const char *students[] = {
        "Dmitriy Kovalev",
        "Krivozubov Vladislav",
        "Romanov Alexey",
        "Prokhorova Lyubov",
        "Chernenko Vladislav",
        "Dmitriy Yakuba",
        "Sukocheva Alis",
        "Perestoronin Pavel",
        "Kononenko Sergey",
        "Saburov Sergey",
		"Simonenko Emil",
		"Minenko Sergey",
		"Namestnik Anastasia"
};

xo_strategy xo_strategies[] = {
        make_shot_kovalev,
        make_shot_krivozubov,
        make_shot_romanov,
        make_shot_prokhorova,
        make_shot_chernenko,
        make_shot_yakuba,
        make_shot_sukocheva,
        make_shot_perestoronin,
        make_shot_kononenko,
        make_shot_saburov,
		make_shot_simonenko,
		make_shot_minenko,
		make_shot_namestnik
};