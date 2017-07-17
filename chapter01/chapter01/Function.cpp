//
//  Function.cpp
//  chapter01
//
//  Created by 熊田聖也 on 2017/07/17.
//  Copyright © 2017年 熊田聖也. All rights reserved.
//

#include "Function.hpp"
#include "Variable.hpp"

PValiable Function::forward(const PValiable& v1, const PValiable& v2)
{
    variables_.emplace_back(v1);
    variables_.emplace_back(v2);
    auto variable = std::make_shared<Variable>(0.0f);
    variable->set_creator(this);
    variable->add_value(v1->get_value());
    variable->add_value(v2->get_value());
    return variable;
}

PValiable Function::forward(const PValiable& v1)
{
    variables_.emplace_back(v1);
    auto variable = std::make_shared<Variable>(0.0f);
    variable->set_creator(this);
    variable->add_value(v1->get_value());
    return variable;
}
