#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){

   int vector[10];
   int i=0;

   int num;
   int ch;
   int ok;

for(i; i<10; i++){

 do{
      printf("Ingresa un entero posicion [%i]   : ", i+1);
      fflush(stdout);
      if ((ok = scanf("%d", &vector[i])) == EOF)
         return -1;
      
      if ((ch = getchar()) != '\n'){
         ok = 0;
      
         while ((ch = getchar()) != EOF && ch != '\n')
            ;
      }
   }while (!ok);
}
 
        long int mayor = syscall(357,vector,&mayor);
        printf("El numero mayor es: %d \n", mayor);

return 0;
}




