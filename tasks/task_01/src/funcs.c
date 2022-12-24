#include "../inc/funcs.h"

void apply(int n, ...)
{
    int i;

    va_list directs;
    va_start(directs, n);

    char *cur_dir;

    printf("+---------------+--------------------+---------------+---------------+\n");
    printf("|    Папка      |      Имя файла     |  Кол-во слов  |  Кол-во строк |\n");
    printf("+---------------+--------------------+---------------+---------------+\n");
    

    for (i = 0; i < n; i++)
    {
        cur_dir = va_arg(directs, char *);

        printf("|%8s       |", cur_dir);

        show_cur_dir(cur_dir);

        printf("+---------------+--------------------+---------------+---------------+\n");
    }

    va_end(directs);
}

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

    if (!flag)
        printf("%17s   |%8d       |%8d       |\n", file_name, words_amount, strings_amount);
    else
    {
        printf("|               +--------------------+---------------+---------------+\n");
        printf("|               |%17s   |%8d       |%8d       |\n", file_name, words_amount, strings_amount);
    }

    return;
}

void show_cur_dir(char *current_path)
{
    DIR *current_directory;

    struct dirent *dir;

    int i = 0;

    current_directory = opendir(current_path);

    char *real_path;

    if (current_directory)
    {
        while ((dir = readdir(current_directory)) != NULL)
        {
            if (dir->d_type == 8)
            {
                real_path = get_real_path(current_path, dir->d_name);
                count_words(real_path, i);
                free(real_path);

                i++;
            }
        }
        closedir(current_directory);
    }
    else  
        return;
}

char *get_real_path(char *cur_dir, char *file_name)
{
    int i, len;
    char *real_path = malloc(sizeof(cur_dir) + sizeof(file_name) + 10);

    i = 0;
    while (cur_dir[i])
    {
        real_path[i] = cur_dir[i];
        i++;
    }

    real_path[i] = '/';

    len = i + 1;
    i = 0;

    while (file_name[i])
    {
        real_path[i + len] = file_name[i];
        i++;
    }
    
    real_path[i + len] = '\0';

    return real_path;
}
