# 42-cub3d
Devil with that deadlines and your f-ing work-life balance, Karen \
Что по [сабжу](https://github.com/lavrenovamaria/42-cub3d/files/8080052/en.subject.pdf):
1. Разрешенные функции - open, close, read, write, printf, malloc, free, perror, strerror, exit, все функции либы math и либы minilibx
2. Клавиши со стрелками влево и вправо позволяют повернуть взор влево-вправо в лабиринте
3. Клавиши A и D позволяют переместиться вправо-влево в лабиринте(приставной шаг)
4. Клавиши W и S позволяют идти вперед-назад
5. Нажатие ESC закрывает окно, окно также можно свернуть и развернуть, изменить размер нельзя из-за ограничений библиотеки minilibx. Нажатие на красный крестик так же закрывает программу полностью(не висит в ожидании в терминале).
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
Существует две версии библиотеки minilibx, которые можно скачать в Интре: opengl и mms. \
mms: это самая последняя версия библиотеки MiniLibX. Чтобы использовать функцию mlx_get_screen_size, например, которая получает максимальное разрешение монитора, вам нужно скомпилировать библиотеку mms. \
opengl: это устаревшая версия библиотеки MiniLibX.

#### ```void *mlx_init();```
Установка соединения между программой и графической системой. Никаких параметров не требуется для неё. Вернет идентификатор void*, используемый для дальнейших вызовов библиотечных подпрограмм.
#### ```mlx_new_window(void mlx_ptr, int size_x, int size_y, char *title);```
Функция, создающая окно. В mlx_ptr будет местоположение экземпляра MLX, возвращенного функцией mlx_init(). Параметры ширины и высоты определяют размер окна, ```char *title``` указывает имя окна в заголовке
#### ```int mlx_destroy_window(void mlx_ptr, void win_ptr);```
Функция, закрывающая окно. Введите значение, возвращаемое функцией mlx_new_window, в ```*win_ptr.```
#### ```int mlx_pixel_put(void mlx_ptr, void win_ptr, int x, int y, int color);```
Это та самая медленная функция, которая не записывает в буфер, а выводит сразу на экран попиксельно, поэтому её стоит заменить самописной(взять из ридмишки по фрактолу). Введите данные о цвете типа int в позиции (x, y) окна. Введите значение, возвращаемое функцией mlx_new_window, в ```*win_ptr```
#### ```mlx_new_image(void mlx_ptr, int width, int height);```
Введите размер изображения для ввода по ширине и высоте.
Создаёт буфер для всех пикселей изображения и поместит все данные пикселей в окно через буфер. Типа того.
#### ```mlx_get_data_addr(void img_ptr, int bits_per_pixel, int line_length, int *endian);```
Он получает адрес памяти для ввода изображения. Введите возвращаемое значение для изображения, созданного в ```*img_ptr```. Вы можете узнать способ хранения данных[(прямой или обратный порядок байтов)](https://russianblogs.com/article/5102954868/) через ```*endian```.
Как узнать big или little endian у вас на компуктере:
```
#include <stdio.h>
int main ()
{
  unsigned int x = 0x76543210;
  char *c = (char*) &x;
 
  printf ("*c is: 0x%x\n", *c);
  if (*c == 0x10)
    printf ("Underlying architecture is little endian. \n");
  else
     printf ("Underlying architecture is big endian. \n");
  return 0;
}
```
```*bits_per_pixel``` — количество битов, необходимых для представления одного пикселя. [Жуткая ридмишка по цветам да ещё и на корейском(everybody gon' respect the reader, but the one in front of the readme lives forever)](https://github.com/p-eye/cub3d_texturing/blob/master/1.mlx_get_data_addr.md)
#### ```int mlx_put_image_to_window(void mlx_ptr, void win_ptr, void *img_ptr, int x, int y);```
Данные о пикселях, полученные в пространстве изображения из позиции (x, y) окна, выводятся в окне. Введите значение, возвращаемое функцией mlx_new_window, в ```*win_ptr.``` Введите возвращаемое значение для изображения, созданного в ```*img_ptr.```
#### ```mlx_xpm_file_to_image (void mlx_ptr, char filename, int width, int *height);```
Эта функция позволяет применить файл xpm в качестве текстуры к данным изображения. Получите размер файла xpm через переменные ширины и высоты. В переменной ```*filename``` введите имя xpm-файла, который будет использоваться в качестве изображения.
#### ```int mlx_key_hook(void win_ptr, int ( funct_ptr)(), void param);```
```*win_ptr``` - введите значение, возвращаемое функцией mlx_new_window (значение, указывающее на конкретное окно). (```*funct_ptr```)() : введите значение указателя используемой функции. (Кнопка, нажатая пользовательским значением int, используется как первый параметр введенной функции). \
param - ведите переменные, которые будут использоваться в функции (если нужно использовать много переменных, сгруппируйте их в структуру и введите). В конце должна использоваться функция mlx_loop .
#### ```int mlx_loop(void *mlx_ptr);```
Он бесконечно зацикливается и ждет, пока не произойдет событие, произвольно определенное в программе.
#### ```int mlx_hook(void win_ptr, int x_event, int x_mask, int (funct)(), void *param);```
x_event - событие, определенное в библиотеке X11. Введите событие, которое вы хотите сгенерировать, как тип int в качестве параметра функции mlx_hook. x_mask - обычно вводится 0(почему хз). Отличие от mlx_key_hook: в mlx_key_hook событие происходит временно при каждом нажатии клавиши, но в mlx_hook событие повторяется бесконечно, пока клавиша нажата.
#### ```int mlx_loop_hook(void mlx_ptr, int ( funct_ptr)(), void *param);```
Функция, введенная в качестве параметра в ```(*funct_ptr)()```, выполняется бесконечно без условия возникновения события.
### Как тебя парсить будем? Заметки
1. Получаем файл карты в качестве аргумента основной функции
2. Файл карты парсится в чаровскую переменную построчно с помощью функции get_next_line.
3. 

