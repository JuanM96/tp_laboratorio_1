#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float num1=0; // Variable del valor A
    float num2=0; // Variable del valor B
    float sumaRes; // Resultado de la suma
    float restaRes; // Resultado de la resta
    float divisionRes; // Resultado de la division
    float multiplicacionRes; // Resultado de la multiplicacion
    float factorialRes; // Resultado del factorial
    float factorialAux; // Auxiliar para validar un error en factorial
    int flagNum1=0; // Bandera para saber si se ingreso el numero A
    int flagNum2=0; // Bandera para saber si se ingreso el numero B
    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1: // 1- Ingresar 1er operando (A=x)
                num1=getFloat("Ingrese el 1er operando: ");
                flagNum1=1;
                printf("--------------------------\n");
                printf("A=[%.2f]\n",num1);
                printf("--------------------------\n");
                break;
            case 2: // 2- Ingresar 2do operando (B=y)
                num2=getFloat("Ingrese el 2do operando: ");
                flagNum2=1;
                printf("--------------------------\n");
                printf("B=[%.2f]\n",num2);
                printf("--------------------------\n");
                break;
            case 3: // 3- Calcular la suma (A+B)
                if(flagNum1==1 && flagNum2==1)
                {
                    sumaRes=sumar(num1,num2);
                    printf("--------------------------\n");
                    printf("A+B=[%.2f]\n",sumaRes);
                    printf("--------------------------\n");
                }
                else if (flagNum1==0 || flagNum2==0)
                {
                    printf("--------------------------\n");
                    printf("ERROR,Falta ingresar el algun operando (A) o (B)\n");
                    printf("--------------------------\n");
                }
                break;
            case 4: // 4- Calcular la resta (A-B)
                if(flagNum1==1 && flagNum2==1)
                {
                    restaRes=restar(num1,num2);
                    printf("--------------------------\n");
                    printf("A-B=[%.2f]\n",restaRes);
                    printf("--------------------------\n");
                }
                else if (flagNum1==0 || flagNum2==0)
                {
                    printf("--------------------------\n");
                    printf("ERROR,Falta ingresar el algun operando (A) o (B)\n");
                    printf("--------------------------\n");
                }
                break;
            case 5: // 5- Calcular la division (A/B)
                if(flagNum1==1 && flagNum2==1)
                {
                    if (num2==0)
                    {
                        printf("--------------------------\n");
                        printf("MATH ERROR, Imposible division por 0\n");
                        printf("--------------------------\n");
                    }
                    else
                    {
                        divisionRes=dividir(num1,num2);
                        printf("--------------------------\n");
                        printf("A/B=[%.2f]\n",divisionRes);
                        printf("--------------------------\n");
                    }
                }
                else if (flagNum1==0 || flagNum2==0)
                {
                    printf("--------------------------\n");
                    printf("ERROR,Falta ingresar el algun operando (A) o (B)\n");
                    printf("--------------------------\n");
                }
                break;
            case 6: // 6- Calcular la multiplicacion (A*B)
                if(flagNum1==1 && flagNum2==1)
                {
                multiplicacionRes=multiplicar(num1,num2);
                printf("--------------------------\n");
                printf("A*B=[%.2f]\n",multiplicacionRes);
                printf("--------------------------\n");
                }
                else if (flagNum1==0 || flagNum2==0)
                {
                    printf("--------------------------\n");
                    printf("ERROR,Falta ingresar el algun operando (A) o (B)\n");
                    printf("--------------------------\n");
                }
                break;
            case 7: // 7- Calcular el factorial (A!)
                if(flagNum1==1)
                {
                    if (num1>34)
                    {
                        printf("--------------------------\n");
                        printf("ERROR,Numero demasiado grande\nPor favor ingrese un numero menor a 34 para calcular A!");
                        printf("\n--------------------------\n");
                    }
                    else if(num1<0)
                    {
                        printf("--------------------------\n");
                        printf("MATH ERROR, Ingreso un numero negativo\n");
                        printf("--------------------------\n");
                    }
                    else
                    {
                        factorialAux= num1-(int)num1;
                        if (factorialAux==0)
                        {
                            factorialRes=factorial(num1);
                            printf("--------------------------\n");
                            printf("A!=[%.2f]\n",factorialRes);
                            printf("--------------------------\n");
                        }
                        else
                        {
                            printf("--------------------------\n");
                            printf("MATH ERROR, Imposible factorial de un numero decimal\n");
                            printf("--------------------------\n");
                        }
                    }

                }
                else
                {
                    printf("--------------------------\n");
                    printf("ERROR,Falta ingresar el primer operando (A)\n");
                    printf("--------------------------\n");
                }
                break;
            case 8: // 8- Calcular todas las operaciones
                if(flagNum1==1 && flagNum2==1)
                {
                    sumaRes=sumar(num1,num2);
                    printf("--------------------------\n");
                    printf("A+B=[%.2f]\n",sumaRes);
                    printf("--------------------------\n");
                    restaRes=restar(num1,num2);
                    printf("--------------------------\n");
                    printf("A-B=[%.2f]\n",restaRes);
                    printf("--------------------------\n");
                    if (num2==0)
                    {
                        printf("--------------------------\n");
                        printf("MATH ERROR, Imposible division por 0\n");
                        printf("--------------------------\n");
                    }
                    else
                    {
                        divisionRes=dividir(num1,num2);
                        printf("--------------------------\n");
                        printf("A/B=[%.2f]\n",divisionRes);
                        printf("--------------------------\n");
                    }
                    multiplicacionRes=multiplicar(num1,num2);
                    printf("--------------------------\n");
                    printf("A*B=[%.2f]\n",multiplicacionRes);
                    printf("--------------------------\n");
                    if (num1>34)
                    {
                        printf("--------------------------\n");
                        printf("ERROR,Numero demasiado grande\nPor favor ingrese un numero menor a 34 para calcular A!");
                        printf("\n--------------------------\n");
                    }
                    else if(num1<0)
                    {
                        printf("--------------------------\n");
                        printf("MATH ERROR, Ingreso un numero negativo\n");
                        printf("--------------------------\n");
                    }
                    else
                    {
                        factorialAux= num1-(int)num1;
                        if (factorialAux==0)
                        {
                            factorialRes=factorial(num1);
                            printf("--------------------------\n");
                            printf("A!=[%.2f]\n",factorialRes);
                            printf("--------------------------\n");
                        }
                        else
                        {
                            printf("--------------------------\n");
                            printf("MATH ERROR, Imposible factorial de un numero decimal\n");
                            printf("--------------------------\n");
                        }
                    }
                }
                else if (flagNum1==0 || flagNum2==0)
                {
                    printf("--------------------------\n");
                    printf("ERROR,Falta ingresar el algun operando (A) o (B)\n");
                    printf("--------------------------\n");
                }
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
