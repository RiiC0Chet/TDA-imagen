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

     /**
        @brief Recubre la matriz con un marco negro.
     */

    void enmarca_imagen();

    /**
       @brief Devuelve el numero de columnas por referencia
       @return devuelve el numero de columnas

    */

    int & Getcolumnas();

    /**
       @brief Devuelve el numero de filas por referencia
       @return devuelve el numero de filas

    */

    int & Getfilas();

    /**
       @brief Calcular el numero de filas de la imagen.
              Devuelve: int, Número de filas de la imagen.
       @return Puntero a la zona de memoria con los valores de los píxeles. 0 en caso de
       errores.
    */

    const unsigned char* GetVector();

    /**
       @brief Calcula el maximo/imagen valor de imagen.
       @param bool opcion, depende de su estado coge el maximo o el minimo.    
       @return  el valor maximo/minimo.
    */

    byte MaxMinImagen(bool opcion);


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

    /**
        @brief Leer una imagen en formato PGM.
        @param nombre: Nombre del fichero con la imagen PGM.
        @param filas: Número de filas de la imagen leída.
        @param columnas: Número de columnas de la imagen leída.
        @return Puntero a la zona de memoria con los valores de los píxeles. 0 en caso de
        errores.
    **/
    unsigned char* LeerImagenPGM(const string nombre, int& filas, int& columnas);




   

    /**
        @brief Guarda una imagen en formato PGM.
        @param v: Vector con los valores de los píxeles de la imagen almacenados por filas.
        Tiene filas x columnas componentes.
        @param nombre: Nombre del fichero con la imagen PGM.
        @param filas: Número de filas de la imagen.
        @param columnas: Número de columnas de la imagen.
        @return true en caso de éxito y false en caso de error.
        Guarda en el fichero indicado por 'nombre' la imagen incluida en 'v' y devuelve un
        booleano indicando si ha tenido o no éxito.
    */
    bool EscribirImagenPGM(const char* nombre, const unsigned char* v,
        const int filas, const int columnas);

    /**
     @brief Consiste en generar a partir de una imagen original, otra imagen con el criterio de que si un
            pixel de la imagen original tiene un nivel de gris p comprendido en un intervalo
            definido por 2 umbrales T_1 y T_2.
     @param  fichero1: nombre del fichero que contiene la imagen original
     @param  fichero2:  nombre del fichero que contedrá el resultado de la transformación
     @param  T_1:   los valores del intervalo de la umbralización
     @param  T_2:   los valores del intervalo de la umbralización
     @return devuelve el fichero con la imagen umbralizada
    */
    void UmbralizarGrises(const char* fichero1, const char* fichero2, int T_1, int T_2);

    /**
     @brief  Consiste en realizar un zoom de una porción de la imagen mediante un simple procedimiento
             de interpolación consistente en construir a partir de una subimagen N x N, una imagen
             dedimension (2N-1) x (2N-1).
     @param  fichero1: nombre del fichero que contiene la imagen original
     @param  fichero2:  nombre del fichero que contedrá el resultado de la transformación
     @param  x1/y1:   coordenadas esquina superior izquierda.
     @param x2/y2:   coordenadas esquina inferior derecha.
     @return devuelve el fichero con la subimagen (fichero 2)
    */

    void ZoomImagen(const char* fichero1, const char* fichero2, int x1, int y1, int x2, int y2);

     /**
     @brief  Consiste en cambiar los niveles maximos y minimos de grises de una imagen a 
             traves de una formula dada
     @param  nombre del fichero de imagen origen
     @param  nombre del fichero de imagen final con el filtro ya aplicado
     @param  minimo del intervalo
     @param  maximo del intervalo
     @return devuelve el fichero con la subimagen (fichero 2)

    */
    void AumentoContraste(const char* fichero1, const char* fichero2,int min, int max);

};




#endif /* IMAGEN_H */
