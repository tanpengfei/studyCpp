//
//  FileManger.cpp
//  cppStudyPro
//
//  Created by 谭鹏飞 on 2020/10/12.
//  Copyright © 2020 谭鹏飞. All rights reserved.
//

#include "FileManger.hpp"
void readFile(){
    char data[100];
    ofstream ofFile;
    ofFile.open("afile.dat",ios::app|ios::out);
    if(ofFile.is_open()){
        cout << "文件打开" << endl;
    }

    cout << "请输入小于100字符内容:" << endl;
    cin.getline(data, 100);
    ofFile << data << endl;
    ofFile.close();
    
    char data1[100];
    char data2[100];

    ifstream iFile;
    iFile.open("afile.dat",ios::in|ios::binary);
    cout << "q读取到写入数据：" << endl;
    while (iFile >> data1) {
      cout << data1 << endl;
    }

    iFile.close();
    
}
