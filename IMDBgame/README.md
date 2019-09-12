# Оглавление.
1. [🤔 Что это? 🤔](#1_0)
2. [🏆 Награды 🏆](#2_0)
3. [👷 Что нужно делать?](#3_0)
4. [📱 Контакты 📻](#4_0)

# 🤔 Что это? 🤔<a name="1_0"></a>
🎥 Расчет числа **Бэйкона** для любого актера на IMDB!

# 🏆 Награды 🏆 <a name="2_0"></a>
🔥2🔥 балла по программированию! За лабу дают от 1 до 3!!! 🔥🔥🔥
Награждаются:
Романов Алексей
Кононенко Сергей
Ковалев Дмитрий
Кривозубов Владислав
Прохорова Любовь
Топорков Павел
Сукочева Алис
Якуба Дмитрий

# 👷 Что нужно делать? <a name="3_0"></a>
**Я не могу писать код! ♿♿♿**

Поэтому мне нужна ваша помощь, если вы хотите 2 балла, то пишите мне! Также я буду периодически выкладывать задачи и искать людей готовых их сделать.

# 📱 Контакты 📻 <a name="4_0"></a>

Если вы решили написать какой-нибудь код, то свяжитесь со мной! 🤙🤙🤙🤙

1. 📺 __Telegram:__ @VASYA_VAN

2. 🐉 __VK__: https://vk.com/ya_vrzh 🐉

3. ♻️ Еще я хожу в универ, там со мной можно говорить!

# cloc .
```
-------------------------------------------------------------------------------
Language                     files          blank        comment           code
-------------------------------------------------------------------------------
C                               20            269            113           1352
C/C++ Header                     5            103              2            418
Markdown                         1              9              0             17
-------------------------------------------------------------------------------
SUM:                            26            381            115           1787
-------------------------------------------------------------------------------
```
# cppcheck --enable=all .

```
[functions\interfaces\actorfile_interface.h:16]: (warning) %d in format string (no. 1) requires 'int' but the argument type is 'unsigned int'.
[functions\interfaces\actorfile_interface.h:72]: (style) The scope of the variable 'i' can be reduced.
[functions\interfaces\actorfile_interface.h:72]: (style) The scope of the variable 'j' can be reduced.
[functions\interfaces\actorfile_interface.h:72]: (style) The scope of the variable 'pivot' can be reduced.
[functions\file_actions\getid_byname.c:11]: (warning) scanf() without field width limits can crash with huge input data.
[functions\interfaces\create_arrs.h:39]: (style) The scope of the variable 'temp' can be reduced.
[functions\file_actions\make_array_act_to_act.c:22]: (style) The scope of the variable 'middle' can be reduced.
[functions\file_actions\make_array_act_to_act.c:60]: (style) The scope of the variable 'last_actor' can be reduced.
[functions\file_actions\make_array_act_to_act.c:62]: (style) The scope of the variable 'cur_film' can be reduced.
[functions\file_actions\make_array_act_to_act.c:60]: (style) Variable 'last_actor' is assigned a value that is never used.
[functions\file_actions\make_array_act_to_act.c:62]: (style) Variable 'cur_film' is assigned a value that is never used.
[functions\file_actions\make_array_act_to_act.c:65]: (style) Variable 'last_actor' is assigned a value that is never used.
[functions\file_actions\make_data_file.c:23]: (style) The scope of the variable 'middle' can be reduced.
[functions\file_actions\make_data_file.c:93]: (style) The scope of the variable 'cur_el' can be reduced.
[functions\file_actions\make_data_file.c:177]: (style) The scope of the variable 'cur_film' can be reduced.
[functions\file_actions\make_data_file.c:177]: (style) Variable 'cur_film' is assigned a value that is never used.
[functions\parsers\act_to_act_parser.c:21]: (style) The scope of the variable 'middle' can be reduced.
[functions\parsers\act_to_act_parser.c:84]: (style) The scope of the variable 'cur_el' can be reduced.
[functions\parsers\act_to_act_parser.c:166]: (style) The scope of the variable 'cur_film' can be reduced.
[functions\parsers\act_to_act_parser.c:166]: (style) Variable 'cur_film' is assigned a value that is never used.
[functions\parsers\act_to_file_vers2_.c:21]: (style) The scope of the variable 'middle' can be reduced.
[functions\parsers\act_to_file_vers2_.c:50]: (style) The scope of the variable 'cur_film' can be reduced.
[functions\parsers\act_to_file_vers2_.c:49]: (style) Variable 'cur_actor' is assigned a value that is never used.
[functions\parsers\act_to_file_vers2_.c:50]: (style) Variable 'cur_film' is assigned a value that is never used.
[functions\parsers\check.c:7]: (style) The scope of the variable 'prev' can be reduced.
[functions\parsers\parser_[id_name].c:16]: (style) Unused variable: check_id
[functions\parsers\reader.c:25]: (warning) %d in format string (no. 1) requires 'int' but the argument type is 'unsigned int'.
[functions\parsers\struct_parser.c:14]: (style) The scope of the variable 'length' can be reduced.
[functions\parsers\struct_parser.c:18]: (warning) Storing fgetc() return value in char variable and then comparing with EOF.
[functions\parsers\struct_parser.c:34]: (warning) Storing fgetc() return value in char variable and then comparing with EOF.
[functions\parsers\struct_parser.c:42]: (warning) Storing fgetc() return value in char variable and then comparing with EOF.
[functions\parsers\struct_parser.c:63]: (warning) Storing fgetc() return value in char variable and then comparing with EOF.
[functions\struct_actions\graph_solve_optimize_justar.c:14]: (error) Unmatched '('. Configuration: ''.
[functions\struct_actions\justar_time.c:111]: (style) The scope of the variable 'id' can be reduced.
[functions\interfaces\graph_interface.h:48]: (style) The scope of the variable 'temp' can be reduced.
[functions\interfaces\graph_interface.h:118]: (style) The scope of the variable 'index' can be reduced.
[main_func.c:27] -> [main_func.c:51]: (style) Local variable i shadows outer variable
[main_func.c:51] -> [main_func.c:75]: (style) Local variable i shadows outer variable
[functions\parsers\struct_parser.c:53]: (style) The function 'fill_struct' is never used.
[functions\struct_actions\graph_solve_optimize_memory.c:21]: (style) The function 'find_result' is never used.
[functions\file_actions\make_array_act_to_act.c:49]: (style) The function 'reads_in_matrix_of_conections_actors' is never used.
(information) Cppcheck cannot find all the include files (use --check-config for details)
```

