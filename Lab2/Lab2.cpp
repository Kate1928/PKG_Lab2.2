// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

    //window.setVerticalSyncEnabled(true);

    /*CircleShape shape(100.f, 3);
    shape.setPosition(100, 100);
    shape.setFillColor(Color::Magenta);*/

    ifstream file;
    file.open("File2");
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

    for (int x = 0; x < header[0] * header[1] * 4; x += 4)
    {

        pixel = getColor(ind, header[2], x);
        pixel = pixel >> 1;
        pixels[x] = argbAll[pixel].r;
        pixels[x + 1] = argbAll[pixel].g;
        pixels[x + 2] = argbAll[pixel].b;
        pixels[x + 3] = argbAll[pixel].a;
    }
    window.clear(Color::Black);
    texture.update(pixels);
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