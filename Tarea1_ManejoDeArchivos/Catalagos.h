#include<string>
#include<cstdlib>
#include<fstream>
#include <locale.h>
#include <clocale>
#include<iostream>
#include<vector>;

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
	cout << endl;
	string nominaNueva;
	string nombreNuevo;
	string cipNuevo;
	bool repetido = true;

	ifstream archivoProfesoresInput;
	string dato;

	while (repetido) 
	{
		archivoProfesoresInput.open("ProfesoresCVA.csv");

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
	cout << "Listo, profesor registrado exitosamente!" << endl << endl;

}

void AltaMateria() 
{
	cout << endl;
	string claveNueva;
	string nombreNuevo;
	string cipNuevo;
	string unidadesNuevo;
	string programasNuevos;
	string requisitosNuevos;
	bool repetido = true;

	ifstream archivoMateriasInput;
	string dato;

	while (repetido)
	{
		archivoMateriasInput.open("MateriasCVA.csv");

		repetido = false;
		cout << "Ingresa la clave de la materia a registrar" << endl;
		cin >> claveNueva;


		while (!archivoMateriasInput.eof())
		{
			getline(archivoMateriasInput, dato);
			dato = dato.substr(0, dato.find(','));
			if (dato == claveNueva)
			{
				repetido = true;
				cout << "Esa materia ya esta dada de alta" << endl << endl;
			}
		}
		archivoMateriasInput.close();
	}



	getline(cin, nombreNuevo);
	cout << "Ingresa el nombre de la materia a registrar" << endl;
	getline(cin, nombreNuevo);
	cout << "Ingresa el CIP de la materia a registrar" << endl;
	cin >> cipNuevo;
	cout << "Ingresa las unidades de la materia a registrar" << endl;
	cin >> unidadesNuevo;
	getline(cin, programasNuevos);
	cout << "Ingresa los programas academicos de la materia a registrar" << endl;
	getline(cin, programasNuevos);
	cout << "Ingresa los requisitos de la materia a registrar" << endl;
	cin >> requisitosNuevos;



	ofstream archivoMateriasOutput;
	archivoMateriasOutput.open("MateriasCVA.csv", ios::out | ios::app);

	archivoMateriasOutput << endl << claveNueva << ',' << nombreNuevo << ',' << cipNuevo<<','<<unidadesNuevo<<','<<programasNuevos<<','<<requisitosNuevos<< endl;
	archivoMateriasOutput.close();
	cout << "Listo, materia registrada exitosamente!"<<endl<<endl;
}

void AltaGrupo() 
{
	cout << endl;
	bool profesorExiste = false;
	bool materiaExiste = false;

	string claveMateria;
	string nominaNueva;
	string numeroGrupo="0";
	string horario;
	string salon;
	string semestre;

	ifstream archivoProfesoresInput;
	string dato;

	ifstream archivoMateriasInput;
	string dato2;

	while (!profesorExiste && !materiaExiste)
	{
		archivoProfesoresInput.open("ProfesoresCVA.csv");
		archivoMateriasInput.open("MateriasCVA.csv");

		cout << "Ingresa la clave de la materia a registrar" << endl;
		cin >> claveMateria;
		cout << "Ingresa la nomina del profesor de la materia a registrar" << endl;
		cin >> nominaNueva;


		while (!archivoProfesoresInput.eof())
		{
			getline(archivoProfesoresInput, dato);
			dato = dato.substr(0, dato.find(','));
			if (dato == nominaNueva) 
			{
				profesorExiste = true;
			}
			
		}

		while (!archivoMateriasInput.eof())
		{
			getline(archivoMateriasInput, dato2);
			dato2 = dato2.substr(0, dato2.find(','));
			if (dato2 == claveMateria)
			{
				materiaExiste = true;
			}
		}


		if (!materiaExiste && !profesorExiste)
		{
			cout << "La clave de la materia ni la nomina del profesor existen, intentalo de nuevo" << endl;
			profesorExiste = false;
			materiaExiste = false;
		}
		else if (!materiaExiste) 
		{
			cout << "La clave de la materia no existe,intentalo de nuevo" << endl;
			profesorExiste = false;
			materiaExiste = false;
		}
		else if (!profesorExiste) 
		{
			cout << "La nomina del profesor no existe,intentalo de nuevo" << endl;
			profesorExiste = false;
			materiaExiste = false;
		}
		archivoProfesoresInput.close();
		archivoMateriasInput.close();
	}

	
	while (stoi(numeroGrupo)<1 || stoi(numeroGrupo)>10)
	{
		cout << "Ingresa el numero del grupo del grupo a registrar" << endl;
		cin >> numeroGrupo;
		if (stoi(numeroGrupo) < 1 || stoi(numeroGrupo) > 10) 
		{
			cout << "El numero del grupo debe de ser entre 1 y 10,intentalo de nuevo" << endl<<endl;
		}
		
		
	}

	getline(cin, horario);
	cout << "Ingresa el horario del grupo a registrar" << endl;
	getline(cin, horario);
	cout << "Ingresa el salon del grupo a registrar" << endl;
	cin >> salon;
	cout << "Ingresa el semestre del grupo a registrar" << endl;
	cin >> semestre;

	ofstream archivoGruposOutput;
	archivoGruposOutput.open("GruposCVA.csv", ios::out | ios::app);

	archivoGruposOutput << endl << claveMateria << ',' << nominaNueva << ',' << numeroGrupo << ',' << horario << ',' << salon << ',' << semestre << endl;
	archivoGruposOutput.close();
	cout << "Listo, grupo registrado exitosamente!" << endl << endl;

}

