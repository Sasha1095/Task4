//
//  main.cpp
//  BIG_Prog4_alotfile
//
//  Created by sasha on 26/11/2019.
//  Copyright © 2019 sasha. All rights reserved.
//


#include <iostream>
#include "retail.h"
#include "Shop.h"
#include "good.h"
#include "Opt.h"
#include <string.h>
#include <map>
#include <ctime>
#define NMsgs 13

using namespace prog4;

// Add_Opt,Add_retail, getGood, total_opt_and_retail,Sell, change_cost, change_retail_percent, change_opt_size,change,get_type
const char *msgs[] = {"0. Quit", "1. Add_Opt", "2. Add_retail", "3. Take_info", "4. Total","5. Sell","6. Change_cost","7. Change_ret_%","8. Change_opt_sz","9. Change_type","10. Get_type","11.Get_all_inf", "12.Add_random"} ;

const char *errmsgs[] = {"OK", "Not found"};
int Add_Opt (shop &); //
int Add_retail (shop &);
int getGood (shop &); //
int total_opt_and_retail (shop &); //
int Sell (shop &); //
int change_cost (shop &); //
int change_retail_precent (shop &); //
int change_opt_siz (shop &); //
int change_type(shop &); //
int get_type (shop &); //
//int get_all_inf(shop &);



int getint(int *a){
    int n;
    do {
        *a = 0;
        n = scanf("%d", a, sizeof(int));
        if (n < 0)
            return -1;
        if (n == 0) {
            char c;
            while((c = getchar()) != '\n' && c != EOF);
            printf("Not a number! Enter number\n");
        }
    } while (n == 0);
    
    return 0;
    
}


int get_all_inf (shop & obj)
{
    obj.printl(std::cout);
    return 0;
}



std::string RandChar(int Lenght)
{
    char pool[] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
    int SZ = sizeof(pool)-1;
    srand(time(NULL));
    char r;
    std::string srt  ;
    for(int i = 0; i < Lenght; i++)
    {
        r = pool[rand()%SZ];
        srt +=r;
    }
   // strcat(srt,  "/0");
    return srt;
    
}
int Add_random (shop &obj)
{
    int ttype = rand()%2 + 1;
    int ID = rand()%1000 +1;
    
    int Length = rand()%12 + 2;
    std::string name = RandChar(Length);
    Length = rand()%12 + 2;
    std::string country = RandChar(Length);
    
    Length = rand()%15 + 2;
    std::string firm = RandChar(Length);
    
    int cost = rand()%100 + 20;
    
    if (ttype ==1)
    {
           int kol = rand()%10 + 2;
        int size_op = rand()%15 + 1;
        obj.Add_opt(name, country, firm, cost, kol, ID, size_op);
        
    }
    else
    {
       int kol = rand()%10 + 2  ;
        int percent = rand ()%50 + 10 ;
         obj.Add_retail(name, country, firm, cost, kol, ID, percent);
    }
    
    return 0 ;
}




int Add_Opt (shop & obj)
{
    std::string country;
    std::string firm;
    std::string name;
    double cost;
    int kol;
    int size_op;
    int ID;
    std::cout<<"Введите ID"<< std::endl;
    std::cin >> ID;
    
    std::cout<<"Введите Название"<< std::endl;
    std::cin >> name;
    
    std::cout<<"Введите Фирму"<< std::endl;
    std::cin >> firm;
    
    std::cout<<"Введите Страну"<< std::endl;
    std::cin >> country;
    
    std::cout<<"Введите цену за товар"<< std::endl;
    std::cin >> cost;
    
    std::cout<<"Введите количество товара в пачке"<< std::endl;
    std::cin >> size_op;
    
    std::cout<<"Введите количество пачек"<< std::endl;
    std::cin >> kol;
    
    obj.Add_opt(name, country, firm, cost, kol, ID, size_op);
    return 0;
}



int Add_retail (shop &obj)
{
    std::string country;
    std::string firm;
    std::string name;
    double cost;
    int kol;
    int percent;
    int ID;
    std::cout<<"Введите ID"<< std::endl;
    std::cin >> ID;
    
    std::cout<<"Введите Название"<< std::endl;
    std::cin >> name;
    
    std::cout<<"Введите Фирму"<< std::endl;
    std::cin >> firm;
    
    std::cout<<"Введите Страну"<< std::endl;
    std::cin >> country;
    
    std::cout<<"Введите цену за единицу товара"<< std::endl;
    std::cin >> cost;
    
    std::cout<<"Введите процентную надбавку"<< std::endl;
    std::cin >> percent;
    
    std::cout<<"Введите количество товара"<< std::endl;
    std::cin >> kol;
    obj.Add_retail(name, country, firm, cost, kol, ID, percent);
    return 0;
}


