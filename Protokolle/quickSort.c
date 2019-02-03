
#define ANZAHL 20

typedef struct {
  int numberArray = 0;
} t_numberArray;

int main (void) {
  t_numberArray numberArray;
  t_numberArray *p = &numberArray;
  int numberArray[];
  numberArray = {12, 85, 10, 26, 39, 90, 72, 49, 38, 19, 93, 50, 39, 8, 2, 34, 46, 83, 67, 21};

  printf("%d", p -> numberArray);
}
