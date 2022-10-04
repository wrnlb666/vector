//Copyright (c) 2022 wrnlb666
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.




#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef enum primitive_data_type
{
    CHAR    = 1 << 24,
    SHORT   = 1 << 25,
    INT     = 1 << 26,
    FLOAT   = 1 << 27,
    LONG    = 1 << 28,
    DOUBLE  = 1 << 29,
    VOID    = 1 << 30
}primitive_data_type;


#define VEC_CAP 8               //vector default capacity, applys to all types. 

typedef struct vector
{
    union
    {
        char*   char_vec;
        short*  short_vec;
        int*    int_vec;
        float*  float_vec;
        long*   long_vec;
        double* double_vec;
        void*   void_vec;
    };
    size_t  size;               //current size of the vector
    size_t  capacity;           //current capacity of the vecctor
    int     data_type;          //data type of the vector
    size_t  data_type_size;     //sizeof element in void_vec
}vector;


//functions

//init functions
vector* vector_new_char_vec( void );
vector* vector_new_short_vec( void );
vector* vector_new_int_vec( void );
vector* vector_new_float_vec( void );
vector* vector_new_long_vec( void );
vector* vector_new_double_vec( void );
vector* vector_new_void_vec( size_t data_type_size );

//call vector_new_vector( int data_type ). E.g. int_vec: vector* [name] = vector_new_vector( INT );
//For void_vec, call vector_new_vector( VOID | int data_type_size ). Maximum data_type_size being 8388608 bytes. 
vector* vector_new_vector( int data_type );                                         //vector_new_vector( int data_type )



//get value function
char    vector_char_vec_get( vector* vec, size_t index, char* buff );
short   vector_short_vec_get( vector* vec, size_t index, short* buff );
int     vector_int_vec_get( vector* vec, size_t index, int* buff );
float   vector_float_vec_get( vector* vec, size_t index, float* buff );
long    vector_long_vec_get( vector* vec, size_t index, long* buff );
double  vector_double_vec_get( vector* vec, size_t index, double* buff );
void*   vector_void_vec_get( vector* vec, size_t index, void* buff );

//call vector_get( vector* vec, size_t index, <T*> buff ). E.g. get 2nd int (index 1) value from vector* vec: int* [name] = vector_get( vec, 1, [name] );
#define vector_get( vector, index, buff )                                           \
    _Generic ( (buff),                                                              \
            char*:      vector_char_vec_get,                                        \
            short*:     vector_short_vec_get,                                       \
            int*:       vector_int_vec_get,                                         \
            float*:     vector_float_vec_get,                                       \
            long*:      vector_long_vec_get,                                        \
            double:     vector_double_vec_get,                                      \
            void*:      vector_void_vec_get                                         \
    )( vector, index, buff )                                                        //vector_get( vector* vec, size_t index, <T*> buff )




//assign: assign a existing array to the vector
void vector_char_vec_assign( vector* vec, char* src, size_t size );
void vector_short_vec_assign( vector* vec, short* src, size_t size );
void vector_int_vec_assign( vector* vec, int* src, size_t size );
void vector_float_vec_assign( vector* vec, float* src, size_t size );
void vector_long_vec_assign( vector* vec, long* src, size_t size );
void vector_double_vec_assign( vector* vec, double* src, size_t size );
void vector_void_vec_assign( vector* vec, void* src, size_t size );
void vector_assign_error( void );

//call vector_assign( vector* vec, <T*> target, size_t size). Size is the number of elements needs to be assigned not the actual bytes account.
//ATTENTION: size_t size is the number of elements!!! This Apply To All size_t size In This Library!!!
#define vector_assign( vector, src, size )                                          \
    _Generic ( (src),                                                               \
            char*:      vector_char_vec_assign,                                     \
            short*:     vector_short_vec_assign,                                    \
            int*:       vector_int_vec_assign,                                      \
            float*:     vector_float_vec_assign,                                    \
            long*:      vector_long_vec_assign,                                     \
            double*:    vector_double_vec_assign,                                   \
            void*:      vector_void_vec_assign,                                     \
            default:    vector_assign_error                                         \
    )( vector, src, size )                                                          //vector_assign( vector* vec, <T*> target, size_t size)



