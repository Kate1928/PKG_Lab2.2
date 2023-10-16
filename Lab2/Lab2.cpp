// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

//-----------------------------------------BASE-----------------------------------------

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
//int getIndex(vector<unsigned int>& ind, unsigned int header, int x)
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
//    header[0] = byte1 << 8;
//    header[0] = header[0] | byte2;
//
//    file.get(byte1);
//    file.get(byte2);
//    header[1] = byte1 << 8;
//    header[1] = header[1] | byte2;
//
//    file.get(byte1);
//    header[2] = byte1;
//
//    file.get(byte1);
//    file.get(byte2);
//    header[3] = byte1 << 8;
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
//    unsigned int pixel_index = 0, bit;
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
//        pixel_index = getIndex(ind, header[2], x);
//        pixel_index = pixel_index >> 1;
//        if (pixel_index < header[3])
//        {
//            pixels[x] = argbAll[pixel_index].r;
//            pixels[x + 1] = argbAll[pixel_index].g;
//            pixels[x + 2] = argbAll[pixel_index].b;
//            pixels[x + 3] = argbAll[pixel_index].a;
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

//-----------------------------------------B6-----------------------------------------------

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
//int getIndex(vector<unsigned int>& ind, unsigned int header, int x)
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
//    ifstream file2;
//    file2.open("File3");
//    char byte1;
//    char byte2;
//    unsigned int header[4], leftMove = 0;
//
//    //----------------get fileData----------------
//    file.get(byte1);
//    file.get(byte2);
//
//    header[0] = byte1 << 8;
//    header[0] = header[0] | byte2;
//
//    file.get(byte1);
//    file.get(byte2);
//    header[1] = byte1 << 8;
//    header[1] = header[1] | byte2;
//
//    file.get(byte1);
//    header[2] = byte1;
//
//    file.get(byte1);
//    file.get(byte2);
//    header[3] = byte1 << 8;
//    header[3] = header[3] | byte2;
//
//
//    //-----------------get Colors------------------
//
//
////    ARGB* argbAll = new ARGB[header[3]];
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
//    for (int i = 0; i < 4; i++)
//    {
//        file2.get(byte1);
//    }
//    file2.get(byte1);
//    unsigned int pb = byte1;
//    //int countColors = 0;
//    file2.get(byte1);
//    file2.get(byte2);
//    header[3] = byte1 << 16;
//    header[3] = header[3] | byte2;
//    
//    ARGB* argbAll2 = new ARGB[header[3]];
//
//    for (int i = 0; i < header[3]; i++)
//    {
//        file2.get(byte1);
//        argbAll2[i].a = byte1;
//        file2.get(byte1);
//        argbAll2[i].r = byte1;
//        file2.get(byte1);
//        argbAll2[i].g = byte1;
//        file2.get(byte1);
//        argbAll2[i].b = byte1;
//    }
//
//    //-------------------get image-------------
//
//    vector<unsigned int> ind, ind2, indAll;
//    unsigned int pixel_index = 0, pixel2 = 0, bit;
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
//    while (file2.get(byte1))
//    {
//        getByte(byte1, ind2);
//    }
//    int a = 0;    
//
//
//    BYTE* pixels = new BYTE[header[0] * header[1] * 4];
//
//    for (int x = 0; x < header[0] * header[1] * 4; x += 4)
//    {
//
//        pixel_index = getIndex(ind, header[2], x);
//        pixel2 = getIndex(ind2, pb, x);
//        pixel_index = pixel_index >> 1;
//        pixel2 = pixel2 >> 1;
//        if (pixel_index < header[3] && pixel2 < pb)
//        {
//            pixels[x] = argbAll[pixel_index].r | argbAll2[pixel2].r;
//            pixels[x + 1] = argbAll[pixel_index].g | argbAll2[pixel2].g;
//            pixels[x + 2] = argbAll[pixel_index].b | argbAll2[pixel2].b;
//            pixels[x + 3] = argbAll[pixel_index].a | argbAll2[pixel2].a;
//        }
//        else
//        {
//            if (pixel_index >= header[3])
//            {
//                pixels[x] = Color::Black.r | argbAll2[pixel2].r;
//                pixels[x + 1] = Color::Black.g | argbAll2[pixel2].g;
//                pixels[x + 2] = Color::Black.b | argbAll2[pixel2].b;
//                pixels[x + 3] = Color::Black.a | argbAll2[pixel2].a;
//            }
//            else
//            {
//                pixels[x] = Color::Black.r | argbAll[pixel_index].r;
//                pixels[x + 1] = Color::Black.g | argbAll[pixel_index].g;
//                pixels[x + 2] = Color::Black.b | argbAll[pixel_index].b;
//                pixels[x + 3] = Color::Black.a | argbAll[pixel_index].a;
//            }
//            
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

