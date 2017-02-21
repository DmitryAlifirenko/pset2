#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void setInitials(string s)
{
    if (s[0] != ' ')
    {
        printf("%c", toupper(s[0]));
    }
    int n = strlen(s);
    for (int i = 0; i < n; i++)
        if (s[i-1] == ' ' && s[i] != ' ' && s[i+1] != ' ')
        {
            printf("%c", toupper(s[i]));
        }
       
    printf("\n");
}

int main(void)
{
    setInitials(GetString());
}
