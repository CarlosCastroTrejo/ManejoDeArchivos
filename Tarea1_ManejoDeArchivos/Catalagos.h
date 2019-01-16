#include<string>
#include<fstream>
#include <locale.h>
#include <clocale>
#include<iostream>

using namespace std; 

void MostrarCatalogos() 
{
	int catalogo = 0;
	cout << "¿Que catalogo quieres ver?" << endl;
	cout << "1.- Materias" << endl;
	cout << "2.- Grupos" << endl;
	cout << "3.- Profesores" << endl;
	cin >> catalogo;
	cout << endl;
	switch (catalogo)
	{
		case(1):
		{
			ifstream archivoMaterias;
			string dato;
			archivoMaterias.open("MateriasCVA.csv");

			while (!archivoMaterias.eof()) 
			{
				getline(archivoMaterias,dato);
				cout << dato << endl;
			}
			archivoMaterias.close();	
			break;
		}
		case(2):
		{
			ifstream archivoGrupos;
			string dato;
			archivoGrupos.open("GruposCVA.csv");

			while (!archivoGrupos.eof())
			{
				getline(archivoGrupos, dato);
				cout << dato << endl;
			}
			archivoGrupos.close();
			break;
		}
		case(3):
		{
			ifstream archivoProfesores;
			string dato;
			archivoProfesores.open("ProfesoresCVA.csv");

			while (!archivoProfesores.eof())
			{
				getline(archivoProfesores, dato);
				cout << dato << endl;
			}
			archivoProfesores.close();
			break;
		}
		default:
		{
			break;
		}
	}
}

void GruposMateriaEspecifica(string materia) 
{
	bool materiaExiste = false;

	ifstream archivoGrupos;
	string dato;
	string claveMateria;
	string header;


	archivoGrupos.open("GruposCVA.csv");
	getline(archivoGrupos, header);
	cout <<endl<< header << endl;

	while (!archivoGrupos.eof())
	{
		getline(archivoGrupos, dato);
		claveMateria= dato.substr(0, dato.find(','));
		if (claveMateria == materia)
		{
			
			cout << dato << endl;
			materiaExiste = true;
		}
	}
	archivoGrupos.close();

	if (!materiaExiste) 
	{
		cout << "Lo siento esta materia no tiene ningun grupo dado de alta" << endl;
	}
}

void GruposProfesorEspecifico(string profesor) 
{
	bool maestroExiste = false;
	ifstream archivoGrupos;
	string dato;
	string dato2;
	string claveMateria;
	string header;
	archivoGrupos.open("GruposCVA.csv");
	getline(archivoGrupos, header);
	cout << endl << header << endl;


	while (!archivoGrupos.eof())
	{
		getline(archivoGrupos, dato);
		dato2 = dato;
		dato2.erase(0, dato2.find(',')+1);
		dato2 = dato2.substr(0, dato2.find(','));
		if (dato2 == profesor)
		{
			cout << dato << endl;
			maestroExiste = true;
		}
		
	}
	archivoGrupos.close();

	if (!maestroExiste)
	{
		cout << "Lo siento esta profesor no tiene ningun grupo a su mando" << endl;
	}
}