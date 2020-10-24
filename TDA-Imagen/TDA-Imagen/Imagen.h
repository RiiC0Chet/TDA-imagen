/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   Imagen.h
  * Author: dmartinez01
  *
  * Created on 24 de octubre de 2020, 11:07
  */

#ifndef IMAGEN_H
#define IMAGEN_H

  /****************************************************************************/
  // Fichero: imagen.h
  // Fichero de cabecera asociado a la biblioteca libimg.a.
  // Implementacion del TDA imagen (imagen digital en niveles de gris).
  /****************************************************************************/

typedef unsigned char byte; // tipo base de cada pixel

/****************************************************************************/
// Fichero: imagen.h
// Fichero de cabecera asociado a la biblioteca libimg.a.
// Implementacion del TDA imagen (imagen digital en niveles de gris).
/****************************************************************************/

#ifndef IMAGEN
#define IMAGEN
typedef unsigned char byte; // tipo base de cada pixel

class Imagen {

private:

    int filas; // Número de filas de la imagen
    int cols; // Número de columnas de la imagen
    byte** img; // La imagen en si: una matriz dinamica 2D de bytes

public:

    /****************************************************************************/

    /**
        @brief Crear una imagen en memoria con "filas" filas y "cols" columnas.
               Reserva memoria para alojar la imagen de "filas" x "cols" pixeles.
               Recibe: int filas, Número de filas de la imagen.

        @param int cols, Número de columnas de la imagen.
        @param int filas, Número de filas de la imagen.
    */

    Imagen(int filas, int cols);

    /*****************************************************************************/
    /****************************************************************************/

    /**
        @brief Destructor, libera los recursos ocupados por la imagen.
               Devuelve: void.
    */

    ~Imagen();

    /****************************************************************************/
    /****************************************************************************/

    /**
        @brief Calcular el numero de filas de la imagen.
               Devuelve: int, Número de filas de la imagen.
    */

    int num_filas() const;

    /****************************************************************************/
    /****************************************************************************/

    /**
        @brief Calcular el numero de columnas de la imagen.
               Devuelve: int, Número de columnas de la imagen.
    */

    int num_columnas() const;

    /****************************************************************************/

    /**
        @brief Asignar el valor "valor" al pixel ("fila", "col") de la imagen.

        // Precondiciones:
        // 1. 0 <= "fila" < i.num_filas()
        // 2. 0 <= "col" < i.num_columnas()
        // 3. 0 <= valor <= 255

        @param int cols, Número de columnas de la imagen.
        @param int fila, Número de filas de la imagen.
        @param byte valor, valor a escribir.

        // Postcondiciones:
        // 1. "i"("fil","col") == "valor".
        // 2. Los restantes píxeles no se modifican.

    */

    void asigna_pixel(int fila, int col, byte valor);

    /****************************************************************************/

    void Imagen::enmarca_imagen();

    /****************************************************************************/

    /**
        @brief Consultar el valor de la casilla ("fila", "col") de la imagen.

        // Precondiciones:
        // 1. 0 <= "fila" < i.num_filas ()
        // 2. 0 <= "col" < i.num_columnas ()

        @param int col, Número de columnas de la imagen.
        @param int fila, Número de filas de la imagen.

        // Devuelve: byte, valor de "i"("fila","col").
    */

    byte valor_pixel(int fila, int col) const;

#endif /* IMAGEN_H */

