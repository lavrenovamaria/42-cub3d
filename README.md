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
NO ./assets/WALL.xpm(Текстура северная) 
SO ./assets/WALL.xpm(Текстура южная)
WE ./assets/WALL.xpm(Текстура западная)
EA ./assets/WALL.xpm(Текстура восточная)

F 20,20,20(Пол)
C 20,20,20(Потолок)

	1111111111111111111111111
	1000000000110000000000001
	1011000001110000000000001
	1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000000000000010001
100000000000000011010100d0001
1101011111010101111101111000111
11110111 1110101 101011010S01
11111111 1111111 111111111111
```
Существует две версии библиотеки minilibx, которые можно скачать в Интре: opengl и mms. \
mms: это самая последняя версия библиотеки MiniLibX. Чтобы использовать функцию mlx_get_screen_size, например, которая получает максимальное разрешение монитора, вам нужно скомпилировать библиотеку mms. \
opengl: это устаревшая версия библиотеки MiniLibX.

#### ```void *mlx_init();```
Установка соединения между программой и графической системой. Никаких параметров не требуется для неё. Вернет идентификатор void*, используемый для дальнейших вызовов библиотечных подпрограмм. Это соединение должно быть создано до того, как можно будет использовать другие функции mlx.
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
Рубрика "эксперименты"(вот этот код ниже выведет нам белый квадратик):
```
typedef struct s_image {
	void	*img;
	char	*data;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_image;

int main()
{
	void	*mlx;
	void	*win;
	int	width;
	int	height;
	int	i;
	int	j;
	t_image	image;

	width = 200;
	height = 200;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "hop-hey-lalaley");
	image.img = mlx_new_image(mlx, width, height);
	image.data = (int *)mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			image.data[i * width + j] = 0xFFFFFF;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, win, image.img, 30, 30);
	mlx_loop(mlx);
	return(0);
}
```
#### ```mlx_xpm_file_to_image (void mlx_ptr, char filename, int width, int *height);```
Эта функция позволяет применить файл xpm в качестве текстуры к данным изображения. Получите размер файла xpm через переменные ширины и высоты. В переменной ```*filename``` введите имя xpm-файла, который будет использоваться в качестве изображения. Если вы передаете имя файла и адрес переменной типа int, файл xpm преобразуется в изображение и возвращается указатель на изображение.
```
typedef struct s_image {
	void	*img;
	char	*data;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}		t_image;