void BajaGrupo()
{
	cout << endl;
	int claveBaja;
	vector<string>datos;
	ifstream archivoGrupos;
	string dato;
	string header;
	int numeroLista = 0;
	archivoGrupos.open("GruposCVA.csv");
	getline(archivoGrupos, header);
	cout << header << endl;


	while (!archivoGrupos.eof())
	{
		numeroLista++;
		getline(archivoGrupos, dato);
		cout << numeroLista << ".- " << dato << endl;
		datos.push_back(dato);
	}
	archivoGrupos.close();

	cout << "Porfavor ingresa el numero de la lista del grupo que deseas dar de baja" << endl;
	cin >> claveBaja;

	ofstream archivoGruposOutput;
	archivoGruposOutput.open("GruposCVA.csv");
	archivoGruposOutput << header;
	for (int x = 0; x < datos.size(); x++)
	{
		if (x != claveBaja - 1) 
		{
			archivoGruposOutput << endl << datos[x];
		}
	}
	archivoGruposOutput.close();
	cout << "Listo, grupo dado de baja exitosamente!" << endl << endl;
}

void BajaMateria() 
{
	cout << endl;
	string claveBaja;
	bool materiaEncontradaGrupos = false;
	cout << "Porfavor ingresa la clave de la materia que deseas dar de baja" << endl;
	cin >> claveBaja;

	ifstream archivoGrupos;
	string dato;
	archivoGrupos.open("GruposCVA.csv");
	while (!archivoGrupos.eof())
	{
		getline(archivoGrupos, dato);
		dato = dato.substr(0, dato.find(','));
		if (dato == claveBaja) 
		{
			materiaEncontradaGrupos = true;
		}
	}
	archivoGrupos.close();

	if (materiaEncontradaGrupos) 
	{
		cout << "Lo siento esta materia no puede ser dada de baja ya que existe un grupo con esta materia" << endl;
	}
	else 
	{
		vector<string> datos;
		bool encontradoEnMaterias = false;

		ifstream archivoMaterias;
		string dato2;
		archivoMaterias.open("MateriasCVA.csv");

		while (!archivoMaterias.eof())
		{
			getline(archivoMaterias, dato);
			dato2 = dato;
			dato2 = dato2.substr(0, dato2.find(','));
			if (dato2 == claveBaja) 
			{
				encontradoEnMaterias = true;
			}
			else 
			{
				datos.push_back(dato);
			}
		}
		archivoMaterias.close();

		if (encontradoEnMaterias) 
		{
			ofstream archivoMateriasOutput;
			archivoMateriasOutput.open("MateriasCVA.csv");
			for (int x = 0; x < datos.size(); x++) 
			{
				archivoMateriasOutput << datos[x] << endl;
			}

			archivoMateriasOutput.close();
			cout << "Listo, materia dada de baja exitosamente!" << endl << endl;
		}
		else 
		{
			cout << "Lo siento esta materia no puede ser dada de baja ya que existe no existe en el catalogo de materias" << endl;
		}
	
	}
}

