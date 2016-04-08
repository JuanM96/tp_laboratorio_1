/**
*\brief Solicita un numero al usuario de tipo Float
*\param mensaje es el mensaje que recibe la funcion que explica al usuario que debe ingresar
*\return El número ingresado por el usuario
*
*/

float getFloat(char mensaje[]) //Recibo un mensaje y pido un numero float
{
    float aux;
    printf("%s",mensaje);
    scanf("%f",&aux);
    return aux;
}

/**
*\brief Recibe 2 numeros y los suma
*\param numero1 y numero2 son los valores que recibe la funcion para realizar la operacion
*\return El resultado de la suma
*
*/

float sumar(float numero1,float numero2) //Recibo 2 numeros y los sumo
{
    float aux;
    aux=numero1+numero2;
    return aux;
}

/**
*\brief Recibe 2 numeros y los resta
*\param numero1 y numero2 son los valores que recibe la funcion para realizar la operacion
*\return El resultado de la resta
*
*/

float restar(float numero1,float numero2) //Recibo 2 numeros y los resto
{
    float aux;
    aux=numero1-numero2;
    return aux;
}

/**
*\brief Recibe 2 numeros y los divide
*\param numero1 y numero2 son los valores que recibe la funcion para realizar la operacion
*\return El resultado de la divicion
*
*/

float dividir(float numero1,float numero2) //Recibo 2 numeros y los divido
{
    float aux;
    aux=numero1/numero2;
    return aux;
}

/**
*\brief Recibe 2 numeros y los multiplica
*\param numero1 y numero2 son los valores que recibe la funcion para realizar la operacion
*\return El resultado de la multiplicacion
*
*/

float multiplicar(float numero1,float numero2) //Recibo 2 numeros y los multiplico
{
    float aux;
    aux= numero1*numero2;
    return aux;
}

/**
*\brief Recibe 1 numeros y realiza su factorial
*\param numero1 es el valor que recibe la funcion para realizar la operacion
*\return El resultado del factorial
*
*/

float factorial(float numero1) //Recibo el primer numero y calculo su factorial
{
    float aux;
    if(numero1==1)
    {
        return 1;
    }
    else if(numero1==0)
    {
        return 1;
    }
    aux=numero1* factorial(numero1-1);
    return (aux);
}
