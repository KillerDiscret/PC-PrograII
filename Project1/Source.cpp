#include <conio.h>
#include <iostream>
using namespace std;
using namespace System;
int menu()
{
	int OPCION;

	system("cls");
	cout << "\t MENU" << endl;
	cout << "1-Registrar las visitas(Agregar al inicio)" << endl;
	cout << "2-Eliminar un elemento de una posicion dada del arreglo" << endl;
	cout << "3-Modificar un elemento de una posicion dada del arreglo" << endl;
	cout << "4-Mostrar la hora en la que hay mayor cantidad de visitas" << endl;
	cout << "5-Mostrar la cantidad de visitas de una hora que ingrese el usuario" << endl;
	cout << "6-Mostrar en que parte del dia hay mas visitas(madrugada, mañana, tarde o noche)" << endl;
	//si el arreglo llega a 24 de tamaño, mostrará en que parte del día se realizaron más visitas(mañana, tarde, noche omadrugada)
	cout << endl;
	cout << "Ingrese una opcion: " << endl;
	cin >> OPCION;
	return OPCION;
}
int *Registrar(int*Arreglo, int *N)
{
	int registro;
	int*aux = new int[*N + 1];

	if (*N <=23)
	{
		
		cout << "Ingrese la cantidad de visitas:" << endl;
		cin >> registro;
		aux[0] = registro;
		for (int i = 0; i<*N;i++)
		{
			aux[i + 1] = Arreglo[i];
		}
		*N = *N + 1;
		cout << "***************" << endl;
		for (int j = 0;j<*N;j++)
		{
			cout << aux[j] << endl;
		}
	}
	
	return aux;
}
int *Eliminar(int *Arreglo, int *N)
{
	int contador = 0;
	int posicion;
	int *aux = new int[*N - 1];
	if (Arreglo != NULL)
	{
		cout << "Ingrese la posicion a eliminar:" << endl;
		cin >> posicion;
		for (int i = 0;i<*N;i++)
		{
			if (i != posicion - 1)
			{
				aux[contador] = Arreglo[i];
				contador = contador + 1;
			}
		}
	}
	else
	{
		cout << "El arreglo está vacío" << endl;
	}
	*N = *N - 1;
	return aux;
}
void modificar(int *Arreglo, int *N)
{
	int posicion;
	int valor;
	cout << "Ingrese la posicion a cambiar:" << endl;
	cin >> posicion;
	cout << "Ingrese el valor:" << endl;
	cin >> valor;
	Arreglo[posicion - 1] = valor;

}
void mostrarMayor(int *Arreglo, int *N)
{
	int mayor = 0;
	int hora = 0;
	for (int i = 1;i<*N;i++)
	{
		if (mayor <= Arreglo[i])
		{
			mayor = Arreglo[i];
			hora = (*N-1)-i;
		}
	}
	cout << "La hora en donde hay mayor visitas es:" << hora + 1;

}

void mostrarVisitas(int *Arreglo, int *N)
{
	int hora;
	cout << "Ingrese la hora a ver:" << endl;
	cin >> hora;
	cout << "La cantidad de visitas son: " << Arreglo[(*N-1)-(hora-1)] << endl;
}
void mostrarDia(int *Arreglo,int *N)
{
	int mayor=0;
	int mañana=0;
	int tarde=0;
	int noche=0;
	int madrugada=0;
	for (int i=0;i<*N;i++)
	{
		if (i>=0&&i<6)
		{
			madrugada = madrugada + Arreglo[i];
		}
		if (i>=6&&i<12)
		{
			mañana= mañana + Arreglo[i];
		}
		if (i>=12&&i<18)
		{
			tarde= tarde + Arreglo[i];
		}
		if (i>=18&&i<24)
		{
			noche= noche + Arreglo[i];
		}
	}
	int *vector = new int[4];
	for (int j=0; j<4;j++)
	{
		if (j==0)
		{
			vector[j] = madrugada;
		}
		if (j == 1)
		{
			vector[j] = mañana;
		}
		if (j == 2)
		{
			vector[j] = tarde;
		}
		if (j == 3)
		{
			vector[j] = noche;
		}
	}
	for (int x = 0; x<4;x++)
	{
		if (mayor <vector[x] )
		{
			mayor = vector[x];
		}
	}
	if (mayor==madrugada)
	{
		cout << "La parte del dia en que hay más visitantes es madrugada"<< endl;
	}
	if (mayor==mañana)
	{
		cout << "La parte del dia en que hay más visitantes es mañana"<< endl;
	}
	if (mayor==tarde)
	{
		cout << "La parte del dia en que hay más visitantes es tarde"<< endl;
	}
	if (mayor==noche)
	{
		cout << "La parte del dia en que hay más visitantes es noche"<< endl;
	}
}
int main()
{
	int opcion;
	int *Arreglo = NULL;
	int *N = new int;
	*N = 0;
	while (1)
	{
		opcion = menu();
		if (opcion == 1)
		{
			Arreglo = Registrar(Arreglo, N);
			if (*N == 23)
			{
				mostrarDia(Arreglo, N);
			}
		}
		if (opcion == 2)
		{
			Arreglo = Eliminar(Arreglo, N);
		}
		if (opcion == 3)
		{
			modificar(Arreglo, N);
		}
		if (opcion == 4)
		{
			mostrarMayor(Arreglo, N);
		}
		if (opcion == 5)
		{
			mostrarVisitas(Arreglo,N);
		}
		if (opcion == 6)
		{
			mostrarDia(Arreglo,N);
		}
		_getch();
	}

	_getch();
}