void BajaProfesor() 
{
	cout << endl;
	string claveBaja;
	bool profesorEncontradoGrupos = false;
	cout << "Porfavor ingresa la nomina del profesor que deseas dar de baja" << endl;
	cin >> claveBaja;

	ifstream archivoGrupos;
	string dato;
	archivoGrupos.open("GruposCVA.csv");
	while (!archivoGrupos.eof())
	{
		getline(archivoGrupos, dato);
		dato.erase(0, dato.find(',') + 1);
		dato = dato.substr(0, dato.find(','));
		if (dato == claveBaja)
		{
			profesorEncontradoGrupos = true;
		}
	}
	archivoGrupos.close();

	if (profesorEncontradoGrupos)
	{
		cout << "Lo siento este profesor no puede ser dado de baja ya que existe un grupo con este profesor" << endl;
	}
	else
	{
		vector<string> datos;
		bool encontradoEnProfesores = false;

		ifstream archivoProfesores;
		string dato2;
		archivoProfesores.open("ProfesoresCVA.csv");

		while (!archivoProfesores.eof())
		{
			getline(archivoProfesores, dato);
			dato2 = dato;
			dato2 = dato2.substr(0, dato2.find(','));
			if (dato2 == claveBaja)
			{
				encontradoEnProfesores = true;
			}
			else
			{
				datos.push_back(dato);
			}
		}
		archivoProfesores.close();

		if (encontradoEnProfesores)
		{
			ofstream archivoProfesoresOutput;
			archivoProfesoresOutput.open("ProfesoresCVA.csv");
			for (int x = 0; x < datos.size(); x++)
			{
				archivoProfesoresOutput << datos[x] << endl;
			}

			archivoProfesoresOutput.close();
			cout << "Listo, profesor dado de baja exitosamente!" << endl << endl;
		}
		else
		{
			cout << "Lo siento este profesor no puede ser dado de baja ya que existe no existe en el catalogo de profesores" << endl;
		}
	}
}

void ModificacionGrupo() 
{
	cout << endl;
	int claveBaja;
	vector<string>datos;

	ifstream archivoGrupos;
	string dato;
	string header;
	int numeroLista = 0;
	archivoGrupos.open("GruposCVA.csv");
	getline(archivoGrupos, header);
	cout << header << endl;


	while (!archivoGrupos.eof())
	{
		numeroLista++;
		getline(archivoGrupos, dato);
		cout << numeroLista << ".- " << dato << endl;
		datos.push_back(dato);
	}
	archivoGrupos.close();

	cout << "Porfavor ingresa el numero de la lista del grupo que deseas modificar" << endl;
	cin >> claveBaja;

	if (claveBaja >= 1 && claveBaja <= numeroLista) 
	{
		
		cout << endl<< "Este es el grupo que quieres modificar:"<<endl;
		cout << header << endl;
		cout << datos[claveBaja - 1] << endl << endl;;

		bool profesorExiste = false;
		bool materiaExiste = false;
		string claveMateria;
		string nominaNueva;
		string numeroGrupo = "0";
		string horario;
		string salon;
		string semestre;

		ifstream archivoProfesoresInput;
		string dato;

		ifstream archivoMateriasInput;
		string dato2;

		while (!profesorExiste && !materiaExiste)
		{
			archivoProfesoresInput.open("ProfesoresCVA.csv");
			archivoMateriasInput.open("MateriasCVA.csv");

			cout << "Ingresa la clave de la materia por la cual vas a cambiar" << endl;
			cin >> claveMateria;
			cout << "Ingresa la nomina del profesor de la materia por la cual vas a cambiar" << endl;
			cin >> nominaNueva;


			while (!archivoProfesoresInput.eof())
			{
				getline(archivoProfesoresInput, dato);
				dato = dato.substr(0, dato.find(','));
				if (dato == nominaNueva)
				{
					profesorExiste = true;
				}

			}

			while (!archivoMateriasInput.eof())
			{
				getline(archivoMateriasInput, dato2);
				dato2 = dato2.substr(0, dato2.find(','));
				if (dato2 == claveMateria)
				{
					materiaExiste = true;
				}
			}


			if (!materiaExiste && !profesorExiste)
			{
				cout << "La clave de la materia ni la nomina del profesor existen, intentalo de nuevo" << endl;
				profesorExiste = false;
				materiaExiste = false;
			}
			else if (!materiaExiste)
			{
				cout << "La clave de la materia no existe,intentalo de nuevo" << endl;
				profesorExiste = false;
				materiaExiste = false;
			}
			else if (!profesorExiste)
			{
				cout << "La nomina del profesor no existe,intentalo de nuevo" << endl;
				profesorExiste = false;
				materiaExiste = false;
			}
			archivoProfesoresInput.close();
			archivoMateriasInput.close();
		}


		while (stoi(numeroGrupo) < 1 || stoi(numeroGrupo) > 10)
		{
			cout << "Ingresa el numero del grupo del grupo por el cual vas a cambiar" << endl;
			cin >> numeroGrupo;
			if (stoi(numeroGrupo) < 1 || stoi(numeroGrupo) > 10)
			{
				cout << "El numero del grupo debe de ser entre 1 y 10,intentalo de nuevo" << endl << endl;
			}


		}

		getline(cin, horario);
		cout << "Ingresa el horario del grupo por el cual vas a cambiar" << endl;
		getline(cin, horario);
		cout << "Ingresa el salon del grupo por el cual vas a cambiar" << endl;
		cin >> salon;
		cout << "Ingresa el semestre del grupo por el cual vas a cambiar" << endl;
		cin >> semestre;

		string nuevoGrupo = claveMateria + ',' + nominaNueva + ',' + numeroGrupo + ',' + horario + ',' + salon + ',' + semestre;

		ofstream archivoGruposOutput;
		archivoGruposOutput.open("GruposCVA.csv");
		archivoGruposOutput << header ;
		for (int x = 0; x < datos.size(); x++) 
		{
			if (x == claveBaja - 1) 
			{
				archivoGruposOutput <<endl<< nuevoGrupo;
			}
			else 
			{
				archivoGruposOutput <<endl<< datos[x];
			}
			
		}

		archivoGruposOutput.close();

		cout << "Listo el grupo ha sido modificado exitosamente" << endl;
	
	}
	else
	{
		cout << "Lo siento, ese no es un elemento de la lista" << endl << endl;
	}



}

