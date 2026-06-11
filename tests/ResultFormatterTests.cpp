#include "HttpChecker.h"
#include "ResultFormatter.h"
#include <cassert>

void testFormatSuccesfulResult()
{
	HttpCheckResult result{ "https://example.com", true, 200, 123, "" };
	
	assert(formatResult(result) == "https://example.com | 200 | 123 ms");
}

void testFormatErrorResult()
{
	HttpCheckResult result{ "https://example.com", false, 200, 123, "Timeout was reached" };

	assert(formatResult(result) == "https://example.com | ERROR | Timeout was reached");
}


int main()
{
	testFormatSuccesfulResult();
	testFormatErrorResult();

	return 0;
}