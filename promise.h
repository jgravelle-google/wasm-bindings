#ifndef _PROMISE_H_
#define _PROMISE_H_

typedef void PromiseInit(void* resolve, void* reject);
typedef void* AnyCallback(/*optional*/ void* value);

struct Promise;
struct Promise* Promise_constructor(PromiseInit init);
struct Promise* Promise_then(
  Promise* self,
  /*optional*/ AnyCallback fulfillCallback,
  /*optional*/ AnyCallback rejectCallback);
struct Promise* Promise_catch(
  Promise* self,
  /*optional*/ AnyCallback rejectCallback);
struct Promise* Promise_resolve(void* value);
struct Promise* Promise_reject(void* value);
struct Promise* Promise__any(void** values);
struct Promise* Promise_every(void** values);

#endif // _PROMISE_H_
