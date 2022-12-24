# Рубежный контроль №1

## Входные данные

Текстовый файл, в котором хранится матрица, записанные в "простом" формате

---

## Выходные данные

*Матрица*, записанная в "простом" формате

---

## Негативные тесты

- __01__ - указано неверное кол-во аргументов коммандной строки;<br />
__Выходные данные__ : код завершения __1__

- __02__ - отсутствует исходный файл с данными;<br />
__Выходные данные__ : код завершения __2__
  
- __03__ - в исходном файле отсутствуют данные;<br />
__Выходные данные__ : код завершения __3__

- __04__ - в файле неверно записана размерность матрицы;<br />
__Выходные данные__ : код завершения __4__

- __05__ - в файле кол-во цифр матрицы не соответствует размерности;<br />
__Выходные данные__ : код завершения __4__

- __06__ - в файле записаны символы;<br />
__Выходные данные__ : код завершения __7__

- __07__ - в файле несколько максимумов;<br />
__Выходные данные__ : код завершения __7__

- __08__ - в файле неквадратная матрица;<br />
__Выходные данные__ : код завершения __4__

- __09__ - в файле матрица размером _1х1_;<br />
__Выходные данные__ : код завершения __4__

---

## Позитивные тесты

- __01__ - исходные файлы существуют, кол-во аргументов командной строки _3_; размерность матриц: _2x2_; максимум на главной диагонали; 

- __02__ - исходные файлы существуют, кол-во аргументов командной строки _3_; размерность матриц: _2x2_; максимум над главной диагональю; 
  
- __03__ - исходные файлы существуют, кол-во аргументов командной строки _3_; размерность матриц: _2x2_; максимум под главной диагональю; 

- __04__ - исходные файлы существуют, кол-во аргументов командной строки _3_; размерность матриц: _10x10_; максимум на главной диагонали; 

- __05__ - исходные файлы существуют, кол-во аргументов командной строки _3_; размерность матриц: _10x10_; максимум над главной диагональю; 
  
- __06__ - исходные файлы существуют, кол-во аргументов командной строки _3_; размерность матриц: _10x10_; максимум под главной диагональю; 

---