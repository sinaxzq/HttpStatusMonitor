#include "StatusClassifier.h"

bool isHealthy(const HttpCheckResult& result)
{
    return result.success && result.statusCode >= 200 && result.statusCode < 400;
}