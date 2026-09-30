#include <iostream>


//структура stack !!!описывает!!! сам стек. Т.е. структура stack != самому стэку. Это лишь набор его характеристик.
struct stack{
    size_t size_of_el;  //зависит от типа переменных которые кладём в стек
    size_t amount_of_el; // отсчёт что filled, amount_of_el ведётся с 1, что, в общем-то, логично (другого варианта я не придумал)
    size_t filled;
    size_t* start;
};


size_t* stk_init(stack stk1){       // инициализация стека, функция возвращает указатель на начало стека, start, задаёт параметр filled = 0.
    stk1.size_of_el = sizeof(int);       // прямое указание типа данных элементов стека
    stk1.amount_of_el = 1;
    stk1.start = (size_t*)calloc(stk1.amount_of_el, stk1.size_of_el);
    stk1.filled = 0;
    return stk1.start;
};


void stk_add(stack stk1, int a){            // прямое указание типа данных элементов стека
    if (stk1.filled == stk1.amount_of_el)     // проверка на наличие места в стеке
        { *(stk1.start + stk1.filled*stk1.size_of_el) = a;
          stk1.filled++; } 
    else
        { stk1.start = (size_t*)realloc(stk1.start, (stk1.amount_of_el + 1)*stk1.size_of_el); // добавление места под ещё один элемент
          stk1.amount_of_el++;
          *(stk1.start + stk1.filled*stk1.size_of_el) = a;     // добавление э-та
          stk1.filled++; }
};


void stk_del(stack stk1){
    if (stk1.filled != 0)
        { stk1.start = (size_t*)realloc(stk1.start, (stk1.amount_of_el + 1)*stk1.size_of_el); 
          if(stk1.amount_of_el != 1) // уменьшаем размер стека если размер стека не == 1, т. е. не является минимальным.
            { stk1.amount_of_el--; }
          stk1.filled--;}
}; 
//  можем не "затирать" нулями последнее значение, а уменьшить стек при помощи realloc.
//   всё равно если после стек будет увеличен до прежних размеров, realloc всё затрёт нулями.


int main() {
    return 0;
}