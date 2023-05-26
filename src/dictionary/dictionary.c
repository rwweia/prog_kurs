#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dictionary/dictionary.h>


char *upper_reg(char *str, int size)
{
    for (int i = 1; i < size; i += 2)
    {
        if (((str[i] >= -80 && str[i] <= -65) && str[i - 1] == -48) ||
            ((str[i] >= -128 && str[i] <= 113) && str[i - 1] == -47) ||
            (str[i] == -111 && str[i - 1] == -47))
        {
            if (((str[i] >= -80 && str[i] <= -65) && str[i - 1] == -48))
            {
                str[i] -= 32;
            }
            else if (((str[i] >= -128 && str[i] <= -113) && str[i - 1] == -47))
            {
                str[i] += 32;
                str[i - 1]--;
            }
            else
            {
                str[i] -= 16;
                str[i - 1]--;
            }
        }
    }
    return str;
}

void make_arr(char *in, char *from, int index)
{
    int pos = 0;

    while (pos != index)
    {
        in[pos] = from[pos];
        pos++;
    }
}

char punctuation(char *array)
{
    if (array[strlen(array) - 1] == '.' || array[strlen(array) - 1] == ',' ||
        array[strlen(array) - 1] == ':' || array[strlen(array) - 1] == ';' ||
        array[strlen(array) - 1] == '?' || array[strlen(array) - 1] == '!')
        return array[strlen(array) - 1];

    return '\0';
}