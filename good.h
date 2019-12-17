//
//  good.h
//  BIG_Prog4_alotfile
//
//  Created by sasha on 26/11/2019.
//  Copyright © 2019 sasha. All rights reserved.
//

#ifndef good_h
#define good_h
#include <string.h>
//#include <map>
#include <iostream>
#include <exception>
#include "mapa.h"

 namespace prog4
{
class good
{
protected:
    std::string name;
    std::string cntr;
    std::string firm;
    double cost;
    int kol;
    int type;
   // virtual std::ostream & show (std::ostream &) const = 0;
    public :
    virtual std::ostream & print (std::ostream&) const = 0;
    int change_kol (int ko){kol +=ko;return kol;}
    virtual double sum (){return 0;}
    std::string get_name (){return name;}
    std::string get_cntr (){return cntr;}
    std::string get_firm (){return firm;}
    double get_cost (){return cost;}
    int get_type (){return type;}
    int get_kol (){return kol;}
    virtual double Sell(int kolopt){return 0;};
    virtual double Change_cost(double cos){cost = cos;return 0;};
    virtual  good * ChangeType(double inf) {return this;}
    void set_n (std::string nam, std::string cnt, std::string frm){name = nam; cnt = cntr; firm =frm;}
    void set_k (double cos, int ko,int t){type = t; kol =ko ; cost = cos;};
};
}

std::ostream & operator << (std::ostream&,const prog4::good &);

#endif /* good_h */
