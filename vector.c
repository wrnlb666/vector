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



//assign a existing array to the vector
void vector_char_vec_assign( vector* vec, char* src, size_t size )
{
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
        fprintf( stderr, "WARNING: vector is already empty\n" );
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
        fprintf( stderr, "WARNING: vector is already empty\n" );
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
        fprintf( stderr, "WARNING: vector is already empty\n" );
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
        fprintf( stderr, "WARNING: vector is already empty\n" );
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
        fprintf( stderr, "WARNING: vector is already empty\n" );
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
        fprintf( stderr, "WARNING: vector is already empty\n" );
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
        fprintf( stderr, "WARNING: vector is already empty\n" );
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

