#include <stdio.h>
//ESTRUCTURAS
struct empleado2
{
	char nombre[20];
	char apellido[20];
	int edad;
	char sexo;
	double salarioPorHora;
	//struct empleado2 persona;//ERROR | NO SE PUEDE CREAR UNA INSTANCIA DE UNA ESTRUCTURA DENTRO DE UNA ESTRUCTURA, SOLAMENTE MEDIANTE UN PUNTERO
	struct empleado2 *persona; //ESTRUCTURA AUTO REFERENCIADA
}juan,equipoTrabajo[10],*ptrJuan;;
int main()
{
	//struct empleado2 juan,equipoTrabajo[10],*ptrJuan;
	struct empleado2 juan;
	struct empleado2 equipoTrabajo[10];
	struct empleado2 *ptrJuan;
	ptrJuan=&juan;
	return 0;
}
//TODO LEER HASTA EL TYPEDEF E IMPLEMENTAR LOS CÓDIGOS