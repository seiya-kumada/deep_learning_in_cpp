//
//  Function.hpp
//  chapter01
//
//  Created by 熊田聖也 on 2017/07/17.
//  Copyright © 2017年 熊田聖也. All rights reserved.
//

#ifndef Function_hpp
#define Function_hpp
#include <vector>
#include <memory>
#include "Variable.hpp"

using PValiable = std::shared_ptr<Variable>;

class Function
{
private:
    std::vector<PValiable> variables_;
    
public:
    PValiable forward(const PValiable& v1, const PValiable& v2);
    PValiable forward(const PValiable& v1);
    const std::vector<PValiable>& get_variables() const { return variables_; }
};

#endif /* Function_hpp */
