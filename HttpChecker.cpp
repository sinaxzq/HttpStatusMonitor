#include "HttpChecker.h"

#include <cpr/cpr.h>

#include <chrono>

HttpCheckResult checkUrl(const std::string& url)
{
    const auto start = std::chrono::steady_clock::now();

    const cpr::Response response = cpr::Get(
        cpr::Url{ url } ,
        cpr::Timeout{ 5000 }
    );

    const auto end = std::chrono::steady_clock::now();

    const auto elapsedMs =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    return HttpCheckResult{ url, !response.error, response.status_code, elapsedMs, response.error.message };
}