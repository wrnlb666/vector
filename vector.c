//Copyright (c) 2022 Zhang Yixiang
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





#include "vector.h"


//init functions
vector* vector_new_char_vec( void )
{
    vector *temp = malloc( sizeof (vector) );
    *temp = ( vector )
    {
        .char_vec           = NULL,
        .size               = 0,
        .capacity           = VEC_CAP,
        .data_type          = CHAR,
        .data_type_size     = sizeof (char)
    };
    temp->char_vec = realloc( temp->int_vec, temp->data_type_size * temp->capacity );
    if ( !temp->char_vec )
    {
        free( temp );
        temp = NULL;
    }
    return temp;
}

vector* vector_new_short_vec( void )
{
    vector *temp = malloc( sizeof (vector) );
    *temp = ( vector )
    {
        .short_vec          = NULL,
        .size               = 0,
        .capacity           = VEC_CAP,
        .data_type          = SHORT,
        .data_type_size     = sizeof (short)
    };
    temp->short_vec = realloc( temp->int_vec, temp->data_type_size * temp->capacity );
    if ( !temp->short_vec )
    {
        free( temp );
        temp = NULL;
    }
    return temp;
}

vector* vector_new_int_vec( void )
{
    vector *temp = malloc( sizeof (vector) );
    *temp = ( vector )
    {
        .int_vec            = NULL,
        .size               = 0,
        .capacity           = VEC_CAP,
        .data_type          = INT,
        .data_type_size     = sizeof (int)
    };
    temp->int_vec = realloc( temp->int_vec, temp->data_type_size * temp->capacity );
    if ( !temp->int_vec )
    {
        free( temp );
        temp = NULL;
    }
    return temp;
}

vector* vector_new_float_vec( void )
{
    vector *temp = malloc( sizeof (vector) );
    *temp = ( vector )
    {
        .float_vec          = NULL,
        .size               = 0,
        .capacity           = VEC_CAP,
        .data_type          = FLOAT,
        .data_type_size     = sizeof (float)
    };
    temp->float_vec = realloc( temp->int_vec, temp->data_type_size * temp->capacity );
    if ( !temp->float_vec )
    {
        free( temp );
        temp = NULL;
    }
    return temp;
}

vector* vector_new_long_vec( void )
{
    vector *temp = malloc( sizeof (vector) );
    *temp = ( vector )
    {
        .long_vec           = NULL,
        .size               = 0,
        .capacity           = VEC_CAP,
        .data_type          = LONG,
        .data_type_size     = sizeof (long)
    };
    temp->long_vec = realloc( temp->int_vec, temp->data_type_size * temp->capacity );
    if ( !temp->long_vec )
    {
        free( temp );
        temp = NULL;
    }
    return temp;
}

vector* vector_new_double_vec( void )
{
    vector *temp = malloc( sizeof (vector) );
    *temp = ( vector )
    {
        .double_vec         = NULL,
        .size               = 0,
        .capacity           = VEC_CAP,
        .data_type          = DOUBLE,
        .data_type_size     = sizeof (double)
    };
    temp->double_vec = realloc( temp->int_vec, temp->data_type_size * temp->capacity );
    if ( !temp->double_vec )
    {
        free( temp );
        temp = NULL;
    }
    return temp;
}

vector* vector_new_void_vec( size_t data_type_size )
{
    vector *temp = malloc( sizeof (vector) );
    *temp = ( vector )
    {
        .void_vec           = NULL,
        .size               = 0,
        .capacity           = VEC_CAP * data_type_size,
        .data_type          = VOID,
        .data_type_size     = data_type_size
    };
    temp->void_vec = realloc( temp->int_vec, temp->data_type_size * temp->capacity );
    if ( !temp->void_vec )
    {
        free( temp );
        temp = NULL;
    }
    return temp;
}