int getGood (shop & obj)
{
    std::string newinf;
    good *ptr;
    int ID;
    std::cout<<"Введите ID"<< std::endl;
    std::cin >> ID;
    ptr =  obj.getGood(ID);
    if (ptr!= nullptr)
    {
       // good & p = *ptr;
       // ptr->print(std::cout);
        std::cout<< *ptr <<std::endl;
        
    }
    
        
       // std::cout<<ptr<<std::endl;
   /* {
        newinf = ptr->get_firm();
        std::cout << "Фирма " <<ptr->get_firm()<<" Страна "<<ptr->get_cntr()<<" Товар "<<ptr->get_name();
        
    }*/
    else
        std::cout << "ID не найден"<<std::endl;
    return 0;
}


int total_opt_and_retail (shop & obj)
{
    int cost = obj.total_opt_and_retail();
    std::cout<< "Общая цена "<< cost << std::endl;
    return 0;
}


int Sell (shop & obj)
{
    int kol;
    int ID;
    std::cout<<"Введите ID"<< std::endl;
    std::cin >> ID;
    std::cout<<"Введите Количество"<< std::endl;
    std::cin >> kol;
    obj.Sell(ID, kol);
    return 0;
}


int change_cost (shop & obj)
{
    int new_cos;
    int ID;
    std::cout<<"Введите ID"<< std::endl;
    std::cin >> ID;
    std::cout<<"Введите новую стоимость"<< std::endl;
    std::cin >> new_cos;
    obj.change_cost(ID, new_cos);
    return 0;
    
}


int change_retail_precent (shop & obj)
{
    int new_per;
    int ID;
    std::cout<<"Введите ID"<< std::endl;
    std::cin >> ID;
    std::cout<<"Введите новую стоимость"<< std::endl;
    std::cin >> new_per;
    auto it = dynamic_cast<retail*>(obj.getGood(ID));
    if (it !=nullptr)
    obj.change_retail_percent(ID, new_per);
    else
        std::cout << "ID введено неправильно"<<std::endl;
    return 0; 
}



int change_opt_siz (shop & obj)
{
    int new_sz;
    int ID;
    std::cout<<"Введите ID"<< std::endl;
    std::cin >> ID;
    std::cout<<"Введите новую стоимость"<< std::endl;
    std::cin >> new_sz;
    auto it = dynamic_cast<Opt*>(obj.getGood(ID));
    if (it!=nullptr)
    obj.change_opt_size(ID, new_sz);
    else
        std::cout << "ID введено неправильно"<< std::endl;
    return 0;
}

int change_type(shop &obj)
{
    int new_sz;
    int ID;
    int new_ID;
    std::cout<<"Введите ID"<< std::endl;
    std::cin >> ID;
    std::cout<<"Введите процентную надбавку или количество товара в коробке"<< std::endl;
    std::cin >> new_sz;
    std::cout<<"Введите новый ID"<< std::endl;
    std::cin >> new_ID;
    obj.change(ID, new_ID, new_sz);
    return 0;
}



int get_type (shop & obj)
{
    int type;
    int ID;
    std::cout<<"Введите ID"<< std::endl;
    std::cin >> ID;
    type = obj.get_type(ID);
    if (type ==1)
        std::cout<< "Товар оптовый "<<std::endl;
    else
        std::cout<< "Товар розничный"<<std::endl;
    return 0;
}

int (*fptr[])(shop &) = {NULL,Add_Opt, Add_retail, getGood, total_opt_and_retail,Sell,change_cost,change_retail_precent,change_opt_siz,change_type,get_type,get_all_inf,Add_random};

int dialog  (const char *msgs[] , int N )
{
    char *errmsg = "";
    int rc, i, n;
    do{
        puts(errmsg);
        errmsg = "You are wrong! Repeate, please!";
        for (i = 0; i < N; ++i)
            puts(msgs[i]);
        puts("Make your choice: -->");
        n = getint(&rc);
        if (n == -1)
            rc = 0;
    } while (rc < 0 || rc >= N);
    return rc;
}


int main ()
{
    shop Nshop;
    int rc;
    while ((rc = dialog(msgs, NMsgs)))
        if (fptr[rc](Nshop))
            break;
    
    printf("Exit");
    return 0;
    
    return 0 ;
}
