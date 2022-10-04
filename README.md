# vector
vector for C

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
    size_t  size;               //current size of the vector
    size_t  capacity;           //current capacity of the vecctor
    int     data_type;          //data type of the vector
    size_t  data_type_size;     //sizeof element in void_vec
}vector;
```

API list:

```
vector*   vector_new_vector( int data_type );
<T>       vector_get( vec* vector, size_t index, <T*> buff );
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
