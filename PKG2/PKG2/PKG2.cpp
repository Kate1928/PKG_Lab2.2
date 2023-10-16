//// PKG2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


//--------------------------------------------------BASE---------------------------------------------------

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

//---------------------------------------------------B4-----------------------------------------------

// PKG2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

    /* cout << "No file specified\n";
     cin >> leftMove;*/
//    cin >> hex >> leftMove;
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
    

    //-------------------get image-------------

    vector<unsigned int> ind, indAll;
    unsigned int pixel_index = 0, bit;
    //string str;

    Texture texture;
    texture.create(header[0], header[1]);

    Sprite sprite(texture);

    while (file.get(byte1))
    {
        getByte(byte1, ind);
    }
    int a = 0;

    BYTE newARGB;
    unsigned long int newColor;
    bool choise;
    cout << "Change the color? 1-yes/0-no ";
    cin >> choise;
    if (choise)
    {
         cout << endl << "Enter a new color in hexademical format(ARGB):  ";
        cin >> hex >> newColor;
        argbAll[0].b = newColor & 255;
        newColor = newColor >> 8;
        argbAll[0].g = newColor & 255;
        newColor = newColor >> 8;
        argbAll[0].r = newColor & 255;
        newColor = newColor >> 8;
        argbAll[0].a = newColor & 255;
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

//-----------------------------------------------------П6---------------------------------------------------

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
//    ifstream filePallete;
//    filePallete.open("File2");
//    char byte1;
//    char byte2;
//    unsigned int header[4], leftMove = 0;
//
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
//    for (int i = 0; i < 5; i++)
//    {
//        filePallete.get(byte1);
//    }
//    //int countColors = 0;
//    filePallete.get(byte1);
//    filePallete.get(byte2);
//    header[3] = byte1 << 16;
//    header[3] = header[3] | byte2;
//    for (int i = 0; i < header[3]; i++)
//    {
//        filePallete.get(byte1);
//        argbAll[i].a = byte1;
//        filePallete.get(byte1);
//        argbAll[i].r = byte1;
//        filePallete.get(byte1);
//        argbAll[i].g = byte1;
//        filePallete.get(byte1);
//        argbAll[i].b = byte1;
//    }
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