void ModificacionMateria() 
{
	cout << endl;
	string claveBaja;
	cout << "Porfavor ingresa la clave de la materia que deseas cambiar"<< endl;
	cin >> claveBaja;

	vector<string> datos;
	bool encontradoEnMaterias = false;

	ifstream archivoMaterias;
	string dato;
	string dato2;
	string header;
	int numeroEnArregloEncontrado = 0;
	archivoMaterias.open("MateriasCVA.csv");
	getline(archivoMaterias, header);

	while (!archivoMaterias.eof())
	{
		getline(archivoMaterias, dato);
		dato2 = dato;
		dato2 = dato2.substr(0, dato2.find(','));
		if (dato2 == claveBaja)
		{
			encontradoEnMaterias = true;
			datos.push_back(dato);
			numeroEnArregloEncontrado = datos.size() - 1;
		}
		else
		{
			datos.push_back(dato);
		}
	}
	archivoMaterias.close();

	if (encontradoEnMaterias)
	{
		cout << endl << "Esta es la materia que quieres modificar:" << endl;
		cout << header << endl;
		cout << datos[numeroEnArregloEncontrado] << endl;
		string nombreNuevo;
		string cipNuevo;
		string unidadesNuevo;
		string programasNuevos;
		string requisitosNuevos;

		getline(cin, nombreNuevo);
		cout << "Ingresa el nombre de la materia por el cual vas a cambiar" << endl;
		getline(cin, nombreNuevo);
		cout << "Ingresa el CIP de la materia por el cual vas a cambiar" << endl;
		cin >> cipNuevo;
		cout << "Ingresa las unidades de la materia por el cual vas a cambiar" << endl;
		cin >> unidadesNuevo;
		getline(cin, programasNuevos);
		cout << "Ingresa los programas academicos de la materia por los cuales vas a cambiar" << endl;
		getline(cin, programasNuevos);
		cout << "Ingresa los requisitos de la materia por los cuales vas a cambiar" << endl;
		cin >> requisitosNuevos;
		string modificado = claveBaja + ',' + nombreNuevo + ',' + cipNuevo + ',' + unidadesNuevo + ',' + programasNuevos + ',' + requisitosNuevos;

		datos[numeroEnArregloEncontrado] = modificado;

		ofstream archivoMateriasOutput;
		archivoMateriasOutput.open("MateriasCVA.csv");
		for (int x = 0; x < datos.size(); x++)
		{
			
			archivoMateriasOutput << datos[x] << endl;
			
		}

		archivoMateriasOutput.close();
		cout << "Listo, materia modificada exitosamente!" << endl << endl;
	}
	else
	{
		cout << "Lo siento esta materia no puede ser modificada ya que no existe en el catalogo de materias" << endl;
	}


}

