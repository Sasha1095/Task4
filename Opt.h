//
//  Opt.h
//  BIG_Prog4_alotfile
//
//  Created by sasha on 26/11/2019.
//  Copyright © 2019 sasha. All rights reserved.
//

#ifndef Opt_h
#define Opt_h
#include "good.h"
namespace prog4
{

class Opt : public good{
   // protected:
   //  virtual std::ostream & show (std::ostream &) const ;
    private :
    int size_opt;
    public :
    Opt (){type = 1;}
    virtual double sum();
    int get_size_opt(){return size_opt;}
    Opt(std::string nam, std::string cnt, std::string frm,int k,double cos,int size_o);
    void set_sizeopt(int size_o);
    virtual double Sell(int kolopt);
    Opt & Add (int l);
    virtual  double Change_cost(double new_cost);
    Opt & Change_size (int new_size_opt);
    virtual good * ChangeType(double th);
    virtual std::ostream & print (std::ostream&) const;
  //  friend std::ostream & operator << (std::ostream&,const Opt &);
};
}
#endif /* Opt_h */
