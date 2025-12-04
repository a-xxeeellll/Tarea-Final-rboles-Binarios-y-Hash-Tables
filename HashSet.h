#pragma once
#include "HashTableChaining.h"

// HashSet basado en COMPOSICIÓN sobre HashTableChaining<T>
// - Evita repetidos: Insert solo agrega si NO existe.
// - Usa las funciones existentes del profesor: Add / Encontrar / BorrarValor / Imprimir.

template <typename T>
class HashSet
{
public:
    // Constructor por defecto: 26 cubetas (útil si T es string A..Z)
    HashSet() : tabla(26) {}

    // Constructor que permite definir el número de cubetas
    explicit HashSet(size_t numeroDeListas) : tabla(numeroDeListas) {}

    // Inserta solo si NO existe. Regresa true si se insertó; false si ya estaba.
    bool Insert(const T& value)
    {
        if (tabla.Encontrar(value)) return false;
        tabla.Add(value);
        return true;
    }

    // Consulta si existe el elemento. (No es const porque HashTableChaining::Encontrar no es const)
    bool Contains(const T& value)
    {
        return tabla.Encontrar(value);
    }

    // Elimina el elemento si existe. Regresa true si lo borró.
    bool Remove(const T& value)
    {
        return tabla.BorrarValor(value);
    }

    // Solo imprime usando la tabla interna (útil para depuración)
    void Print()
    {
        tabla.Imprimir();
    }

private:
    HashTableChaining<T> tabla;
};
