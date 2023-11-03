// Copyright 2015 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef __GO_SEQ_HDR__
#define __GO_SEQ_HDR__

#include "ref.h"

#ifdef DEBUG
#define LOG_DEBUG(...) printf(__VA_ARGS__);
#else
#define LOG_DEBUG(...) ;
#endif

#define LOG_INFO(...) printf(__VA_ARGS__);
#define LOG_FATAL(...)                                                         \
  {                                                                            \
    printf(__VA_ARGS__);                                                       \
    abort();                                                                   \
  }

// Platform specific types
typedef struct nstring {
	void *ptr;
	int len;
} nstring;
typedef struct nbyteslice {
	void *ptr;
	int len;
} nbyteslice;
typedef int nint;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

extern void init_seq();
// go_seq_dec_ref decrements the reference count for the
// specified refnum. It is called from Go from a finalizer.
extern void go_seq_dec_ref(int32_t refnum);
// go_seq_inc_ref increments the reference count for the
// specified refnum. It is called from Go just before converting
// a proxy to its refnum.
extern void go_seq_inc_ref(int32_t refnum);

extern nstring cproxy_error_Error(int32_t refnum);
//extern int32_t go_seq_to_refnum(id obj); // TODO(acme): fix this

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __GO_SEQ_DARWIN_HDR__
