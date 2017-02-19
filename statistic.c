#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string getStr(){
  printf("Vvedite stroku: ");
	string s=GetString();
	return s;
}

string setUpper(string s){
  int n = strlen(s);
	char* str=calloc(n, sizeof(char*));
	for (int i=0; i<n; i++){
	  str[i]=toupper(s[i]);
	}
	return str;
}

void amountSymbol(string s){
  int n = strlen(s);
  int amount = 1;
	for (int i = 0; i<n; i++)
	{
		for (int j = i + 1; j<n; j++)
		{
			if (s[i] == s[j])
			{
				amount++;
				s[j] = '@';
			}
		}
	if (isalpha(s[i]))
	printf("%c - %i\n", s[i], amount);
	amount = 1;
	s[i] = '@';
	}
}

int main(void)
{
	amountSymbol(setUpper(getStr()));
}