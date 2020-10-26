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
#include <fstream>
#include <istream>
#include <sstream>

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

int & Imagen::Getcolumnas(){

    return cols;
}

/****************************************************************************/

int & Imagen::Getfilas(){

    return filas;
}

/****************************************************************************/


const unsigned char* Imagen::GetVector(){

    unsigned char* vector;
    vector = new unsigned char[filas * cols];

    for (int f = 0; f < filas; f++) {

        for (int c = 0; c < cols; c++) {

            vector[((f*cols) + c )] = valor_pixel(f, c);
        }

    }

    return vector;
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

/****************************************************************************/
/*
unsigned char* Imagen::LeerImagenPGM(const char* nombre, int& filas, int& columnas) {

    istream archivo;
    string linea;
    stringstream aux;
    byte valor_max;

    string comentarios;

    archivo.open(nombre);
    getline(archivo, linea);

    if (linea_magica == "P5") {

        getline(archivo, comentarios);

        getline(archivo, linea);
        aux.str(linea);
        aux >> filas;
        aux >> columnas;
        aux >> valor_max;

        img = new byte * [filas];
        for (int f=0; f < filas; f++)
    }
    else {
      
    }

    
}
*/

/*
bool Imagen::EscribirImagenPGM(const char* nombre, const unsigned char* v, const int filas, const int columnas) {
    
    ofstream flujo;

    flujo.open(nombre);

    if (flujo.is_open())
    {
    
        flujo << "P5" << endl;
        flujo << "#comentario" << endl;
        flujo << columnas << endl;
        flujo << filas << endl;
        flujo << 255 << endl;

        for (int i=0;;i++)
        {
            for()
            {
            
            }
        
        }
    
    }
   
}
 */

void UmbralizarGrises(const char* fichero1, const char* fichero2, int T_1, int T_2) {

    Imagen fch1 (0,0);
    fch1.LeerImagenPGM(fichero1, fch1.Getfilas(), fch1.Getcolumnas());

    Imagen fch2(fch1.num_filas(), fch1.num_columnas());

    for (int f = 0; f < fch1.num_filas(); f++) {

        for (int c=0;c<fch1.Getcolumnas();c++)
        {
            if ( (fch1.valor_pixel(f,c) > T_1) && (fch1.valor_pixel(f, c) < T_2))
            {
                fch2.asigna_pixel(f, c, fch1.valor_pixel(f, c));
            
            }
            else {
                fch2.asigna_pixel(f, c, 255);
            }
        
        }
    }

    fch2.EscribirImagenPGM(fichero2, fch2.GetVector(), fch2.num_filas(), fch2.num_columnas());

}

void ZoomImagen(const char* fichero1, const char* fichero2, int x1, int y1, int x2, int y2) {

    int cont_f=0, cont_c=0;

    Imagen fch1(0, 0);
    fch1.LeerImagenPGM(fichero1,fch1.Getfilas(),fch1.Getcolumnas());

    Imagen fch2((fch1.num_filas() * 2) - 1, (fch1.num_columnas() * 2) - 1);

    for (int f = 0; f < fch2.num_filas(); f++) {

        for (int c = 0;c < fch2.Getcolumnas();c++) {

            if (f%2 == 0 && c%2 == 0)
            {
                fch2.asigna_pixel(f, c, fch1.valor_pixel(cont_f, cont_c));
                cont_c++;
            }
            else if( f%2 != 0)
            {
                fch2.asigna_pixel(f, c, 0);
            }

            
        }
        cont_f++;
        cont_c = 0;
    }

    for (int f=0;f<fch2.num_filas();f=f+2)
    {
        for (int c = 0;c < fch2.Getcolumnas();c++)
        {
            if (fch2.valor_pixel(f, c) == 0)
            {
                fch2.asigna_pixel(f, c, (fch2.valor_pixel(f, c - 1) + fch2.valor_pixel(f, c + 1)) / 2);
            }
            
        }
    }

    for (int f = 1;f<fch2.num_filas();f=f+2)
    {
        for (int c = 0;c < fch2.Getcolumnas();c++)
        {
            if (f % 2 != 0)
            {
                fch2.asigna_pixel(f, c, (fch2.valor_pixel(f + 1, c) + fch2.valor_pixel(f - 1, c)) / 2);
            }
          
        }
    }

     fch2.EscribirImagenPGM(fichero2, fch2.GetVector(), fch2.num_filas(), fch2.num_columnas());
}

byte Imagen::MaxMinImagen(bool opcion) {
    
    byte valor = 0;
    
    if (opcion) {

        for (int f = 0; f < num_filas(); f++)
        {
            for (int c = 0; c < num_columnas(); c++)
            {
                if (valor < valor_pixel(f, c)) {
                    valor = valor_pixel(f, c);
                }
            }
        }
    }

    else {

        valor = 1000;

        for (int f = 0; f < num_filas(); f++)
        {
            for (int c = 0; c < num_columnas(); c++)
            {
                if (valor > valor_pixel(f, c)) {
                    valor = valor_pixel(f, c);
                }
            }
        }
    }

    return valor;
}

void AumentoContraste(const char* fichero1, const char* fichero2, int min, int max)
{
    
    Imagen fch1(0, 0);
    fch1.LeerImagenPGM(fichero1, fch1.Getfilas(), fch1.Getcolumnas());
    Imagen fch2(fch1.num_filas() ,fch1.num_columnas());
    
    unsigned char valor;

    const byte max_img = fch1.MaxMinImagen(true);
    const byte min_img = fch1.MaxMinImagen(false);
    const double valor_fijo = (max - min) / (max_img-min_img);
    double valor_total = 0, decimales;
    int aux;


    for (int f = 0; f < fch2.num_filas(); f++)
    {
        for (int c = 0; c < fch2.num_columnas(); c++)
        {
            valor_total = min + (valor_fijo * (fch1.valor_pixel(f, c) - min_img));

            aux = valor_total;
            decimales = valor_total - aux;
            
            
            if (decimales >= 0.5)
            {
                valor = valor_total+1;
                fch2.asigna_pixel(f, c, valor);
            
            }
            else
            {
                valor = valor_total;
                fch2.asigna_pixel(f, c, valor);
            
            }
        }
    }

    fch2.EscribirImagenPGM(fichero2, fch2.GetVector(), fch2.num_filas(), fch2.num_columnas());


}






