#include<string>
#include<fstream>
#include <locale.h>
#include <clocale>
#include"Catalagos.h"
#include<iostream>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "");
	int decision=0;
	cout << "Hola bienvenido a la base de datos de TEC CVA" << endl;

	while (decision != 5) 
	{
		cout << "\nQue deseas hacer?" << endl;
		cout << "1.- Ver catalogos" << endl;
		cout << "2.- Mostrar todos los grupos de una materia especifica" << endl;
		cout << "3.- Mostrar todos los grupos de un profesor" << endl;


		cout << "5.- Salir" << endl;
		cin >> decision;
		cout << endl;
		switch (decision)
		{
		case(1):
		{
			MostrarCatalogos();
			break;
		}
		case(2):
		{
			cout << "Porfavor ingresa la clave de la materia que deseas buscar" << endl;
			string materia;
			cin >> materia;
			GruposMateriaEspecifica(materia);
			break;
		}
		case(3):
		{
			cout << "Porfavor ingresa la nomina del profesor a buscar" << endl;
			string profesor;
			cin >> profesor;
			GruposProfesorEspecifico(profesor);
			break;
		}
		default:
		{
			break;
		}
		}
	}
	

	
	system("pause");

}