// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

////--------------------------------------BASE-----------------------------------------
//
//#include <SFML/Graphics.hpp>
//#include <windows.h>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//using namespace sf;
//
//
//void getByte(char byte1, vector<unsigned int>& ind)
//{
//    unsigned int t, res = 0, base = 256;
//    t = byte1 & 255;
//    for (int i = 0; i < 8; i++)
//    {
//        res += (t & 1) * (base >>= 1);
//        t >>= 1;
//    }
//    for (int i = 0; i < 8; i++)
//    {
//        ind.push_back(res & 1);
//        res >>= 1;
//    }
//    return;
//}
//
//
//
//int getColor(vector<unsigned int>& ind, unsigned int header, int x)
//{
//    unsigned int pixel = 0;
//    for (int i = 0; i < header; i++)
//    {
//        pixel = pixel | ind[i];
//        pixel = pixel << 1;
//    }
//    auto begin = ind.cbegin(); // указатель на первый элемент
//    ind.erase(begin, begin + header); // удаляем с третьего элемента до последнего
//    
//    return pixel;
//}
//
//struct ARGB
//{
//    BYTE a;		// alpha
//    BYTE r;		// red
//    BYTE g;		// green
//    BYTE b;		// blue
//};
//
//
//
//int main()
//{
//
//    RenderWindow window(VideoMode(400, 400), "Lab2");
//
//    ifstream file;
//    file.open("File4");
//    char byte1;
//    char byte2;
//    unsigned int header[4], leftMove = 0;
//
//    //----------------get fileData----------------
//    file.get(byte1);
//    file.get(byte2);
//
//    header[0] = byte1 << 16;
//    header[0] = header[0] | byte2;
//
//    file.get(byte1);
//    file.get(byte2);
//    header[1] = byte1 << 16;
//    header[1] = header[1] | byte2;
//
//    file.get(byte1);
//    header[2] = byte1;
//
//    file.get(byte1);
//    file.get(byte2);
//    header[3] = byte1 << 16;
//    header[3] = header[3] | byte2;
//
//
//    //-----------------get Colors------------------
//
//
//    ARGB* argbAll = new ARGB[header[3]];
//    BYTE rgb;
//    for (int i = 0; i < header[3]; i++)
//    {
//        file.get(byte1);
//        argbAll[i].a = byte1;
//        file.get(byte1);
//        argbAll[i].r = byte1;
//        file.get(byte1);
//        argbAll[i].g = byte1;
//        file.get(byte1);
//        argbAll[i].b = byte1;
//    }
//
//    //-------------------get image-------------
//
//    vector<unsigned int> ind, indAll;
//    unsigned int pixel = 0, bit;
//    //string str;
//
//    Texture texture;
//    texture.create(header[0], header[1]);
//
//    Sprite sprite(texture);
//
//    while (file.get(byte1))
//    {
//        getByte(byte1, ind);
//    }
//    int a = 0;
//
//    BYTE* pixels = new BYTE[header[0] * header[1] * 4];
//
//    for (int x = 0; x < header[0] * header[1] * 4; x += 4)
//    {
//
//        pixel = getColor(ind, header[2], x);
//        pixel = pixel >> 1;
//        if (pixel < header[3])
//        {
//            pixels[x] = argbAll[pixel].r;
//            pixels[x + 1] = argbAll[pixel].g;
//            pixels[x + 2] = argbAll[pixel].b;
//            pixels[x + 3] = argbAll[pixel].a;
//        }
//        else
//        {
//            pixels[x] = Color::Black.r;
//            pixels[x + 1] = Color::Black.g;
//            pixels[x + 2] = Color::Black.b;
//            pixels[x + 3] = Color::Black.a;
//        }
//    }
//    window.clear(Color::Black);
//    texture.update(pixels);
//    sprite.setScale(10.0, 10.0);
//    window.draw(sprite);
//    window.display();
//
//    while (window.isOpen())
//    {
//        Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//                window.close();
//        }
//
//        
//    }
//    return 0;
//}

//--------------------------------------B1-----------------------------------------

#include <SFML/Graphics.hpp>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
using namespace sf;


