#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "home.h"

void list::ListSize(int &count)
{
    Home *tmp=Head;
    count=0;
    while(tmp!=NULL)
        {
        count++;
        tmp=tmp->Next;
        }
}
//Чтение из файла
void list::Fileread(Home &array)
{
    FILE *input = fopen("Home.csv", "r");
	if (!input) return;
    char line[100] = {};
    while (fgets(line, 100, input))
    {
        const char *delim = ";\"\n";
        char *token = strtok(line, delim);
        Home *tmp = new Home;
        tmp->Next=Head;
        while (token != NULL)
        {
            tmp->id = token;
            token = strtok(NULL, delim);
            tmp->adress = token;
            token = strtok(NULL, delim);
            tmp->telephone = token;
            token = strtok(NULL, delim);
            tmp->area = token;
            token = strtok(NULL, delim);
            tmp->rooms = token;
            token = strtok(NULL, delim);
            tmp->cost = token;
            token = strtok(NULL, delim);
        }
        Head = tmp;
    }
};
//Деструктор
list::~list()
{
    while(Head!=NULL)
    {
        Home *tmp=Head->Next;
        delete Head;
        Head=tmp;
    }
}
//Вывод Списка
void list::printList()
{
    Home *tmp=Head;
    while(tmp!=NULL)
    {
        std::cout<<tmp->id<<",";
        std::cout<<tmp->adress<<",";
        std::cout<<tmp->telephone<<",";
        std::cout<<tmp->area<<",";
        std::cout<<tmp->rooms<<",";
        std::cout<<tmp->cost;
        tmp=tmp->Next;
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
//Вывод строчки списка
void list::print(Home *tmp)
{
        std::cout<<tmp->id<<",";
        std::cout<<tmp->adress<<",";
        std::cout<<tmp->telephone<<",";
        std::cout<<tmp->area<<",";
        std::cout<<tmp->rooms<<",";
        std::cout<<tmp->cost;
        std::cout<<std::endl;
        std::cout<<std::endl;
}
// Функция поиска строчки в структуре 
void list::Search() 
{
    int choice=0;
    std::string n;
    int flag=0;
    while(1)
        {
        choice=0;
        std::cout<<"Vvedite chto jelaete naiti"<< std::endl;
        std::cout<<"1. id"<< std::endl;
        std::cout<<"2. Adress"<< std::endl;
        std::cout<<"3. Telephone"<< std::endl;
        std::cout<<"4. Aria"<< std::endl;
        std::cout<<"5. Rooms"<< std::endl;
        std::cout<<"6. Cost"<< std::endl;
        std::cin>> choice;
        if((choice<1)||(choice>6)) std::cout<<"vvedite nomer iz reada"<<std::endl;
        else break;
        }
    if(choice==1)
        {
            while(flag!=1)
            {
                Home *tmp=Head;
                std::cout<<"Vvedite id"<< std::endl;
                std::cin>>n;
                while(tmp!=NULL)
                {
                    if(tmp->id==n) 
                    {
                        flag++;
                        print(tmp);
                        break;
                    }
                tmp=tmp->Next;
                }
                if (flag!=1) std::cout<<"Net takogo id! Vvedite eshe raz"<< std::endl;

            }
        }
    if(choice==2)
        {
            while(flag!=1)
            {
                Home *tmp=Head;
                std::cout<<"Vvedite adress"<< std::endl;
                std::cin>>n;
                while(tmp!=NULL)
                {
                    if(tmp->adress==n) 
                    {
                        flag++;
                        print(tmp);
                        break;
                    }
                tmp=tmp->Next;
                }
                if (flag!=1) std::cout<<"Net takogo adress! Vvedite eshe raz"<< std::endl;
            }
        }
    if(choice==3)
        {
            while(flag!=1)
            {
                Home *tmp=Head;
                std::cout<<"Vvedite telephone"<< std::endl;
                std::cin>>n;
                while(tmp!=NULL)
                {
                    if(tmp->telephone==n) 
                    {
                        flag++;
                        print(tmp);
                        break;
                    }
                tmp=tmp->Next;
                }
                if (flag!=1) std::cout<<"Net takogo telephone! Vvedite eshe raz"<< std::endl;
            }
        }
    if(choice==4)
        {
            while(flag!=1)
            {
                Home *tmp=Head;
                std::cout<<"Vvedite area"<< std::endl;
                std::cin>>n;
                while(tmp!=NULL)
                {
                    if(tmp->area==n) 
                    {
                        flag++;
                        print(tmp);
                        break;
                    }
                tmp=tmp->Next;
                }
                if (flag!=1) std::cout<<"Net takoi area! Vvedite eshe raz"<< std::endl;
            }
        }
     if(choice==5)
        {
            while(flag!=1)
            {
                Home *tmp=Head;
                std::cout<<"Vvedite rooms"<< std::endl;
                std::cin>>n;
                while(tmp!=NULL)
                {
                    if(tmp->cost==n) 
                    {
                        flag++;
                        print(tmp);
                        break;
                    }
                tmp=tmp->Next;
                }
                if (flag!=1) std::cout<<"Net takih rooms! Vvedite eshe raz"<< std::endl;
            }
        }
    if(choice==6)
        {
            while(flag!=1)
            {
                Home *tmp=Head;
                std::cout<<"Vvedite cost"<< std::endl;
                std::cin>>n;
                while(tmp!=NULL)
                {
                    if(tmp->cost==n) 
                    {
                        flag++;
                        print(tmp);
                        break;
                    }
                tmp=tmp->Next;
                }
                if (flag!=1) std::cout<<"Net takoi cost! Vvedite eshe raz"<< std::endl;
            }
        }
}
//Смена элементов
void list::swap(Home &myschedule, int a)
{
    Home *tmp1 = Head;
    Home *tmp2 = Head;
    int is=-1;
    int ie=-1;
    while(is<0 || is>a || ie<0 || ie>a)
    {
        std::cout<<"Kakoi element hotite zameniti?"<< std::endl;
        std::cin>>is;
        std::cout<<"S kakim?"<< std::endl;
        std::cin>>ie;
        if(is<0 || is>a || ie<0 || ie>a) std::cout<< "Vi vveli nevernoe znachenie"<<std::endl;
    }
    for(int i=0; i<is; i++)
    {
        tmp1=tmp1->Next;
    }
    for(int i=0; i<ie; i++)
    {
        tmp2=tmp2->Next;
    }
    std::string n;
    n=tmp1->id;
    tmp1->id = tmp2->id;
    tmp2->id = n;
    n=tmp1->adress;
    tmp1->adress = tmp2->adress;
    tmp2->adress = n;
    n=tmp1->telephone;
    tmp1->telephone = tmp2->telephone;
    tmp2->telephone = n;
    n=tmp1->area;
    tmp1->area = tmp2->area;
    tmp2->area = n;
    n=tmp1->area;
    tmp1->rooms = tmp2->rooms;
    tmp2->rooms = n;
    n=tmp1->cost;
    tmp1->cost = tmp2->cost;
    tmp2->cost = n;
}
//Изменение элемента списка
void list::edit(Home &spisokhome, int a)
{
    Home *tmp = Head;
    int index=-1;
    while(index<0 || index>a)
    {
        std::cout<<"Kakoi element hotite izmeniti?"<< std::endl;
        std::cin>>index;
        if(index<0 || index>a) std::cout<< "Vi vveli nevernoe znachenie"<<std::endl;
    }
    for(int i=0; i<index; i++)
    {
        tmp=tmp->Next;
    }
    std::string n;
    std::cout<<"Vvedite id"<< std::endl;
    std::cin>>n;
    tmp->id = n;
    std::cout<<"Vvedite adress"<< std::endl;
    std::cin>>n;
    tmp->adress = n;
    std::cout<<"Vvedite telephone"<< std::endl;
    std::cin>>n;
    tmp->telephone = n;
    std::cout<<"Vvedite area"<< std::endl;
    std::cin>>n;
    tmp->area = n;
    std::cout<<"Vvedite rooms"<< std::endl;
    std::cin>>n;
    tmp->rooms = n;
    std::cout<<"Vvedite cost"<< std::endl;
    std::cin>>n;
    tmp->cost = n;
}
//Добавить новый элемент списка 
void list::add(Home &spisokhome, int &a)
{
    std::cout<<"Dobavlenie novogo elementa"<< std::endl;
    Home *tmp= new Home;
    tmp->Next=Head;
    std::string n;
    std::cout<<"Vvedite id"<< std::endl;
    std::cin>>n;
    tmp->id = n;
    std::cout<<"Vvedite adress"<< std::endl;
    std::cin>>n;
    tmp->adress = n;
    std::cout<<"Vvedite telephone"<< std::endl;
    std::cin>>n;
    tmp->telephone = n;
    std::cout<<"Vvedite area"<< std::endl;
    std::cin>>n;
    tmp->area = n;
    std::cout<<"Vvedite rooms"<< std::endl;
    std::cin>>n;
    tmp->rooms = n;
    std::cout<<"Vvedite cost"<< std::endl;
    std::cin>>n;
    tmp->cost = n;
    Head=tmp;
    a++;
}
//сортировка списка методом 
void list::sort()
{
    std::cout<<"Spisok"<< std::endl;
    Home *a, *b, *p, *h=NULL;
    for(Home* i = Head; i != NULL; ) 
    {
        a = i;
        i = i->Next;
        b = h;
        for(p = NULL; (b != NULL) && (a->id > b->id); ) 
        {
            p = b;
            b = b->Next;
        }
 
        if(p == NULL)
        {
            a->Next = h;
            h = a;
        } else {
            a->Next = b;
            p->Next = a;
        }
    }
    if(h != NULL) 
        Head = h;
}
//Разделение Списка
void list::Divide(list &spisokhome, list &secondspisokhome, int index)
{
    Home * tmp= spisokhome.Head;
    for(int i=1; i<index; i++)
    { 
        if(i==index/2)
        {
            secondspisokhome.Head = tmp->Next;
            tmp->Next=nullptr;
            break;
        }
        tmp = tmp->Next; 
    }
}
//Соединение списка
void list::Unite( list &spisokhome, list &secondspisokhome)
{
Home * tmp= spisokhome.Head;
    while(1)
    { 
        if(tmp->Next==nullptr)
        {
            tmp->Next=secondspisokhome.Head;
            break;
        }
        tmp = tmp->Next; 
    }
    secondspisokhome.Head=nullptr;
}
//Запись в файл
void list::file(Home spisokhome)
{
    std::ofstream filew;
    filew.open("Home_2.csv");
    Home *tmp=Head;
    while(tmp!=NULL) 
    {
        std::string n;
        n=tmp->id+","+tmp->adress+","+tmp->telephone+","+tmp->area+","+tmp->rooms+","+tmp->cost;
        std::cout<<std::endl;
        filew << n << std::endl;
        tmp=tmp->Next;
    }
}
