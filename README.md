# 42-cub3d
Devil with that deadlines and your f-ing work-life balance, Karen \
Что по [сабжу](https://github.com/lavrenovamaria/42-cub3d/files/8080052/en.subject.pdf):
1. Разрешенные функции - open, close, read, write, printf, malloc, free, perror, strerror, exit, все функции либы math и либы minilibx
2. Клавиши со стрелками влево и вправо позволяют повернуть взор влево-вправо в лабиринте
3. Клавиши A и D позволяют переместиться вправо-влево в лабиринте(приставной шаг)
4. Клавиши W и S позволяют идти вперед-назад
5. Нажатие ESC закрывает окно, окно так же можно свернуть и развернуть, изменить размер нельзя из-за ограничесний библиотеки minilibx. Нажатие на красный крестик так же закрывает программу полностью(не висит в ожидании в терминале).
6. Карта должна состоять только из 6 возможных символов: 0 для пустого места, 1 для стены и N,S,E или W для стартовой позиции игрока и его ориентации в пространстве.
7. Карта должна быть закрыта/окружена стенами, иначе программа должна выдать ошибку.
8. За исключением содержимого карты, каждый тип элемента может быть разделен одной или несколькими пустыми строками.
9. За исключением содержимого карты, которое всегда должно быть последним, каждый тип элемента может быть установлен в файле в любом порядке.
10. За исключением карты, каждый тип информации из элемента может быть разделен одним или несколькими пробелами.
11. Карта должна быть распарсена(распаршена?) так, как она представлена в файле. Пробелы являются допустимой частью карты и их обработка на ваше усмотрение. Вы должны иметь возможность парсить карту любого типа, если она соответствует правилам карты.
12. Если в файле обнаружена какая-либо неверная конфигурация любого рода, программа должна корректно завершить работу и вернуть "Error\n", за которым следует явное сообщение об ошибке на ваш выбор.

Из чего состоит конфигурационный файл(папка maps, расширение .cub):
```
R 848 480(Разрешение изображения)
NO textures/wall_1.xpm(Текстура северная)
SO textures/wall_2.xpm(Текстура южная)
WE textures/wall_3.xpm(Текстура западная)
EA textures/wall_4.xpm(Текстура восточная)
S textures/sprite_1.xpm(Текстура самого спрайта)
F 184,113,39(Пол)
C 51,198,227(Потолок)
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 1 1 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1
1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1
1 0 1 1 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1
1 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 1 1 1 0 1 1 1 1 0 0 0 1
1 1 1 1 0 1 1 1 1 1 1 1 1 1 0 1 1 1 0 0 0 0 0 0 1 0 0 0 1
1 1 1 1 0 1 1 1 1 1 1 1 1 1 0 1 1 1 0 1 0 1 0 0 1 0 0 0 1
1 1 0 0 0 0 0 0 1 1 0 1 0 1 0 1 1 1 0 0 0 0 0 0 1 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 2 0 1 0 0 2 0 0 0 1
1 1 0 0 0 0 0 0 1 1 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 1 1 1 0 1 1 1 1 1 0 1 0 1 0 0 0 0 0 0 2 0 2 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 0 0 0 2 0 0 0 0 1 0 0 1
1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 1
1 0 0 0 0 0 0 0 0 0 1 1 0 1 0 0 0 0 0 0 N 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
```
