//
//  Variable.hpp
//  chapter01
//
//  Created by 熊田聖也 on 2017/07/17.
//  Copyright © 2017年 熊田聖也. All rights reserved.
//

#ifndef Variable_hpp
#define Variable_hpp

class Function;

class Variable
{
private:
    float               value_      {0.0f};
    const Function*     creator_    {nullptr};
    
public:
    Variable(float value)
    : value_{value} {}
    
    float get_value() const { return value_; }
    void add_value(float value) { value_ += value; }
    const Function* get_creator() const { return creator_; }
    void set_creator(const Function* f) { creator_ = f; }
};

#endif /* Variable_hpp */
