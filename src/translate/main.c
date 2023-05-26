#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include <dictionary/dictionary.h>

#define SIZE_WORD 20
#define SIZE_STRING 200


int main(int argc, char *argv[])
{
    FILE *rus = fopen(argv[1], "r");
    FILE *dict = fopen(argv[2], "r");
    FILE *eng = fopen(argv[3], "w");

    if (rus == NULL || dict == NULL || eng == NULL)
    {
        printf("Can't open file\n");
        return 0;
    }
    else if (argc != 4)
    {
        printf("Error argument\n");
        return 0;
    }

    while (feof(rus) == 0)
    {
        char *word_rus = (char *)malloc(sizeof(char) * SIZE_WORD);
        int flag = 0;

        fscanf(rus, "%s\n", word_rus);

        while (feof(dict) == 0)
        {
            char *dict_rus_buff = (char *)malloc(sizeof(char) * SIZE_WORD);
            char *word_rus_buff = (char *)malloc(sizeof(char) * SIZE_WORD);
            char *word_dict = (char *)malloc(sizeof(char) * SIZE_STRING);
            char symbol;
            int pos_word_dict = 0;

            fgets(word_dict, SIZE_STRING, dict);

            while (word_dict[pos_word_dict] != ' ')
                pos_word_dict++;

            char *dict_rus = (char *)malloc(sizeof(char) * pos_word_dict);

            make_arr(dict_rus, word_dict, pos_word_dict);
            strcpy(dict_rus_buff, dict_rus);
            upper_reg(dict_rus_buff, strlen(dict_rus_buff));
            strcpy(word_rus_buff, word_rus);

            if (punctuation(word_rus_buff) != '\0')
            {
                symbol = punctuation(word_rus_buff);
                word_rus_buff[strlen(word_rus_buff) - 1] = '\0';
            }

            upper_reg(word_rus_buff, strlen(word_rus_buff));

            if (strcmp(dict_rus_buff, word_rus_buff) == 0)
            {
                char word_eng[SIZE_WORD];
                int index_dict_eng = 0;

                for (size_t n = 0; n < strlen(word_dict); n++)
                {
                    if (isalpha(word_dict[n]) != 0)
                    {
                        word_eng[index_dict_eng] = word_dict[n];
                        index_dict_eng++;
                    }
                }

                word_eng[index_dict_eng] = '\0';

                if (punctuation(word_rus) != '\0')
                    fprintf(eng, "%s%c ", word_eng, symbol);
                else
                    fprintf(eng, "%s ", word_eng);

                flag = 1;
            }
            free(word_dict);
            free(dict_rus_buff);
            free(word_rus_buff);
            free(dict_rus);
        }
        fseek(dict, 0, SEEK_SET);

        if (flag == 0)
            fprintf(eng, "%s ", word_rus);

        if (punctuation(word_rus) != '\0')
            fprintf(eng, "%c", '\n');

        free(word_rus);
    }

    fclose(rus);
    fclose(eng);
    fclose(dict);

    return 0;
}


