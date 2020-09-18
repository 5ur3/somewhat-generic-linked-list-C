#include "mainlinkedlist.h"

#define TYPE char
#include "typedlinkedlist.h"
#undef TYPE

#define TYPE short
#include "typedlinkedlist.h"
#undef TYPE

#define TYPE int
#include "typedlinkedlist.h"
#undef TYPE

#define TYPE long
#include "typedlinkedlist.h"
#undef TYPE

#define NAME long_long
#define TYPE long long
#include "typedlinkedlist.h"
#undef TYPE
#undef NAME

#define TYPE float
#include "typedlinkedlist.h"
#undef TYPE

#define TYPE double
#include "typedlinkedlist.h"
#undef TYPE

#define NAME long_double
#define TYPE long double
#include "typedlinkedlist.h"
#undef TYPE
#undef NAME
