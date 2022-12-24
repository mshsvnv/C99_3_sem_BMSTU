# Дополнительная задача №1

### _Условие задачи:_
Реализовать программу, которая считает кол-во слов в файлах, которые реализуют данную задачу.
Необходимо использовать функцию с переменным кол-вом параметров!

---

### _Алгоритм работы:_
В функцию __apply__ подается в качестве параметров:

1. кол-во папок, находящихся в текущей директории;
2. наименования самих папок;

```c
int main()
{
    apply(3, ".", "src", "inc");
    
    return SUCCESS;
}
```
Затем в цикле проходим по всем переданным папкам и находим подходящие файлы.

```c
// функция с переменным числом параметров
void apply(int n, ...)
{
    int i;

    va_list directs;
    va_start(directs, n);

    char *cur_dir;

    for (i = 0; i < n; i++)
    {
        cur_dir = va_arg(directs, char *);

        show_cur_dir(cur_dir);
    }

    va_end(directs);
}
```

Каждый файл (*имя файлы) передается в функцию __count_words__, где и происходит подсчет слов и строк в файле.
```c
// функция для подсчета слов и строк в файле
void count_words(char *file_name, int flag)
{
    char symb;
    int cur_len, words_amount, strings_amount;

    cur_len = 0;
    words_amount = 0;
    strings_amount = 0;

    if (strstr(file_name, ".exe"))
        return;

    FILE *f_in = fopen(file_name, "r");

    while (!feof(f_in))
    {
        cur_len = 0;

        while ((symb = fgetc(f_in)) != '\n' && symb != EOF)
        {
            if (isalnum(symb))
                cur_len++;
            else
            {
                if (cur_len != 0 && symb != 95 && symb != 46)
                {
                    words_amount += 1;
                    cur_len = 0;
                }
            }
        }
        if (cur_len != 0)
            words_amount += 1;

        strings_amount++;
    }

    fclose(f_in);

    return;
}

```