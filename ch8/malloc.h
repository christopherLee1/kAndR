typedef long _Align; // for alignment to long boundary

union header
    {
    struct
        {
        union header *ptr; //next block if on free list
        unsigned size; // size of this block
        } s;
    _Align x; // force alignment of blocks
    };

typedef union header Header;

#define NALLOC 1024
