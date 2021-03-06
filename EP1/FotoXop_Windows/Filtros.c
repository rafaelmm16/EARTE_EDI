#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Imagem.h"
#include "Filtros.h"

#define COORD_INDEX(x ,y , w)    (x+ (y*w)) // w for width

void escurecerImagem(Imagem *img)
{
    int v;
    printf("Digite o fator de escurecimento: ");
    scanf("%d", &v);

    for (int h = 0; h < obtemAltura(img); h++)
    {
        for (int w = 0; w < obtemLargura(img); w++)
        {
            Pixel pixel = obtemPixel(img, h, w);
            pixel.cor[RED] = (((int)pixel.cor[RED] - v) >= 0 ? (pixel.cor[RED] - v) : 0);
            pixel.cor[GREEN] = (((int)pixel.cor[GREEN] - v) >= 0 ? (pixel.cor[GREEN] - v) : 0);
            pixel.cor[BLUE] = (((int)pixel.cor[BLUE] - v) >= 0 ? (pixel.cor[BLUE] - v) : 0);
            recolorePixel(img, h, w, pixel);
        }
    }
}

void clarearImagem(Imagem *img)
{
    int v;
    printf("Digite o fator de clareamento: ");
    scanf("%d", &v);

    for (int h = 0; h < obtemAltura(img); h++)
    {
        for (int w = 0; w < obtemLargura(img); w++)
        {
            Pixel pixel = obtemPixel(img, h, w);
            pixel.cor[RED] = (((int)pixel.cor[RED] + v) <= 255 ? (pixel.cor[RED] + v) : 255);
            pixel.cor[GREEN] = (((int)pixel.cor[GREEN] + v) <= 255 ? (pixel.cor[GREEN] + v) : 255);
            pixel.cor[BLUE] = (((int)pixel.cor[BLUE] + v) <= 255 ? (pixel.cor[BLUE] + v) : 255);
            recolorePixel(img, h, w, pixel);
        }
    }
}

void escalaDeCinzaImagem(Imagem *img)
{
    int media = 0;

    for (int h = 0; h < obtemAltura(img); h++)
    {
        for (int w = 0; w < obtemLargura(img); w++)
        {

            Pixel pixel = obtemPixel(img, h, w);
            media = (((int)pixel.cor[RED])+((int)pixel.cor[GREEN])+((int)pixel.cor[BLUE]))/3;
            pixel.cor[RED] = media;
            pixel.cor[GREEN] = media;
            pixel.cor[BLUE] = media;
            recolorePixel(img, h, w, pixel);
        }
    }
}

