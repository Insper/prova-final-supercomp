#ifndef IMAGEM_H
#define IMAGEM_H

#include <string>


typedef struct {
    int rows, cols;
    int total_size;
    int nchannels;
    unsigned char *pixels;
} imagem;


imagem *new_image(int rows, int cols, int nchannels);
imagem *read_pgm(std::string path);
void write_pgm(imagem *img, std::string path);

#endif
