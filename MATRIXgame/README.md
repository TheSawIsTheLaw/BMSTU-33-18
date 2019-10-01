### Статистика по написанным на данный момент функциям
`get_by_pos`  
[![Pipeline status](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/badges/matrixgame_get_by_pos/pipeline.svg)](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/commits/matrixgame_get_by_pos) [![Coverage report](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/badges/matrixgame_get_by_pos/coverage.svg)](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/commits/matrixgame_get_by_pos)  
`set_by_pos`  
[![Pipeline status](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/badges/matrixgame_set_by_pos/pipeline.svg)](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/commits/matrixgame_set_by_pos) [![Coverage report](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/badges/matrixgame_set_by_pos/coverage.svg)](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/commits/matrixgame_set_by_pos)  
`add_column`  
[![Pipeline status](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/badges/matrixgame_add_column/pipeline.svg)](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/commits/matrixgame_add_column) [![Coverage report](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/badges/matrixgame_add_column/coverage.svg)](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/commits/matrixgame_add_column)  
`del_row_`  
[![Pipeline status](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/badges/matrixgame_del_row_/pipeline.svg)](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/commits/matrixgame_del_row_) [![Coverage report](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/badges/matrixgame_del_row_/coverage.svg)](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/commits/matrixgame_del_row_)  
`transpose`  
[![Pipeline status](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/badges/matrixgame_transpose/pipeline.svg)](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/commits/matrixgame_transpose) [![Coverage report](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/badges/matrixgame_transpose/coverage.svg)](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/commits/matrixgame_transpose)  
`print_matrix`  
[![Pipeline status](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/badges/matrixgame_print_matrix/pipeline.svg)](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/commits/matrixgame_print_matrix) [![Coverage report](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/badges/matrixgame_print_matrix/coverage.svg)](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/commits/matrixgame_print_matrix)  
`create_matrix`  
[![Pipeline status](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/badges/matrixgame_create_matrix/pipeline.svg)](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/commits/matrixgame_create_matrix) [![Coverage report](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/badges/matrixgame_create_matrix/coverage.svg)](https://git.iu7.bmstu.ru/aolenev/iu7-cprog-sems-2019-aolenev/commits/matrixgame_create_matrix)

### Общее описание задачи
Пишем набор функций для работы с матрицей, которая удовлетворяет нижеуказанным свойствам:

* Матрица в памяти представлена массивом указателей на указатели int **matrix, (строки будут разбросаны по памяти рандомно, линейность отсутствует, это стоит учитывать при написании функций)

* Матрица явлется полем структуры, в которую также входят еще 2 поля - размерность матрицы

* Строками матрицы является структура данных, созданная в предыдущем семинарском проекте (ARRgame). С вопросами по использованию функций данной структуры обращаться к @yadv18u603

* Все дейтвия с матрицей реализуются с использованием ***адресной арифметики***

* Пишут функцию также по 2 человека (первый - функция, второй тесты к функции). Те, кто желание бешеное имеет, могут по две или три функции писать, я буду ходатайствовать о добавке вам баллов. 

* Как только вы получили функцию узнайте у архитектора формат входных и выходных вашей функции(Тем, кто пишет функции). Вопросы по данной теме к архитектору @tpa18u531.

* Тестерам по вопросам формата функций тестирования обращаться к @ks18u889.

