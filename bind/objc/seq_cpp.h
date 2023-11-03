// Copyright 2015 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef __GO_SEQ_CPP_HDR__
#define __GO_SEQ_CPP_HDR__

#include "ref.h"
#include "seq.h"
#include "_cgo_export.h"
#include <string>

#define NULL_REFNUM 41
#define IS_FROM_GO(x) ((x) < 0)

class GoSeqReference {
public:
  GoSeqReference() = delete;
  GoSeqReference(int32_t refnum, void *obj) : _refnum(refnum), _obj(obj) {}
  int32_t incNum() {
    IncGoRef(_refnum);
    return _refnum;
  }
  void *obj() {
    return _obj;
  }
  ~GoSeqReference() {
    if (IS_FROM_GO(_refnum)) { // TODO(acme): check if this is the right way to do this
      DestroyRef(_refnum);
    }
  }
private:
  int32_t _refnum;
  void *_obj;
};

class GoSeqObject {
public:
    virtual GoSeqReference* ref() = 0;
};

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// go_seq_objc_from_refnum is a special case of go_seq_from_refnum for
// Objective-C objects that implement a Go interface.
extern void *go_seq_objc_from_refnum(int32_t refnum);

extern nbyteslice go_seq_from_objc_bytearray(std::vector<std::uint8_t> *data, int copy); // TODO(acme): fix this
extern nstring go_seq_from_objc_string(std::string s);

extern int32_t go_seq_go_to_refnum(GoSeqReference *ref);

extern GoSeqReference *go_seq_from_refnum(int32_t refnum);

extern int32_t go_seq_to_refnum(void *ref);

#ifdef __cplusplus
}
#endif // __cplusplus

extern std::vector<std::uint8_t> *go_seq_to_objc_bytearray(nbyteslice, int copy); // TODO(acme): fix this
extern std::string go_seq_to_objc_string(nstring str); // TODO(acme): fix this

#endif // __GO_SEQ_CPP_HDR__
