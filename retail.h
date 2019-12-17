//
//  retail.h
//  BIG_Prog4_alotfile
//
//  Created by sasha on 26/11/2019.
//  Copyright © 2019 sasha. All rights reserved.
//

#ifndef retail_h
#define retail_h
#include "good.h"
//#indlude "Opt.cpp"
namespace prog4
{
class retail : public good
{
//protected:
//virtual std::ostream & show (std::ostream &) const ;
    private :
    double percent;
    public :
    double get_percent (){return percent;}
    void set_percent (int percen){percent = percen;}
    virtual double Sell(int kolret);
    retail (){type = 2;}
    retail (std::string nam, std::string cnt, std::string frm,int k,double cos,double perc);
    virtual double sum ();
    virtual  good * ChangeType(double size_o);
    //~retail ();
    retail & Add (int l);
    virtual double Change_cost(double cos);
    retail & Change_percent (int new_per);
    virtual std::ostream & print (std::ostream&)const;
  //  friend std::ostream & operator << (std::ostream&,const retail &);  
};
}

#endif /* retail_h */
