#include "String.h"
#include <malloc.h>
#include <string.h>


struct String_t
{
	char *stringPtr;
	size_t length;
} String;

uint GetLastStringException()
{
	return g_LastStringException;
}

String *CreateString(const char *source)
{
	g_LastStringException = 0;

	if (source)
	{
		String *destination = (String *)malloc(sizeof(source));
		size_t index;

		if (destination)
		{
			for (index = 0; source[index] != '\0'; ++index)
			{
				destination->stringPtr[index] = source[index];
			}

			destination->length = index;

			destination->stringPtr[index] = '\0';

			return destination;
		}
		else
		{
			// catch exception if destination wasn't allocated correctly
			g_LastStringException = 2;
			return NULL;
		}
	}
	else
	{
		g_LastStringException = 1;
		return NULL;
	}
	
}

bool DeleteString(String *str)
{
	g_LastStringException = 0;
	bool isSuccessful;

	if (str)
	{
		free(str);

		// Using uninitalized memory but we're making sure it is unintialized
		if (!str)
		{
			isSuccessful = true;
		}
		else
		{
			isSuccessful = false;
		}
	}
	else
	{
		g_LastStringException = 1;
		isSuccessful = false;
	}

	return isSuccessful;
}

const char *GetString(const String *str)
{
	g_LastStringException = 0;

	if (str)
	{
		return str->stringPtr;
	}
	else
	{
		g_LastStringException = 1;
		return NULL;
	}
}

size_t GetStringLength(const String *str)
{
	g_LastStringException = 0;

	if (str)
	{
		return str->length;
	}
	else
	{
		g_LastStringException = 1;
		return 0;
	}
}

bool IsEmpty(const String *str)
{
	g_LastStringException = 0;

	if (str)
	{
		return (str->length == 0) ? true : false;
	}
	else
	{
		g_LastStringException = 1;
		return true;
	}
}

int CompareString(const String *str1, const String *str2)
{
	if (str1 && str2)
	{
		return strcmp(str1->stringPtr, str2->stringPtr);
	}
	else
	{
		g_LastStringException = 1;
		return 0xdeadbeef;
	}
}

String *CopyString(String *dst, const String *src)
{
	g_LastStringException = 0;

	if (dst && src)
	{
		dst = (String *) malloc(sizeof(src));

		if (dst)
		{
			size_t index;

			for (index = 0; index < src->length; ++index)
			{
				dst->stringPtr[index] = src->stringPtr[index];
			}
			dst->stringPtr[index] = '\0';
		}
		else
		{
			g_LastStringException = 2;
		}
	}
	else
	{
		g_LastStringException = 1;
	}

	return NULL;
}

String *CopyCString(String *dst, const char *src)
{
	g_LastStringException = 0;

	if (dst)
	{
		dst = CreateString(src);
		return dst;
	}
	else
	{
		g_LastStringException = 2;
		return NULL;
	}
}