#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>



struct Home
{
    std::string id {""};
    std::string adress{""};
    std::string telephone{""};
    std::string area{""};
    std::string rooms{""};
	std::string cost{""};
    Home *Next;
};

struct list
{
    Home *Head;
    list(): Head(NULL){};                    
    ~list();                                
    void Fileread(Home &spisokhome);             
    void printList();                            
    void Search();
    void print(Home *tmp);
    void swap(Home &spisokhome, int a);
    void edit(Home &spisokhome, int a);
    void add(Home &spisokhome, int &a);
    void sort();
    void ListSize(int &count);
    void file(Home spisokhome);
   void Divide(list &spisokhome , list &second, int kek);
    void Unite(list& spisokhome, list& secondspisokhome);
};
