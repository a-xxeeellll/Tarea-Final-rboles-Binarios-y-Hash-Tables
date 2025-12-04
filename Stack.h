#pragma once
#include<iostream>
#include <cmath>   // para INFINITY

using namespace std;

class Stack
{
public:
	Stack(int in_capacity = 0);

	~Stack();

	// Inserta un elemento en el tope de la pila
	void Push(int value)
	{
		int oldCapacity = capacity;

		// checamos si alcanza la capacidad
		if (count == capacity)
		{
			if (capacity == 0)
				capacity = 1;
			else
				capacity *= 2;
			// entonces necesitamos el resize:
			// 1) pedimos m�s memoria din�mica
			int* arrayConMasMemoria = new int[capacity];
			// 2) copiamos todo del array original al nuevo
			for (int i = 0; i < oldCapacity; i++)
			{
				arrayConMasMemoria[i] = elements[i];
			}
			// 3) borramos el array original
			delete[] elements;
			// 4) reasignamos elements al arrayConMasMemoria
			elements = arrayConMasMemoria;
		}

		elements[count] = value;
		count++; // y ahora tiene dentro 1 elementos m�s. Que el tope de la pila est� un elemento m�s arriba.
	}

	// saca y regresa el elemento del tope de la pila.
	int Pop()
	{
		// si s� hay al menos un elemento, entonces s� lo podemos sacar.
		if (count > 0)
		{
			count--; // nos basta hacer esto para que ese �ltimo elemento ya no se pueda acceder.
			return elements[count];
		}
		
		// no se necesita el else porque si entr� al if de arriba entonces ya va a hacer return y no
		// llegar�a a esta parte del c�digo.
		cout << "ERROR la pila estaba vac�a pero se intent� sacar un elemento de ella." << endl;
		return -INFINITY;
	}

	// te regresa el elemento del tope de la pila PERO sin sacarlo de la pila.
	int Peek()
	{
		if (count > 0)
		{
			return elements[count - 1];
		}

		cout << "ERROR la pila estaba vac�a pero se intent� hacer Peek de ella." << endl;
		return -INFINITY;
	}

	void PrintStack()
	{
		cout << "imprimiendo stack: " << endl;
		for (int i = 0; i < count; i++)
			cout << elements[i] << ", ";
		cout << endl;
	}

private:
	// los datos que realmente almacena la pila.
	int* elements;

	// n�mero de elementos actualmente en la pila. Adem�s, count representa el tope de tu pila.
	int count; 

	// cu�ntos elementos caben en la pila antes de hacer un resize.
	int capacity;
};

