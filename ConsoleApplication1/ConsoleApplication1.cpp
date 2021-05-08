
// //////////////////////////////////////////////////////////
// how to use TooJpeg: creating a JPEG file
// see https://create.stephan-brumme.com/toojpeg/
// compile: g++ example.cpp toojpeg.cpp -o example -std=c++11
#include "C:\Users\xxx\Desktop\CImg-2.9.8_pre043021\CImg.h"
#include "..\..\..\..\Desktop\toojpeg\toojpeg.h"
#include "bitmap.h"
#include <vector>
#include <omp.h>
#include <iostream>
using namespace std;
using namespace cimg_library;


#include <fstream>

// output file
std::ofstream myFile("compresse22d.jpg", std::ios_base::out | std::ios_base::binary);

// write a single byte compressed by tooJpeg
void myOutput(unsigned char byte)
{
    myFile << byte;
}

// //////////////////////////////////////////////////////////
// use a C++ file stream
#include <fstream>

// output file



// //////////////////////////////////////////////////////////
int main()
{
    clock_t t;
    cimg::imagemagick_path("C:\\Program Files\\ImageMagick-7.0.11-Q16-HDRI\\magick.exe");
    CImg<unsigned char> image("test.jpg");
    image.save_bmp("imgB.bmp");
    image._width;
    
    Bitmap img;
    vector <vector <Pixel> > bmp;
    Pixel rgb;

    //read a file example.bmp and convert it to a pixel matrix
    img.open("imgB.bmp");

    //verify that the file opened was a valid image
    bool validBmp = img.isImage();
    auto image1 = new unsigned char[image._width * image._height * 3];
    //int number_of_threads =  1 + (rand() % 4);
    omp_set_num_threads(4);
    
    
    
    if (validBmp == true)
    {
        bmp = img.toPixelMatrix();
        int timeBefore =
         t = clock();
       
        for (auto y = 0; y < image._height; y++) {
            for (auto x = 0; x < image._width; x++)
            {
                
                auto offset = (y * image._width + x) * 3;
                image1[offset] = bmp[y][x].red;
                image1[offset + 1] = bmp[y][x].green;
                image1[offset + 2] = bmp[y][x].blue;
            }

           
        }

    }
    
    const auto width = 800;
    const auto height = 600;
    // RGB: one byte each for red, green, blue
    const auto bytesPerPixel = 3;

    // allocate memory

    // create a nice color transition (replace with your code)
    

    // start JPEG compression
    // note: myOutput is the function defined in line 18, it saves the output in example.jpg
    // optional parameters:
    const bool isRGB = true;  // true = RGB image, else false = grayscale
    const auto quality = 10;    // compression quality: 0 = worst, 100 = best, 80 to 90 are most often used
    const bool downsample = false; // false = save as YCbCr444 JPEG (better quality), true = YCbCr420 (smaller file)
    const char* comment = "TooJpeg example image"; // arbitrary JPEG comment
    auto ok = TooJpeg::writeJpeg(myOutput, image1, image._width, image._height, isRGB, quality, downsample, comment);


    // error => exit code 1
    t = clock() - t;

    printf("It took me %d clicks (%f seconds).\n", t, ((float)t) / CLOCKS_PER_SEC);
    std::ofstream outfile;

    outfile.open("test.txt", std::ios_base::app); // append instead of overwrite
    outfile << "number of threads "+ 4 + ' ' + std::to_string(((float)t) / CLOCKS_PER_SEC);
    outfile << endl;
    system("PAUSE");
    return 0;
}
