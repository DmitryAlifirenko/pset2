#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

string getText();
int getLength(char* text);
void encryptText(int length, char* text);
int firstLowercaseLetter=97;
int firstUppercaseLetter=65;
int alphabetLength=26;

int key;
string txt="";

int main(int argc, string argv[]){
    if (argc==2)
    {
        key = atoi(argv[1]);
    }
    else
    {
        printf("Usage: ./caesar <key>");
        return 1;
    }

    encryptText(getLength(getText()),txt);
    printf("\n");
    return 0;
}

string getText(){
    printf("plaintext: ");
    txt = GetString();
    return txt;
}

int getLength(char* text){
    int length = strlen(text);
    return length;
}

void encryptText(int length, char* text){
    printf("ciphertext: ");
    for(int i = 0; i < length; i++){
          if(isalpha(text[i]))
        {
            if(islower(text[i]))
            {
                printf("%c", ((((text[i] - firstLowercaseLetter)+key)%alphabetLength)+firstLowercaseLetter));
            }
            else
            {
                printf("%c", ((((text[i] - firstUppercaseLetter)+key)%alphabetLength)+firstUppercaseLetter));
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
}
