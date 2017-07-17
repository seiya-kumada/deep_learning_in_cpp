//
//  main.cpp
//  chapter01
//
//  Created by 熊田聖也 on 2017/07/17.
//  Copyright © 2017年 熊田聖也. All rights reserved.
//

#include <iostream>
#include "Variable.hpp"
#include "Function.hpp"
#include <cpplinq.hpp>

void traverse(const PValiable& variable)
{
    std::cout << variable->get_value() << std::endl;
    auto f = variable->get_creator();
    if (f == nullptr)
    {
        return;
    }
    
    cpplinq::from(f->get_variables()) >> cpplinq::for_each([](const auto& variable){ traverse(variable); });
}

int main(int argc, const char * argv[]) {
    auto v1 = std::make_shared<Variable>(1);
    auto v2 = std::make_shared<Variable>(1);
    
    auto f1 = std::make_unique<Function>();
    auto f2 = std::make_unique<Function>();
    auto f3 = std::make_unique<Function>();
    
    auto r1 = f1->forward(v1, v2);
    auto r2 = f2->forward(r1);
    auto r3 = f3->forward(r2);
    
    traverse(r3);
}
