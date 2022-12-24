# Тесты для лабораторной работы №08

## Входные данные

Текстовые файлы, в которых хранятся матрицы, записанные в "простом" формате

---

## Выходные данные

*Матрица*, записанная в "простом" формате, в случае ключей *a* или *m*

__ИЛИ__

*Обратная матрица*, записанная в "простом" формате, в случае ключей *o*

---

## Негативные тесты

- __01__ - указано неверное кол-во аргументов коммандной строки;<br />
__Выходные данные__ : код завершения __1__

- __02__ - в аргументах командной строки передано неверное имя ключа;<br />
__Выходные данные__ : код завершения __1__
  
- __03__ - отсутствует исходный файл с данными;<br />
__Выходные данные__ : код завершения __2__
  
- __04__ - в исходном файле отсутствуют данные;<br />
__Выходные данные__ : код завершения __3__

- __05__ - в файле неверно записана размерность матрицы;<br />
__Выходные данные__ : код завершения __4__

- __06__ - в файле кол-во цифр матрицы не соответствует размерности;<br />
__Выходные данные__ : код завершения __4__

- __07__ - в файле записаны символы;<br />
__Выходные данные__ : код завершения __7__

- __08__ - передан ключ *a*, размерности матриц неодинаковые;<br />
__Выходные данные__ : код завершения __4__

- __09__ - передан ключ *m*, кол-во столбцов в первой матрице не равно кол-ву строк второй матрицы;<br />
__Выходные данные__ : код завершения __4__

- __10__ - передан ключ *o*, матрица не квадратная;<br />
__Выходные данные__ : код завершения __4__

- __11__ - передан ключ *o*, матрица вырожденная;<br />
__Выходные данные__ : код завершения __8__

---

## Позитивные тесты

- __01__ - исходные файлы существуют, кол-во аргументов командной строки _5_; ключ *а*; размерность матриц: _2x2_;

- __02__ - исходные файлы существуют, кол-во аргументов командной строки _5_; ключ *а*; размерность матриц: _1x5_;

- __03__ - исходные файлы существуют, кол-во аргументов командной строки _5_; ключ *а*; размерность матриц: _5x1_;

- __04__ - исходные файлы существуют, кол-во аргументов командной строки _5_; ключ *а*; размерность матриц: _1x1_;

- __05__ - исходные файлы существуют, кол-во аргументов командной строки _5_; ключ *m*; размерность матриц: _2x2_;

- __06__ - исходные файлы существуют, кол-во аргументов командной строки _5_; ключ *m*; размерности матриц: _3x2_, _2x3_;

- __07__ - исходные файлы существуют, кол-во аргументов командной строки _5_; ключ *m*; размерности матриц: _1x4_, _4x1_;
  
- __08__ - исходные файлы существуют, кол-во аргументов командной строки _5_; ключ *m*; размерности матриц: _4x1_, _1x4_;
  
- __09__ - исходные файлы существуют, кол-во аргументов командной строки _5_; ключ *m*; размерность матриц: _1x1_;

- __10__ - исходные файлы существуют, кол-во аргументов командной строки _4_; ключ *o*; размерность матрицы: _3x3_;

- __11__ - исходные файлы существуют, кол-во аргументов командной строки _4_; ключ *o*; размерность матрицы: _1x1_;
- 
---