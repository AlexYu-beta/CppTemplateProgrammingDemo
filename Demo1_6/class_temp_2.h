//
// Created by alex on 16-11-9.
//

#ifndef TEMPLATEPROGRAMMINGDEMOS_CLASS_TEMP_2_H
#define TEMPLATEPROGRAMMINGDEMOS_CLASS_TEMP_2_H
template <typename T>
class class_temp_2{
public:
    static int id;
    class_temp_2(){++id;}
};

template <typename T>
int class_temp_2<T>::id=1;
#endif //TEMPLATEPROGRAMMINGDEMOS_CLASS_TEMP_2_H
