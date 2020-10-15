//
//  Dog.cpp
//  cppStudyPro
//
//  Created by 谭鹏飞 on 2020/10/10.
//  Copyright © 2020 谭鹏飞. All rights reserved.
//

#include "Dog.hpp"

Dog::Dog(string name){
    _name = name;
}

Dog::~Dog(){
    
}

void Dog::eat(){
    cout << _name <<"狗吃屎" << endl;
}