int main()
{
	void	*mlx;
	void	*win;
	int	width;
	int	height;
	int	i;
	int	j;
	t_image	image;

	mlx = mlx_init();
  	win = mlx_new_window(mlx, 500, 500, "hop-hey-lalaley");
  	image.img = mlx_xpm_file_to_image(mlx, "./fotka_kota.xpm", &width, &height);
  	mlx_put_image_to_window(mlx, win, image.img, 30, 30);
	mlx_loop(mlx);
	return(0);
```
#### ```int mlx_key_hook(void win_ptr, int ( funct_ptr)(), void param);```
```*win_ptr``` - введите значение, возвращаемое функцией mlx_new_window (значение, указывающее на конкретное окно). (```*funct_ptr```)() : введите значение указателя используемой функции. (Кнопка, нажатая пользовательским значением int, используется как первый параметр введенной функции). \
param - ведите переменные, которые будут использоваться в функции (если нужно использовать много переменных, сгруппируйте их в структуру и введите). В конце должна использоваться функция mlx_loop .
#### ```int mlx_loop(void *mlx_ptr);```
Это функция, которая бесконечно зацикливается и ожидает события от клавиатуры или мыши. 
#### ```int mlx_hook(void win_ptr, int x_event, int x_mask, int (funct)(), void *param);```
x_event - событие, определенное в библиотеке X11. Введите событие, которое вы хотите сгенерировать, как тип int в качестве параметра функции mlx_hook. x_mask - обычно вводится 0(почему хз). Отличие от mlx_key_hook: в mlx_key_hook событие происходит временно при каждом нажатии клавиши, но в mlx_hook событие повторяется бесконечно, пока клавиша нажата.
#### ```int mlx_loop_hook(void mlx_ptr, int ( funct_ptr)(), void *param);```
Функция, введенная в качестве параметра в ```(*funct_ptr)()```, выполняется бесконечно без условия возникновения события.
### Как тебя парсить будем? Заметки
1. ???
Как-то дефайним
```
 # define NORTH 0
 # define SOUTH 1
 # define WEST 2
 # define EAST 3
 # define SPRITE 4
 # define RESOLUTION 5
 # define FLOOR_COLOR 6
 # define CEILING_COLOR 7
```
### Raycasting

Raycasting: это быстрая полу-3D-технология, которая создает трехмерную перспективу на двумерной карте.
Raycasting работает быстро, потому что он рассчитывает только каждую вертикальную линию на экране.
Raycasting был первым решением в прошлом, когда компьютеры были медленнее, чем сегодня, и 3D-движок не мог работать в режиме реального времени.

#### Базовые штуки

0 значит стен нет
1 стена
N, S, W, E направление взгляда игрока при запуске игры
Что-то другое - ошибка
1. Для каждого значения х(для каждой вертикальной линии) мы запускаем луч от позиции игрока.
2. Луч движется прямо по 2D-карте, пока не упрется в стену, и когда он попадет в стену, вычислится расстояние от точки попадания до игрока (расстояние по перпендикуляру к стене). Это расстояние определяет, насколько высоко стена должна быть отрисована на экране. Высота стены отображается на экране ниже по мере увеличения расстояния между игроком и стеной и выше по мере увеличения расстояния между игроком и стеной. Все это можно получить с помощью двумерных расчетов, а верхнее изображение представляет собой двумерный вид сверху. Обратите внимание, что луч начинается с игрока и достигает стены.

#### Raycasting метод
Чтобы найти первую стену, в которую попадает луч, вы должны запустить луч с позиции игрока и итеративно проверить, ударяется ли луч в стену.
Когда подтверждается, что луч входит в стену (попадание), цикл, проверяющий, входит ли луч в стену, останавливается, и расстояние (вертикальный луч попал в стену) измеряется и стена рисуется необходимой высотой. И наоборот, если обнаруживается, что луч не содержится в стене, его трассировка продолжается. В новом положении, совпадающем с направлением луча, еще раз проверьте, входит ли он в стену. Повторяйте, пока не упретесь в стену.
В отличие от человека, который может с первого взгляда сказать, где луч падает на стену, компьютер не может определить единственную формулу, потому что он может исследовать только ограниченное количество точек на пути луча.

#### Метод добавления константной величины к позиции луча. Луч добавляет постоянное значение к положению луча и итеративно проверяет, попал ли он в стену.:
1. При этом методе, даже если он ударится о стену, есть вероятность, что он промахнется по ней и решит, что не ударился о стену.
2. Например, в случае исследования красных точек, отстоящих от луча на верхнем изображении, луч проходит прямо через синюю стену, но компьютер этого не обнаружил, потому что смотрел только на то место, где была красная точка.
3. Проверка большего количества местоположений снижает вероятность того, что компьютер промахнется по стене, но добавляет больше вычислений.

![map2](https://user-images.githubusercontent.com/84707645/155163439-88ef0726-f09e-4308-ae78-d982cf5849d9.gif)

#### Метод проверки за счет сокращения интервала между точками осмотра в два раза
1. Уменьшив расстояние шага контрольной точки в два раза, можно подтвердить, что луч прошел сквозь стену, но проблема в том, что положение все равно не точное.
2. Ограничение: чтобы получить бесконечную точность при добавлении постоянного значения к положению луча и использовании итерационного метода, интервал между контрольными точками должен быть бесконечно мал, и тогда требуется бесконечное количество вычислений.

![map3](https://user-images.githubusercontent.com/84707645/155165512-9a099892-63c7-49e9-a7f2-92985a8d9bab.gif)

#### Алгоритм цифрового дифференциального анализа (DDA)
1. Хотя бесконечное уменьшение расстояния между контрольными точками описанным выше способом не ужасно, есть лучший способ обнаружить все стены с минимальными вычислениями или вообще без них. Это метод исследования всех сторон стены, на которые падает луч.
2. Таким образом, поскольку ширина одного квадрата равна 1, все стены могут быть выражены целыми числами. Интервал между контрольными точками не является постоянным, но интервал между контрольными точками изменяется в зависимости от расстояния до соседней стороны. Таким образом, лучи попадают именно туда, куда мы хотим.
3. Алгоритм DDA — это быстрый алгоритм, обычно используемый для определения того, какие квадраты сталкиваются с линией, проходящей через двумерную сетку. Вы можете использовать этот алгоритм, чтобы узнать, в какие квадраты попадает луч на карте, и когда он обнаруживает, что попал в стену, алгоритм останавливается.
4. Некоторые трассировщики лучей используют евклидовы углы для указания направления игрока и лучи для определения поля зрения, но гораздо проще работать с векторами и камерами.
5. Позиция игрока всегда является вектором. Если направление выражено в виде вектора, оно определяется двумя значениями: координатой x и координатой y вектора направления.
6. При рисовании линии в направлении, которое видит игрок, все точки на линии представляют собой сумму «положение игрока + кратные вектору направления».
7. Важно только направление вектора направления, а длина не очень важна. Умножение x и y на одно и то же значение указывает на одно и то же направление, даже если длина изменяется.

![dda](https://user-images.githubusercontent.com/84707645/155165721-2d985948-63b9-4d1c-9116-05b1f3f14d7e.gif)

#### Вид камеры

![vector](https://user-images.githubusercontent.com/84707645/155168910-7085fe20-d49b-44a3-a5f6-36eef7259f48.gif)

1. Помимо вектора направления, для использования вектора также требуется плоскость камеры.
2. Плоскость камеры (синяя) представляет собой поверхность экрана компьютера, а вектор направления (черный) указывает внутрь экрана.
3. Плоскость камеры всегда перпендикулярна вектору направления.
4. Положение игрока, выраженное в виде точки, расположено перед плоскостью камеры.
5. Конкретный луч с определенной координатой x на экране — это луч, который начинается в этой позиции игрока и проходит через эту позицию на экране или в плоскости камеры.
6. Поскольку настоящий 3D-движок работает с 3D, требуются два вектора, но рейкастинг, работающий с 2D-картой, отображает один вектор, потому что плоскость камеры — это не реальная плоскость, а линия.
#### Представление вектора
