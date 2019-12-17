//
//  good.cpp
//  BIG_Prog4_alotfile
//
//  Created by sasha on 26/11/2019.
//  Copyright © 2019 sasha. All rights reserved.
//

#include "good.hpp"
#include "good.h"

using namespace prog4;



std::ostream & operator << (std::ostream& s,const good & p)
{
    return p.print(s);
}
