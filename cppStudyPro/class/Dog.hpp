//
//  Dog.hpp
//  cppStudyPro
//
//  Created by 谭鹏飞 on 2020/10/10.
//  Copyright © 2020 谭鹏飞. All rights reserved.
//

#ifndef Dog_hpp
#define Dog_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
class Dog{
    private:
    string _name;
        
    public:
    Dog(string name);
    ~Dog();
    void eat();
    
};
#endif /* Dog_hpp */