//push_back: push element to the end of the vector
void vector_char_vec_push_back( vector* vec, char target );
void vector_short_vec_push_back( vector* vec, short target );
void vector_int_vec_push_back( vector* vec, int target );
void vector_float_vec_push_back( vector* vec, float target );
void vector_long_vec_push_back( vector* vec, long target );
void vector_double_vec_push_back( vector* vec, double target );
void vector_void_vec_push_back( vector* vec, void* target );
void vector_push_back_error( void );

//call vector_push_back( vector* vec, <T> target ). For void_vec, target needs to be type void*.
#define vector_push_back( vector, target )                                          \
    _Generic ( (target),                                                            \
            char:       vector_char_vec_push_back,                                  \
            short:      vector_short_vec_push_back,                                 \
            int:        vector_int_vec_push_back,                                   \
            float:      vector_float_vec_push_back,                                 \
            long:       vector_long_vec_push_back,                                  \
            double:     vector_double_vec_push_back,                                \
            void*:      vector_void_vec_push_back,                                  \
            default:    vector_push_back_error                                      \
    )( vector, target )                                                             //vector_push_back( vector* vec, <T> target )



//pop_back: pop element from the end of the vector
void vector_char_vec_pop_back( vector* vec );
void vector_short_vec_pop_back( vector* vec );
void vector_int_vec_pop_back( vector* vec );
void vector_float_vec_pop_back( vector* vec );
void vector_long_vec_pop_back( vector* vec );
void vector_double_vec_pop_back( vector* vec );
void vector_void_vec_pop_back( vector* vec );

//call vector_pop_back( vector* vec ). For void_vec, return value is dynamically allocated on the heap, user need to manually free the pointer.
void vector_pop_back( vector* vec );



//insert: insert an exesting array to the specified index/element of the vector
void vector_char_vec_insert( vector* vec, size_t index, char* src, size_t size );
void vector_short_vec_insert( vector* vec, size_t index, short* src, size_t size );
void vector_int_vec_insert( vector* vec, size_t index, int* src, size_t size );
void vector_float_vec_insert( vector* vec, size_t index, float* src, size_t size );
void vector_long_vec_insert( vector* vec, size_t index, long* src, size_t size );
void vector_double_vec_insert( vector* vec, size_t index, double* src, size_t size );
void vector_void_vec_insert( vector* vec, size_t index, void* src, size_t size );

//call vector_insert( vector* vec, size_t index, <T*> src, size_t size ). For void_vec, user need to make sure sturct/type are of the same exact struct/type.
//ATTENTION: size_t size is the number of elements!!!
#define vector_insert( vector, index, src, size )                                   \
    _Generic ( (src),                                                               \
            char*:      vector_char_vec_insert,                                     \
            short*:     vector_short_vec_insert,                                    \
            int*:       vector_int_vec_insert,                                      \
            float*:     vector_float_vec_insert,                                    \
            long*:      vector_long_vec_insert,                                     \
            double*:    vector_double_vec_insert,                                   \
            void*:      vector_void_vec_insert                                      \
    )( vec, index, src, size )                                                      //vector_insert( vector* vec, size_t index, <T*> src, size_t size )



//erase: erase a range of elements form the vector. Starting from index, with size size
void vector_char_vec_erase( vector* vec, size_t index, size_t size );
void vector_short_vec_erase( vector* vec, size_t index, size_t size );
void vector_int_vec_erase( vector* vec, size_t index, size_t size );
void vector_float_vec_erase( vector* vec, size_t index, size_t size );
void vector_long_vec_erase( vector* vec, size_t index, size_t size );
void vector_double_vec_erase( vector* vec, size_t index, size_t size );
void vector_void_vec_erase( vector* vec, size_t index, size_t size );

//call vector_erase( vector* vec, size_t index, size_t size ). 
//ATTENTION: size_t size is the number of elements!!!
void vector_erase( vector* vec, size_t index, size_t size );



//clear: deallocate the vector (basically destroy the vector and free the memory)
//call vector_clear( vector* vec )
void vector_clear( vector* vec );


#endif  // vector.h