#ifndef _JSON_HPP_
#define _JSON_HPP_

// Handwritten C++ glue code

enum class JSONKind {
  number,
  string,
  array,
  dict,
};
class JSON {
  JSONKind kind;
  union {
    double number;
    std::string string;
    std::vector<JSON> array;
    std::map<std::string, JSON> dict;
  } data;

public:
  JSON(double number) : kind(JSONKind::number) {
    data.number = number;
  }
  JSON(std::string string) : kind(JSONKind::string) {
    data.string = string;
  }
  JSON(std::vector<JSON> array) : kind(JSONKind::array) {
    data.array = array;
  }
  JSON(std::map<std::string, JSON> dict) : kind(JSONKind::dict) {
    data.dict = dict;
  }

  JSON operator[](int idx) {
    assert(kind == JSONKind::array);
    return data.array[idx];
  }
  JSON operator[](std::string key) {
    assert(kind == JSONKind::dict);
    return data.dict[key];
  }

  std::string str() {
    assert(kind == JSONKind::string);
    return data.string;
  }
};

#endif // _JSON_HPP_
