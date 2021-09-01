#include <stdbool.h>
#include <stddef.h>

#ifndef _STRING_H_
#define _STRING_H_


///* ERROR HANDLING *///

typedef unsigned int uint;

/**
 * @brief | 0 - No errors
 *		  | 1 - Passed a null pointer to a function
 *        | 2 - Not enough memory
 *		  | 3 -
**/
uint g_LastStringException;


/**
 * @brief  Return the last exception thrown by program
**/
uint GetLastStringException();




///* STRING STRUCTURE *///

typedef struct String_t 
{
	char *s_ptr;
	size_t length;

} String;


/**
 * @brief  Receives a source string, allocates space for the String object
 *		   and a new copy of the source, then copies the source to the String object and
 *		   returns that object.
 * @param  source that is the original string
 * @return pointer to copied string
**/
String *CreateString(const char *source);


/**
 * @brief  frees all the resources of the string, the String object itself, and also the internal char *.
 * @param  source that is the string to deallocate
 * @return boolean that all is successful
**/
bool DeleteString(String *str);


/**
 * @brief if the user wants the pointer const char* of a string struct
 * @param str the target string
 * @return the const char* to str
*/
const char *GetString(const String *str);


/**
 * @brief returns the string's length
 * @param The string to check
 * @return the length
**/
size_t GetStringLength(const String *str);


/**
 * @brief If the string is empty or not
 * @param str to check
**/
bool IsEmpty(const String *str);


/**
 * @brief
 * @param str1
 * @param str2
**/
int CompareString(const String *str1, const String *str2); // see strcmp()


/**
 * @brief Copy the string source into destination string
 * @param dst string to be copied to
 * @param src string to be copied from
 * @return the destination pointer
**/
String *CopyString(String *dst, const String *src); // don’t forget to take care of the old underlying string!


/**
 * @brief Copy C-style string into struct string
 * @param dst string
 * @param src C-style string to copy from
 * @return dst pointer
**/
String *CopyCString(String *dst, const char *src);

/**
 * @brief Appends src to dest
 * @param dst string to append to
 * @param src string
 * @return pointer to concatenated string
*/
String *AppendString(String *dst, const String *src);  


/**
 * @brief Appends const char to 
 * @param dst 
 * @param src 
 * @return 
*/
String *AppendCString(String *dst, const char *src);



#endif