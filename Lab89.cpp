#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "home.h"

int main()
{
    Home spisokhome;
    list box;
    int size = 0;
    box.Fileread(spisokhome);
    box.printList();
    box.ListSize(size);
    box.Search();
    box.swap(spisokhome, size);
    box.printList();
    box.edit(spisokhome, size);
    box.printList();
    box.add(spisokhome, size);
    box.printList();
    box.sort();
    box.printList();
    list minibox;
   box.Divide(box, minibox, size);
    std::cout << "Perviy spisok" << std::endl;
    box.printList();
    std::cout << "Vtoroy spisok" << std::endl;
    minibox.printList();
    box.Unite(box, minibox);
    std::cout << "Vostanovleniy spisok" << std::endl;
    box.printList();
    box.file(spisokhome);
    box.~list();
    return 0;
}
