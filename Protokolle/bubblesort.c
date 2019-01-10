int main() {
  int mat[] = {42, 17, 33, 81, 92, 43, 10};
  int i, j, temp;

  for(i = 0; i < 6; i++)
    for(j = 0; j < 6; j++) {
      if(mat[j] > mat[j+1]) {
        temp = mat[j];
        mat[j] = mat[j+1];
        mat[j+1] = temp;
      }
    }

    // Sort by name
}
