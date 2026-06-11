#include <ResultFormatter.h>

#include <sstream>

std::string formatResult(const HttpCheckResult& result)
{
	std::ostringstream output;
	
	output << result.url << " | ";

	if (!result.success)
	{
		output << "ERROR | " << result.errorMessage;
		return output.str();
	}

	output << result.statusCode << " | " << result.elapsedMs << " ms";

	return output.str();
}
