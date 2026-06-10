#include <cpr/cpr.h>

#include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

struct HttpCheckResult
{
    std::string url;
    bool success{};
    long statusCode{};
    long long elapsedMs{};
    std::string errorMessage;
};

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

void printResult(const HttpCheckResult& result)
{
    std::cout << result.url << " | ";

    if (!result.success)
    {
        std::cout << "ERROR | " << result.errorMessage << "\n";
        return;
    }

    std::cout << result.statusCode << " | " << result.elapsedMs << " ms\n";
}

int main(int argc , char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: HttpStatusMonitor <url> [url...]\n";
        return 1;
    }

    for (int i = 1; i < argc; ++i)
    {
        const std::string url = argv[i];

        const HttpCheckResult result = checkUrl(url);

        printResult(result);
    }

    return 0;
}