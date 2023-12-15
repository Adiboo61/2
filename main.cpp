
#include <iostream>
#include <string>
#include <cpr/cpr.h>


void search(std::string &text) {
    size_t pos_text = 0;
	size_t b_pos;
	size_t e_pos;
    while(text.find("<h1>", pos_text) != std::string::npos) {
        b_pos = text.find("<h1>") + 4;
        e_pos = text.find("</h1>");
        std::cout << text.substr(b_pos, e_pos - b_pos);
        pos_text = e_pos;
    }
}


int main() {

	cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"));
	search(r.text);
}