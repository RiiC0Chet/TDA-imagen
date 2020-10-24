/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   Imagen.cpp
  * Author: dmartinez01
  *
  * Created on 24 de octubre de 2020, 11:07
  */

#include "Imagen.h"
#include <iostream>

using namespace std;

/****************************************************************************/

Imagen::Imagen(int filas_aux, int cols_aux) {

    // Crear una imagen plana con valor 255 (blanco)
    filas = filas_aux;
    cols = cols_aux;

    img = new byte * [filas];

    for (int f = 0; f < filas; f++) {

        img[f] = new byte[cols];
        for (int c = 0; c < cols; c++) {
            img[f][c] = 255;
        }
    }


    // Crear el marco que delimita la imagen
    for (int f = 0; f < filas; f++) // lado izquierdo
        img[f][0] = 0;

    for (int f = 0; f < filas; f++) // lado derecho
        img[f][cols - 1] = 0;

    for (int c = 0; c < cols; c++) // lado superior
        img[0][c] = 0;

    for (int c = 0; c < cols; c++) // lado inferior
        img[filas - 1][c] = 0;


}

/****************************************************************************/

Imagen::~Imagen() {

    for (int f = 0; f < filas; f++)
        delete img[f];

    delete [] img;

};

/****************************************************************************/

int Imagen::num_filas() const {

    return filas;
}

/****************************************************************************/

int Imagen::num_columnas() const {

    return cols;
}

/****************************************************************************/

byte Imagen::valor_pixel(int fila, int col) const {

    return img[fila][col];
}

/****************************************************************************/

void Imagen::enmarca_imagen()
{
    for (int f = 0; f < filas; f++) // lado izquierdo
        img[f][0] = 0;

    for (int f = 0; f < filas; f++) // lado derecho
        img[f][cols - 1] = 0;

    for (int c = 0; c < cols; c++) // lado superior
        img[0][c] = 0;

    for (int c = 0; c < cols; c++) // lado inferior
        img[filas - 1][c] = 0;

}

/****************************************************************************/

void Imagen::asigna_pixel(int fila, int col, byte valor) {

    img[fila][col] = valor;
}