void ModificacionProfesor()
{

	cout << endl;
	string claveBaja;
	cout << "Porfavor ingresa la nomina del profesor que deseas cambiar" << endl;
	cin >> claveBaja;

	vector<string> datos;
	bool encontradoEnProfesores = false;

	ifstream archivoProfesores;
	string dato;
	string dato2;
	string header;
	int numeroEnArregloEncontrado = 0;
	archivoProfesores.open("ProfesoresCVA.csv");
	getline(archivoProfesores, header);

	while (!archivoProfesores.eof())
	{
		getline(archivoProfesores, dato);
		dato2 = dato;
		dato2 = dato2.substr(0, dato2.find(','));
		if (dato2 == claveBaja)
		{
			encontradoEnProfesores = true;
			datos.push_back(dato);
			numeroEnArregloEncontrado = datos.size() - 1;
		}
		else
		{
			datos.push_back(dato);
		}
	}
	archivoProfesores.close();

	if (encontradoEnProfesores)
	{
		cout << endl << "Este es el profesor que vas a modificar:" << endl;
		cout << header << endl;
		cout << datos[numeroEnArregloEncontrado] << endl;

		string nombreNuevo;
		string cipNuevo;

		getline(cin, nombreNuevo);
		cout << "Ingresa el nombre a registrar" << endl;
		getline(cin, nombreNuevo);
		cout << "Ingresa el CIP a registrar" << endl;
		cin >> cipNuevo;
		

		string modificado = claveBaja + ',' + nombreNuevo + ',' + cipNuevo;

		datos[numeroEnArregloEncontrado] = modificado;

		ofstream archivoProfesoresOutput;
		archivoProfesoresOutput.open("ProfesoresCVA.csv");
		for (int x = 0; x < datos.size(); x++)
		{
			archivoProfesoresOutput << datos[x] << endl;
		}

		archivoProfesoresOutput.close();
		cout << "Listo,profesor modificado exitosamente" << endl << endl;
	}
	else
	{
		cout << "Lo siento este profesor no puede ser modificado ya que su nomina no existe en el catalogo de profesores" << endl;
	}


}

void MismoHorario() 
{
	cout << endl;
	string horario;
	bool horarioExiste = false;
	getline(cin, horario);
	cout << "Escribe el horario de los grupos que quieres desplegar" << endl;
	getline(cin, horario);
	cout << endl;

	ifstream archivoGrupos;
	string dato;
	string dato2;
	string header;
	archivoGrupos.open("GruposCVA.csv");
	getline(archivoGrupos, header);
	cout << header << endl;

	while (!archivoGrupos.eof())
	{
		getline(archivoGrupos, dato);
		dato2 = dato;
		dato2.erase(0, dato2.find(',') + 1);
		dato2.erase(0, dato2.find(',') + 1);
		dato2.erase(0, dato2.find(',') + 1);
		dato2 = dato2.substr(0, dato2.find(','));
		if (dato2 == horario)
		{
			horarioExiste = true;
			cout << dato << endl;
		}
	}
	archivoGrupos.close();

	if (!horarioExiste)
	{
		cout << "Lo siento no existe ningun grupo que este asignado a este horario" << endl;
	}

}

void MismoSalon() 
{
	cout << endl;
	string salon;
	bool salonExiste = false;
	cout << "Escribe el salon de los grupos que quieres desplegar" << endl;
	cin >> salon;
	cout << endl;

	ifstream archivoGrupos;
	string dato;
	string dato2;
	string header;
	archivoGrupos.open("GruposCVA.csv");
	getline(archivoGrupos, header);
	cout << header << endl;

	while (!archivoGrupos.eof())
	{
		getline(archivoGrupos, dato);
		dato2 = dato;
		dato2.erase(0, dato2.find(',') + 1);
		dato2.erase(0, dato2.find(',') + 1);
		dato2.erase(0, dato2.find(',') + 1);
		dato2.erase(0, dato2.find(',') + 1);
		dato2 = dato2.substr(0, dato2.find(','));
		if (dato2 == salon) 
		{
			salonExiste = true;
			cout << dato << endl;
		}
	}
	archivoGrupos.close();

	if (!salonExiste) 
	{
		cout << "Lo siento no existe ningun grupo que este asignado a este salon" << endl;
	}

}