vector* vector_new_vector( int data_type )
{
    vector* temp = NULL;
    switch ( data_type )
    {
        case CHAR:
            temp = vector_new_char_vec();
            break;
        case SHORT:
            temp = vector_new_short_vec();
            break;
        case INT:
            temp = vector_new_int_vec();
            break;
        case FLOAT:
            temp = vector_new_float_vec();
            break;
        case LONG:
            temp = vector_new_long_vec();
            break;
        case DOUBLE:
            temp = vector_new_double_vec();
            break;
        default:
        {
            if ( data_type >> 30 == 1 )
            {
                size_t data_type_size_x4 = data_type << 2;
                temp = vector_new_void_vec( data_type_size_x4 >> 2 );
            }
            else
            {
                fprintf( stderr, "ERROR: Wrong data_type input\n" );
                abort();
            }
        }
    }
    if ( temp )
    {
        return temp;
    }
    else
    {
        fprintf( stderr, "ERROR: malloc failed\n" );
        abort();
        return (vector*) -1;
    }
}



//get the value of specified index, value will be stored in char* buff
char vector_char_vec_get( vector* vec, size_t index, char* buff )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != CHAR )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( index >= vec->size )
    {
        fprintf( stderr, "ERROR: index out of bound\n");
        abort();
    }
    if ( buff == NULL )
    {
        buff = malloc( vec->data_type_size );
    }
    *buff = vec->char_vec[index];
    return *buff;
}

short vector_short_vec_get( vector* vec, size_t index, short* buff )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != SHORT )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( index >= vec->size )
    {
        fprintf( stderr, "ERROR: index out of bound\n");
        abort();
    }
    if ( buff == NULL )
    {
        buff = malloc( vec->data_type_size );
    }
    *buff = vec->short_vec[index];
    return *buff;
}

int vector_int_vec_get( vector* vec, size_t index, int* buff )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != INT )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( index >= vec->size )
    {
        fprintf( stderr, "ERROR: index out of bound\n");
        abort();
    }
    if ( buff == NULL )
    {
        buff = malloc( vec->data_type_size );
    }
    *buff = vec->int_vec[index];
    return *buff;
}

float vector_float_vec_get( vector* vec, size_t index, float* buff )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != FLOAT )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( index >= vec->size )
    {
        fprintf( stderr, "ERROR: index out of bound\n");
        abort();
    }
    if ( buff == NULL )
    {
        buff = malloc( vec->data_type_size );
    }
    *buff = vec->float_vec[index];
    return *buff;
}

long vector_long_vec_get( vector* vec, size_t index, long* buff )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != LONG )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( index >= vec->size )
    {
        fprintf( stderr, "ERROR: index out of bound\n");
        abort();
    }
    if ( buff == NULL )
    {
        buff = malloc( vec->data_type_size );
    }
    *buff = vec->long_vec[index];
    return *buff;
}

double vector_double_vec_get( vector* vec, size_t index, double* buff )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != DOUBLE )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( index >= vec->size )
    {
        fprintf( stderr, "ERROR: index out of bound\n");
        abort();
    }
    if ( buff == NULL )
    {
        buff = malloc( vec->data_type_size );
    }
    *buff = vec->double_vec[index];
    return *buff;
}

void* vector_void_vec_get( vector* vec, size_t index, void* buff )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != VOID )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( index >= vec->size )
    {
        fprintf( stderr, "ERROR: index out of bound\n");
        abort();
    }
    if ( buff == NULL )
    {
        buff = malloc( vec->data_type_size );
    }
    memcpy( buff, (char*) vec->void_vec + index * vec->data_type_size, vec->data_type_size );
    return buff;
}