//-----------------------------------------П1-----------------------------------------


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



int getIndex(vector<unsigned int>& ind, unsigned int header, int x)
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

    ifstream file;
    file.open("File4");
    char byte1;
    char byte2;
    unsigned int header[4], leftMove = 0;

    //----------------get fileData----------------
    file.get(byte1);
    file.get(byte2);

    header[0] = byte1 << 8;
    header[0] = header[0] | byte2;

    file.get(byte1);
    file.get(byte2);
    header[1] = byte1 << 8;
    header[1] = header[1] | byte2;

    file.get(byte1);
    header[2] = byte1;

    file.get(byte1);
    file.get(byte2);
    header[3] = byte1 << 8;
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
    //------------------get new bmp-------------

    ofstream fileOut ("FileOut.bmp", ios::binary);

    // записываем заголовок файла
    unsigned int y = 19778;
    //fileOut.seekg(0, ios::beg);

    fileOut.write((char*)&y, 2);
    int x = 4; // number to round up
    int sizeX = ((header[0] * 3 + x - 1) & ~(x - 1));
    int size = sizeX * header[1];
    y = size + 54;
    fileOut.write((char*)&y, 4);
    y = 0;
    fileOut.write((char*)&y, 4);
    y = 54;
    fileOut.write((char*)&y, 4);

    // записываем заголовок изображения


    y = 40;
    fileOut.write((char*)&y, 4);
    fileOut.write((char*)&header[0], 4);
    fileOut.write((char*)&header[1], 4);
    y = 1;
    fileOut.write((char*)&y, 2);
    //fileOut.write(0, 1);
    y = 24;
    fileOut.write((char*)&y, 2);
    y = 0;
    fileOut.write((char*)&y, 4);

    fileOut.write((char*)&size, 4);
    y = 2835;
    fileOut.write((char*)&y, 4);
    fileOut.write((char*)&y, 4);
    y = 0;
    fileOut.write((char*)&y, 4);
    fileOut.write((char*)&y, 4);


    //-------------------get image-----+new bmp--------

    vector<unsigned int> ind, indAll;
    unsigned int pixel_index = 0, bit;

    Texture texture;
    texture.create(header[0], header[1]);

    Sprite sprite(texture);

    while (file.get(byte1))
    {
        getByte(byte1, ind);
    }
    

    BYTE* pixels = new BYTE[header[0] * header[1] * 4];

    for (int x = 0; x < header[0] * header[1] * 4; x += 4)
    {

        pixel_index = getIndex(ind, header[2], x);
        pixel_index = pixel_index >> 1;
        if (pixel_index < header[3])
        {
            pixels[x] = argbAll[pixel_index].r;
            pixels[x + 1] = argbAll[pixel_index].g;
            pixels[x + 2] = argbAll[pixel_index].b;
            pixels[x + 3] = argbAll[pixel_index].a;

        }
        else
        {
            pixels[x] = Color::Black.r;
            pixels[x + 1] = Color::Black.g;
            pixels[x + 2] = Color::Black.b;
            pixels[x + 3] = Color::Black.a;
        }
        /*if (a < header[0] - 1)
        {
            fileOut.write((char*)&pixels[x + 2], 1);
            fileOut.write((char*)&pixels[x + 1], 1);
            fileOut.write((char*)&pixels[x], 1);
            a++;
        }

        if (a == header[0] - 1)
        {
            fileOut.write((char*)&pixels[x + 2], 1);
            fileOut.write((char*)&pixels[x + 1], 1);
            fileOut.write((char*)&pixels[x], 1);
            y = 0;
            fileOut.write((char*)&y, (size / header[1]) - header[0]);
            a = 0;
        }*/
        
    }

    BYTE** pixelBMP = new BYTE * [header[1]];
    for (int i = 0; i < header[1]; i++)
    {
        pixelBMP[i] = new BYTE[header[0] * 4];
    }
    int a = 0;
    for (int i = 0; i < header[1]; i++)
    {
        for (int j = 0; j < header[0] * 4; j++)
        { 
            pixelBMP[i][j] = pixels[a++];
        }
    }

    for (int i = header[1] - 1; i >= 0; i--)
    {
        for (int j = 0; j < header[0] * 4; j += 4)
        {
            fileOut.write((char*)&pixelBMP[i][j + 2], 1);//b
            fileOut.write((char*)&pixelBMP[i][j + 1], 1);//g
            fileOut.write((char*)&pixelBMP[i][j], 1);//r
        }
        y = 0;
        fileOut.write((char*)&y, sizeX - (header[0] * 3));
    }
    window.clear(Color::Black);
    texture.update(pixels);
    //sprite.setScale(10.0, 10.0);
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
