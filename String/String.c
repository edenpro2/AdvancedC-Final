#include "String.h"
#include <malloc.h>
#include <string.h>


uint GetLastStringException()
{
	return g_LastStringException;
}

String *CreateString(const char *source)
{
	g_LastStringException = 0;

	if (source)
	{
		String *destination = (String *) malloc(sizeof(String));
		destination->s_ptr = (char *) malloc (strlen(source) + 1);

		size_t index;

		if (destination && destination->s_ptr)
		{
			for (index = 0; source[index] != '\0'; ++index)
			{
				destination->s_ptr[index] = source[index];
			}

			destination->length = index;

			destination->s_ptr[index] = '\0';

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
		if (str->s_ptr)
		{
			free(str->s_ptr);
		}
		free(str);
		isSuccessful = true;
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
		return str->s_ptr;
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
		return strcmp(str1->s_ptr, str2->s_ptr);
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
		DeleteString(dst);

		dst = CreateString(src->s_ptr);
		if (dst)
		{
			return dst;
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


String *AppendString(String *dst, const String *src)
{
	g_LastStringException = 0;

	if (dst && src)
	{
		String *ConcatString = (String *)malloc(sizeof(String));
		ConcatString->s_ptr = (char *)malloc(dst->length + src->length + 2);

		size_t index;

		for (index = 0; index < dst->length; ++index)
		{
			ConcatString->s_ptr[index] = dst->s_ptr[index];
		}

		for (index; index < (dst->length + src->length); ++index)
		{
			ConcatString->s_ptr[index] = src->s_ptr[index + dst->length];
		}

		ConcatString->s_ptr[index] = '\0';

		ConcatString->length = index;

		DeleteString(dst);
		dst = ConcatString;

		return dst;
	}
	else
	{
		g_LastStringException = 1;
		return NULL;
	}

}

// Still not implemented correctly
String *AppendCString(String *dst, const char *src)
{
	String *tempSrc = CreateString(src);

	AppendString(dst, tempSrc);

	DeleteString(tempSrc);

	return dst;
}