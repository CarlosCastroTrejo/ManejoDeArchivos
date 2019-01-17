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

	while (decision != 9) 
	{
		cout << "\n¿Que deseas hacer?" << endl;
		cout << "1.- Dar de alta" << endl;
		cout << "2.- Dar de baja" << endl;
		cout << "3.- Hace modificacion" << endl;
		cout << "4.- Ver catalogos" << endl;
		cout << "5.- Mostrar todos los grupos de una materia especifica" << endl;
		cout << "6.- Mostrar todos los grupos de un profesor especifico" << endl;
		cout << "7.- " << endl;
		cout << "8.- Mostrar profesores o materias con el mismo CIP" << endl;
		cout << "9.- Salir" << endl;
		cin >> decision;
		cout << endl;
		switch (decision)
		{
		case(1):
		{
			int catalogo = 0;
			cout << "1.- Catalogo Materias" << endl;
			cout << "2.- Catalogo Profesores" << endl;
			cout << "3.- Catalogo Grupos" << endl;
			cin >> catalogo;

			switch (catalogo)
			{
			case(1):
			{
				AltaMateria();
				break;
			}
			case(2):
			{
				AltaProfesor();
				break;
			}
			case(3):
			{
				AltaGrupo();
				break;
			}
			default:
			{
				break;
			}
			}

			break;
		}
		case(2):
		{
			int catalogo = 0;
			cout << "1.- Catalogo Materias" << endl;
			cout << "2.- Catalogo Profesores" << endl;
			cout << "3.- Catalogo Grupos" << endl;
			cin >> catalogo;

			switch (catalogo)
			{
			case(1):
			{
				break;
			}
			case(2):
			{
				break;
			}
			case(3):
			{
				BajaGrupo();
				break;
			}
			default:
			{
				break;
			}
			}
			break;
		}
		case(3):
		{
			break;
		}

		case(4):
		{
			MostrarCatalogos();
			break;
		}
		case(5):
		{
			cout << "Porfavor ingresa la clave de la materia que deseas buscar" << endl;
			string materia;
			cin >> materia;
			GruposMateriaEspecifica(materia);
			break;
		}
		case(6):
		{
			cout << "Porfavor ingresa la nomina del profesor a buscar" << endl;
			string profesor;
			cin >> profesor;
			GruposProfesorEspecifico(profesor);
			break;
		}

		case(7):
		{

			break;
		}

		case(8):
		{
			int decision = 0;
			string CIP;
			cout << "1.- Profesores" << endl;
			cout << "2.- Materias" << endl;
			cin >> decision;
			cout << "Porfavor ingresa el CIP a buscar" << endl;
			cin >> CIP;
			if (decision == 1) 
			{
				ProfesoresConMismoCIP(CIP);
			}
			else if (decision == 2) 
			{
				MateriasConMismoCIP(CIP);
			}
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