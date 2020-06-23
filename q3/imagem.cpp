#include "imagem.h"
#include <fstream>
#include <string>

imagem *new_image(int rows, int cols, int nchannels) {
    imagem *img = new imagem;
    img->rows = rows;
    img->cols = cols;
    img->total_size = rows * cols * nchannels;
    img->nchannels = nchannels;
    img->pixels = new unsigned char[img->total_size];
    return img;

}

imagem *read_pgm(std::string path) {
    std::ifstream inf(path);
    std::string first_line;
    std::getline(inf, first_line);
    int nchannels;
    if (first_line == "P3") {
        nchannels = 3;
    } else if (first_line == "P2") {
        nchannels = 1;
    } else {
        return NULL;
    }

    imagem *img = new imagem;
    inf >> img->cols;
    inf >> img->rows;
    img->nchannels = nchannels;
    int temp;
    inf >> temp;
    img->total_size = img->rows * img->cols * img->nchannels;
    img->pixels = new unsigned char[img->total_size];

    for (int k = 0; k < img->total_size; k++) {
        int t;
        inf >> t;
        img->pixels[k] = t;
    }

    return img;
}

inline int get_color(imagem *img, int i, int j, int k) {
    int row_size = img->cols * img->nchannels;
    return img->pixels[i * row_size + j * img->nchannels + k];
}

void write_pgm(imagem *img, std::string path) {
    std::ofstream of(path);
    if (img->nchannels == 3) {
        of << "P3\n";
    } else {
        of << "P2\n";
    }
    of << img->cols << " " <<  img->rows << " 255\n";
    for (int k = 0; k < img->total_size; k++) {
        of << ((int) img->pixels[k]) << " ";
    }
}

