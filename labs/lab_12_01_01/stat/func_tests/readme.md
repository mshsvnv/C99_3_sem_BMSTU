# Тесты для лабораторной работы №01. Задача №1

## Входные данные

Текстовый файл, в котором хранятся целые числа

---

## Выходные данные

*Упорядоченный по возрастанию массив чисел* случае отсутствия ключа *-f*

__ИЛИ__

*Упорядоченный и отфильтрованный по возрастанию массив чисел*

---

## Негативные тесты

- __01__ - указано неверное кол-во аргументов коммандной строки;<br />
__Выходные данные__ : код завершения __1__
  
- __02__ - отсутствует исходный файл с данными;<br />
__Выходные данные__ : код завершения __2__

- __03__ - отсутствует файл для записи;<br />
__Выходные данные__ : код завершения __2__
  
- __04__ - в исходном файле отсутствуют данные;<br />
__Выходные данные__ : код завершения __3__
  
- __05__ - в аргументах командной строки передано неверное имя ключа;<br />
__Выходные данные__ : код завершения __4__

- __06__ - в файле записаны символы;<br />
__Выходные данные__ : код завершения __7__

- __07__ - передан ключ *f*, в файле записаны одинаковые числа;<br />
__Выходные данные__ : код завершения __6__

- __08__ - передан ключ *f*, в файле записано одно число;<br />
__Выходные данные__ : код завершения __6__

- __09__ - передан ключ *f*, в файле максимальное и минимальное значения находятся рядом;<br />
__Выходные данные__ : код завершения __6__

- __10__ - в файле записаны не целые числа;<br />
__Выходные данные__ : код завершения __7__

---

## Позитивные тесты

- __01__ - исходный файл существует, кол-во аргументов командной строки _2_; данные в файле не осортированы;

- __02__ - исходный файл существует, кол-во аргументов командной строки _2_; данные в файле осортированы по возрастанию; 

- __03__ - исходный файл существует, кол-во аргументов командной строки _2_; данные в файле осортированы по убыванию;

- __04__ - исходный файл существует, кол-во аргументов командной строки _2_; в файле все числа одинаковые;

- __05__ - исходный файл существует, кол-во аргументов командной строки _3_; данные в файле не осортированы;

- __06__ - исходный файл существует, кол-во аргументов командной строки _3_; данные в файле осортированы по возрастанию; 

- __07__ - исходный файл существует, кол-во аргументов командной строки _3_; данные в файле осортированы по убыванию;

- __08__ - исходный файл существует, кол-во аргументов командной строки _2_; в файле 1 число;
  
---
