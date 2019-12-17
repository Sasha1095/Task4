//
//  Shop.h
//  BIG_Prog4_alotfile
//
//  Created by sasha on 26/11/2019.
//  Copyright © 2019 sasha. All rights reserved.
//

#ifndef Shop_h
#define Shop_h
#include "good.h"
//#include "mapa.cpp"


namespace prog4 {
    

class shop
{
    private :
    Map <int,good *> goods;
    public :
    ~shop ();
    shop & Add_opt (  std::string name,std::string cntr,std::string firm,double cost,int kol,int index,int size_o);
    shop & Add_retail (  std::string name,std::string cntr,std::string firm,double cost,int kol,int index,double percen);
    good * getGood(int i) ;
    // good & getGoodref(int i);
    double total_opt_and_retail ();
    int id_opt_and_retail (int index_op,int index_re);
    shop & Sell ( int index, int kolich);
    shop & change_cost (int index,int chcost);
    shop & change_retail_percent (int index,int chpers);
    shop & change_opt_size (int index, int new_size);
    void change (int index,int new_index,double  new_size);
    int get_type (int index);
    std::ostream & printl (std::ostream&);
    //  int get_kol ();
};
 /*   class exception_incorect : public std::exception {
        const char *  what() const noexcept override {
            return "11";
        }
    };*/
}
#endif /* Shop_h */
