#include <stdio.h>
#include <string.h>

char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main()
{
    char pair[25];
    char str[50];
    scanf("%s", pair);
    scanf("%s", str);
    
    char enc[5][5];
    int id = -1;
    int pair_len = strlen(pair);
    int str_len = strlen(str);
    
    for (int i = 0; i < 25; i++)
    {
        if (i < pair_len)
        {
            enc[i / 5][i % 5] = pair[i];
            letters[pair[i] - 'a'] = 0;
        }
        else
        {
            while (!letters[++id])
                continue;
            enc[i / 5][i % 5] = letters[id];
        }
    }
    
    for (int i = 0; i < str_len; i += 2)
    {
        if (str[i + 1] == '\0')
        {
            printf("%c", str[i]);
            break;
        }
        
        if (str[i] == str[i + 1])
        {
            printf("%c%c", str[i], str[i + 1]);
            continue;
        }
        
        int k1 = 10, j1 = 10, k2 = 10, j2 = 10;
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (enc[j][k] == str[i])
                {
                    j1 = j;
                    k1 = k;
                }
                if (enc[j][k] == str[i + 1])
                {
                    j2 = j;
                    k2 = k;
                }
            }
        }
        
        if (j1 < 5 && j2 < 5)
        {
            if (j1 == j2 || k1 == k2)
                printf("%c%c", str[i + 1], str[i]);
            else
                printf("%c%c", enc[j1][k2], enc[j2][k1]);
        }
        else
        {
            printf("%c%c", str[i], str[i + 1]);
        }
    }
    
    return 0;
}