//assign a existing array to the vector
void vector_char_vec_assign( vector* vec, char* src, size_t size )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != CHAR )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( size >= vec->capacity )
    {
        while ( size >= vec->capacity )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity += 128;
            }
            else
            {
                vec->capacity *= 2;
            }
        }
        vec->char_vec = realloc( vec->char_vec, vec->data_type_size * vec->capacity );
        if ( !vec->char_vec )
        {
            free( vec->char_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    else if ( size <= vec->capacity / 4 )
    {
        while ( size <= vec->capacity / 4 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->char_vec = realloc( vec->char_vec, vec->data_type_size * vec->capacity );
        if ( !vec->char_vec )
        {
            free( vec->char_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( vec->char_vec, src, vec->data_type_size * size );
    vec->size = size;
}

void vector_short_vec_assign( vector* vec, short* src, size_t size )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != SHORT )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( size >= vec->capacity )
    {
        while ( size >= vec->capacity )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity += 128;
            }
            else
            {
                vec->capacity *= 2;
            }
        }
        vec->short_vec = realloc( vec->short_vec, vec->data_type_size * vec->capacity );
        if ( !vec->short_vec )
        {
            free( vec->short_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    else if ( size <= vec->capacity / 4 )
    {
        while ( size <= vec->capacity / 4 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->short_vec = realloc( vec->short_vec, vec->data_type_size * vec->capacity );
        if ( !vec->short_vec )
        {
            free( vec->short_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( vec->short_vec, src, vec->data_type_size * size );
    vec->size = size;
}

void vector_int_vec_assign( vector* vec, int* src, size_t size )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != INT )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( size >= vec->capacity )
    {
        while ( size >= vec->capacity )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity += 128;
            }
            else
            {
                vec->capacity *= 2;
            }
        }
        vec->int_vec = realloc( vec->int_vec, vec->data_type_size * vec->capacity );
        if ( !vec->int_vec )
        {
            free( vec->int_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    else if ( size <= vec->capacity / 4 )
    {
        while ( size <= vec->capacity / 4 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->int_vec = realloc( vec->int_vec, vec->data_type_size * vec->capacity );
        if ( !vec->int_vec )
        {
            free( vec->int_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( vec->int_vec, src, vec->data_type_size * size );
    vec->size = size;
}

void vector_float_vec_assign( vector* vec, float* src, size_t size )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != FLOAT )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( size >= vec->capacity )
    {
        while ( size >= vec->capacity )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity += 128;
            }
            else
            {
                vec->capacity *= 2;
            }
        }
        vec->float_vec = realloc( vec->float_vec, vec->data_type_size * vec->capacity );
        if ( !vec->float_vec )
        {
            free( vec->float_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    else if ( size <= vec->capacity / 4 )
    {
        while ( size <= vec->capacity / 4 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->float_vec = realloc( vec->float_vec, vec->data_type_size * vec->capacity );
        if ( !vec->float_vec )
        {
            free( vec->float_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( vec->float_vec, src, vec->data_type_size * size );
    vec->size = size;
}

void vector_long_vec_assign( vector* vec, long* src, size_t size )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != LONG )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( size >= vec->capacity )
    {
        while ( size >= vec->capacity )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity += 128;
            }
            else
            {
                vec->capacity *= 2;
            }
        }
        vec->long_vec = realloc( vec->long_vec, vec->data_type_size * vec->capacity );
        if ( !vec->long_vec )
        {
            free( vec->long_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    else if ( size <= vec->capacity / 4 )
    {
        while ( size <= vec->capacity / 4 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->long_vec = realloc( vec->long_vec, vec->data_type_size * vec->capacity );
        if ( !vec->long_vec )
        {
            free( vec->long_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( vec->long_vec, src, vec->data_type_size * size );
    vec->size = size;
}

void vector_double_vec_assign( vector* vec, double* src, size_t size )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != DOUBLE )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( size >= vec->capacity )
    {
        while ( size >= vec->capacity )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity += 128;
            }
            else
            {
                vec->capacity *= 2;
            }
        }
        vec->double_vec = realloc( vec->double_vec, vec->data_type_size * vec->capacity );
        if ( !vec->double_vec )
        {
            free( vec->double_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    else if ( size <= vec->capacity / 4 )
    {
        while ( size <= vec->capacity / 4 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->double_vec = realloc( vec->double_vec, vec->data_type_size * vec->capacity );
        if ( !vec->double_vec )
        {
            free( vec->double_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( vec->double_vec, src, vec->data_type_size * size );
    vec->size = size;
}

void vector_void_vec_assign( vector* vec, void* src, size_t size )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != VOID )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( size >= vec->capacity )
    {
        while ( size >= vec->capacity )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity += 128;
            }
            else
            {
                vec->capacity *= 2;
            }
        }
        vec->void_vec = realloc( vec->void_vec, vec->data_type_size * vec->capacity );
        if ( !vec->void_vec )
        {
            free( vec->void_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    else if ( size <= vec->capacity / 4 )
    {
        while ( size <= vec->capacity / 4 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->void_vec = realloc( vec->void_vec, vec->data_type_size * vec->capacity );
        if ( !vec->void_vec )
        {
            free( vec->void_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( vec->void_vec, src, vec->data_type_size * size );
    vec->size = size;
}

void vector_assign_error( void )
{
    fprintf( stderr, "ERROR: src type is not supported\n" );
    abort();
}



//push an element to the back of the vector
void vector_char_vec_push_back( vector* vec, char target )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != CHAR )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( vec->size == vec->capacity )
    {
        if ( vec->capacity >= 256 )
        {
            vec->capacity += 128;
        }
        else
        {
            vec->capacity *= 2;
        }
        vec->char_vec = realloc( vec->char_vec, vec->data_type_size * vec->capacity );
        if ( !vec->char_vec )
        {
            free( vec->char_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    vec->char_vec[ vec->size++ ] = target;
}

void vector_short_vec_push_back( vector* vec, short target )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != SHORT )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( vec->size == vec->capacity )
    {
        if ( vec->capacity >= 256 )
        {
            vec->capacity += 128;
        }
        else
        {
            vec->capacity *= 2;
        }
        vec->short_vec = realloc( vec->short_vec, vec->data_type_size * vec->capacity );
        if ( !vec->short_vec )
        {
            free( vec->short_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    vec->short_vec[ vec->size++ ] = target;
}

void vector_int_vec_push_back( vector* vec, int target )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != INT )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( vec->size == vec->capacity )
    {
        if ( vec->capacity >= 256 )
        {
            vec->capacity += 128;
        }
        else
        {
            vec->capacity *= 2;
        }
        vec->int_vec = realloc( vec->int_vec, vec->data_type_size * vec->capacity );
        if ( !vec->int_vec )
        {
            free( vec->int_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    vec->int_vec[ vec->size++ ] = target;
}

void vector_float_vec_push_back( vector* vec, float target )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != FLOAT )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( vec->size == vec->capacity )
    {
        if ( vec->capacity >= 256 )
        {
            vec->capacity += 128;
        }
        else
        {
            vec->capacity *= 2;
        }
        vec->float_vec = realloc( vec->float_vec, vec->data_type_size * vec->capacity );
        if ( !vec->float_vec )
        {
            free( vec->float_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    vec->float_vec[ vec->size++ ] = target;
}

void vector_long_vec_push_back( vector* vec, long target )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != LONG )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( vec->size == vec->capacity )
    {
        if ( vec->capacity >= 256 )
        {
            vec->capacity += 128;
        }
        else
        {
            vec->capacity *= 2;
        }
        vec->long_vec = realloc( vec->long_vec, vec->data_type_size * vec->capacity );
        if ( !vec->long_vec )
        {
            free( vec->long_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    vec->long_vec[ vec->size++ ] = target;
}

void vector_double_vec_push_back( vector* vec, double target )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != DOUBLE )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( vec->size == vec->capacity )
    {
        if ( vec->capacity >= 256 )
        {
            vec->capacity += 128;
        }
        else
        {
            vec->capacity *= 2;
        }
        vec->double_vec = realloc( vec->double_vec, vec->data_type_size * vec->capacity );
        if ( !vec->double_vec )
        {
            free( vec->double_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    vec->double_vec[ vec->size++ ] = target;
}

void vector_void_vec_push_back( vector* vec, void* target )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != VOID )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( vec->size == vec->capacity )
    {
        if ( vec->capacity >= 256 )
        {
            vec->capacity += 128;
        }
        else
        {
            vec->capacity *= 2;
        }
        vec->void_vec = realloc( vec->void_vec, vec->data_type_size * vec->capacity );
        if ( !vec->void_vec )
        {
            free( vec->void_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( (char*) vec->void_vec + ( vec->data_type_size * vec->size++ ), target, vec->data_type_size );
}

void vector_push_back_error( void )
{
    fprintf( stderr, "ERROR: target type is not supported\n" );
    abort();
}



//pop an element from the back of the vector
void vector_char_vec_pop_back( vector* vec )
{
    if ( !vec->size )
    {
        #ifdef VECTOR_WARNING
        fprintf( stderr, "WARNING: vector is already empty\n" );
        #endif
    }
    else
    {
        if ( vec->size <= vec->capacity / 3 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->char_vec = realloc( vec->char_vec, vec->data_type_size * vec->capacity );
        if ( !vec->char_vec )
        {
            fprintf( stderr, "ERROR: realloc failed\n");
            free( vec->char_vec );
            free( vec );
            vec = NULL;
            abort();
        }
        --vec->size;
    }
}

void vector_short_vec_pop_back( vector* vec )
{
    if ( !vec->size )
    {
        #ifdef VECTOR_WARNING
        fprintf( stderr, "WARNING: vector is already empty\n" );
        #endif
    }
    else
    {
        if ( vec->size <= vec->capacity / 3 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->short_vec = realloc( vec->short_vec, vec->data_type_size * vec->capacity );
        if ( !vec->short_vec )
        {
            fprintf( stderr, "ERROR: realloc failed\n");
            free( vec->short_vec );
            free( vec );
            vec = NULL;
            abort();
        }
        --vec->size;
    }
}

void vector_int_vec_pop_back( vector* vec )
{
    if ( !vec->size )
    {
        #ifdef VECTOR_WARNING
        fprintf( stderr, "WARNING: vector is already empty\n" );
        #endif
    }
    else
    {
        if ( vec->size <= vec->capacity / 3 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->int_vec = realloc( vec->int_vec, vec->data_type_size * vec->capacity );
        if ( !vec->int_vec )
        {
            fprintf( stderr, "ERROR: realloc failed\n");
            free( vec->int_vec );
            free( vec );
            vec = NULL;
            abort();
        }
        --vec->size;
    }
}

void vector_float_vec_pop_back( vector* vec )
{
    if ( !vec->size )
    {
        #ifdef VECTOR_WARNING
        fprintf( stderr, "WARNING: vector is already empty\n" );
        #endif
    }
    else
    {
        if ( vec->size <= vec->capacity / 3 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->float_vec = realloc( vec->float_vec, vec->data_type_size * vec->capacity );
        if ( !vec->float_vec )
        {
            fprintf( stderr, "ERROR: realloc failed\n");
            free( vec->float_vec );
            free( vec );
            vec = NULL;
            abort();
        }
        --vec->size;
    }
}

void vector_long_vec_pop_back( vector* vec )
{
    if ( !vec->size )
    {
        #ifdef VECTOR_WARNING
        fprintf( stderr, "WARNING: vector is already empty\n" );
        #endif
    }
    else
    {
        if ( vec->size <= vec->capacity / 3 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->long_vec = realloc( vec->long_vec, vec->data_type_size * vec->capacity );
        if ( !vec->long_vec )
        {
            fprintf( stderr, "ERROR: realloc failed\n");
            free( vec->long_vec );
            free( vec );
            vec = NULL;
            abort();
        }
        --vec->size;
    }
}

void vector_double_vec_pop_back( vector* vec )
{
    if ( !vec->size )
    {
        #ifdef VECTOR_WARNING
        fprintf( stderr, "WARNING: vector is already empty\n" );
        #endif
    }
    else
    {
        if ( vec->size <= vec->capacity / 3 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->double_vec = realloc( vec->double_vec, vec->data_type_size * vec->capacity );
        if ( !vec->double_vec )
        {
            fprintf( stderr, "ERROR: realloc failed\n");
            free( vec->double_vec );
            free( vec );
            vec = NULL;
            abort();
        }
        --vec->size;
    }
}

void vector_void_vec_pop_back( vector* vec )
{
    if ( !vec->size )
    {
        #ifdef VECTOR_WARNING
        fprintf( stderr, "WARNING: vector is already empty\n" );
        #endif
    }
    else
    {
        if ( vec->size <= vec->capacity / 3 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->void_vec = realloc( vec->void_vec, vec->data_type_size * vec->capacity );
        if ( !vec->void_vec )
        {
            fprintf( stderr, "ERROR: realloc failed\n");
            free( vec->void_vec );
            free( vec );
            vec = NULL;
            abort();
        }
        --vec->size;
    }
}

void vector_pop_back( vector* vec )
{
    switch ( vec->data_type )
    {
        case CHAR:      vector_char_vec_pop_back( vec );            break;
        case SHORT:     vector_short_vec_pop_back( vec );           break;
        case INT:       vector_int_vec_pop_back( vec );             break;
        case FLOAT:     vector_float_vec_pop_back( vec );           break;
        case LONG:      vector_long_vec_pop_back( vec );            break;
        case DOUBLE:    vector_double_vec_pop_back( vec );          break;
        case VOID:      vector_void_vec_pop_back( vec );            break;
        default:        fprintf( stderr, "ERROR: bad vector\n" );   abort(); 
    }
}



//insert an array into the vector at specified index/position in the vector
void vector_char_vec_insert( vector* vec, size_t index, char* src, size_t size )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != CHAR )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( vec->size + size >= vec->capacity )
    {
        while ( vec->size + size >= vec->capacity )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity += 128;
            }
            else
            {
                vec->capacity *= 2;
            }
        }
        vec->char_vec = realloc( vec->char_vec, vec->data_type_size * vec->capacity );
        if ( !vec->char_vec )
        {
            free( vec->char_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( &vec->char_vec[ index + size ], &vec->char_vec[index], vec->data_type_size * ( vec->size - index ) );
    memmove( &vec->char_vec[index], src, vec->data_type_size * size );
    vec->size += size;
}

void vector_short_vec_insert( vector* vec, size_t index, short* src, size_t size )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != SHORT )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( vec->size + size >= vec->capacity )
    {
        while ( vec->size + size >= vec->capacity )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity += 128;
            }
            else
            {
                vec->capacity *= 2;
            }
        }
        vec->short_vec = realloc( vec->short_vec, vec->data_type_size * vec->capacity );
        if ( !vec->short_vec )
        {
            free( vec->short_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( &vec->short_vec[ index + size ], &vec->short_vec[index], vec->data_type_size * ( vec->size - index ) );
    memmove( &vec->short_vec[index], src, vec->data_type_size * size );
    vec->size += size;
}

void vector_int_vec_insert( vector* vec, size_t index, int* src, size_t size )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != INT )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( vec->size + size >= vec->capacity )
    {
        while ( vec->size + size >= vec->capacity )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity += 128;
            }
            else
            {
                vec->capacity *= 2;
            }
        }
        vec->int_vec = realloc( vec->int_vec, vec->data_type_size * vec->capacity );
        if ( !vec->int_vec )
        {
            free( vec->int_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( &vec->int_vec[ index + size ], &vec->int_vec[index], vec->data_type_size * ( vec->size - index ) );
    memmove( &vec->int_vec[index], src, vec->data_type_size * size );
    vec->size += size;
}

void vector_float_vec_insert( vector* vec, size_t index, float* src, size_t size )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != FLOAT )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( vec->size + size >= vec->capacity )
    {
        while ( vec->size + size >= vec->capacity )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity += 128;
            }
            else
            {
                vec->capacity *= 2;
            }
        }
        vec->float_vec = realloc( vec->float_vec, vec->data_type_size * vec->capacity );
        if ( !vec->float_vec )
        {
            free( vec->float_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( &vec->float_vec[ index + size ], &vec->float_vec[index], vec->data_type_size * ( vec->size - index ) );
    memmove( &vec->float_vec[index], src, vec->data_type_size * size );
    vec->size += size;
}

void vector_long_vec_insert( vector* vec, size_t index, long* src, size_t size )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != LONG )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( vec->size + size >= vec->capacity )
    {
        while ( vec->size + size >= vec->capacity )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity += 128;
            }
            else
            {
                vec->capacity *= 2;
            }
        }
        vec->long_vec = realloc( vec->long_vec, vec->data_type_size * vec->capacity );
        if ( !vec->long_vec )
        {
            free( vec->long_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( &vec->long_vec[ index + size ], &vec->long_vec[index], vec->data_type_size * ( vec->size - index ) );
    memmove( &vec->long_vec[index], src, vec->data_type_size * size );
    vec->size += size;
}

void vector_double_vec_insert( vector* vec, size_t index, double* src, size_t size )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != DOUBLE )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( vec->size + size >= vec->capacity )
    {
        while ( vec->size + size >= vec->capacity )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity += 128;
            }
            else
            {
                vec->capacity *= 2;
            }
        }
        vec->double_vec = realloc( vec->double_vec, vec->data_type_size * vec->capacity );
        if ( !vec->double_vec )
        {
            free( vec->double_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( &vec->double_vec[ index + size ], &vec->double_vec[index], vec->data_type_size * ( vec->size - index ) );
    memmove( &vec->double_vec[index], src, vec->data_type_size * size );
    vec->size += size;
}

void vector_void_vec_insert( vector* vec, size_t index, void* src, size_t size )
{
    #ifdef VECTOR_WARNING
    if ( vec->data_type != VOID )
    {
        fprintf( stderr, "WARNING: incompatible data type\n" );
    }
    #endif
    if ( vec->size + size >= vec->capacity )
    {
        while ( vec->size + size >= vec->capacity )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity += 128;
            }
            else
            {
                vec->capacity *= 2;
            }
        }
        vec->void_vec = realloc( vec->void_vec, vec->data_type_size * vec->capacity );
        if ( !vec->void_vec )
        {
            free( vec->void_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( (char*) vec->void_vec + ( index + size ) * vec->data_type_size, (char*) vec->void_vec + index * vec->data_type_size, vec->data_type_size * ( vec->size - index ) );
    memmove( (char*) vec->void_vec + index * vec->data_type_size, src, vec->data_type_size * size );
    vec->size += size;
}



//erase a range of elements from the vector. Starting from index and with size size
void vector_char_vec_erase( vector* vec, size_t index, size_t size )
{
    if ( index + size > vec->size )
    {
        fprintf( stderr, "ERROR: index out of bound\n");
        abort();
    }
    if ( vec->size - size <= vec->capacity / 4 )
    {
        while ( vec->size - size <= vec->capacity / 4 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->char_vec = realloc( vec->char_vec, vec->data_type_size * vec->capacity );
        if ( !vec->char_vec )
        {
            free( vec->char_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( &vec->char_vec[index], &vec->char_vec[ index + size ], ( vec->size - ( index + size ) ) * vec->data_type_size );
    vec->size -= size;
}

void vector_short_vec_erase( vector* vec, size_t index, size_t size )
{
    if ( index + size > vec->size )
    {
        fprintf( stderr, "ERROR: index out of bound\n");
        abort();
    }
    if ( vec->size - size <= vec->capacity / 4 )
    {
        while ( vec->size - size <= vec->capacity / 4 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->short_vec = realloc( vec->short_vec, vec->data_type_size * vec->capacity );
        if ( !vec->short_vec )
        {
            free( vec->short_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( &vec->short_vec[index], &vec->short_vec[ index + size ], ( vec->size - ( index + size ) ) * vec->data_type_size );
    vec->size -= size;
}

void vector_int_vec_erase( vector* vec, size_t index, size_t size )
{
    if ( index + size > vec->size )
    {
        fprintf( stderr, "ERROR: index out of bound\n");
        abort();
    }
    if ( vec->size - size <= vec->capacity / 4 )
    {
        while ( vec->size - size <= vec->capacity / 4 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->int_vec = realloc( vec->int_vec, vec->data_type_size * vec->capacity );
        if ( !vec->int_vec )
        {
            free( vec->int_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( &vec->int_vec[index], &vec->int_vec[ index + size ], ( vec->size - ( index + size ) ) * vec->data_type_size );
    vec->size -= size;
}

void vector_float_vec_erase( vector* vec, size_t index, size_t size )
{
    if ( index + size > vec->size )
    {
        fprintf( stderr, "ERROR: index out of bound\n");
        abort();
    }
    if ( vec->size - size <= vec->capacity / 4 )
    {
        while ( vec->size - size <= vec->capacity / 4 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->float_vec = realloc( vec->float_vec, vec->data_type_size * vec->capacity );
        if ( !vec->float_vec )
        {
            free( vec->float_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( &vec->float_vec[index], &vec->float_vec[ index + size ], ( vec->size - ( index + size ) ) * vec->data_type_size );
    vec->size -= size;
}

void vector_long_vec_erase( vector* vec, size_t index, size_t size )
{
    if ( index + size > vec->size )
    {
        fprintf( stderr, "ERROR: index out of bound\n");
        abort();
    }
    if ( vec->size - size <= vec->capacity / 4 )
    {
        while ( vec->size - size <= vec->capacity / 4 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->long_vec = realloc( vec->long_vec, vec->data_type_size * vec->capacity );
        if ( !vec->long_vec )
        {
            free( vec->long_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( &vec->long_vec[index], &vec->long_vec[ index + size ], ( vec->size - ( index + size ) ) * vec->data_type_size );
    vec->size -= size;
}

void vector_double_vec_erase( vector* vec, size_t index, size_t size )
{
    if ( index + size > vec->size )
    {
        fprintf( stderr, "ERROR: index out of bound\n");
        abort();
    }
    if ( vec->size - size <= vec->capacity / 4 )
    {
        while ( vec->size - size <= vec->capacity / 4 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->double_vec = realloc( vec->double_vec, vec->data_type_size * vec->capacity );
        if ( !vec->double_vec )
        {
            free( vec->double_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( &vec->double_vec[index], &vec->double_vec[ index + size ], ( vec->size - ( index + size ) ) * vec->data_type_size );
    vec->size -= size;
}

void vector_void_vec_erase( vector* vec, size_t index, size_t size )
{
    if ( index + size > vec->size )
    {
        fprintf( stderr, "ERROR: index out of bound\n");
        abort();
    }
    if ( vec->size - size <= vec->capacity / 4 )
    {
        while ( vec->size - size <= vec->capacity / 4 && vec->capacity > VEC_CAP )
        {
            if ( vec->capacity >= 256 )
            {
                vec->capacity -= 128;
            }
            else
            {
                vec->capacity /= 2;
            }
        }
        vec->void_vec = realloc( vec->void_vec, vec->data_type_size * vec->capacity );
        if ( !vec->void_vec )
        {
            free( vec->void_vec );
            free( vec );
            vec = NULL;
            fprintf( stderr, "ERROR: realloc failed\n" );
            abort();
        }
    }
    memmove( (char*) vec->void_vec + index * vec->data_type_size, (char*) vec->void_vec + ( index + size ) * vec->data_type_size, ( vec->size - ( index + size ) ) * vec->data_type_size );
    vec->size -= size;
}

void vector_erase( vector* vec, size_t index, size_t size )
{
    switch ( vec->data_type )
    {
        case CHAR:      vector_char_vec_erase( vec, index, size );      break;
        case SHORT:     vector_short_vec_erase( vec, index, size );     break;
        case INT:       vector_int_vec_erase( vec, index, size );       break;
        case FLOAT:     vector_float_vec_erase( vec, index, size );     break;
        case LONG:      vector_long_vec_erase( vec, index, size );      break;
        case DOUBLE:    vector_double_vec_erase( vec, index, size );    break;
        case VOID:      vector_void_vec_erase( vec, index, size );      break;
        default:        fprintf( stderr, "ERROR: bad vector\n" );       abort();
    }
}



void vector_clear( vector* vec )
{
    free( vec->void_vec );
    free( vec );
    vec = NULL;
}