//
// Created by alex on 16-11-9.
//

#ifndef TEMPLATEPROGRAMMINGDEMOS_CLASS_TEMP_H
#define TEMPLATEPROGRAMMINGDEMOS_CLASS_TEMP_H
template <typename T>
class class_temp{
public:
    static int id;
    class_temp(){++id;}
};

template <typename T>
int class_temp<T>::id=0;
#endif //TEMPLATEPROGRAMMINGDEMOS_CLASS_TEMP_H