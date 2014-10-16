#include <mbed.h>
#include <SDFileSystem.h>


SDFileSystem sd(PB_0, PB_1, PB_2, PB_3, "sd"); // the pinout on the mbed Cool Components workshop board


int main()
{
  FILE *fp = fopen("/sd/myfile.txt", "w");
  fprintf(fp, "Hello World!\n");
  fclose(fp);

  return 0;
}
