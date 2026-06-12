#include "StatusClassifier.h"

#include <cassert>

void testHealthyForSuccessful2xx()
{
    const HttpCheckResult result{
        "https://example.com",
        true,
        200,
        100,
        ""
    };

    assert(isHealthy(result));
}

void testHealthyForRedirect3xx()
{
    const HttpCheckResult result{
        "https://example.com",
        true,
        301,
        100,
        ""
    };

    assert(isHealthy(result));
}

void testUnhealthyFor4xx()
{
    const HttpCheckResult result{
        "https://example.com/missing",
        true,
        404,
        100,
        ""
    };

    assert(!isHealthy(result));
}

void testUnhealthyForRequestError()
{
    const HttpCheckResult result{
        "https://bad.test",
        false,
        0,
        5000,
        "Timeout was reached"
    };

    assert(!isHealthy(result));
}

int main()
{
    testHealthyForSuccessful2xx();
    testHealthyForRedirect3xx();
    testUnhealthyFor4xx();
    testUnhealthyForRequestError();

    return 0;
}