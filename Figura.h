#pragma once
#include<iostream>
#include<stdexcept>
#include<numeric>
#include <cmath>   // para tan
using std::tan;    // opcional, para no escribir std::tan

using namespace std;

class Figura
{
public:
	virtual float CalcularArea() = 0;
	virtual float CalcularPerimetro() = 0;

};

class Circulo : public Figura
{
	float radio;

public:
	Circulo(float radio)
	{
		this->radio = radio;
	}

	float CalcularArea() override
	{
		return 3.1416f * radio * radio;
	}

	float CalcularPerimetro() override
	{
		return 3.1416f * 2 * radio;
	}

};

class Cuadrado : public Figura
{
protected:
	float lado;
public:
	// Explicit es una cosa medio peculiar.
	// explicit quiere decir que no se puede hacer impl�cito, tienes que poner tal cual el nombre del 
	// constructor para poder instanciar un objeto de esta clase.
	explicit Cuadrado(float lado)
	{
		this->lado= lado;
	}

	// no sirve para constructores que reciben dos par�metros o m�s que no son por defecto.
	// aqu� s� sirve porque solo lado1 no es por defecto.
	//Cuadrado(float lado1, float lado2 = 10) // recordatorio, los par�metros por defecto deben ir m�s a la derecha que los otros.
	//{
	//	this->lado = lado1;
	//}

	// Sin virtual expl�cito
	float CalcularArea() override
	{
		return lado * lado;
	}

	// Con virtual expl�cito
	virtual float CalcularPerimetro() override
	{
		return lado * 4;
	}

};

class Cubo : public Cuadrado
{
public:
	// Si una funci�n es virtual en alguna clase ancestra, entonces siempre va a ser virtual dicha funci�n,
	// a pesar de que clases posteriores de ese ancestro no la marque como virtual.
	// Ejemplo: figura.CalcularArea() es virtual; Cuadrado.CalcularArea() es override pero no virtual; 
	// Cubo.CalcularArea() todav�a puede hacer override a pesar de que en Cuadrado no est� expl�citamente como virtual.
	// En resumen: Una vez virtual, por siempre ser� virtual.

	// Sin importar si en Cuadrado es virtual expl�citamente, todav�a se le puede hacer override.
	float CalcularArea() override
	{
		return lado * lado * 6.0f;
	}

	// Con virtual expl�cito
	float CalcularPerimetro() override
	{
		return lado * 12.0f;
	}
};

class FiguraNLados : public Figura
{
	int numeroDeLados;
	float tamanoLados;
public:
	FiguraNLados(int numLados, float tamLados)
	{
		// Los bloques try-throw-catch son s�per com�nes en cosas de web, como servidores.
		try
		{
			if (numLados < 3)
			{
				// Entonces no es una figura de N lados (3 ser�a al menos un tri�ngulo)
				throw invalid_argument("Numero de lados es menor 3 en la figura de N lados. Debe ser al menos 3");
			}
			if (tamLados <= 0)
			{
				throw invalid_argument("el lado es 0 o menor, por lo que la figura de N lados no ser�a v�lida");
			}

			numeroDeLados = numLados;
			tamanoLados = tamLados;
		}
		catch(const invalid_argument& e)
		{
			cerr << e.what() << endl;
			// adem�s de imprimir el programa, podemos hacer otras cosas para manejar ese error
			// Por ejemplo, ponerles valor por defecto
			numeroDeLados = 3;
			tamanoLados = 1;
		}
	}

	float CalcularArea() override
	{
		// �rea pol�gono regular: A = (n * s^2) / (4 * tan(pi/n))
		return (numeroDeLados * tamanoLados* tamanoLados) / (4.0f * tan(3.1416f / (numeroDeLados)));
	}

	float CalcularPerimetro() override
	{
		// �rea pol�gono regular: A = (n * s^2) / (4 * tan(pi/n))
		return numeroDeLados * tamanoLados;
	}

};

class Linea : public Figura
{
	float* segmentos; // arreglo de las medidas de cada segmento
	int numSegmentos;
public:
	Linea(float* arraySegmentos, int numeroSegmentos)
	{
		try
		{
			if (arraySegmentos == nullptr)
			{
				throw invalid_argument("array de segmentos en nullptr");
			}
			if (numSegmentos <= 0)
			{
				throw invalid_argument("numero de segmentos no puede ser 0 o menor");
			}
			numSegmentos = numeroSegmentos;
			segmentos = new float[numSegmentos];
			for (int i = 0; i < numSegmentos; i++)
			{
				segmentos[i] = arraySegmentos[i];
			}

		}
		catch (const invalid_argument& e)
		{
			cerr << e.what() << endl;
			// asignamos valores por defecto que sean seguros a nuestras vriables
			numSegmentos = -1;
			segmentos = nullptr;
		}

	}

	float CalcularArea() override
	{
		// �rea pol�gono regular: A = (n * s^2) / (4 * tan(pi/n))
		return 0;
	}

	float CalcularPerimetro() override
	{
		float total = 0;

		// no jal�, pero la idea es que el for sencillito tradicional de abajo hace lo mismo.
		// total = accumulate(segmentos[0], segmentos[numSegmentos - 1], 0.0f);

		total = 0;
		for (int i = 0; i < numSegmentos; i++)
		{
			total += segmentos[i];
		}
		return total;
	}

};

void DemostracionFiguras();