void getByte(char byte1, vector<unsigned int>& ind)
{
    unsigned int t, res = 0, base = 256;
    t = byte1 & 255;
    for (int i = 0; i < 8; i++)
    {
        res += (t & 1) * (base >>= 1);
        t >>= 1;
    }
    for (int i = 0; i < 8; i++)
    {
        ind.push_back(res & 1);
        res >>= 1;
    }
    return;
}



int getColor(vector<unsigned int>& ind, unsigned int header, int x)
{
    unsigned int pixel = 0;
    for (int i = 0; i < header; i++)
    {
        pixel = pixel | ind[i];
        pixel = pixel << 1;
    }
    auto begin = ind.cbegin(); // указатель на первый элемент
    ind.erase(begin, begin + header); // удаляем с третьего элемента до последнего

    return pixel;
}

BYTE brightness(BYTE r, BYTE g, BYTE b)
{
    return 0.299 * r + 0.587 * g + 0.114 * b;
}

struct ARGB
{
    BYTE a;		// alpha
    BYTE r;		// red
    BYTE g;		// green
    BYTE b;		// blue
};



int main()
{

    RenderWindow window(VideoMode(400, 400), "Lab2");

    ifstream file;
    file.open("File4");
    char byte1;
    char byte2;
    unsigned int header[4], leftMove = 0;

    //----------------get fileData----------------
    file.get(byte1);
    file.get(byte2);

    header[0] = byte1 << 16;
    header[0] = header[0] | byte2;

    file.get(byte1);
    file.get(byte2);
    header[1] = byte1 << 16;
    header[1] = header[1] | byte2;

    file.get(byte1);
    header[2] = byte1;

    file.get(byte1);
    file.get(byte2);
    header[3] = byte1 << 16;
    header[3] = header[3] | byte2;


    //-----------------get Colors------------------


    ARGB* argbAll = new ARGB[header[3]];
    BYTE rgb;
    for (int i = 0; i < header[3]; i++)
    {
        file.get(byte1);
        argbAll[i].a = byte1;
        file.get(byte1);
        argbAll[i].r = byte1;
        file.get(byte1);
        argbAll[i].g = byte1;
        file.get(byte1);
        argbAll[i].b = byte1;
    }

    //-------------------get image-------------

    vector<unsigned int> ind, indAll;
    unsigned int pixel = 0, bit;
    //string str;

    Texture texture;
    texture.create(header[0], header[1]);

    Sprite sprite(texture);

    while (file.get(byte1))
    {
        getByte(byte1, ind);
    }
    int a = 0;

    BYTE* pixels = new BYTE[header[0] * header[1] * 4];
    BYTE bri = 0;
    vector<int> allPixels;

    for (int x = 0; x < header[0] * header[1] * 4; x += 4)
    {
        
        pixel = getColor(ind, header[2], x);
        pixel = pixel >> 1;
        bri += brightness(argbAll[pixel].r, argbAll[pixel].g, argbAll[pixel].b);// all brightness
        allPixels.push_back(pixel);
        /*if (pixel < header[3])
        {
            pixels[x] = argbAll[pixel].r;
            pixels[x + 1] = argbAll[pixel].g;
            pixels[x + 2] = argbAll[pixel].b;
            pixels[x + 3] = argbAll[pixel].a;
        }
        else
        {
            pixels[x] = Color::Black.r;
            pixels[x + 1] = Color::Black.g;
            pixels[x + 2] = Color::Black.b;
            pixels[x + 3] = Color::Black.a;
        }*/
    }
    //средняя яркость 
    bri /= header[0] * header[1];
    cout << "Enter a contrast level:  ";
    int contrastLevel;
    cin >> contrastLevel;
    //Коэффициент коррекции
    double k = 1.0 + contrastLevel / 100.0;
    for (int i = 0; i < header[3]; i++)
    {
        int delta = i - bri;
        int temp = bri + k * delta;

        if (temp < 0)
            temp = 0;

        if (temp >= 255)
            temp = 255;
        argbAll[i] = (unsigned char)temp;
    }
    window.clear(Color::Black);
    texture.update(pixels);
    sprite.setScale(10.0, 10.0);
    window.draw(sprite);
    window.display();

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }


    }
    return 0;
}


