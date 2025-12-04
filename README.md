# Árboles Binarios y Tablas Hash — Programación Orientada a Objetos 2025C

Proyecto desarrollado en C++ que implementa estructuras de datos Binary Search Tree (BST) y Hash Table con Chaining, mostrando operaciones básicas como inserción, búsqueda, recorrido y eliminación.  
---

## Contenido del proyecto

El repositorio incluye:

| Archivo / Carpeta | Descripción |
|--------------------|-------------|
| `BinarySearchTree.h` | Implementación del árbol binario de búsqueda. |
| `BinarySearchTree.cpp` | Funciones principales del BST (Add, Find, Min, Max, Sucesor, Predecesor, etc). |
| `HashTableChaining.h` | Implementación de una tabla hash con manejo de colisiones mediante listas ligadas. |
| `LinkedList.h` | Clase auxiliar de lista ligada usada por la tabla hash. |
| `Stack.h` | Clase auxiliar utilizada en algunos recorridos del BST. |
| `main.cpp` | Contiene las pruebas y demostraciones de cada estructura. |
| `README.md` | Este archivo. |

---

## Estructuras implementadas

### Binary Search Tree (BST)
Permite:
- Insertar elementos (`Add`)
- Buscar valores (`Find`)
- Recorridos InOrder, PreOrder y PostOrder (recursivos e iterativos)
- Obtener mínimo, máximo, sucesor y predecesor
- Borrar nodos por valor (`BorrarPorValor`)
- Limpiar el árbol (`ClearPostOrderIterative`)

### Hash Table con Chaining
Permite:
- Agregar elementos (`Add`)
- Buscar (`Encontrar`)
- Eliminar (`BorrarValor`)
- Imprimir las cubetas (`Imprimir`)
- Usa `LinkedList<T>` como contenedor de colisiones.

---

## Modificaciones realizadas por mí

1. Creación de la función `DemostracionHashTableChaining()`  
   Implementa pruebas para agregar, borrar y buscar valores dentro de la tabla hash.

2. Corrección y prueba de `DemostracionBinarySearchTree()`  
   Se revisaron los casos de prueba, los mensajes de salida y se validaron los recorridos correctos del árbol.

3. Configuración y compilación completa en VS Code  
   Ajuste de rutas, configuración del compilador `g++` (MinGW 15.2.0) y corrección de problemas de codificación UTF-8 en la terminal.

4. Ajuste en la codificación de salida (Windows)  
   Se añadió la configuración `SetConsoleOutputCP(CP_UTF8);` para evitar símbolos extraños en consola.

5. Limpieza de código y compatibilidad entre los `.h` y `.cpp`  
   Todos los includes fueron revisados y organizados correctamente.

---

## Compilación y Ejecución

### En Visual Studio Code

1. Asegúrate de tener instalado **g++ (MinGW)**  
   Puedes verificarlo con:
   ```bash
   g++ --version
(este texto fue realizado con IA profe :D )
