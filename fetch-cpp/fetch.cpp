// C++ version of fetch program

#include "fetch.hpp"

void fetchAsyncAwait() {
  Response response = await(fetch("data/foo.json"));
  JSON data = await(response.json());
  printf("%s\n", data["someProp"].str().c_str());
}

void fetchPromise() {
  fetch("data/foo.json")
    .then([](Response response) {
      return response.json();
    })
    .then([](JSON data) {
      printf("%s\n", data["someProp"].str().c_str());
    });
}
