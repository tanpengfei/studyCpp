//
//  TThread.cpp
//  cppStudyPro
//
//  Created by 谭鹏飞 on 2020/10/14.
//  Copyright © 2020 谭鹏飞. All rights reserved.
//

#include "TThread.hpp"
#define Thread_Num 5
struct thread_data{
    int thread_id;
    char * message;
};
void *PrintHello(void * threadData){
    struct thread_data * thread;
    thread = (struct thread_data*)threadData;
    timeTest();
    cout << "thread_id = "<<thread->thread_id << endl;
    cout << "thread_msg = " << thread->message << endl;
    pthread_exit(NULL);
}

void creatThread(){
    pthread_t threads[Thread_Num];
    struct thread_data td[Thread_Num];
    pthread_attr_t attr;
    void* status;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    
    int rc;
    int i;
    
    for (i = 0; i < Thread_Num; i++) {
        cout<< "main() creat thread" << i << endl;
        td[i].thread_id = i;
        td[i].message = (char *)"this is a message";
        rc = pthread_create(&threads[i], &attr, PrintHello, (void*)&td[i]);
        cout << "Main: program running.-0" << endl;
//        rc = pthread_join(threads[i], &status);
        cout << "Main: program running.-1" << endl;
        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    // 删除属性，并等待其他线程
      pthread_attr_destroy(&attr);
      for( i=0; i < Thread_Num; i++ ){
         rc = pthread_join(threads[i], &status);
         if (rc){
            cout << "Error:unable to join," << rc << endl;
            exit(-1);
         }
         cout << "Main: completed thread id :" << i ;
         cout << "  exiting with status :" << status << endl;
      }
    
      cout << "Main: program exiting." << endl;
//      pthread_exit(NULL);这里再调用就会卡死xcode

}
void timeTest(){
    cout << "测试时间" << endl;
    struct tm * tim;
    time_t t;
    t = time(NULL);
    tim = localtime(&t);
    cout << "time = " << tim->tm_hour <<":" << tim->tm_min << ":" << tim->tm_sec << endl;
    sleep(1);
    
    t = time(NULL);
    tim = localtime(&t);
    cout << "time = " << tim->tm_hour <<":" << tim->tm_min << ":" << tim->tm_sec << endl;
}
