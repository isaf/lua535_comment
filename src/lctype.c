/*
** $Id: lctype.c,v 1.12.1.1 2017/04/19 17:20:42 roberto Exp $
** 'ctype' functions for Lua
** See Copyright Notice in lua.h
*/
/*已看完*/

#define lctype_c
#define LUA_CORE

#include "lprefix.h"


#include "lctype.h"

#if !LUA_USE_CTYPE	/* { */

#include <limits.h>
/*
下表的数值与ASCII表的数值是有对应的。比如ASCII表中'A'的值是65，那就对应下表中的第67个值，即luai_ctype[65+1]（参考testprop）,即0x15，
换成二进制是0001 0101，里面的1描述了该字符的特性，对应lctype.h中的定义（ALPHABIT，PRINTBIT这些），第0个1表示它是个字母，第2个1表示它可打印，第4个1表示它是个16进制字符。
*/
LUAI_DDEF const lu_byte luai_ctype_[UCHAR_MAX + 2] = {  /*以下一共有0xff+2，即257（255+2）个值*/
  0x00,  /* EOZ */
  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,	/* 0. */    /*1-8*/
  0x00,  0x08,  0x08,  0x08,  0x08,  0x08,  0x00,  0x00,                /*9-16*/
  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,	/* 1. */    /*17-24*/
  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,                /*25-32*/
  0x0c,  0x04,  0x04,  0x04,  0x04,  0x04,  0x04,  0x04,	/* 2. */    /*33-40*/
  0x04,  0x04,  0x04,  0x04,  0x04,  0x04,  0x04,  0x04,                /*41-48*/
  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,  0x16,	/* 3. */    /*49-56*/
  0x16,  0x16,  0x04,  0x04,  0x04,  0x04,  0x04,  0x04,                /*57-64*/
  0x04,  0x15,  0x15,  0x15,  0x15,  0x15,  0x15,  0x05,	/* 4. */    /*65-72*/
  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,                /*73-80*/
  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,	/* 5. */    /*81-88*/
  0x05,  0x05,  0x05,  0x04,  0x04,  0x04,  0x04,  0x05,                /*89-96*/
  0x04,  0x15,  0x15,  0x15,  0x15,  0x15,  0x15,  0x05,	/* 6. */    /*97-104*/
  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,                /*105-112*/
  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,  0x05,	/* 7. */    /*113-120*/
  0x05,  0x05,  0x05,  0x04,  0x04,  0x04,  0x04,  0x00,                /*121-128*/
  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,	/* 8. */    /*129-136*/
  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,                /*137-144*/
  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,	/* 9. */    /*145-152*/
  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,                /*153-160*/
  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,	/* a. */    /*161-168*/
  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,                /*169-176*/
  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,	/* b. */    /*177-184*/
  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,                /*185-192*/
  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,	/* c. */    /*193-200*/
  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,                /*201-208*/
  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,	/* d. */    /*209-216*/
  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,                /*217-224*/
  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,	/* e. */    /*225-232*/
  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,  0x01,                /*233-240*/
  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,	/* f. */    /*241-248*/
  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,                /*249-256*/
};

#endif			/* } */
