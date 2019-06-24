/*
Translation of JS sample
(https://developers.google.com/web/updates/2015/03/introduction-to-fetch)

function status(response) {
  if (response.status >= 200 && response.status < 300) {
    return Promise.resolve(response)
  } else {
    return Promise.reject(new Error(response.statusText))
  }
}

function json(response) {
  return response.json()
}

fetch('users.json')
  .then(status)
  .then(json)
  .then(function(data) {
    console.log('Request succeeded with JSON response', data);
  }).catch(function(error) {
    console.log('Request failed', error);
  });
*/

#include "fetch.h"
#include "promise.h"

void* status(void* anyResponse) {
  Response* response = (Response*)anyResponse;
  int status = Response_status(response);
  if (status >= 200 && status < 300) {
    return Promise_resolve(response);
  } else {
    Error* error = Error_constructor(response.statusText);
    return Promise_reject(error);
  }
}

void* json(void* anyResponse) {
  Response* response = (Response*) anyResponse;
  return Response_json(response);
}

void lambda_then(data) {
  console_log('Request succeeded with JSON response', data);
}
void lambda_catch(error) {
  console_log('Request failed', error);
}

int main() {
  Promise* promise = fetch("users.json");
  Promise_then(promise, status);
  Promise_then(promise, json);
  Promise_then(promise, lambda_then);
  Promise_catch(promise, lambda_catch);
  return 0;
}
