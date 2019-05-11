from random import *

attendee_list = [
    "Chernenko Vladislav",
    "Krivozubov Vladislav",
    "Perestoronin Pavel",
    "Prokhorova Lyubov",
    "Romanov Alexey",
    "Yakuba Dmitriy",
    "Sukocheva Alis",
    "Kononenko Sergey"
]


def form_bracket(attendee_list):
    attendee_list_copy = attendee_list[::]
    bracket_list = list()

    n = 0

    while len(attendee_list_copy):
        n += 1
        first_player_ind = randint(0, len(attendee_list_copy) - 1)
        second_player_ind = randint(0, len(attendee_list_copy) - 1)

        while second_player_ind == first_player_ind:
            second_player_ind = randint(0, len(attendee_list_copy) - 1)

        bracket_list.append("Battle #{0}: {1} vs {2}".format(n,
                                                             attendee_list_copy[first_player_ind],
                                                             attendee_list_copy[second_player_ind]))

        f_p = attendee_list_copy[first_player_ind]
        s_p = attendee_list_copy[second_player_ind]

        attendee_list_copy.remove(f_p)
        attendee_list_copy.remove(s_p)

    return bracket_list


def print_bracket(bracket_list):
    for x in bracket_list:
        print(x)


bracket_list = form_bracket(attendee_list)
print_bracket(bracket_list)
