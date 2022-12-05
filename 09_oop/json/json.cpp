#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>


using namespace std;


struct BasicToken { string value; };


struct StringToken : public BasicToken {

    StringToken(string str) { value = "\"" + str + "\""; }
};


struct NumToken : BasicToken {

    template <typename T>

    NumToken(T num) { value = "\"" + to_string(num) + "\""; }
};


struct BoolToken : BasicToken {

    BoolToken(bool bl) { value = bl ? "\"true\"" : "\"false\""; }
};


struct ArrayToken : BasicToken {

    ArrayToken(initializer_list<BasicToken> arr) {
        value = "[\n        ";
        for (size_t i = 1; auto k : arr) {
            value.append(k.value);
            if (i != arr.size()) {
                value.append(",\n        ");
                i++;
            }
        }
        value.append("\n    ]");
    }
};


struct Json
{
    unordered_map<string, BasicToken> tokens;

    Json(unordered_map<string, BasicToken> input) { tokens = input; }

    string output() {
        string out = "{\n";
        for (size_t i = 1; const auto & elem : tokens) {
            out.append("    \"" + elem.first + "\": " + elem.second.value);
            if (i != tokens.size()) {
                out.append(",\n");
                i++;
            }
        }
        out.append("\n}");

        return out;
    }
};