#include<string>
#include<cstdlib>
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
		cout << "Lo siento este profesor no tiene ningun grupo a su mando" << endl;
	}
}

void MateriasConMismoCIP(string CIP) 
{
	bool encontrado = false;
	ifstream archivoMaterias;
	string dato;
	string header;
	string dato2;
	archivoMaterias.open("MateriasCVA.csv");
	getline(archivoMaterias, header);
	cout << header << endl;



	while (!archivoMaterias.eof())
	{
		getline(archivoMaterias, dato);
		dato2 = dato;
		dato2.erase(0, dato2.find(',')+1);
		dato2.erase(0, dato2.find(',')+1);
		dato2 = dato2.substr(0, dato2.find(','));
		if (dato2 == CIP) 
		{
			cout << dato << endl;
			encontrado = true;
		}
	}
	archivoMaterias.close();

	if (!encontrado) 
	{
		cout << "Lo siento ninguna materia tiene ese CIP" << endl;
	}
}

void ProfesoresConMismoCIP(string CIP)
{
	bool encontrado = false;
	ifstream archivoProfesores;
	string dato;
	string header;

	string dato2;
	archivoProfesores.open("ProfesoresCVA.csv");
	getline(archivoProfesores, header);
	cout << header << endl;

	while (!archivoProfesores.eof())
	{
		getline(archivoProfesores, dato);
		dato2 = dato;
		dato2.erase(0, dato2.find(',') + 1);
		dato2.erase(0, dato2.find(',') + 1);
		dato2 = dato2.substr(0, dato2.find(','));
		if (dato2 == CIP)
		{
			cout << dato << endl;
			encontrado = true;
		}
	}
	archivoProfesores.close();

	if (!encontrado)
	{
		cout << "Lo siento ningun profesor tiene ese CIP" << endl;
	}
}

void AltaProfesor() 
{
	string nominaNueva;
	string nombreNuevo;
	string cipNuevo;
	bool repetido = true;

	ifstream archivoProfesoresInput;
	string dato;
	archivoProfesoresInput.open("ProfesoresCVA.csv");

	while (repetido) 
	{
		repetido = false;
		cout << "Ingresa la nomina a registrar" << endl;
		cin >> nominaNueva;

	
		while (!archivoProfesoresInput.eof())
		{
			getline(archivoProfesoresInput, dato);
			dato = dato.substr(0, dato.find(','));
			if (dato == nominaNueva)
			{
				repetido = true;
				cout << "Esa nomina ya esta dada de alta" << endl << endl;
			}
		}
		archivoProfesoresInput.close();
	}

	getline(cin, nombreNuevo);
	cout << "Ingresa el nombre a registrar" << endl;
	getline(cin,nombreNuevo);
	cout << "Ingresa el CIP a registrar" << endl;
	cin >> cipNuevo;

	ofstream archivoProfesoresOutput;
	archivoProfesoresOutput.open("ProfesoresCVA.csv",ios::out|ios::app);

	archivoProfesoresOutput <<endl<< nominaNueva << ',' << nombreNuevo << ',' << cipNuevo << endl;
	archivoProfesoresOutput.close();

}