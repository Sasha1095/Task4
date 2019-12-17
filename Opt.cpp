//
//  Opt.cpp
//  BIG_Prog4_alotfile
//
//  Created by sasha on 26/11/2019.
//  Copyright © 2019 sasha. All rights reserved.
//

#include "Opt.hpp"
#include "Opt.h"
#include "retail.h"

using namespace prog4;


// конструктор для опта

Opt::Opt(std::string nam, std::string cnt, std::string frm,int k,double cos,int size_o)
{
    name = nam;
    cntr = cnt;
    firm = frm;
    kol = k;
    cost = cos;
    size_opt = size_o;
    type = 1;
    
}

// методы для опта

Opt & Opt::Add(int l)
{
    //   kol = "wd";
    kol +=l;
    return *this;
}


double Opt::sum()
{
    double money = kol*size_opt*cost;
    return money;
}


void Opt::set_sizeopt(int size_o)
{
    size_opt = size_o;
}



double Opt::Change_cost(double new_cost)
{
    
    cost = new_cost;
    return cost;
}



double Opt::Sell(int kolopt)
{
    if (kolopt > kol)
    {
        std::cout << "Ошибка количество покупаемого товара больше чем товара на складе"<<std::endl;
        return 0;
    }
    if (kolopt < 0)
    {
        std::cout << "Ошибка количество покупаемого товара не может быть отрицательным"<<std::endl;
        return 0;
    }
    double money = kolopt*size_opt*cost;
    kol = kol-kolopt;
    return money;
}




Opt & Opt::Change_size(int new_size_opt) // Доделать функцию
{
    size_opt = new_size_opt;
    return *this;
}

std::ostream & Opt::print(std::ostream & s) const
{
    s<< " name : " << name <<std::endl;
    s<< " country : " << cntr << std::endl;
    s<< " firm : "    << firm << std::endl;
    s<< " cost : " <<cost << std::endl;
    s<<" Opt" <<std::endl;
    s<<" kol boxes : " << kol << std::endl;
    s<< " kol in a box "<< size_opt << std::endl;
    return s;
}


/*std::ostream & Opt::operator << (std::ostream& s,const good &p)
{
    s<< " name : " << name <<std::endl;
    s<< " country : " << cntr << std::endl;
    s<< " firm : "    << firm << std::endl;
    s<< " cost : " <<cost << std::endl;
    s<<" Opt" <<std::endl;
    s<<" kol boxes : " << kol << std::endl;
    s<< " kol in a box "<< size_opt << std::endl;
    return s;
} */

good * Opt::ChangeType(double per)  {
    int k = kol * size_opt;
    retail *newl;
    newl = new retail; 
    newl->set_n(name, cntr, firm);
    newl->set_k(cost, k, 2);
    newl->set_percent(per);
    return newl;
    
}
