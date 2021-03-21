#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#include "Imagem.h"
#include "Filtros.h"

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
    //AVISO(Filtros.c
          //: Ainda nao implementei a funcao 'clarearImagem'); //Retire esssa mensagem ao implementar a fução

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
    //AVISO(Filtros.c
          //: Ainda nao implementei a funcao 'escalaDeCinzaImagem'); //Retire esssa mensagem ao implementar a fução
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
    AVISO(Filtros.c
          : Ainda nao implementei a funcao 'filtroSobel'); //Retire esssa mensagem ao implementar a fução

    /* Dicas:
     * 1) Se quiser, pode ignorar as bordas das imagens
     * 2) Para o pixel na posição (h, w), obtenha os outros 8 pixels vizinhos e aplique a matriz gx e gy
     *    em cada banda de cor do pixel. Combine o valor obtido por gx e gy e modifique o pixel de img.
     *    Lembre-se que a obtenção dos pixels deve ser a partir de uma cópia da imagem.
     * 3) Verifique se o novo valor obtido para a banda de cor é um valor válido (entre 0 e 255).
    */
}

void deteccaoBordasLaplace(Imagem *img)
{
    AVISO(Filtros.c
          : Ainda nao implementei a funcao 'deteccaoBordasLaplace'); //Retire esssa mensagem ao implementar a fução

    /* Siga as mesmas dicas do filtro de Sobel */
}

void meuFiltro(Imagem *img)
{
    AVISO(Filtros.c
          : Ainda nao implementei a funcao 'meuFiltro'); //Retire esssa mensagem ao implementar a fução
}
