//
//  shop.cpp
//  BIG_Prog4_alotfile
//
//  Created by sasha on 26/11/2019.
//  Copyright © 2019 sasha. All rights reserved.
//

#include "shop.hpp"
#include "Shop.h"
#include "retail.h"
#include "Opt.h"

using namespace prog4;
// контейнерный класс shop


good * shop::getGood(int i)
{
    auto it = goods.find(i);
    if (it!=goods.end())
        return goods.at(i);   
    else
        return nullptr;
}

/*good & shop::getGoodref(int i)
{
    exception_incorect e;
    auto it = goods.find(i);
    if (it!=goods.end())
        return *goods.at(i);
    else
        throw e;
} */

shop & shop::Add_opt(std::string nam, std::string cnt, std::string frm, double cos, int k, int index,int size_o)
{
    auto it = goods.find(index);
    if (it != goods.end())
    {
        Opt* newobj = new Opt(nam, cnt, frm,k,cos,size_o);
        delete it->second; 
        it->second = newobj;
        //goods.erase(index);
        // goods.emplace(index,&newobj);
        return *this;
    }
    Opt *newobj = new Opt(nam, cnt, frm,k,cos,size_o);
    goods.emplace(index,newobj);
    return * this;
}





shop & shop::Add_retail(std::string nam, std::string cnt, std::string frm, double cos, int k, int index, double percen)
{
    auto it = goods.find(index);
    if (it != goods.end())
    {
        //  std::cout<<"Товар с данным ID уже существует"<<std::endl;
        retail *newobj = new retail(nam , cnt, frm,k, cos,percen); 
        delete it->second;
        it->second = newobj;
        return *this;
    }
    retail *newobj =new retail (nam , cnt, frm,k, cos,percen);
    goods.emplace(index,newobj);
    return *this;
}




double shop::total_opt_and_retail()
{
    double money = 0;
    for (auto it = goods.begin(); it != goods.end(); ++it)
    {
        money +=  it->second->sum();
    }
    
    return money;
}
std::ostream & shop::printl (std::ostream&s)
{
    
    for (auto it = goods.begin(); it != goods.end(); ++it)
    {
        it->second->print(s);
        
        
    }
    return s;
}
shop & shop::Sell(int index, int kolich)
{
    double money;
    int i = 0;
    auto it = goods.find(index);
    if (it !=goods.end())
    {
        money = it->second->Sell(kolich);
        std::cout << "Была произведена покупка на сумму = "<< money<<" рублей"<<std::endl;
        i = it->second->get_kol();
    }
    else
    {
        std::cout << "ID не найдено"<<std::endl;
    }
    return *this;
}




shop & shop::change_retail_percent(int index, int chcost)
{
    retail * ret;
    auto it = goods.find(index);
    if (it == goods.end())
    {
        std::cout<< "ID не найдено"<< std::endl;
        return *this;
    }
    
    ret = dynamic_cast<retail*>(it->second);
    
    if (ret)
    {
        ret->Change_percent(chcost);
        std::cout << "цена изменена"<<std::endl;
    }
    else
        std::cout <<"ID указан не верно или такого товара нет на складе"<<std::endl;
    return *this;
}





shop & shop::change_cost(int index, int chcost)
{
    auto it = goods.find(index);
    if (it == goods.end())
    {
        std::cout <<"ID не существует"<< std::endl;
        return *this;
    }
    it->second->Change_cost(chcost);
    std::cout << "Цена была изменена"<<std::endl;
    return *this;
}





int shop::get_type(int index)
{
    auto it = goods.find(index);
    if(it==goods.end())
    {
        std::cout<<"ID не существует"<<std::endl;
        return 0;
    }
    return it->second->get_type();
}


void shop::change(int index, int new_index, double new_size)
{
    auto it = goods.find(index);
    if (it == goods.end())
    {
        std::cout << "ID не найден"<< std::endl;
        return;
    }
    good * ptr = it->second->ChangeType(new_size);
    goods.erase(index);
    goods.emplace(new_index, ptr);
    
}

shop & shop::change_opt_size(int index, int new_size)
{
    auto it = goods.find(index);
    if (it == goods.end())
    {
        std::cout << "ID не найден"<< std::endl;
        return *this;
    }
    Opt * new_op;
    new_op = dynamic_cast<Opt *>(it->second);
    if (new_op != nullptr)
    new_op->Change_size(new_size);
    else
        std::cout << " ID введён неверно "<<std::endl;
    return *this;
}

shop :: ~shop ()
{
    
    for (auto it = goods.begin(); it != goods.end(); ++it)
        delete  it->second ; 
    
}
