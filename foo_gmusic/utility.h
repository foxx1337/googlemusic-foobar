#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include "disableWarnings.h"
MSC_DISABLE_WARNINGS
#include "string_base.h"
#include <Windows.h>
MSC_RESTORE_WARNINGS


namespace foo_gmusic
{

namespace detail
{
inline std::vector<TCHAR> toTChar(const pfc::string8& text)
{
#ifdef  UNICODE
    size_t requiredSize;
    mbstowcs_s(&requiredSize, nullptr, 0, text.c_str(), text.get_length());

    auto res = std::vector<TCHAR>(requiredSize + 1);
    mbstowcs_s(nullptr, res.data(), res.size(), text.c_str(), text.get_length());
#else
    auto res = std::vector<TCHAR>(text.size());
    std::copy(text.begin(), text.end(), res.begin());
#endif
    return res;
}

inline pfc::string8 fromTChar(const std::vector<TCHAR>& text)
{
#ifdef UNICODE
    std::vector<char> chars(text.size() / sizeof(TCHAR));
    wcstombs_s(nullptr, chars.data(), chars.size(), text.data(), _TRUNCATE);
    return{ chars.data(), chars.size() };
#else
    return{ text.data(), test.size() };
#endif
}

inline std::string toStdString(const pfc::string& str)
{
    return str.c_str();
}

inline pfc::string8 toPfcString(const std::string& str)
{
    return str.c_str();
}

inline pfc::string8 toPfcString(t_int64 val)
{
    return pfc::format_int(val).toString();
}

} // namespace detail

} // namespace foo_gmusic