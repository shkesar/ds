#include "type.h"

int 			get_int 	(any_t any) { return any.value.i;  }

unsigned int 	get_uint	(any_t any) { return any.value.ui; }

char 			get_char	(any_t any) { return any.value.c;  }

char* 			get_string 	(any_t any) { return any.value.s;  }

long  			get_long   	(any_t any) { return any.value.l;  }

unsigned long 	get_ulong 	(any_t any) { return any.value.ul; }

void* 			get_vptr 	(any_t any) { return any.value.v;  }
