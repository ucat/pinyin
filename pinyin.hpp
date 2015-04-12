#ifndef __PINYIN_HPP__
#define __PINYIN_HPP__

#include <unordered_map>
#include <string>
#include <locale>
#include <codecvt>


namespace ucat {

extern const std::unordered_map<std::wstring, std::string> hz2py_dict;

struct PinyinConfig {
    std::string delimiter;
    bool accent;
    bool only_chinese;
    bool uppercase;

    PinyinConfig():
        accent(true),
        only_chinese(false),
        uppercase(false) {}
};

class Pinyin {
public:
    parse(const std::string & str, const PinyinConfig & conf) {
        std::wstring_convert<std::codecvt_utf8_utf16<utf16_t>, wchar_t> wchar_conv;
    }

    parse(const std::wstring & str, const PinyinConfig & conf) {

    }
private:
    std::string hz2py(const std::wstring & hz) {
        // 我们考虑的词大小为4个汉字即可
        std::string py;

        for (size_t pos = 0; pos < hz.size(); pos++) {
            for (size_t len = 4; len >= 1; len--) {
                if (pos + len > hz.size()) {
                    continue;
                }
                std::wstring hz_sub = hz.substr(pos, len);
                auto iter = hz2py_dict.find(hz_sub);
                if (iter != hz2py_dict.end()) {
                    py += iter->second;
                    pos += len - 1;
                    break;
                }
            }

        }

        return py;
    }
};


};


#endif

