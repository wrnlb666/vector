# vector
vector for pure C.  

Require ISO C11 or later for ```_Generic``` keyword. 

Differences among other C vectors: User may use any primitive data (```char, short, int, float, long, double```) type directly. 

API should be pretty similar to what cpp's vector provides. 

vector field: 

```
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
    size_t  size;               //current size of the vector (element count)
    size_t  capacity;           //current capacity of the vecctor (element count)
    int     data_type;          //data type of the vector
    size_t  data_type_size;     //sizeof element in void_vec
}vector;
```

API list:

```
vector*   vector_new_vector( int data_type );
<T>       vector_get( vec* vector, size_t index );
void      vector_assign( vector* vec, <T*> target, size_t size);
void      vector_push_back( vector* vec, <T> target );
void      vector_pop_back( vector* vec );
void      vector_insert( vector* vec, size_t index, <T*> src, size_t size );
void      vector_erase( vector* vec, size_t index, size_t size );
void      vector_clear( vector* vec );
```

to active warning message: 
```
#define VECTOR_WARNING
```
