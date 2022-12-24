# Тесты для лабораторной работы №08

## Входные данные

Название операции; целые положительные числа

---

## Выходные данные

Вычисленное значение в виде списка

---

## Негативные тесты

- __01__ - неверно выбранная операция;<br />
__Выходные данные__ : код завершения __1__

---

### out

- __02__ - значение - **1**;<br />
__Выходные данные__ : код завершения __3__

- __03__ - значение - **отрицательное число**;<br />
__Выходные данные__ : код завершения __3__

- __04__ - значение - **символ**;<br />
__Выходные данные__ : код завершения __3__

---

### mul

- __05__ - одно из значений - **отрицательное число**;<br />
__Выходные данные__ : код завершения __3__

- __06__ - одно из значений - **символ**;<br />
__Выходные данные__ : код завершения __3__

- __07__ - оба значения - **1**;<br />
__Выходные данные__ : код завершения __3__

---

### sqrt

- __08__ - значение - **отрицательное число**;<br />
__Выходные данные__ : код завершения __3__

- __09__ - значение - **символ**;<br />
__Выходные данные__ : код завершения __3__

- __10__ - значение - **1**;<br />
__Выходные данные__ : код завершения __3__

---

### div

- __11__ - одно из значений - **отрицательное число**;<br />
__Выходные данные__ : код завершения __3__

- __12__ - одно из значений - **символ**;<br />
__Выходные данные__ : код завершения __3__

- __13__ - одинаковые значения;<br />
__Выходные данные__ : код завершения __3__

- __14__ - делимое меньше делителя;<br />
__Выходные данные__ : код завершения __3__

- __15__ - деление с остатком;<br />
__Выходные данные__ : код завершения __3__

- __16__ - деление на 0;<br />
__Выходные данные__ : код завершения __3__

---


## Позитивные тесты

### out

- __01__ - значение - целое положительное число;<br />

- __02__ - значение - **простое** целое положительное число;<br />

---

### mul

- __03__ - значения - целые положительные числа;<br />

- __04__ - значения - **1** и целое положительное число;<br />

---

### sqrt

- __05__ - значение - целое положительное число;<br />

---

### div

- __06__ - значения - целые положительные числа, делимое больше делителя;<br />

- __07__ - делитель - **1**, делимое - целое положительное число;<br />

---