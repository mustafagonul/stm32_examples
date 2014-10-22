#include <mbed.h>
#include <SDFileSystem.h>


SDFileSystem sd(PA_7, PA_6, PA_5, PE_7, "sd"); // the pinout on the mbed Cool Components workshop board


int main()
{
  FILE *fp = fopen("/sd/myfile.txt", "w");
  fprintf(fp, "Hello World!\n");
  fclose(fp);

  return 0;
}
