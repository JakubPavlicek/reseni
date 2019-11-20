#include <cstdio>
#include <string.h>

char output[255];

const char* toUpper(const char* inputX)
{
  char y[strlen(inputX) + 1];
  strncpy(y, inputX, sizeof y);
  for(int i = 0; i < strlen(y); i++)
  {
    if(y[i] > 96 && y[i] < 123) // písmena a-z
    {
      y[i] = y[i] - 32;
    }
    else{
      y[i] = y[i];
    }
  }
  strcpy (output,y);
  return output;
}

int main()
{
  const char* input = "Hello, world!";
  printf("%s", toUpper(input));
  return 0;
}