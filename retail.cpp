//
//  retail.cpp
//  BIG_Prog4_alotfile
//
//  Created by sasha on 26/11/2019.
//  Copyright © 2019 sasha. All rights reserved.
//

#include "retail.hpp"
#include "retail.h"
#include "Opt.h"

using namespace prog4;

// конструктор для розницы
retail:: retail (std::string nam, std::string cnt, std::string frm,int k,double cos,double perc)
{
    name = nam;
    cntr = cnt;
    firm = frm;
    kol = k;
    cost = cos;
    percent = perc ;
    type = 2;
}
// методы для розницы

retail & retail::Add(int l)
{
    kol +=l;
    return *this;
}

double retail::Change_cost(double cos)
{
    cost = cos;
    return cost;
}



retail &retail::Change_percent(int new_per)
{
    percent = new_per;
    return *this;
}





double retail::Sell(int kolret)
{
    
    if (kolret > kol)
    {
        std::cout << "Ошибка количество покупаемого товара больше чем товара на складе"<<std::endl;
        return 0;
    }
    if (kolret < 0)
    {
        std::cout << "Ошибка количество покупаемого товара не может быть отрицательным"<<std::endl;
        return 0;
    }
    double money = kolret*cost*(1+percent/100) ;
    kol -=kolret;
    return money;
}


double retail::sum()
{
    double money;
    money = kol*cost*(1+percent/100);
    return money;
}


good * retail::ChangeType(double size_o)
{
    int k = kol/size_o;
    Opt * newop;
    newop = new Opt;     
    newop->set_sizeopt(size_o);
    newop->set_n(name, cntr, firm);
    newop->set_k(cost - cost*percent/100, k, 1);
    return newop;
}

std::ostream & retail::print(std::ostream & s) const
{
    s<< " name : " << name <<std::endl;
    s<< " country : " << cntr << std::endl;
    s<< " firm : "    << firm << std::endl;
    s<< " cost : " <<cost << std::endl;
    s<<" retail " <<std::endl;
    s<<" kol : " << kol << std::endl;
    s<< " percent : "<< percent << std::endl;
    return s;
}

/*std::ostream & retail::operator << (std::ostream& s,const good &p)   
{
    s<< " name : " << name <<std::endl;
    s<< " country : " << cntr << std::endl;
    s<< " firm : "    << firm << std::endl;
    s<< " cost : " <<cost << std::endl;
    s<<" retail " <<std::endl;
    s<<" kol : " << kol << std::endl;
    s<< " percent : "<< percent << std::endl;
    return s;
} */
