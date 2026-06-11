#pragma once

#include <string>

struct HttpCheckResult
{
    std::string url;
    bool success{};
    long statusCode{};
    long long elapsedMs{};
    std::string errorMessage;
};

HttpCheckResult checkUrl(const std::string& url);