void filtroSobel(Imagem *img)
{
   /* Dicas:
     * 1) Se quiser, pode ignorar as bordas das imagens
     * 2) Para o pixel na posição (h, w), obtenha os outros 8 pixels vizinhos e aplique a matriz gx e gy
     *    em cada banda de cor do pixel. Combine o valor obtido por gx e gy e modifique o pixel de img.
     *    Lembre-se que a obtenção dos pixels deve ser a partir de uma cópia da imagem.
     * 3) Verifique se o novo valor obtido para a banda de cor é um valor válido (entre 0 e 255).
    */

    Imagem *copia = NULL;
    copia = copiaImagem(img);

    for(int i = 1; i < obtemAltura(img)-1; i++){
        for(int j = 1; j < obtemLargura(img)-1; j++){

            Pixel pixel = obtemPixel(copia, i, j);

            Pixel I1 = obtemPixel(copia, i-1, j-1);
            Pixel I2 = obtemPixel(copia, i-1, j);
            Pixel I3 = obtemPixel(copia, i-1, j+1);

            Pixel I7 = obtemPixel(copia, i+1, j-1);
            Pixel I8 = obtemPixel(copia, i+1, j);
            Pixel I9 = obtemPixel(copia, i+1, j+1);

            Pixel J1 = obtemPixel(copia, i-1, j-1);
            Pixel J4 = obtemPixel(copia, i, j-1);
            Pixel J7 = obtemPixel(copia, i+1, j-1);

            Pixel J3 = obtemPixel(copia, i-1, j+1);
            Pixel J6 = obtemPixel(copia, i, j+1);
            Pixel J9 = obtemPixel(copia, i+1, j+1);

            int red_x = 0, green_x = 0, blue_x = 0;

            red_x = (int)I1.cor[RED]*1 + (int)I2.cor[RED]*2 + (int)I3.cor[RED]*1
            + (int)I7.cor[RED]*(-1) + (int)I8.cor[RED]*(-2) + (int)I9.cor[RED]*(-1);

            green_x = (int)I1.cor[GREEN]*1 + (int)I2.cor[GREEN]*2 + (int)I3.cor[GREEN]*1
            + (int)I7.cor[GREEN]*(-1) + (int)I8.cor[GREEN]*(-2) + (int)I9.cor[GREEN]*(-1);

            blue_x = (int)I1.cor[BLUE]*1 + (int)I2.cor[BLUE]*2 + (int)I3.cor[BLUE]*1
            + (int)I7.cor[BLUE]*(-1) + (int)I8.cor[BLUE]*(-2) + (int)I9.cor[BLUE]*(-1);

            int red_y = 0, green_y = 0, blue_y = 0;

            red_y = (int)J1.cor[RED]*1 + (int)J4.cor[RED]*2 + (int)J7.cor[RED]*1
            + (int)J3.cor[RED]*(-1) + (int)J6.cor[RED]*(-2) + (int)J9.cor[RED]*(-1);

            green_y = (int)J1.cor[green_y]*1 + (int)J4.cor[green_y]*2 + (int)J7.cor[green_y]*1
            + (int)J3.cor[green_y]*(-1) + (int)J6.cor[green_y]*(-2) + (int)J9.cor[green_y]*(-1);

            blue_y = (int)J1.cor[blue_y]*1 + (int)J4.cor[blue_y]*2 + (int)J7.cor[blue_y]*1
            + (int)J3.cor[blue_y]*(-1) + (int)J6.cor[blue_y]*(-2) + (int)J9.cor[blue_y]*(-1);

            int RED_Count = 0, GREEN_Count = 0, BLUE_Count = 0;

            RED_Count = sqrt(pow(red_x, 2) + pow(red_y, 2))/3;
            GREEN_Count = sqrt(pow(green_x, 2) + pow(green_y, 2))/3;
            BLUE_Count = sqrt(pow(blue_x, 2) + pow(blue_y, 2))/3;

            //Verificação da soma (0 - 255)
            if (RED_Count < 0){
                RED_Count = 0;
            }
            else if (RED_Count >= 255){
                RED_Count = 255;
            }
            else if (GREEN_Count < 0){
                GREEN_Count = 0;
            }
            else if (GREEN_Count >= 255){
                GREEN_Count = 255;
            }
            else if (BLUE_Count < 0){
                BLUE_Count = 0;
            }
            else if (BLUE_Count >= 255){
                BLUE_Count = 255;
            }
            else{
                pixel.cor[RED] = RED_Count;
                pixel.cor[GREEN] = GREEN_Count;
                pixel.cor[BLUE] = BLUE_Count;

                recolorePixel(img, i, j, pixel);
            }
        }
    }
    free(copia);
}

void deteccaoBordasLaplace(Imagem *img)
{
    Imagem *copia = NULL;
    copia = copiaImagem(img);

    for (int i = 1; i < obtemAltura(img)-1; i++){
        for (int j = 1; j < obtemLargura(img)-1; j++){

        Pixel pixel = obtemPixel(copia, i, j);

        Pixel I2 = obtemPixel(copia, i-1, j);
        Pixel I4 = obtemPixel(copia, i, j+1);
        Pixel I6 = obtemPixel(copia, i, j-1);
        Pixel I8 = obtemPixel(copia, i+1, j);

        int RED_Count = 0, GREEN_Count = 0, BLUE_Count = 0;

        RED_Count = (int)I2.cor[RED]*(-1) + (int)I4.cor[RED]*(-1) + (int)pixel.cor[RED]*4
        + (int)I6.cor[RED]*(-1) + (int)I8.cor[RED]*(-1);

        GREEN_Count = (int)I2.cor[GREEN]*(-1) + (int)I4.cor[GREEN]*(-1) + (int)pixel.cor[GREEN]*4
        + (int)I6.cor[GREEN]*(-1) + (int)I8.cor[GREEN]*(-1);

        BLUE_Count = (int)I2.cor[BLUE]*(-1) + (int)I4.cor[BLUE]*(-1) + (int)pixel.cor[BLUE]*4
        + (int)I6.cor[BLUE]*(-1) + (int)I8.cor[BLUE]*(-1);

        RED_Count =  sqrt(RED_Count*RED_Count + RED_Count*RED_Count)/3;
        GREEN_Count = sqrt(GREEN_Count*GREEN_Count + GREEN_Count*GREEN_Count)/3;
        BLUE_Count = sqrt(BLUE_Count*BLUE_Count + BLUE_Count*BLUE_Count)/3;

        //Verificação da soma (0 - 255)
        if (RED_Count < 0){
            RED_Count = 0;
        }
        else if (RED_Count > 255){
            RED_Count = 255;
        }
        else if (GREEN_Count < 0){
            GREEN_Count = 0;
        }
        else if (GREEN_Count > 255){
            GREEN_Count = 255;
        }
        else if (BLUE_Count < 0){
            BLUE_Count = 0;
        }
        else if (BLUE_Count > 255){
            BLUE_Count = 255;
        }
        else{
            pixel.cor[RED] = RED_Count;
            pixel.cor[GREEN] = GREEN_Count;
            pixel.cor[BLUE] = BLUE_Count;

            recolorePixel(img, i, j, pixel);
            }
        }
    }
    free(copia);
}

