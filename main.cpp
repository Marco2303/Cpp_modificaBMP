#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{

    srand(time(0));

    fstream f("D:\\sviluppo\\QT\\Cpp_modificaBMP\\immagine.bmp",ios::out | ios::in | ios::binary);
    //fstream f("D:\\sviluppo\\QT\\build-Cpp_modificaBMP-Desktop_Qt_6_1_0_MinGW_64_bit-Debug\\debug\\immagine.bmp",ios::out | ios::in | ios::binary);
    f.seekg(0,ios::end);
    long dimensione = f.tellg();
    cout << "Dimensione BMP:  " << dimensione << endl;

    f.seekg(0,ios::beg);

    //char* r_long = new char[dimensione];

    char* immagineRAM = nullptr;

    immagineRAM = new char[dimensione];
    f.read(immagineRAM,dimensione);

    for (int i=10000;i<dimensione;i++){
       long disturbo = rand()% 256;
       immagineRAM[i] = disturbo;
       }

    //remove("D:\\sviluppo\\QT\\build-Cpp_modificaBMP-Desktop_Qt_6_1_0_MinGW_64_bit-Debug\\debug\\immagine.bmp");

    f.seekp(0, ios::beg);
    f.write(immagineRAM,dimensione);

    f.close();f.clear();

    system("pause");

    return 0;
}