void meuFiltro(Imagem *img)
{
    Imagem *copia = NULL;
    copia = copiaImagem(img);

    for(int i = 1; i < obtemAltura(img)-1; i++){
        for(int j = 1; j < obtemLargura(img)-1; j++){

            Pixel pixel = obtemPixel(copia, i, j);

            Pixel I1 = obtemPixel(copia, i-1, j-1);
            Pixel I2 = obtemPixel(copia, i-1, j);
            Pixel I3 = obtemPixel(copia, i-1, j+1);

            Pixel I4 = obtemPixel(copia, i-1, j+1);
            Pixel I5 = obtemPixel(copia, i-1, j+1);
            Pixel I6 = obtemPixel(copia, i-1, j+1);

            Pixel I7 = obtemPixel(copia, i+1, j-1);
            Pixel I8 = obtemPixel(copia, i+1, j);
            Pixel I9 = obtemPixel(copia, i+1, j+1);

            Pixel J1 = obtemPixel(copia, i-1, j-1);
            Pixel J4 = obtemPixel(copia, i, j-1);
            Pixel J7 = obtemPixel(copia, i+1, j-1);

            Pixel J3 = obtemPixel(copia, i-1, j+1);
            Pixel J6 = obtemPixel(copia, i, j+1);
            Pixel J9 = obtemPixel(copia, i+1, j+1);

            int red_x = 0, green_x = 0, blue_x = 0;

            red_x = (int)I1.cor[RED]*2 + (int)I2.cor[RED]*4 + (int)I3.cor[RED]*8
            + (int)I4.cor[RED]*1 + (int)I5.cor[RED]*1 + (int)I6.cor[RED]*1
            + (int)I7.cor[RED]*(-2) + (int)I8.cor[RED]*(-4) + (int)I9.cor[RED]*(-8);

            green_x = (int)I1.cor[GREEN]*2 + (int)I2.cor[GREEN]*4 + (int)I3.cor[GREEN]*8
            + (int)I4.cor[RED]*1 + (int)I5.cor[RED]*1 + (int)I6.cor[RED]*1
            + (int)I7.cor[GREEN]*(-2) + (int)I8.cor[GREEN]*(-4) + (int)I9.cor[GREEN]*(-8);

            blue_x = (int)I1.cor[BLUE]*2 + (int)I2.cor[BLUE]*4 + (int)I3.cor[BLUE]*8
            + (int)I4.cor[RED]*1 + (int)I5.cor[RED]*1 + (int)I6.cor[RED]*1
            + (int)I7.cor[BLUE]*(-2) + (int)I8.cor[BLUE]*(-4) + (int)I9.cor[BLUE]*(-8);

            int red_y = 0, green_y = 0, blue_y = 0;

            red_y = (int)J1.cor[RED]*2 + (int)J4.cor[RED]*4 + (int)J7.cor[RED]*8
            + (int)J3.cor[RED]*(-2) + (int)J6.cor[RED]*(-4) + (int)J9.cor[RED]*(-8);

            green_y = (int)J1.cor[green_y]*2 + (int)J4.cor[green_y]*4 + (int)J7.cor[green_y]*8
            + (int)J3.cor[green_y]*(-2) + (int)J6.cor[green_y]*(-4) + (int)J9.cor[green_y]*(-8);

            blue_y = (int)J1.cor[blue_y]*2 + (int)J4.cor[blue_y]*4 + (int)J7.cor[blue_y]*8
            + (int)J3.cor[blue_y]*(-2) + (int)J6.cor[blue_y]*(-4) + (int)J9.cor[blue_y]*(-8);

            int RED_Count = 0, GREEN_Count = 0, BLUE_Count = 0;

            RED_Count = sqrt(pow(red_x, 2) + pow(red_y, 2))/6;
            GREEN_Count = sqrt(pow(green_x, 2) + pow(green_y, 2))/6;
            BLUE_Count = sqrt(pow(blue_x, 2) + pow(blue_y, 2))/6;

            //Verificação da soma (0 - 255)
            if (RED_Count < 0){
                RED_Count = 0;
            }
            else if (RED_Count >= 255){
                RED_Count = 255;
            }
            else if (GREEN_Count < 0){
                GREEN_Count = 0;
            }
            else if (GREEN_Count >= 255){
                GREEN_Count = 255;
            }
            else if (BLUE_Count < 0){
                BLUE_Count = 0;
            }
            else if (BLUE_Count >= 255){
                BLUE_Count = 255;
            }
            else{
                pixel.cor[RED] = RED_Count;
                pixel.cor[GREEN] = GREEN_Count;
                pixel.cor[BLUE] = BLUE_Count;

                recolorePixel(img, i, j, pixel);
            }
        }
    }
    free(copia);
}
